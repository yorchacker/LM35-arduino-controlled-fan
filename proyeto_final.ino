                                        
float tempC;                            // create variable to store the temperature in.
#define tempPin A0                     // Attach vout to analog pin 0.
int led = 9;                           // attach led to pin 13.
int fan1 = 5;                           // attach base of transistor to digital pin 3.
char valor = 0;
int relayPin = 2;                       // define pin for relay

void setup()                            // Will execute once at the start of the code.
{
  Serial.begin(9600);                   // opens serial port, sets data rate to 9600 bps
  pinMode (led, OUTPUT);                // sets the led pin 13 up as an output.
  pinMode (fan1, OUTPUT);               // sets the fan1 pin 3 up as an output.
  pinMode(relayPin, OUTPUT);
  Serial.println("Proyecto de Control Jorge Viloria");
  delay(1000);
  Serial.println("   INICIANDO SISTEMA DE CONTROL ");
  delay(800);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, LOW);         // turns on led.
  delay(1000);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  analogWrite (fan1, 200);
  delay(1000);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, LOW);         // turns on led.
  delay(1000);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  delay(1000);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, LOW);         // turns on led.
  analogWrite (fan1, 100);
  delay(1000);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  delay(1000);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  analogWrite (fan1, 40);
  delay(500);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, LOW);         // turns on led.
  delay(500);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  delay(500);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, LOW);         // turns on led.
  delay(500);
  digitalWrite(relayPin, HIGH);// turn relay ON delay(800);
  digitalWrite (led, HIGH);         // turns on led.
  delay(500);
  digitalWrite(relayPin, LOW);// turn relay ON delay(800);
  digitalWrite (led, LOW);  
  delay(2000);
}

void loop()                             // code here will continue to replay nutil powered off.
{
  tempC = analogRead(tempPin);          // read the analog value from the lm35 sensor.
  tempC = (5.0 * tempC * 100.0)/1024.0; // convert the analog input to temperature in centigrade.
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("C");
  
  // send the data to the computer.
    if (tempC > 47)                     // creates bool expression for analyzation. if it evaluates to true,
    {               
                                       // the body of the if statement will execute.
      digitalWrite(relayPin, LOW);     // turn relay ON.
      Serial.println("Relay OFF");
      digitalWrite (led, HIGH);         // turns on led.
      analogWrite (fan1, 200);          // turns on fan1.
      Serial.println ("FAN ON");
      delay(3000);
    }
    else                                // if the if equation evaluates to false the else statement will execute.
    {
      digitalWrite(relayPin, HIGH);// turn relay ON
      Serial.println("Relay ON");
      digitalWrite (led, LOW);          // turns off led.
      analogWrite (fan1, 60);         // turns off fan1.
      Serial.println("FAN OFF");
      delay(3000);
    }
    delay(2000);
}

 







//Processing Code:
//
////import Serial communication library
//import processing.serial.*;
//
////init variables
//Serial commPort;
//float tempC;
//float tempF;
//int yDist;
//PFont font12;
//PFont font24;
//float[] tempHistory = new float[100];
//
//void setup()
//{
//  //setup fonts for use throughout the application
//  font12 = loadFont("Verdana-12.vlw"); 
//  font24 = loadFont("Verdana-24.vlw"); 
//  
//  //set the size of the window
//  size(210, 200);
//  
//  //init serial communication port
//  commPort = new Serial(this, "COM5", 9600);
//  
//  //fill tempHistory with default temps
//  for(int index = 0; index<100; index++)
//    tempHistory[index] = 0;
//}
//
//void draw()
//{
//  //get the temp from the serial port
//  while (commPort.available() > 0) 
//  {
//    tempC = commPort.read();
//  
//    //refresh the background to clear old data
//    background(123);
//
//    //draw the temp rectangle
//    colorMode(RGB, 160);  //use color mode sized for fading
//    stroke (0);
//    rect (49,19,22,162);
//    //fade red and blue within the rectangle
//    for (int colorIndex = 0; colorIndex <= 160; colorIndex++) 
//    {
//      stroke(160 - colorIndex, 0, colorIndex);
//      line(50, colorIndex + 20, 70, colorIndex + 20);
//    }
//    
//    //draw graph
//    stroke(0);
//    fill(255,255,255);
//    rect(90,80,100,100);
//    for (int index = 0; index<100; index++)
//    {  
//      if(index == 99)
//        tempHistory[index] = tempC;
//      else
//        tempHistory[index] = tempHistory[index + 1];
//      point(90 + index, 180 - tempHistory[index]); 
//    }
//  
//    //write reference values
//    fill(0,0,0);
//    textFont(font12); 
//    textAlign(RIGHT);
//    text("212 F", 45, 25); 
//    text("32 F", 45, 187);
//  
//    //draw triangle pointer
//    yDist = int(160 - (160 * (tempC * 0.01)));
//    stroke(0);
//    triangle(75, yDist + 20, 85, yDist + 15, 85, yDist + 25);
//  
//    //write the temp in C and F
//    fill(0,0,0);
//    textFont(font24); 
//    textAlign(LEFT);
//    tempC = 5*tempC*100/1024;
//    text(str(int(tempC)) + " C", 115, 37);
//    text(str(int(tempC*1.8+32)) + " F", 115, 65);
//  }
//}
