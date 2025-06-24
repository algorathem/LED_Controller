#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>          // For serial communication
#include <QSerialPortInfo>      // To list available serial ports

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();       // Slot to read incoming serial data
    void handleError(QSerialPort::SerialPortError error);  // Handle serial errors
    void onDarkModeToggled(bool checked);
private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;     // Serial port object

    void initializeSerialPort(); // Setup serial port
};

#endif // MAINWINDOW_H
