int redLed = 13;
int yellowLed = 12;
int greenLed = 8;

unsigned long previousMillis = 0;
int ledState = 0;

void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();

    switch (ledState) {
        case 0:
            if (currentMillis - previousMillis >= 6000) {
                previousMillis = currentMillis;
                digitalWrite(redLed, LOW);
                digitalWrite(yellowLed, HIGH);
                ledState = 1;
            } else {
                digitalWrite(redLed, HIGH);
            }
            break;

        case 1:
            if (currentMillis - previousMillis >= 2000) {
                previousMillis = currentMillis;
                digitalWrite(yellowLed, LOW);
                digitalWrite(greenLed, HIGH);
                ledState = 2;
            }
            break;

        case 2:
            if (currentMillis - previousMillis >= 2000) {
                previousMillis = currentMillis;
                digitalWrite(greenLed, LOW);
                digitalWrite(yellowLed, HIGH);
                ledState = 3;
            }
            break;

        case 3:
            if (currentMillis - previousMillis >= 2000) {
                previousMillis = currentMillis;
                digitalWrite(yellowLed, LOW);
                ledState = 0;
            }
            break;
    }
}
