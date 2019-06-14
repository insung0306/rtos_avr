void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;

  TCCR2A = 0x00;
  TCCR2B = 0x04;
  TCNT2 = 6;
  TIMSK2 = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}

int toggle = 0;

SIGNAL(TIMER2_OVF_vect){
  static int count = 0;

  TCNT2 = 6;
  count++;
  if(count > 1000){
    if(toggle == 0){
      PORTB = 0x20;
      toggle = 1;
    }
    else{
      PORTB = 0x00;
      toggle = 0;
    }
    count = 0;
  }
}
