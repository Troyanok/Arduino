const int LED=9; // Присваиваем контакту 9 идентификатор LED
const int BUTTON=2; // Присваиваем контакту 2 идентификатор BUTTON

void setup()
{
  pinMode(LED,OUTPUT); // Задаём для контакта LED режим вывода
  pinMode(BUTTON,INPUT); // Задаём для контакта LED режим ввода
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    for (int i = 0; i <= 255; i ++)
    {
      analogWrite(LED, i);
      delay(10);
    }
    for (int i = 255; i >= 0; i --)
    {
      analogWrite(LED, i);
      delay(10);
    }
  }
}
