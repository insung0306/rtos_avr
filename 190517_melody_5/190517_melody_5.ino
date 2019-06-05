//----define tone code----------
#define C3 3822
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956
//------------------------------

//-----set keypad 4by4-------------------------
unsigned long prevMillis_3 = 0;
int i = 0;
int row = 0;
int btn_num[2][4] = {{0,1,2,3},{4,5,6,7}};//[row][colum]
int flag_key[4][4] = {{0,},};
int flag2 = 0;
int flag3 = 0; //controll sound
//---------------------------------------------

//---set buzzer----------------------

unsigned long prevMicros = 0;
unsigned long prevMillis_1 = 0;
unsigned long prevMillis_2 = 0;

int num_tone = 0; // parameta_tones[]
int tones[]={C4,D4,E4,F4,G4,A4,B4}; // tone arr
int flag = 0;//it allow that buzzer action
int toggle = 0;
//------------------------------------


void setup() {
  //buzzer
  pinMode(10,OUTPUT);
  //row
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  //colum
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMicros = micros();
  unsigned long currMillis = millis();
  unsigned long currMillis_2 = millis();

  if(currMillis_2 - prevMillis_3 > 10){ 
    prevMillis_3 = currMillis_2; 

    for(int j=0; j<4; j++){
      //Col HIGH
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(6+i,HIGH);
    
      //Check Row State
      row = digitalRead(j+4);
      if(row == 1){
         if(flag_key[i][j] == 1){
          num_tone = btn_num[j][i];
          flag_key[i][j] = 0;
          flag = 1;
         }
      }
      else{
       if(flag_key[i][j] == 0){
        num_tone = btn_num[j][i];
        flag_key[i][j] = 1; 
        flag = 0;
       }
      }
    }
    
    i++;
    if(i == 4){
      i = 0;
    }    
  }

  if(flag){
    if(currMicros-prevMicros > tones[num_tone]){
      prevMicros = currMicros;

      if(!toggle)
        digitalWrite(10,1);
      else
        digitalWrite(10,0);

      toggle = !toggle;
    }
  }

    if(currMillis-prevMillis_1 > 325){
      prevMillis_1 = currMillis;
      prevMillis_2 = currMillis;

    }
}
