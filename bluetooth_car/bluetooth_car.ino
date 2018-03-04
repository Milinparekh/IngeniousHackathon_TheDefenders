// Android Phone Controlled Robot
// Successfully Tested on Android App --> 'Arduino Bluetooth 
// Terminal'; it is available free on the Google Play Store

//coded by Milin parekh 
//follow my instagram page ****  www.instagram.com/build_more/  ****
char state;
int flag=0;            // ALL THE UDF ARE DECLAREDHERE
void stp();
void fwd();
void left();
void right();
void back();
void rotate();
void setup()
{
    pinMode(3,OUTPUT);                  
    pinMode(4,OUTPUT);                  
    pinMode(5,OUTPUT);                  
    pinMode(2,OUTPUT);                  
Serial.begin(9600);   // Baud rate set to 9600bps
}
void loop() {
    if(Serial.available() > 0)      // Ckeck for command Recieved
    {    
      state = Serial.read();
      Serial.println(state);  
      flag=0;
    }  
    if (state == 'S')     // Checking Command from User
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");                     // all the UDF are called here from onwards
          flag=1;
       }
    }
    else if (state == 'F')
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == 'B')
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == 'L')
    {
        left();
        if(flag == 0)
        {
          Serial.println("Left");
          flag=1;
         }
    }
   else if (state == 'R')
  {
        right();
        if(flag == 0)
        {
          Serial.println("Right");
          flag=1;
         }
    }
 else if (state=='X')
 {
    rotate();
    if(flag == 0)
    {
       Serial.println("rotate");
       flag=1;
    }
 }
    
 
Serial.println(state); //loop() ends here                // all the UDF are defined here
 }
void fwd()          // Forward               
{
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(3,LOW);
  delay (10);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  
}
void back()          // Backward
{
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  delay (10);
   digitalWrite(3,LOW);
  digitalWrite(5,LOW);
}
void left()          //LEFT
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  delay (10);
  digitalWrite(2,LOW); 
 }
void right()          // Right
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
 delay (10);
 digitalWrite(4,LOW);
}
void stp()            // Robot STops
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void rotate()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
delay (10);
digitalWrite(2,LOW);
  digitalWrite(5,LOW);
}
