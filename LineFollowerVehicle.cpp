#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). 
int in1 = 2; //right motors high/low 
int ena = 3; //right motors pwm 
int in2 = 4; //right motors high/low 
int enb = 5; //left motors pwm 
int in3 = 6; //left motors high/low 
int in4 = 7; //left motors high/low 
int echo = 8; //echo receiver pins 
int trig = 9; //trig transmitter pins 
double distance; //for ultrasonic equation 
double time; //for ultrasonic equation 
int otl2; //sensor 2 left high/low 
int otc2; //sensor 2 center high/low 
int otr2; //sensor 2 right high/low 
int otl1; //sensor 1 left high/low 
int otc1; //sensor 1 center high/low 
int otr1; //sensor 1 right high/low 
int regularSpeed = 90; //speed when moving forward for the four motors 
int leftRotationSpeed = 110; //left rotation speed 
int rightRotationSpeed = 110; //right rotation speed 
void setup() { 
pinMode(in1,OUTPUT); 
pinMode(in2,OUTPUT); 
pinMode(in3,OUTPUT); 
pinMode(in4,OUTPUT); 
pinMode(ena,OUTPUT); 
pinMode(enb,OUTPUT); 
  pinMode(otl1,INPUT); 
  pinMode(otc1,INPUT); 
  pinMode(otr1,INPUT); 
  pinMode(otl2,INPUT); 
  pinMode(otc2,INPUT); 
  pinMode(otr2,INPUT); 
  pinMode(trig,OUTPUT); 
  pinMode(echo,INPUT); 
   Serial.begin(9600);  
} 
 
void loop() { 
  // Ultrasonic as long as there is an object with in 20 cm  
  digitalWrite(trig,LOW); 
  delayMicroseconds(5); 
  digitalWrite(trig,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig,LOW); 
  time= pulseIn(echo,HIGH); 
  distance= time/2.0*343.0*0.0001; 
  Serial.print ("distance:"); 
  Serial.println (distance); 
  if (distance < 20) 
   { 
    digitalWrite(in1,LOW); 
    digitalWrite(in2,LOW); 
    digitalWrite(in3,LOW); 
    digitalWrite(in4,LOW); 
   } 
     else //ultrasonic when that object is removed 
     { 
      digitalWrite(in1,LOW); 
      digitalWrite(in2,HIGH); 
      analogWrite(ena,regularSpeed); 
      digitalWrite(in3,LOW); 
      digitalWrite(in4,HIGH); 
      analogWrite(enb,regularSpeed); 
      //IR sensors conditions 
      otl2=digitalRead(A0); 
      otc2=digitalRead(A1); 
      otr2=digitalRead(A2); 
      otr1=digitalRead(A3); 
      otc1=digitalRead(A4); 
      otl1=digitalRead(A5); 
       if (otl1==0 && otc1==0 && otr1==0 && otl2==0 && otc2==0 && otr2==0) //forward 
       { 
        digitalWrite(in1,LOW); 
        digitalWrite(in2,HIGH); 
        analogWrite(ena,regularSpeed); 
        digitalWrite(in3,LOW); 
        digitalWrite(in4,HIGH); 
        analogWrite(enb,regularSpeed); 
       } 
         else if (otl1==0 && otc1==0 && otr1==0 && otl2==1 && otc2==0 && otr2==0) //forward 
         { 
          digitalWrite(in1,LOW); 
          digitalWrite(in2,HIGH); 
          analogWrite(ena,regularSpeed); 
          digitalWrite(in3,LOW); 
          digitalWrite(in4,HIGH); 
          analogWrite(enb,regularSpeed); 
         } 
           else if (otl1==0 && otc1==0 && otr1==1 && otl2==0 && otc2==0 && otr2==0) //forward 
           { 
            digitalWrite(in1,LOW); 
            digitalWrite(in2,HIGH); 
            analogWrite(ena,regularSpeed); 
            digitalWrite(in3,LOW); 
            digitalWrite(in4,HIGH); 
            analogWrite(enb,regularSpeed); 
           } 
             else if (otl1==0 && otc1==0 && otr1==1 && otl2==1 && otc2==0 && otr2==0) //forward 
             { 
              digitalWrite(in1,LOW); 
              digitalWrite(in2,HIGH); 
              analogWrite(ena,regularSpeed); 
              digitalWrite(in3,LOW); 
              digitalWrite(in4,HIGH); 
              analogWrite(enb,regularSpeed); 
             } 
               else if (otl1==0 && otc1==0 && otr1==0 && otl2==1 && otc2==1 && otr2==0) //turn right 
               { 
                digitalWrite(in1,HIGH); 
                digitalWrite(in2,LOW); 
                analogWrite(ena,leftRotationSpeed); 
                digitalWrite(in3,LOW); 
                digitalWrite(in4,HIGH); 
                analogWrite(enb,rightRotationSpeed); 
               }  
                 else if (otl1==0 && otc1==0 && otr1==0 && otl2==0 && otc2==1 && otr2==1) //turn right 
                 { 
                  digitalWrite(in1,HIGH); 
                  digitalWrite(in2,LOW); 
                  analogWrite(ena,leftRotationSpeed); 
                  digitalWrite(in3,LOW); 
                  digitalWrite(in4,HIGH); 
                  analogWrite(enb,rightRotationSpeed); 
                 } 
                   else if (otl1==0 && otc1==0 && otr1==0 && otl2==1 && otc2==1 && otr2==1) //turn right 
                   { 
                    digitalWrite(in1,HIGH); 
                    digitalWrite(in2,LOW); 
                    analogWrite(ena,leftRotationSpeed); 
                    digitalWrite(in3,LOW); 
                    digitalWrite(in4,HIGH); 
                    analogWrite(enb,rightRotationSpeed); 
                   } 
                     else if (otl1==0 && otc1==1 && otr1==1 && otl2==0 && otc2==0 && otr2==0) //turn left 
                     { 
                      digitalWrite(in1,LOW); 
                      digitalWrite(in2,HIGH); 
                      analogWrite(ena,leftRotationSpeed); 
                      digitalWrite(in3,HIGH); 
                      digitalWrite(in4,LOW); 
                      analogWrite(enb,rightRotationSpeed); 
                     } 
                       else if (otl1==1 && otc1==1 && otr1==0 && otl2==0 && otc2==0 && otr2==0) //turn left 
                       { 
                        digitalWrite(in1,LOW); 
                        digitalWrite(in2,HIGH); 
                        analogWrite(ena,leftRotationSpeed); 
                        digitalWrite(in3,HIGH); 
                        digitalWrite(in4,LOW); 
                        analogWrite(enb,rightRotationSpeed); 
                       } 
                         else if (otl1==1 && otc1==1 && otr1==1 && otl2==0 && otc2==0 && otr2==0) //turn left 
                         { 
                          digitalWrite(in1,LOW); 
                          digitalWrite(in2,HIGH); 
                          analogWrite(ena,leftRotationSpeed); 
                          digitalWrite(in3,HIGH); 
                          digitalWrite(in4,LOW); 
                          analogWrite(enb,rightRotationSpeed); 
                         } 
                           else //stop  
                           { 
                            digitalWrite(in1,LOW); 
                            digitalWrite(in2,LOW); 
                            digitalWrite(in3,LOW); 
                            digitalWrite(in4,LOW); 
                          } 
     } 
}