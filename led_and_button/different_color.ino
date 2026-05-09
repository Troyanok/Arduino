const int BLED = 11;   // Присваиваем контакту 9 идентификатор BLED 
const int GLED = 9;    // Присваиваем контакту 10 идентификатор GLED 
const int RLED = 10;   // Присваиваем контакту 11 идентификатор RLED 
const int BUTTON = 2;  // Присваиваем контакту 2 идентификатор BUTTON

boolean lastButton = LOW;     // Предыдущее состояние кнопки 
boolean currentButton = LOW;  // Текущее состояние кнопки 
int ledMode = 0;
int count = 0;

void setup()
{
  pinMode(BLED,OUTPUT);  // Задаём для контакта BLED режим вывода для голубого цвета
  pinMode(GLED,OUTPUT);  // Задаём для контакта GLED режим вывода для зелёного цвета
  pinMode(RLED,OUTPUT);  // Задаём для контакта RLED режим вывода для красного цвета
  pinMode(BUTTON,INPUT); // Задаём для контакта BUTTON режим ввода
  
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON); // Считываем текущее состояние кнопки
  if (last != current) // Текущее состояние отлично от последнего
  {
    delay(5);
    current = digitalRead(BUTTON); // Сбрасываем значение кнопки
  }
  return current; // Возвращаем текущее состояние кнопки
}

void setMode(int mode)
{
  if (count == 0)
  {
    return;
  }
  // Красный
  if (mode == 1)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  
  // Зелёный
  else if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }

  // Синий
  else if (mode == 3)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }

  // Фиолетовый (Красный + Синий)
  else if (mode == 4)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 256);
    analogWrite(BLED, 127);
  }

  // Зеленовато-Голубой (Синий + зелёный)
  else if (mode == 5)
  {
    analogWrite(RLED, 256);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }

  // Оранжевый (Зелёный + Красный)
  else if (mode == 6)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 256);
  }

  // Белый (Зелёный + Красный + Синий)
  else if (mode == 7)
  {
    analogWrite(RLED, 170);
    analogWrite(GLED, 170);
    analogWrite(BLED, 170);
  }
  
  //Отключен
  else if (mode == 0)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop()
{
  currentButton = debounce(lastButton);

  if ((lastButton == LOW) && (currentButton == HIGH))
  {
    ledMode++;
    count++;
  }

  lastButton = currentButton;

  if (ledMode == 8)
  {
    ledMode = 0;
  }
  
  setMode(ledMode);
}




