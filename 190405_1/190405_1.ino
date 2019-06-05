unsigned long outTime = 0; 
unsigned long inTime = 0; 

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,myISR,CHANGE);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  
  delay(1000);
}

void myISR(){
  //down = millis();
  if(digitalRead(2) == 1){
    outTime = micros();
    
  }else{
    inTime = micros();
    int a = inTime - outTime;
    long b = a/29/2; //(a/1000)*(170/1);
//    Serial.println(a);
    Serial.print(b);
    Serial.println("cm");
  }
  
}
