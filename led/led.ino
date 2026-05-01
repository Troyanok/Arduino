const int LED=9; // Присваиваем контакту 9 идентификатор LED

void setup()
{
  pinMode(LED,OUTPUT); // Задаём для контакта LED режим вывода
}

void loop()
{
  digitalWrite(LED, HIGH); // Устанавливаем на контакте LED высокий логический уровень
}
