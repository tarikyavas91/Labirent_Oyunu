#include <Servo.h>
const byte pin_restart = 0;
const byte pin_Xup = 3;
const byte pin_Xdown = 4;
const byte pin_Yup = 5;
const byte pin_Ydown = 6;

const byte min_number = 30;
const byte max_number = 150;

Servo servo_x;
Servo servo_y;

byte x_kordinat = 90;
byte y_kordinat = 90;

byte kordinat_(byte kordinat, Servo my); // Kordinatları düzeltme fonk. Min ve max aşarsa diye
void _rest();                  // kodrinatları tekrardan 90 a çeker

void setup()
{

  Serial.begin(9600);
  servo_x.attach(9);
  servo_y.attach(10);

  pinMode(pin_Xup, INPUT);
  pinMode(pin_Xdown, INPUT);
  pinMode(pin_Yup, INPUT);
  pinMode(pin_Ydown, INPUT);

  attachInterrupt(pin_restart, _rest, RISING);
}

void loop()
{
  while (digitalRead(pin_Xup) == HIGH)
  {
    if (x_kordinat >= min_number && x_kordinat <= max_number)
      x_kordinat++;
    servo_x.write(x_kordinat);
    delay(20);
    Serial.println("X_up");
  }

  while (digitalRead(pin_Xdown) == HIGH)
  {
    if (x_kordinat >= min_number && x_kordinat <= max_number)
      x_kordinat--;
    servo_x.write(x_kordinat);
    delay(20);
    Serial.println("X_down");
  }

  while (digitalRead(pin_Yup) == HIGH)
  {
    if (y_kordinat >= min_number && y_kordinat <= max_number)
      y_kordinat++;
    servo_y.write(y_kordinat);
    delay(20);
    Serial.println("Y_up");
  }

  while (digitalRead(pin_Ydown) == HIGH)
  {
    if (y_kordinat >= min_number && y_kordinat <= max_number)
      y_kordinat--;
    servo_y.write(y_kordinat);
    delay(20);
    Serial.println("Y_down");
  }

  /* Kodinatları düzeltme */
  if (x_kordinat > max_number || x_kordinat < min_number)
    x_kordinat = kordinat_(x_kordinat, servo_x);
  if (y_kordinat > max_number || y_kordinat < min_number);
    y_kordinat = kordinat_(y_kordinat, servo_y);

  Serial.print(y_kordinat);
  Serial.print("      ");
  Serial.println(x_kordinat);

}

byte kordinat_(byte kordinat, Servo my)
{
  if (kordinat > max_number)
    kordinat = max_number;
  else if (kordinat < min_number)
    kordinat = min_number;
  my.write(kordinat);
  return (kordinat);
}

void _rest()
{
  Serial.println("RESTARS");
  servo_x.write(90);
  servo_y.write(90);
  x_kordinat = 90;
  y_kordinat = 90;
  Serial.println("kesme");
}