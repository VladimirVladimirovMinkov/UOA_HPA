void setup() {
  Serial.begin(115200);

  pinMode(14, INPUT);
  pinMode(27, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(100);
}

long start;
int rudder = 1000;
int elevator = 1000;
int events[12];

void loop() {
  while(Serial.available()>0)
  {
    if(Serial.peek() == 's')
    {
      rudder = 1000;
      elevator = 1000;
      delay(1000);
    }
    Serial.write(Serial.read());
  }


  start = micros();
  digitalWrite(13, HIGH);
  while (micros() - start < rudder);
  digitalWrite(13, LOW);

  start = micros();
  digitalWrite(12, HIGH);
  while (micros() - start < elevator);
  digitalWrite(12, LOW);

  for(int i = 0; i < 5; i++)
  {
    start = micros();
    rudder = (analogRead(14)/3)+500;
    elevator = (analogRead(27)/3)+500;

    events[i*2] =  rudder;
    events[i*2+1] = elevator;
    // 10 milisconds of code

    while (micros() - start < 10000);
  }
  events[10] = random(200); // heart rate
  events[11] = micros();
  // save the events to eeprom or sd
}