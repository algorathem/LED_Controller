#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QPalette>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStyle>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialPort(new QSerialPort(this))
{
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(1023);

    // List available ports in debug output
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : serialPortInfos) {
        qDebug() << "Port found:" << info.portName() << "-" << info.description();
    }

    initializeSerialPort();

    // Connect slider value changes to send serial commands
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](int value) {
        if (serialPort->isOpen()) {
            QString command = "S" + QString::number(value) + "\n";
            serialPort->write(command.toUtf8());
            serialPort->flush();  // Ensure data sent immediately
            ui->labelStatus->setText("Mode: Slider"); //For debugging purposes to get slider serial values- QString::number(value)
        }
    });

    // Connect toggle button to send "P" command (potentiometer mode)
    connect(ui->pushButtonToggle, &QPushButton::clicked, this, [=]() {
        if (serialPort->isOpen()) {
            serialPort->write("P\n");  // Switch to potentiometer mode
            ui->labelStatus->setText("Mode: Potentiometer");
        }
    });

    connect(ui->darkModeCheckBox, &QCheckBox::toggled, this, &MainWindow::onDarkModeToggled);

}

MainWindow::~MainWindow()
{
    if (serialPort->isOpen())
        serialPort->close();
    delete ui;
}

void MainWindow::initializeSerialPort()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    if (serialPortInfos.isEmpty()) {
        ui->statusbar->showMessage("No serial ports found");
        qDebug() << "No serial ports found";
        return;
    }

    serialPort->setPort(serialPortInfos.first());

    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    connect(serialPort, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        ui->statusbar->showMessage("Failed to open serial port");
        qDebug() << "Failed to open serial port";
        return;
    }

    ui->statusbar->showMessage(QString("Connected to %1").arg(serialPort->portName()));
    qDebug() << "Serial port opened:" << serialPort->portName();
}

// Buffer to accumulate incoming data until newline
QString buffer;

void MainWindow::readSerialData()
{
    buffer += QString::fromUtf8(serialPort->readAll());

    int newlineIndex = buffer.indexOf('\n');
    while (newlineIndex != -1) {
        QString line = buffer.left(newlineIndex).trimmed();
        buffer = buffer.mid(newlineIndex + 1);

        qDebug() << "Line received:" << line;

        if (!line.isEmpty()) {
            ui->labelPotValue->setText(line);
        }

        newlineIndex = buffer.indexOf('\n');
    }
}

void MainWindow::onDarkModeToggled(bool checked)
{
    static QPalette lightPalette = qApp->style()->standardPalette();

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(42,42,42));
    darkPalette.setColor(QPalette::AlternateBase, QColor(66,66,66));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42,130,218));
    darkPalette.setColor(QPalette::Highlight, QColor(42,130,218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    if (checked) {
        qApp->setPalette(darkPalette);
        ui->labelPotValue->setStyleSheet("QLabel { color: white; }");
        ui->labelStatus->setStyleSheet("QLabel { color: white; }");
    } else {
        qApp->setPalette(lightPalette);
        ui->labelPotValue->setStyleSheet("QLabel { color: black; }");
        ui->labelStatus->setStyleSheet("QLabel { color: black; }");
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        ui->statusbar->showMessage("Critical serial error occurred");
        qDebug() << "Serial error:" << serialPort->errorString();
        serialPort->close();
    }
}
