#define C3 3822
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956


unsigned long prevMicros = 0;
unsigned long prevMillis = 0;

int count = 0;
int melody[1][7] = {
  {1911,1703,1517,1432,1276,1136,1012}
};
int schoolMelody[24] = {
  G4,G4,A4,A4,G4,G4,E4,
  G4,G4,E4,E4,D4,
  G4,G4,A4,A4,G4,G4,E4,
  G4,E4,D4,E4,C4
};
int toggle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currMicros = micros();
  unsigned long currMillis = millis();

  if(currMicros-prevMicros > schoolMelody[count]){
    prevMicros = currMicros;

    if(!toggle)
      digitalWrite(10,1);
    else
      digitalWrite(10,0);

    toggle = !toggle;
  }

  if(currMillis-prevMillis > 1000){
    prevMillis = currMillis;

    count++;
    if(count >= 24){
      count = 0;
    }
  }
}
