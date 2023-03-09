#include <Arduino.h>
#include <Servo.h>
int pos = 0;
enum pin
{
  pin_Xup = 3,
  pin_Xdown = 4,
  pin_Yup = 5,
  pin_Ydown = 6,
  pin_restart = 2
};

Servo servo_x;
Servo servo_y;

byte x_kordinat = 90;
byte y_kordinat = 90;

void _rest()
{
  servo_x.write(90);
  servo_y.write(90);
  x_kordinat = 90;
  y_kordinat = 90;
}
Servo myservo;
void setup()
{
  Serial.begin(9600);

  // servo_x.attach(9);
  // servo_y.attach(10);
  // Serial.print("Oyun Basliyor");

  // pinMode(pin_Xup, INPUT);
  // pinMode(pin_Xdown, INPUT);
  // pinMode(pin_Yup, INPUT);
  // pinMode(pin_Ydown, INPUT);

  // attachInterrupt(pin_restart, _rest, FALLING);
}

void loop()
{
  /*    servo_x.write(x_kordinat);
     x_kordinat++; */

/*   servo_x.write(x_kordinat);
  servo_y.write(y_kordinat);

  if (digitalRead(pin_Xup) == HIGH)
    if (x_kordinat >= 30 && x_kordinat <= 120)
      x_kordinat++;

  if (digitalRead(pin_Xdown) == HIGH)
    if (x_kordinat >= 30 && x_kordinat <= 120)
      x_kordinat--;

  if (digitalRead(pin_Yup) == HIGH)
    if (y_kordinat >= 30 && y_kordinat <= 120)
      y_kordinat++;
  if (digitalRead(pin_Ydown) == HIGH)
    if (y_kordinat >= 30 && y_kordinat <= 120)
      y_kordinat--; */

  Serial.print("X_up:");
  Serial.println(digitalRead(pin_Xup));
  /* Serial.print("  X_down:");
  Serial.print(digitalRead(pin_Xdown));
  Serial.print("----  Y_up:");
  Serial.print(digitalRead(pin_Yup));
  Serial.print("  Y_down:");
  Serial.println(digitalRead(pin_Ydown));

  Serial.println(" ");
  Serial.print("X_kordinat");
  Serial.print(x_kordinat); */
  // Serial.print("Y_kordinat");
  // Serial.println(y_kordinat);
  // Serial.println(" ");

  delay(500);
}