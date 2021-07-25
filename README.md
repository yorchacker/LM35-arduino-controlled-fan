# LM35-arduino-controlled-fan
Control System with an arduino using a lm35 and a cpu fan to mantain a temperature.

  
                                        
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

 
