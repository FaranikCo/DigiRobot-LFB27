/*
  LFB27_ReadSensors
  Reads the output of IR sensors that are connected to main board and writes results on serial port.
*/

#define S1 10
#define S2 11
#define S3 12
#define S4 A0
#define S5 A1

bool irSensors[5] = {0, 0, 0, 0, 0};
int irPins[5] = {10, 11, 12, A0, A1};

void setup()
{
  Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void loop()
{
  readSensors();
  delay(100);
}


void readSensors()
{
  Serial.print("irSensors: ");
  for (int i = 0; i < 5; i++)
  {
    irSensors[i] = digitalRead(irPins[i]);
    Serial.print(irSensors[i]);
    if (i != 4)
    {
      Serial.print(",");
    }
  }
  Serial.println();
}
