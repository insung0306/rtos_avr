//unsigned long outTime = 0; 
//unsigned long inTime = 0; 
//unsigned long lang = 0;
//unsigned long previousMicross = 0;
//unsigned long previousMicros = 0;

unsigned int a=0, b=0, c=0, d=0;

int count=0; int count1 = 0;
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
//  attachInterrupt(0,myISR,CHANGE);
//  Serial.begin(9600);
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
//  unsigned long currentMicross = micros();
//  unsigned long currentMicros = micros();



  
//  if(currentMicros - previousMicros > 10){
//    previousMicros = currentMicros;
//    count1++;
//    if(count1 >=0 && count1 <= 10){
//      digitalWrite(3,HIGH); 
//    }
//    else if(count1 >= 11){
//      digitalWrite(3,LOW);
//    }
//    if(count1 == 1000000)
//      count1 = 0;
//  }

//  if(count == 1){

    first = 10;
    pinNum = 14;
//  }
//  else if(count == 2){
//    first = 2;
//    pinNum = 15;
//  }
//  else if(count == 3){
//    first = 3;
//    pinNum = 16;
//  }
//  else if(count == 4){
//    first = a;
//    pinNum = 17;
//  }
  digitalWrite(pinNum,0);
  digitalWrite(A,arr[first][0]);
  digitalWrite(B,arr[first][1]);
  digitalWrite(C,arr[first][2]);
  digitalWrite(D,arr[first][3]);
  digitalWrite(E,arr[first][4]);
  digitalWrite(F,arr[first][5]);
  digitalWrite(G,arr[first][6]);
  digitalWrite(pinNum,1);
//  if(currentMicross - previousMicross > 2){
//    previousMicross = currentMicross;
    
//    if(count == 0){
//      digitalWrite(14,0);
//      digitalWrite(A,arr[a][0]);
//      digitalWrite(B,arr[a][1]);
//      digitalWrite(C,arr[a][2]);
//      digitalWrite(D,arr[a][3]);
//      digitalWrite(E,arr[a][4]);
//      digitalWrite(F,arr[a][5]);
//      digitalWrite(G,arr[a][6]);
//      digitalWrite(14,1);
//    }
//
//    else if(count == 1){
//      digitalWrite(15,0);
//      digitalWrite(11,arr[b][0]);
//      digitalWrite(9,arr[b][1]);
//      digitalWrite(7,arr[b][2]);
//      digitalWrite(5,arr[b][3]);
//      digitalWrite(4,arr[b][4]);
//      digitalWrite(10,arr[b][5]);
//      digitalWrite(8,arr[b][6]);
//      digitalWrite(15,1);
//    }
//
//    else if(count == 2){
//      digitalWrite(16,0);
//      digitalWrite(A,arr[c][0]);
//      digitalWrite(B,arr[c][1]);
//      digitalWrite(C,arr[c][2]);
//      digitalWrite(D,arr[c][3]);
//      digitalWrite(E,arr[c][4]);
//      digitalWrite(F,arr[c][5]);
//      digitalWrite(G,arr[c][6]);
//      digitalWrite(16,1);
//    }
//
//    else if(count == 3){
//      digitalWrite(17,0);
//      digitalWrite(A,arr[d][0]);
//      digitalWrite(B,arr[d][1]);
//      digitalWrite(C,arr[d][2]);
//      digitalWrite(D,arr[d][3]);
//      digitalWrite(E,arr[d][4]);
//      digitalWrite(F,arr[d][5]);
//      digitalWrite(G,arr[d][6]);
//      digitalWrite(17,1);
//    }
//    
//    if(count == 5)
//      count = 0;
//    count++;
//  }
}

//void myISR(){
//  //down = millis();
//  if(digitalRead(2) == 1){
//    outTime = micros();
//    
//  }else{
//    inTime = micros();
//    int microTime = inTime - outTime;
//    lang = microTime/29/2;
////    Serial.print(lang);
////    Serial.println("cm");
//  }
//  a = lang/1000;
//  b = (lang%1000)/100;
//  c = (lang%100)/10;
//  d = lang%10;
//}
