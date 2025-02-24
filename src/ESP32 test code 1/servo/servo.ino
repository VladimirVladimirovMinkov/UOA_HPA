void setup() {

  Serial.begin(115200);

  pinMode(2, OUTPUT);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);

  pinMode(15, OUTPUT);
  delay(100);
  digitalWrite(15, LOW);
  delay(100);
}

long start;
char snum[5];
int i = 1000;
bool increasingi = true;
int j = 1000;
bool increasingj = true;

void loop() {

  while(Serial.available()>0)
  {
    if(Serial.read() == 's')
    {
      i = 1000;
      j = 1000;
      delay(1000);
    }
  }


  if(i > 2500)
    increasingi = false;
  else if(i < 500)
    increasingi = true;
  
  if(j > 2500)
    increasingj = false;
  else if(j < 500)
    increasingj = true;
  
  i = i + (increasingi - !increasingi);
  j = j + (increasingj - !increasingj);

  start = micros();
  digitalWrite(15, HIGH);
  while (micros() - start < i);
  digitalWrite(15, LOW);

  start = micros();
  digitalWrite(2, HIGH);
  while (micros() - start < j);
  digitalWrite(2, LOW);

  delay(7);
}