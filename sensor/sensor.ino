int ir_sesnor1 = 4;
int ir_sesnor2 = 5;
int ir_sesnor3 = 13;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir_sesnor1,INPUT);
pinMode(ir_sesnor2,INPUT);
pinMode(ir_sesnor3,INPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);

} //yes


void loop() {
  // put your main code here, to run repeatedly:

int a = digitalRead(ir_sesnor1);
int b = digitalRead(ir_sesnor2);
int c = digitalRead(ir_sesnor3);

Serial.print(a);Serial.print(" ");
Serial.print(b);Serial.print(" ");
Serial.println(c);Serial.print(" ");


if(c==HIGH)
{
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  }

if(b==HIGH)
{
  digitalWrite(8,HIGH);
  //digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  //digitalWrite(9,LOW);
  }
if(a==HIGH)
{
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  }
if((a==HIGH && c==HIGH)||(a==HIGH && c==HIGH && b==HIGH))
{
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  }





}
