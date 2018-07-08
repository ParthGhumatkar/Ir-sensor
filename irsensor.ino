#include <IRremote.h> // Library for IRsensor

int RECV_PIN = 8; // Sensor pin
IRrecv irrecv(RECV_PIN);
decode_results results; // Signals from the remote will be dected and decoded  

#define RED_LED 0x5EE9 //Red LED Hex code 
#define BLUE_LED 0x4CE9  //Blue LED Hex code 
#define GREEN_LED 0x1EE9   //Green LED Hex code 
#define TURN_ALL_OFF 0xCE9 
#define TURN_ALL_ON 0x2CE9

int Blue_LED = 7; //Blue LED pin 
int Red_LED = 6; //Red LED pin 
int Green_LED = 5; //Green LED pin 

void setup()
{
  pinMode(Blue_LED, OUTPUT); 
  pinMode(Red_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);
  
  irrecv.enableIRIn(); // Starting to receive process
}
void loop() {

  if (irrecv.decode(&results)) //Attempt to receive a Hex code or got a Hex code
  {
    if (results.value ==TURN_ALL_OFF) // If TURN_ALL_OFF Hex code received all LEDS will turn off.
    {
      digitalWrite(Blue_LED, LOW);
      digitalWrite(Red_LED, LOW);
      digitalWrite(Green_LED, LOW);
    }
    if (results.value == TURN_ALL_ON ) // If TURN_ALL_ON Hex code received all LEDS will turn on.
    {
      digitalWrite(Blue_LED, HIGH);
      digitalWrite(Red_LED, HIGH);
      digitalWrite(Green_LED, HIGH);
    }
    if (results.value == RED_LED) // If RED_LED Hex code received all Red LED will turn on.
    {
      digitalWrite(Red_LED, HIGH);  
    }
    if (results.value == BLUE_LED) // If BLUE_LED Hex code received all BLUE LED will turn on.
    {
      digitalWrite(Blue_LED, HIGH); 
    }
    if (results.value ==GREEN_LED) // If GREEN_LED Hex code received all Green LED will turn on.
    {
      digitalWrite(Green_LED, HIGH);
    }
    irrecv.resume(); //After receiving Hex code and reseting 
  }
}
