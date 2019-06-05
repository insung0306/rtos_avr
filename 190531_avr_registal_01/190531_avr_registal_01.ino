void setup() {
  // put your setup code here, to run once:
  //pinMode(13,OUTPUT); //13번 : PB5
  DDRB = 0x20;
  DDRD = 0x00;
}

void loop() {
  if(PIND & 0x04)
    //digitalWrite(13,1); 
    PORTB = 0x20;
  else
    //digitalWrite(13,0);
    PORTB = 0x00;
}
