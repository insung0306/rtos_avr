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
  pinMode(10,OUTPUT); // clock
  pinMode(11,OUTPUT); // data
  pinMode(12,OUTPUT); // latch
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);

}

int data[] = {0,0,0,0,0,1,0,0};
void loop() {

  for(int i=0; i<8; i++){
    digitalWrite(11,data[i]);
    digitalWrite(10,HIGH);
    digitalWrite(10,LOW);
  }
  digitalWrite(12,HIGH);
  digitalWrite(12,LOW);
  delay(1000);
  for(int i=0; i<8; i++){
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(10,LOW);
  }
  digitalWrite(12,HIGH);
  digitalWrite(12,LOW);
  delay(1000);
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);

//
//  
//
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,HIGH);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
  
//  digitalWrite(12,HIGH);
//  digitalWrite(12,LOW);
//
//  delay(1000);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//  
//  digitalWrite(11,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(10,LOW);
//
//  digitalWrite(12,HIGH);
//  digitalWrite(12,LOW);
//  
//  delay(1000);
}
