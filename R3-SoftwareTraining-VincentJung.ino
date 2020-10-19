int input1 = 9;
int input2 = 6; 
int input3 = 10;
int input4 = 11;

int s1 = 5; 
int s2 = 4; 
int s3 = 3; 
int s4 = 2;

int motorpwm = 0;  

int s1state;
int s2state;
int s3state;
int s4state;

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
}

void loop()
{
  s1state = digitalRead(s1);
  s2state = digitalRead(s2);
  s3state = digitalRead(s3);
  s4state = digitalRead(s4);
  
  int pot = analogRead(A0);
  motorpwm = map(pot,1023,1,0,255);
  
  if(s1state == LOW && s2state == HIGH && s3state == HIGH && s4state == HIGH)
  {
    analogWrite(input1, motorpwm);
    analogWrite(input4, motorpwm);
  }  
  else if(s1state == HIGH && s2state == LOW && s3state == HIGH && s4state == HIGH)
  {
    analogWrite(input2, motorpwm);
    analogWrite(input3, motorpwm);
  }
   else if(s1state == HIGH && s2state == HIGH && s3state == LOW && s4state == HIGH)
  {
    analogWrite(input1, motorpwm);
    analogWrite(input3, motorpwm);
  }
   else if(s1state == HIGH && s2state == HIGH && s3state == HIGH && s4state == LOW)
  {
    analogWrite(input2, motorpwm);
    analogWrite(input4, motorpwm);
  }
  else
  {
    analogWrite(input1, 0);
    analogWrite(input2, 0);
    analogWrite(input3, 0);
    analogWrite(input4, 0);
  }

}