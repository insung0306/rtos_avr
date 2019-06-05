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

//---set buzzer----------------------
unsigned long prevMicros = 0;

int num_tone = 0; // parameta_tones[]
int tones[]={C4,D4,E4,F4,G4,A4,B4,C5}; // tone arr
int flag_buz = 0;//it allow that buzzer action
int toggle = 0;
//------------------------------------

unsigned long preMillis = 0;
int btn_num[4][4] = {{0,1,2,3},{4,5,6,7},};//[row][colum]

void setup() {
  //Serial.begin(9600);
  //buzzer
  pinMode(10,OUTPUT);
  
  //ROW pin
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);

  //COL pin
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

int row = 0;
int flag[4][4] = {{0,},};
int i, j;

void loop() {
  unsigned long currMillis = millis();
  unsigned long currMicros = micros();

  if(currMillis - preMillis >= 10){
    preMillis = currMillis;

    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(6+j,LOW);

    row = digitalRead(2+i);
    if(row == 0){
      if(flag[i][j] == 1){
        num_tone = btn_num[i][j];
//        Serial.print(i);
//        Serial.print(j);
//        Serial.println(" Down");
          flag_buz = 1;
      }
      flag[i][j] = 0;
    }
    else{
      if(flag[i][j] == 0){
//        Serial.print(i);
//        Serial.print(j);
//        Serial.println(" UP");
          flag_buz = 0;
      }
      flag[i][j] = 1; 
    }

    j++;
    if(j>=4){
      j = 0;
      i++;
      if(i>=4){
        i = 0;
      }
    }
  }
  
  if(flag_buz){
    if(currMicros-prevMicros > tones[num_tone]){
      prevMicros = currMicros;

      if(!toggle)
        digitalWrite(10,1);
      else
        digitalWrite(10,0);

      toggle = !toggle;
    }
  }
}
