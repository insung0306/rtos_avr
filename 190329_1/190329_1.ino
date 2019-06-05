//int a=0;
int duty = 0;
int count = 0;
unsigned long previousMillis = 0;
unsigned long previousMicros = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //for(int i=0; i<100; i++){
      //a = i*100;
      //digitalWrite(13,HIGH);
      //delayMicroseconds(a);
      //digitalWrite(13,LOW);
      //delayMicroseconds(10000-a);
    //}
  unsigned long currentMicros = micros();
  unsigned long currentMillis = millis();

  if(currentMicros - previousMicros > 100){
    previousMicros = currentMicros;
    count++;
    
    if(count >= 100){
      count = 0;
      digitalWrite(13,1);
      //digitalWrite(12,1);
    }
    if(count == duty){
      digitalWrite(13,0);
    }
  } 
  if(currentMillis - previousMillis > 10){
    previousMillis = currentMillis;
    duty++;
    if(duty == 100){
      duty = 0;
    }
  }
}
