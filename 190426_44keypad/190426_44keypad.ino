int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int a=0;

void setup() {
  Serial.begin(9600);
  
  //Row 1
  pinMode(2,INPUT);
  //Colum
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  //Col 1 high
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  
  //Check Row State
  a = digitalRead(2);
  if(a == 1){
    if(flag1 == 1){
      Serial.println("high 1");  
      flag1 = 0;
    }
  }
  else{
    if(flag1 == 0){
      Serial.println("low 1");
      flag1 = 1;
    }
  }
  delay(10);

  //Col 2 high
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
  digitalWrite(9,0);
  
  //Check Row State
  a = digitalRead(2);
  if(a == 1){
    if(flag2 == 1){
      Serial.println("high 2");  
      flag2 = 0;
    }
  }
  else{
    if(flag2 == 0){
      Serial.println("low 2");
      flag2 = 1;
    }
  }
  delay(10);

  //Col 3 high
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
  
  //Check Row State
  a = digitalRead(2);
  if(a == 1){
    if(flag3 == 1){
      Serial.println("high 3");  
      flag3 = 0;
    }
  }
  else{
    if(flag3 == 0){
      Serial.println("low 3");
      flag3 = 1;
    }
  }
  delay(10);

  //Col 4 high
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,1);
  
  //Check Row State
  a = digitalRead(2);
  if(a == 1){
    if(flag4 == 1){
      Serial.println("high 4");  
      flag4 = 0;
    }
  }
  else{
    if(flag4 == 0){
      Serial.println("low 4");
      flag4 = 1;
    }
  }
  delay(10);
}
