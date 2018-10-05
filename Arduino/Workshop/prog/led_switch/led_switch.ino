int ledpin=13;
int inpin=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(inpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(HIGH==digitalRead(inpin))
  {
    digitalWrite(ledpin,HIGH);
    delay(1000);
    digitalWrite(ledpin,LOW);
    delay(1000);
  }
}
