const int pwmPin = 9;       // PWM output pin
const int potPin = A0;      // Potentiometer analog pin
bool useSerialInput = false;
int pwmValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char mode = Serial.read();
    if (mode == 'S') {  // Switch to serial input mode
      useSerialInput = true;
      int value = Serial.parseInt();  // Read simulated potentiometer value
      pwmValue = map(value, 0, 1023, 0, 255);
      // Clear remaining buffer to avoid stuck reads
      while (Serial.available()) Serial.read();
    } else if (mode == 'P') {  // Switch back to potentiometer
      useSerialInput = false;
    }
  }

  if (!useSerialInput) {
    int potValue = analogRead(potPin);
    pwmValue = map(potValue, 0, 1023, 0, 255);
  }

  analogWrite(pwmPin, pwmValue);
  Serial.print("PWM: ");
  Serial.println(pwmValue);

  delay(50);  // Smooth output
}
