const int LED=9; // Присваиваем контакту 9 идентификатор LED

void setup()
{
  pinMode(LED,OUTPUT); // Задаём для контакта LED режим вывода
}

void loop()
{
  for (int i = 100; i <= 1000; i += 10)
  {
    digitalWrite(LED, HIGH); // Устанавливаем на контакте LED высокий логический уровень
    delay(i);
    digitalWrite(LED, LOW); // Устанавливаем на контакте LED низкий логический уровень
    delay(i);
  }
}
