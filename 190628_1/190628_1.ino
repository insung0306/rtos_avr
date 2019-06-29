void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
}

unsigned long prevMillis;
unsigned long prevMicros;
int duty = 0;
int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMillis = millis();
  unsigned long currMicros = micros();

  
  if(currMicros - prevMicros >= 100){
    prevMicros = currMicros;
    count++;
    if(count == 100){
      digitalWrite(12,HIGH);
      count = 0;
    }
    if(count == duty){
      digitalWrite(12,LOW);
    }
  }

  if(currMillis - prevMillis >= 25){
    prevMillis = currMillis;
    duty++;
    if(duty == 90){
      duty = 10;
    }
  }
}
