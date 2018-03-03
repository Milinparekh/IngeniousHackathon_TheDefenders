#include<NewPing.h>
#include<Servo.h>
#include <SoftwareSerial.h>

#define TRIGGER_PIN  12  //  trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  //  echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // 

int P1;    //pwm1 value
int P2;    //pwm2 value

#define E1 3  // pwm Pin for motor 1
#define E2 10  // pwm Pin for motor 2
 
#define I1 8  // Control pin 1 for motor 1
#define I2 7  // Control pin 2 for motor 1
#define I3 6  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

char state;
int flag=0; 
void stp();
void fwd();
void left();
void right();
void back();
void rotate();
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
void setup() {
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  
  
   
   Serial.begin(9600);

    


    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    pinMode(A0,INPUT);
    
}
 
void loop()


{
  digitalWrite(5,HIGH);   // both pins high for the access of vcc pins on baord
 digitalWrite(4,HIGH);

  
  
  
  
  int dis=sonar.ping_cm();  //the vaklues of P1 and P2 will be changing instantaneously
  
  if(dis > 100)
    {
       P1 = 255;
       P2 = 255;
   }
  else if( 80<dis  && dis<100 )
    {
      P1 = 200 ;
    P2 = 200;
    }
  else if( 60<dis  && dis<80 )
    {
       P1 = 150 ;
     P2 = 150;
    }
  else if( 40<dis && dis<60 )
    {
     P1 = 120;
       P2 = 120;
    }
  else if( dis<40 )
    {
        P1 =50;
        P2 = 50;
    }
     Serial.println(dis);
  
  if(Serial.available() > 0)      // Ckeck for command Recieved
    {    
      state = Serial.read();
      Serial.write(state);  
      flag=0;
    }  
    if (state == 'S')     // Checking Command from User
    {
        stp();
        if(flag == 0){
          Serial.write("Stop");
          flag=1;
       }
    }
    else if (state == 'F')
    {
        fwd();
        if(flag == 0)
        {
          Serial.write("Forward");
          flag=1;
         }
    }
    else if (state == 'B')
    {
        back();
        if(flag == 0)
        {
          Serial.write("Backward");
          flag=1;
        }
    }
    else if (state == 'L')
    {
        left();
        if(flag == 0)
        {
          Serial.write("Left");
          flag=1;
         }
    }
   else if (state == 'R')
  {
        right();
        if(flag == 0)
        {
          Serial.write("Right");
          flag=1;
         }
    }
 
 

 }
 
 void stp()                              //fumction for stopping the car
 {
   digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
 }
 
void fwd()                                                     //forward
{
    analogWrite(E1,P1); 
    analogWrite(E2,P2); 
 
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
 delay(15);
 digitalWrite(I1,LOW);
  digitalWrite(I3,LOW);
    
}
void back()          // Backward
{
    analogWrite(E1, P1); // Run in half speed
    analogWrite(E2,P2); // Run in full speed
 
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
delay(15);
 digitalWrite(I1, LOW);
    digitalWrite(I4,LOW);
    
  
  
}
void left()          //LEFT
{
  analogWrite(E1,P1); // Run in half speed
    analogWrite(E2,P2); // Run in full speed
 
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    delay(15);
   digitalWrite(I1,LOW);
    digitalWrite(I4,LOW);

 
}

void right()  //Right
{
    analogWrite(E1, P1); // Run in half speed
    analogWrite(E2,P2); // Run in full speed
 
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
delay(15);
 digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);

  }    
  
