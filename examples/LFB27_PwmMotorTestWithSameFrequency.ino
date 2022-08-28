#define MotLP     7
#define MotLN     6
#define MotRP     9
#define MotRN     8

#define RightPwm  3
#define LeftPwm   5

enum Dir
{
  Forward = 0,
  Backward = 1
};

void setup()
{
  /*Set same frequency for RightPwm (Pin 3) and LeftPwm (pin 5) to get same performance in both motors*/
  TCCR0B = TCCR0B & B11111000 | B00000011; // for PWM frequency of 976.56 Hz to LeftPwm pin (The DEFAULT)
  TCCR2B = TCCR2B & B11111000 | B00000011; // for PWM frequency of 980.39 Hz to RightPwm pin
  pinMode(MotRP, OUTPUT);
  pinMode(MotRN, OUTPUT);
  pinMode(MotLP, OUTPUT);
  pinMode(MotLN, OUTPUT);
}

void loop()
{
  /*Turns both motors in forward direction*/
  moveRobot(Forward, Forward, 192, 192);
  delay(1000);
  stopRobot();
  delay(2000);
  /*Turns both motors in backward direction*/
  moveRobot(Backward, Backward, 128, 128);
  delay(1300);
  stopRobot();
  delay(2000);
  /*Turns the motors in the opposite direction*/
  moveRobot(Forward, Backward, 94, 94);
  delay(1200);
  stopRobot();
  delay(2000);
}

void moveRobot(Dir leftDirection, Dir rightDirection, int leftPwmValue, int rightPwmValue)
{
  if (leftDirection == Forward)
  {
    digitalWrite(MotLP, HIGH);
    digitalWrite(MotLN, LOW);
  }
  else if (leftDirection == Backward)
  {
    digitalWrite(MotLP, LOW);
    digitalWrite(MotLN, HIGH);
  }
  analogWrite(LeftPwm, leftPwmValue);

  if (rightDirection == Forward)
  {
    digitalWrite(MotRP, LOW);
    digitalWrite(MotRN, HIGH);
  }
  else if (rightDirection == Backward)
  {
    digitalWrite(MotRP, HIGH);
    digitalWrite(MotRN, LOW);
  }
  analogWrite(RightPwm, rightPwmValue);
}
void stopRobot()
{
  /*Stop left motor*/
  digitalWrite(MotLP, LOW);
  digitalWrite(MotLN, LOW);
  /*Stop right motor*/
  digitalWrite(MotRP, LOW);
  digitalWrite(MotRN, LOW);
}
