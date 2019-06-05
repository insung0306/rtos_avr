

//-------dot-matrix-----------
//rowpin(register)->2.15,2.1,2.2,2.3,2.4,2.5,2.6,2.7
//colpin(register)->1.15,1.1,1.2,1.3,1.4,1.5,1.6,1.7

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

char b[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
void setup() {
  pinMode(10,OUTPUT); // clock
  pinMode(11,OUTPUT); // data
  pinMode(12,OUTPUT); // latch
}

int data[] = {0,0,0,0,0,1,0,0};
void loop() {
  
  for(int j=0; j<8; j++){
    //----row-off-------
    for(int i=0; i<8; i++){
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(10,LOW);
    }
    for(int i=0; i<8; i++){
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(10,LOW);
    }
    digitalWrite(12,HIGH);
    digitalWrite(12,LOW);
    //----row------
    for(int i=0; i<8; i++){
      if(b[j] & (0x01<< i)){
        digitalWrite(11,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(10,LOW); 
      }
      else{
        digitalWrite(11,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(10,LOW);
      }
    }
    //-----col-------
    for(int i=0; i<8; i++){
      if(a[0][j] & (0x01<< i)){
        digitalWrite(11,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(10,LOW); 
      }
      else{
        digitalWrite(11,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(10,LOW);
      }
    }
    digitalWrite(12,HIGH);
    digitalWrite(12,LOW);
   }

}
