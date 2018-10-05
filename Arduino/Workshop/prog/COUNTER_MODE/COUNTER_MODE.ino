int ledpin[]={10,11,12,13};
int switch_1 = 2;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<4;i++)
    pinMode(ledpin[i],OUTPUT);

   pinMode(switch_1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(HIGH==digitalRead(switch_1))
  down_counter();
else
  up_counter();
  
 
}

void down_counter()
{
   for(byte counter=15;counter>=0;counter--)
  {
    if(LOW==digitalRead(switch_1))
      up_counter();
    displayBinary(counter);
    delay(200);
  }
}

void up_counter()
{
  
  for(byte counter=0;counter<=15;counter++)
  {
    
    if(HIGH==digitalRead(switch_1))
      down_counter();
    displayBinary(counter);
    delay(200);
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

