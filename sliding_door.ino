#define switch1 2
#define switch2 3
#define output1 4
#define output2 5
#define closed 0
#define opened 1
#define sensor 6

boolean door_status=closed;
boolean temp1,temp2;
char data_in;

void setup() {
  Serial.begin(9600);
  Serial.println("welcome");
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2,INPUT_PULLUP);
  pinMode(output1,OUTPUT);
  pinMode(output2,OUTPUT);
  pinMode(sensor,INPUT);
}


void close_door()
{
  if (digitalRead(switch2)!=0)
  {
    digitalWrite(output1,0);
    digitalWrite(output2,1);
   if(digitalRead(switch2)==0)
   {
    digitalWrite(output2,0);
   }
  }
}
void open_door()
{
  if (digitalRead(switch1)!=0)
  {
    digitalWrite(output1,0);
    digitalWrite(output2,1);
   if(digitalRead(switch1==0))
   {
    digitalWrite(output2,0);
  }
  }
}

void halt()
{
  temp1=digitalRead(output1);
  temp2=digitalRead(output2);
  digitalWrite(output1,0);
  digitalWrite(output2,0);
  
}

void resum()
{
  digitalWrite(output1,temp1);
  digitalWrite(output2,temp2);
  if((digitalRead(switch1)==0)|(digitalRead(switch2)==0))
  {
     digitalWrite(output1,0);
     digitalWrite(output2,0);
    
  }
}
void loop() {
   if(Serial.available())
   {
      data_in = Serial.read();
      Serial.println(data_in);
}
if(data_in=='c')
{
  close_door();
}
else if(data_in=='o')
{
  open_door();
}
else if(data_in=='h')
{
  halt();
}
else if(data_in=='r')
{
resum();
  
}
else
{
 Serial.println("INVALID CHARACTER");
}
if(digitalRead(sensor)==1)
{
  halt();
  while(digitalRead(sensor)==1);
  if(digitalRead(sensor)==0)
  {
    resum;
  }
  
}
}
