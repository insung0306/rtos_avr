void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

unsigned long prevMillis;
unsigned long prevMillis_duty;
unsigned long prevMicros;
int duty = 770;
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
     
     //if(count == duty){
       digitalWrite(13,LOW);
       flag = false;
     //} 
   }
  }

  if(currMillis - prevMillis >= 20){
    prevMillis = currMillis;
    flag = true;
    count = 0;
    duty = duty + 9;
    if(duty >= 2300){
      duty = 770;
    }
    digitalWrite(13,HIGH);
    currMicros = prevMicros = micros();
  }

}
