#define led_pin A3
#define led 13
#define buzzer 12
#define button_pin A2
#define relay_pin 8

int sensor_analog_val1 = 0;
int sensor_analog_val2 = 0;

bool sensor_digital_val1 = false;
bool sensor_digital_val2 = false;

void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, 1);
  pinMode(led,1);
  digitalWrite(led_pin, 0);
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(relay_pin, 1);
  digitalWrite(relay_pin, 1);
}

void open_water(int timee)
{
  digitalWrite(relay_pin, 0);
  digitalWrite(led, 1);
  delay(timee);
}

void close_water()
{
  digitalWrite(relay_pin, !0);
  digitalWrite(led, !1);
  delay(1);
}

void buzzerr()
{

  for (int b = 5; b > 0; b--)
  {
    tone(buzzer, 2000);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
}

void sensor_scan()
{

  sensor_analog_val1 = analogRead(A0);
  sensor_analog_val2 = analogRead(A1);

  sensor_digital_val1 = digitalRead(2);
  sensor_digital_val2 = digitalRead(3);

  if (sensor_digital_val1 || sensor_digital_val2)
  {
    buzzerr();
    open_water(5000);
  }
  //else
    //close_water();

  // if(sensor_analog_val1 || sensor_analog_val2 == 500)
  // {

  // }
}

void botton_scan()
{
  if (digitalRead(button_pin) == 0)
  {
    delay(30);
    if (digitalRead(button_pin) == 0)
    {
      open_water(100);
      digitalWrite(led_pin, 1);
    }
  }
  else
  {
    close_water();
    digitalWrite(led_pin, 0);
  }
}

void loop()
{
  botton_scan();
  sensor_scan();
  Serial.print(sensor_analog_val1);
  Serial.print(sensor_digital_val1);
  Serial.print(" ");
  Serial.print(sensor_digital_val2);
  Serial.print(sensor_analog_val2);
  Serial.println("");
  delay(1);
}
