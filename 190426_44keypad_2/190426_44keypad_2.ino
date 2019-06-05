#define BTN_NUM 4

int flag[BTN_NUM][BTN_NUM] = {0,};
int a=0;
int b=0;
int c=0;
int d=0;
int btn_num[BTN_NUM] = {1,2,3,4};

void setup() {
  Serial.begin(9600);
  
  //Row 1
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  //Colum
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {

  for(int i =0; i<BTN_NUM; i++){
    //Col 1 high
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(6+i,1);
       
    //Check Row State
    a = digitalRead(2);
    if(a == 1){
      if(flag[i] == 1){ //
        Serial.println("HIGH" + String(btn_num[i])); //  
        flag[i] = 0; //
      }
    }
    else{
      if(flag[i] == 0){//
        Serial.println("Low" + String(btn_num[i]));//
        flag[i] = 1; //
      }
    }
   
    //Check Row State
    b = digitalRead(3);
    if(b == 1){
      if(flag[i] == 1){ //
        Serial.println("HIGH" + String(btn_num[i])); //  
        flag[i] = 0; //
      }
    }
    else{
      if(flag[i] == 0){//
        Serial.println("Low" + String(btn_num[i]));//
        flag[i] = 1; //
      }
    }
  
    //Check Row State
    c = digitalRead(4);
    if(c == 1){
      if(flag[i] == 1){ //
        Serial.println("HIGH" + String(btn_num[i])); //  
        flag[i] = 0; //
      }
    }
    else{
      if(flag[i] == 0){//
        Serial.println("Low" + String(btn_num[i]));//
        flag[i] = 1; //
      }
    }
   
    //Check Row State
    d = digitalRead(5);
    if(d == 1){
      if(flag[i] == 1){ //
        Serial.println("HIGH" + String(btn_num[i])); //  
        flag[i] = 0; //
      }
    }
    else{
      if(flag[i] == 0){//
        Serial.println("Low" + String(btn_num[i]));//
        flag[i] = 1; //
      }
    }
    delay(10);
    }
}
