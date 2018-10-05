int ledpin[]={10,11,12,13};
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<4;i++)
    pinMode(ledpin[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(byte counter=15;counter>=0;counter--)
  {
    displayBinary(counter);
    delay(1000);
  }
 
}

void displayBinary(byte numtoshow)
{
  for(int i=0;i<4;i++)
  {
    if(bitRead(numtoshow,i)==1)
    {
      digitalWrite(ledpin[i],HIGH);
    }
    else
    {
      digitalWrite(ledpin[i],LOW);
    }
  }
}

