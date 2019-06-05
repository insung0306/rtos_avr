//-----------4 by 4 var-----------

#define BTN_NUM 4

unsigned long pre_millis=0;

int flag[4][4] = {};
int row=0;
int btn_num[4][4] = {{11,12,13,14},{21,22,23,24},{31,32,33,34},{41,42,43,44}};
int i = 0;

//--------------fnd var-----------

// 1 -> g, 2 -> dp, 3 -> a, 4 -> f , 6 -> d, 7 -> e, 8 -> c, 9 -> b
//int A=14, B=19, C=18, D=16, E=17, F=15, G=12, DP=13;
int fnd_pin[8] = {14, 19, 18, 16, 17, 15, 12, 13};

int arr[10][7]{
    {0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0}
  };

int first = 0;
int fnd_btn_num = 0;
bool fnd_toggle = false;
int fnd_num_ten =0;
int fnd_num_own =0;

void setup() {
  
//---- fnd setup -----------

  pinMode(10,OUTPUT);//5
  pinMode(11,OUTPUT);//10

  pinMode(fnd_pin[0],OUTPUT);
  pinMode(fnd_pin[1],OUTPUT);
  pinMode(fnd_pin[2],OUTPUT);
  pinMode(fnd_pin[3],OUTPUT);
  pinMode(fnd_pin[4],OUTPUT);
  pinMode(fnd_pin[5],OUTPUT);
  pinMode(fnd_pin[6],OUTPUT);
  pinMode(fnd_pin[7],OUTPUT);

//---4 by 4 keypad setup-------

  //Row 
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
  unsigned long curr_millis = millis();
  
  if(curr_millis - pre_millis > 10){ 
    pre_millis = curr_millis; 

//--------4 by 4 keypad-------------
    for(int j=0; j<4; j++){
      //Col high
      digitalWrite(6,0);
      digitalWrite(7,0);
      digitalWrite(8,0);
      digitalWrite(9,0);
      digitalWrite(6+i,1);
    
      //Check Row State
      row = digitalRead(j+2);
      if(row == 1){
         if(flag[i][j] == 1){ 
         fnd_btn_num = btn_num[j][i];  
         flag[i][j] = 0; 
        }
      }
      else{
       if(flag[i][j] == 0){
        fnd_btn_num = btn_num[j][i];
        flag[i][j] = 1; 
       }
      }
    }
    
    i++;
    if(i == 4){
      i = 0;
    }    
  }

//-----------fnd Write------------------------//
    fnd_num_ten = fnd_btn_num/10;
    fnd_num_own = fnd_btn_num%10;
  
    digitalWrite(10,1);
    digitalWrite(11,1);

      if(fnd_toggle){
        digitalWrite(10,1);
        digitalWrite(11,0);
        first = fnd_num_own;
        for(int k=0; k<8; k++)
          digitalWrite(fnd_pin[k],arr[first][k]);
        fnd_toggle = false;
      }else{
        digitalWrite(10,0);
        digitalWrite(11,1);
        first = fnd_num_ten;
        for(int k=0; k<8; k++)
          digitalWrite(fnd_pin[k],arr[first][k]);
        fnd_toggle = true;
      }

    for(int k=0; k<8; k++){
     digitalWrite(fnd_pin[k],1);
    }
}
