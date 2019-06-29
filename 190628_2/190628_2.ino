void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

unsigned long prevMillis;
unsigned long prevMicros;
int duty = 22;
int count = 0;
bool flag = false;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMillis = millis();
  unsigned long currMicros = micros();


   if(currMicros - prevMicros >= 32){
     prevMicros = currMicros;
     count++;
     if(count == 625){
      count = 0;
      digitalWrite(13,HIGH);
     }
     if(count == duty){
       digitalWrite(13,LOW);
     } 
   }

  if(currMillis - prevMillis >= 20){
    prevMillis = currMillis;
    duty++;
    if(duty == 72){
      duty = 22;
    }
  }
}
