unsigned long outTime = 0; 
unsigned long inTime = 0; 
unsigned long lang = 0;
unsigned long previousMicros2 = 0;
unsigned long previousMicros = 0;

unsigned int a=0, b=0, c=0, d=0;

int microTime=0;
int count=0; int count1 = 0; int count2 = 0; // same same
int A=11, B=9, C=7, D=5, E=4, F=10, G=8, DP=6;
int first=0; int pinNum=0;

int arr[10][7]{
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1}
  };
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0,myISR,CHANGE);
  pinMode(3,OUTPUT);
  
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);   
  pinMode(D,OUTPUT);   
  pinMode(E,OUTPUT);   
  pinMode(F,OUTPUT);   
  pinMode(G,OUTPUT);    
  pinMode(DP,OUTPUT);    

  pinMode(14,OUTPUT);//12
  pinMode(15,OUTPUT);//9
  pinMode(16,OUTPUT);//8
  pinMode(17,OUTPUT);//6
  digitalWrite(14,1);
  digitalWrite(15,1);
  digitalWrite(16,1);
  digitalWrite(17,1);

  
}

void loop() {
  unsigned long currentMicros = micros();
  //unsigned long currentMicros2 = micros();
  count++;
  
  if(currentMicros - previousMicros > 10){
    previousMicros = currentMicros;
    count1++;
    count2++;
    if(count1 >=0 && count1 <= 10){
      digitalWrite(3,HIGH); 
    }
    else if(count1 >= 11){
      digitalWrite(3,LOW);
    }
    if(count1 == 100000)
      count1 = 0;
//    if(count2 == 51){
//      count2 = 0;
//    }
  }
    
//  if(count2 == 50){
   
//  }

  
  if(count == 1){
    first = d;
    pinNum = 14;
  }
  else if(count == 2){
    first = c;
    pinNum = 15;
  }
  else if(count == 3){
    first = b;
    pinNum = 16;
  }
  else if(count == 4){
    first = a;
    pinNum = 17;
    count = 0;
  }
//  if(count == )
//    count = 0;

  digitalWrite(pinNum,0);
  digitalWrite(A,arr[first][0]);
  digitalWrite(B,arr[first][1]);
  digitalWrite(C,arr[first][2]);
  digitalWrite(D,arr[first][3]);
  digitalWrite(E,arr[first][4]);
  digitalWrite(F,arr[first][5]);
  digitalWrite(G,arr[first][6]);
//  digitalWrite(pinNum,1);
//  digitalWrite(pinNum,0);
  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,0);
  digitalWrite(D,0);
  digitalWrite(E,0);
  digitalWrite(F,0);
  digitalWrite(G,0);
  digitalWrite(pinNum,1);
//  if(count2 == 2)
//    fnd();
//  if(count2 >= 3)
//    count2 = 0;
}

void myISR(){
  //down = millis();
  if(digitalRead(2) == 1){
    outTime = micros();
    
  }else{
    inTime = micros();
    microTime = inTime - outTime;
    lang = microTime/29/2;
    a = lang/1000;
    b = (lang%1000)/100;
    c = (lang%100)/10;
    d = lang%10;
    //Serial.println(lang);
  }
  
}
