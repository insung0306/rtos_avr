void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
}

unsigned long prevMillis;
unsigned long prevMillis_duty;
unsigned long prevMicros;
int duty = 0;
int count = 0;
bool flag = false;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMillis = millis();
  unsigned long currMillis_duty = millis();
  unsigned long currMicros = micros();

  if(flag == true){
    if(currMicros - prevMicros >= duty){
      prevMicros = currMicros;
      count++;
      digitalWrite(12,LOW);
      flag = false;
    }
  }

  if(currMillis - prevMillis >= 10){
    prevMillis = currMillis;
    flag = true;
    digitalWrite(12,HIGH);
    prevMicros = currMicros = micros();
  }
  
  if(currMillis_duty - prevMillis_duty >= 100){
    prevMillis_duty = currMillis_duty;
    duty = duty + 1000;
    if(duty == 90000){
      duty = 1000;
    }
  }
}
