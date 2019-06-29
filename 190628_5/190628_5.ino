void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  
  TCCR1A = 0x03;
  TCCR1B = 0x0D;
  OCR1A = 723;
  TCNT1 = 712;
  TIMSK1 = 0x03;
}

unsigned long prevMillis;
unsigned long prevMicros;
int duty = 723;
int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMillis = millis();
  if(currMillis - prevMillis >= 20){
    prevMillis = currMillis;
    OCR1A++;
    
    if(OCR1A >= 748){
      OCR1A = 723;
    }
  }
}

SIGNAL(TIMER1_OVF_vect){
  TCNT1 = 712;
  digitalWrite(13,HIGH);
}


SIGNAL(TIMER1_COMPA_vect){
  digitalWrite(13,LOW);
}
