int count = 0;
unsigned long remocon_micro;
unsigned long remocon_time_arr[50];
unsigned int offset_value[50];
int remocon_callback;

unsigned int a=0, b=0, c=0, d=0;
int A=11, B=9, C=7, D=5, E=4, F=10, G=8, DP=6;
int first=0; int pinNum=0;
int fnd_count = 0;

int fnd_arr[10][7]{
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

int remocon_input_num[9];
int remocon_num[10][8] = {
  {0,1,1,0,1,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,1,1,1,0,1,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,1,1,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,1,0,1,0},
  {0,1,0,1,0,0,1,0}
};
int count_num = 0;
int count_num_check = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0,remocon_ISR,FALLING);

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
  // put your main code here, to run repeatedly:
  
  if(remocon_callback == 1){
    remocon_callback = 0;
    remocon_callback_print();
  }

  fnd_on();
}

void remocon_ISR(){
  remocon_micro = micros();
  remocon_time_arr[count] = remocon_micro;

  //시간의 차를 넣어주는 부분
  if(count > 0)
    offset_value[count] = remocon_time_arr[count] - remocon_time_arr[count-1];

  //리드코드 읽는 부분
  if(offset_value[count] > 13000&&offset_value[count] < 14000){
    count = 1;
  }

  //리피트코드 읽는 부분
  if(offset_value[count] > 11000&&offset_value[count] < 12000){
    count = -1;
//    Serial.println("R");
  }
  count++;

  
  if(count > 33){
    count = 0;
    remocon_callback =1; 
  }
}

void remocon_callback_print(){
  count_num=0;
  count_num_check = 0;
  for(int i = 18;i<25;i++){
      if(i > 17 && i < 26 && offset_value[i] > 1000 && offset_value[i] < 2000){
        remocon_input_num[count_num] = 0;
        count_num++;
      }
      else if(i > 17 && i < 26 && offset_value[i] > 2000 && offset_value[i] < 3000){
        remocon_input_num[count_num] = 1;
        count_num++;
      }
      else if(count_num == 7){
        count_num = 0;
      }
    }
    for(int k=0; k<10;k++){
      for(int j=0; j<8;j++){
        if(remocon_num[k][j] == remocon_input_num[j]){
          count_num_check++;
        }
      }
      if(count_num_check == 8){
        a = k/1000;
        b = (k%1000)/100;
        c = (k%100)/10;
        d = k%10;
      }
      count_num_check = 0;
    }
}

void fnd_on(){
  fnd_count++;

  if(fnd_count == 1){
    first = d;
    pinNum = 14;
  }
  else if(fnd_count == 2){
    first = c;
    pinNum = 15;
  }
  else if(fnd_count == 3){
    first = b;
    pinNum = 16;
  }
  else if(fnd_count == 4){
    first = a;
    pinNum = 17;
    fnd_count = 0;
  }
  
  digitalWrite(pinNum,0);
  digitalWrite(A,fnd_arr[first][0]);
  digitalWrite(B,fnd_arr[first][1]);
  digitalWrite(C,fnd_arr[first][2]);
  digitalWrite(D,fnd_arr[first][3]);
  digitalWrite(E,fnd_arr[first][4]);
  digitalWrite(F,fnd_arr[first][5]);
  digitalWrite(G,fnd_arr[first][6]);
  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,0);
  digitalWrite(D,0);
  digitalWrite(E,0);
  digitalWrite(F,0);
  digitalWrite(G,0);
  digitalWrite(pinNum,1);
}
