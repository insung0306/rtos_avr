int duty = 0;
int count=0, count1=0;
int a=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
}

void loop() {
  while(1) {
    count++;

    if(count==625){
      count=0;
      digitalWrite(11,1);
    }
    else if(count==100){
      digitalWrite(11,0);
    }

    delayMicroseconds(32);
  }




  //for(int i=0;i<5;i++){
    //digitalWrite(11,1);
    //delayMicroseconds(700+a);
    //digitalWrite(11,0);
    //delay(17);
    //delayMicroseconds(2300-a);  
  //}
  //a+=32;
  //if(a>1600)
    //a=0;
}
