void setup() {
  // put your setup code here, to run once:
  
  pinMode(4,OUTPUT);//1
  pinMode(5,OUTPUT);//2
  pinMode(6,OUTPUT);//3
  pinMode(7,OUTPUT);//4
  pinMode(8,OUTPUT);//5
  pinMode(9,OUTPUT);//7
  pinMode(10,OUTPUT);//10
  pinMode(11,OUTPUT);//11

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
  digitalWrite(14,0);
  digitalWrite(4,1);
  digitalWrite(10,1);
  digitalWrite(11,1);
  digitalWrite(9,1);
  digitalWrite(7,1);
  digitalWrite(5,1);
  
}
