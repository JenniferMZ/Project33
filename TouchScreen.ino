// Project 33 - Touch Screen

int x, y = 0;
int readX()   // returns the value of the touchscreen's x-axis

#define yelLED 2
#define grnLED 3
#define bluLED 4
#define whtLED 5


{
  int xr = 0;
  pinMode (A0, INPUT);
  pinMode (A1, OUTPUT);
  pinMode (A2, INPUT);
  pinMode (A3, OUTPUT);
  digitalWrite (A1, LOW);   // SET A1 TO GND
  digitalWrite (A3, HIGH);  // SET A3 AS 5V
  delay(5);
  xr = analogRead(0);       // stores the value of the x-axis
  return xr;
}



int readY()     // returns the value of the touchscreen's y-axis
{
  int yr = 0;
  pinMode (A0, OUTPUT);
  pinMode (A1, INPUT);
  pinMode (A2, OUTPUT);
  pinMode (A3, INPUT);
  digitalWrite (14, LOW);   // set A0 to GND
  digitalWrite (16, HIGH);  // set A2 as 5V
  delay(5);
  yr = analogRead(1);       // stores the value of the y/axis
  return yr;
}



void setup() 
{
  Serial.begin(9600);
  pinMode (yelLED, OUTPUT);
  pinMode (grnLED, OUTPUT);
  pinMode (bluLED, OUTPUT);
  pinMode (whtLED, OUTPUT);
}



void loop() 
{
  Serial.print ( "x = " );
  x = readX();
  Serial.print ( x );
  y = readY();
  Serial.print ( " y = " );
  Serial.println ( y );
  delay (200);



  // LED control statement
  if (x > 450 && y < 400)
  {
    digitalWrite (whtLED, HIGH);
    delay(1500);
    digitalWrite (whtLED, LOW);
  }
  
  if (x < 500 && y < 400)
  {
    digitalWrite (bluLED, HIGH);
    delay(1500);
    digitalWrite (bluLED, LOW);
  }

  if (x > 450 && x < 1023 && y > 400)
  {
    digitalWrite (yelLED, HIGH);
    delay(1500);
    digitalWrite (yelLED, LOW);
  }
  
  if (x < 500 && y > 400 )
  { 
    digitalWrite (grnLED, HIGH);
    delay(1500);
    digitalWrite (grnLED, LOW);
  }

}


