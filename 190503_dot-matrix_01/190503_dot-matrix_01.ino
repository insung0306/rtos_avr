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

void loop() {
  for(int i=0; i<8; i++){
    digitalWrite(i+2,HIGH);
  }
  for(int j=10; j<18; j++)
    digitalWrite(j,LOW);
}
