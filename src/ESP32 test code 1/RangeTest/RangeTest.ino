void setup() {
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(100);
}

void loop() {
  for(int i = 60; i < 76; i+=3)
  {
    for(int j = 26; j > 0; j-=8)
    {
      digitalWrite(16, LOW);
      delay((i-j)/4);
      digitalWrite(16, HIGH);
      delay((i-j)/4);

      digitalWrite(16, LOW);
      delay((i-j)/4);
      digitalWrite(16, HIGH);
      delay((i-j)/4);

      digitalWrite(16, LOW);
      delay((i-j)/4);
      digitalWrite(16, HIGH);
      delay((i-j)/4);
    }
  }
}
