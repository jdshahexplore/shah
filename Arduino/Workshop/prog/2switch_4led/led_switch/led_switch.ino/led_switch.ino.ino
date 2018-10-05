int ledpin=10;
int ledpin2=11;
int ledpin3=12;
int ledpin4=13;
int inpin=2;
int inpin2=3;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
    pinMode(ledpin2,OUTPUT);
      pinMode(ledpin3,OUTPUT);
        pinMode(ledpin4,OUTPUT);
  pinMode(inpin,INPUT);
  pinMode(inpin2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(LOW==digitalRead(inpin))
  {
    if(LOW==digitalRead(inpin2))
    {
      digitalWrite(ledpin,HIGH);
      delay(1000);
      digitalWrite(ledpin,LOW);
      delay(1000);
    }
    else
    {
      digitalWrite(ledpin2,HIGH);
      delay(1000);
      digitalWrite(ledpin2,LOW);
      delay(1000);
    }
  }
  else
  {
    if(LOW==digitalRead(inpin2))
    {
      digitalWrite(ledpin3,HIGH);
      delay(1000);
      digitalWrite(ledpin3,LOW);
      delay(1000);
    }
    else
    {
      digitalWrite(ledpin4,HIGH);
      delay(1000);
      digitalWrite(ledpin4,LOW);
      delay(1000);
    }
  }
}
