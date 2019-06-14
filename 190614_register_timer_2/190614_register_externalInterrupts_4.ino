unsigned long Millis = 0;
int duty = 0;
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20;

  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 56;
  TIMSK2 = 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long prevMillis = millis();
  if(prevMillis - Millis >= 10){
    Millis = prevMillis;
    duty++;
    if(duty >= 100){
      duty = 0;
    }
  }
}

int toggle = 0;

SIGNAL(TIMER2_OVF_vect){
  static int count = 0;
  
  TCNT2 = 56;
  count++;
  if(count == 100){
    count = 0;
    PORTB = 0x20;
  }
  if(count == duty){
    PORTB = 0x00;
  }
}
