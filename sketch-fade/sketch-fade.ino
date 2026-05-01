const int LED=9; // Присваиваем контакту 9 идентификатор LED

void setup()
{
  pinMode(LED,OUTPUT); // Задаём для контакта LED режим вывода
}

void loop()
{
  for (int i = 0; i <= 256; i ++)
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
