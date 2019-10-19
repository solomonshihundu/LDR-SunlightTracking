//import the Servo motor support library
#include<Servo.h>    

//Servo object declaration
Servo servo;

// initially starting from 90 degree
int initialPosition = 90; 

//for read data from LDR1   
int topRight = A0;

//for read data from LDR2
int bottonLeft = A1;  

//for read data from LDR3   
int bottomRight = A2;   

//for read data from LDR4
int topLeft = A3;     
     
int baseLine = 15;          

void setup() 
{ 

  //connect vertical servo to pin 7 of arduino
  servo.attach(7);   
 
  //define LDR as input
  pinMode(topRight, INPUT);  
  pinMode(topLeft, INPUT);
  
  pinMode(bottonLeft, INPUT);
  pinMode(bottomRight, INPUT);  
  
  //it will start servo from 90 when we reset system
  servo.write(initialPosition); 

  delay(2000);          
} 
void loop() 
{ 
  //read and store values from LDRs
  //top LDRs readings
  int topRightLDR = analogRead(L1); 
  int topLeftLDR = analogRead(L4);

  //bottom LDRs readings
  int bottonLeftLDR = analogRead(L2); 
  int bottomRightLDR = analogRead(L3);
  
  //average of two corner LDR
  int topLDROutput =(topRightLDR+topLeftLDR);  
  int bottomLDROutput =(bottonLeftLDR+bottomRightLDR);


  //horizontal axis 
  //difference of the two  ldr outputs will indicate the difference in
  //light intensities from opposing directions
  int topLdrDifference= abs(topLDROutput - bottomLDROutput); 
  int bottomLdrDifference= abs(bottomLDROutput - topLDROutput);
  
  if((topLdrDifference <= baseLine) || (bottomLdrDifference <= baseLine))
 {
   //difference is less then 15 so do nothing
  } 
 else 
 {    

  //variable stores new servo position
    int newPosition  = initialPosition;
    
    if(topLdrDifference > bottomLdrDifference) 
    {
     
     //move vertical servo in lessthen 90 degree
      newPosition--;   
    }
    
 if(topLdrDifference < bottomLdrDifference) 
    {
      
      //move vertical servo in greaterthen 90 degree
       newPosition++;  
    }
  }

  servo.write(newPosition);
  
   delay(100);
}

