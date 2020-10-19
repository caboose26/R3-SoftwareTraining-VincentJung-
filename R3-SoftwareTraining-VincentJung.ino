int input1 = 9;
int input2 = 6; 
int input3 = 10;
int input4 = 11;
//initializing the input pins on the motor controller with digital pwm pins in arduino
int s1 = 5; 
int s2 = 4; 
int s3 = 3; 
int s4 = 2;
//initializing the dipswitch to digital pins in arduino
int motorpwm = 0;  

int s1state;
int s2state;
int s3state;
int s4state;
//initializing additional variables
void setup()
{
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s4, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  //input pullup required for switches to be at LOW when toggled on.
}

void loop()
{
  s1state = digitalRead(s1);
  s2state = digitalRead(s2);
  s3state = digitalRead(s3);
  s4state = digitalRead(s4);
  //setting the state of each switch to a variable
  int pot = analogRead(A0);
  //setting the potentiometer value to variable
  motorpwm = map(pot,1023,1,0,255);
  //mapping the potentiometer value from 0 to 1023 to 0 to 255
  if(s1state == LOW && s2state == HIGH && s3state == HIGH && s4state == HIGH)
  {
    analogWrite(input1, motorpwm);
    analogWrite(input4, motorpwm);
    //this is for when only switch 1 when is on to make rover go forward
  }  
  else if(s1state == HIGH && s2state == LOW && s3state == HIGH && s4state == HIGH)
  {
    analogWrite(input2, motorpwm);
    analogWrite(input3, motorpwm);
    //this is for when only switch 2 when is on to make rover go backward
  }
   else if(s1state == HIGH && s2state == HIGH && s3state == LOW && s4state == HIGH)
  {
    analogWrite(input1, motorpwm);
    analogWrite(input3, motorpwm);
     //this is for when only switch 3 when is on to make rover turn left
  }
   else if(s1state == HIGH && s2state == HIGH && s3state == HIGH && s4state == LOW)
  {
    analogWrite(input2, motorpwm);
    analogWrite(input4, motorpwm);
     //this is for when only switch 4 when is on to make rover turn right
  }
  else
  {
    analogWrite(input1, 0);
    analogWrite(input2, 0);
    analogWrite(input3, 0);
    analogWrite(input4, 0);
    //this covers the event of no switch or multiple switches being on at the same time casuing motor to stop
  }

}
