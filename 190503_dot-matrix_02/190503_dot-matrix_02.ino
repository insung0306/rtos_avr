char a[10][8] = {
  {0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38},
  {0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c},
  {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
  {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38},
  {0x00,0x08,0x18,0x28,0x48,0x7C,0x08,0x08},              
  {0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38},              
  {0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38},              
  {0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20},
  {0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38},
  {0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38}
                };

//{0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c};
//{0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c};

void setup() {
  //--------dot-matrix-ROW---------------
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  //-------dot-matrix-COL-----------------
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
}

int row_for; int col_for;
int k = 5;
void loop() {

  for(int j=0; j<8; j++){
    digitalWrite(j+2,HIGH);

         
    for(int i=0; i<8; i++){
      if(a[k][j] & (0x80 >> i))
        digitalWrite(i+10,LOW);
      else
        digitalWrite(i+10,HIGH);
    }
    for(int i=0; i<8; i++){
      digitalWrite(i+10,HIGH);
    }
    
    digitalWrite(j+2,LOW);
    delay(2.5);
  }
}
