int count = 0;
unsigned long remocon_micro;
unsigned long remocon_time_arr[50];
unsigned int offset_value[50];
int remocon_callback;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(remocon_callback == 1){
    remocon_callback = 0;
    remocon_callback_print();
  }

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
    Serial.println("R");
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
            Serial.print(k);
      }
      count_num_check = 0;
    }
}
