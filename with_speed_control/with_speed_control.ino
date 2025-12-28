
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

/* -------- L298N - LEFT MOTORS -------- */
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14
#define ENA1 33
#define ENB1 12

/* -------- L298N - RIGHT MOTORS -------- */
#define IN5 18
#define IN6 5
#define IN7 17
#define IN8 16
#define ENA2 19
#define ENB2 4

int speedValue = 150;   // PWM (0–255)

/* -------- SETUP -------- */
void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);

  // PWM Channels
  ledcSetup(0, 1000, 8); ledcAttachPin(ENA1, 0);
  ledcSetup(1, 1000, 8); ledcAttachPin(ENB1, 1);
  ledcSetup(2, 1000, 8); ledcAttachPin(ENA2, 2);
  ledcSetup(3, 1000, 8); ledcAttachPin(ENB2, 3);

  Serial.begin(115200);
  SerialBT.begin("SLEEPY_BOT@pritam");

  stopMotor();
}

/* -------- LOOP -------- */
void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    Serial.println(cmd);

    if (cmd == 'F') forward();
    else if (cmd == 'B') backward();
    else if (cmd == 'L') left();
    else if (cmd == 'R') right();
    else if (cmd == 'S' || cmd == 'D') stopMotor();
    else setSpeedByChar(cmd);
  }
}

/* -------- SPEED CONTROL -------- */
void setSpeed() {
  ledcWrite(0, speedValue);
  ledcWrite(1, speedValue);
  ledcWrite(2, speedValue);
  ledcWrite(3, speedValue);
}

void setSpeedByChar(char c) {
  switch (c) {
    case '0': speedValue = 0;   break;
    case '1': speedValue = 25;  break;
    case '2': speedValue = 50;  break;
    case '3': speedValue = 75;  break;
    case '4': speedValue = 100; break;
    case '5': speedValue = 125; break;
    case '6': speedValue = 150; break;
    case '7': speedValue = 175; break;
    case '8': speedValue = 200; break;
    case '9': speedValue = 225; break;
    case 'q': speedValue = 255; break; // 100%
    default: return;
  }
  setSpeed();
}

/* -------- MOVEMENT -------- */
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
  setSpeed();
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
  setSpeed();
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
  setSpeed();
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
  setSpeed();
}

void stopMotor() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}