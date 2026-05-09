const int LED=9; // Присваиваем контакту 9 идентификатор LED
const int BUTTON=2; // Присваиваем контакту 2 идентификатор BUTTON
int count = 0;
  
void setup()
{
  pinMode(LED,OUTPUT); // Задаём для контакта LED режим вывода
  pinMode(BUTTON,INPUT); // Задаём для контакта LED режим ввода
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH)
  {
    count ++;
    if (count % 2 == 1)
    {
      for (int i = 0; i <= 255; i ++)
      {
        analogWrite(LED, i);
        delay(10);
      }
    }
    else
    {
      for (int i = 255; i > 1; i --)
      {
        analogWrite(LED, i);
        delay(10);
      }
    }
  }
}
