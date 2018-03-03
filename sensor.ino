void setup() {
  pinMode(3,INPUT); //three ir sensors will be placed over herecc
   pinMode(4,INPUT);
    pinMode(5,INPUT);

  pinMode(6,OUTPUT); //these three pins are there for the triggering signal for display indication or for deploying the airbag 
    pinMode(7,OUTPUT);
      pinMode(8,OUTPUT);
  
}

void loop() {

int s1=digitalRead(3);
int s2=digitalRead(4);
int s3=digitalRead(5);

  


}
