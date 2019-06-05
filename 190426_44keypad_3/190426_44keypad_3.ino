#define BTN_NUM 4

int flag[4][4] = {};
int row=0;
int btn_num[4][4] = {{11,12,13,14},{21,22,23,24},{31,32,33,34},{41,42,43,44}};
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

  for(int i =0; i<4; i++){
    for(int j =0; j<4; j++){
      //Col 1 high
      digitalWrite(6,0);
      digitalWrite(7,0);
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(6+i,1);
       
       //Check Row State
      row = digitalRead(j+2);
      if(row == 1){
        if(flag[i][j] == 1){ 
          Serial.println("HIGH" + String(btn_num[j][i]));  
          flag[i][j] = 0; 
        }
      }
      else{
        if(flag[i][j] == 0){
          Serial.println("Low" + String(btn_num[j][i]));
          flag[i][j] = 1; 
        }
      }
      delay(10);    
    }
  }
}
