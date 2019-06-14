void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD = 0x00;
  EICRA = 0x01;
  EIMSK = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}
unsigned long after = 0;
unsigned long before = 0;

SIGNAL(INT0_vect){
  char input = PIND;
  if(input & 0x04){
    after = millis();
    Serial.println(after - before);
  }
  else{
    before = millis();
  }
}
