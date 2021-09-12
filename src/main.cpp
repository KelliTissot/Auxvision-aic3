#include <Arduino.h>
#include <Ultrasonic.h>

int led_pin = 14;
int led_pwm = 0;
int trigger = 26;
int echo = 25;
int distancia_min = 20;

Ultrasonic ultrasonic(trigger, echo); // An ultrasonic sensor HC-04

void setup()
{
   Serial.begin(9600);
   pinMode(led_pin, OUTPUT);
   ledcAttachPin(led_pin, led_pwm);//Atribuimos o pino 2 ao canal 0.
   ledcSetup(led_pwm, 1000, 8);//Atribuimos ao canal 0 a frequencia de 1000Hz com resolucao de 8bits.
}

void loop()
{
   float distancia = ultrasonic.read();
   if (distancia <= distancia_min)
   {
      float potencia = distancia_min -distancia;
      Serial.println(potencia);
      //Serial.print("\nVai bater!!!\n");
      ledcWrite(led_pwm, (255-potencia*5));
   }
   else
   {
      //Serial.print("\nVai na fé!!!\n");
      ledcWrite(led_pwm, 255);
   }
   //Serial.print("Sensor 01: ");
   //Serial.print(ultrasonic.read()); // Prints the distance on the default unit (centimeters)
   //Serial.println("cm");

      delay(500);
}