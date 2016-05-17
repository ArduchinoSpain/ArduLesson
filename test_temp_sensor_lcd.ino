#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Tiempo de refresco de la pantalla LCD.
#define  REFRESH_RATE 1000

// Pin analogico del sensor de temperatura
#define TEMPIN 1

// Iniciar pantalla LCD con interfaz I2C en el canal 27
// OJO: Debes consultar el canal, según el modelo de LCD.
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temperature;
long int lastTimeUpdate;

void setup(){
    Serial.begin(9600);
}

void loop(){

    temperature = analogRead(TEMPIN);
    // Convierte el valor a temperatura
    temperature = (5.0 * temperature * 100.0)/1024.0;
    Serial.print(temperature);

    if (millis() > lastTimeUpdate) {
        lcd.print(temperature);
      lastTimeUpdate = millis() + REFRESH_RATE;

    }

}
