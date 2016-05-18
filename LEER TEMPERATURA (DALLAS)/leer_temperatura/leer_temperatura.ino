#include <OneWire.h> //Se importan las librerías
#include <DallasTemperature.h>

#define Pin 2 //Se declara el pin donde se conectará la DATA

OneWire ourWire(Pin); //Se establece el pin declarado como bus para la comunicación OneWire

DallasTemperature sensors(&ourWire); //Se instancia la librería DallasTemperature

void setup() {
delay(1000);
Serial.begin(9600);
sensors.begin(); //Se inician los sensores
}

void loop() {
sensors.requestTemperatures(); //Prepara el sensor para la lectura

Serial.print(sensors.getTempCByIndex(0)); //Se lee e imprime la temperatura en grados Celsius
Serial.println(" grados Centigrados");
Serial.print(sensors.getTempFByIndex(0)); //Se lee e imprime la temperatura en grados Fahrenheit
Serial.println(" grados Fahrenheit"); 

delay(1000); //Se provoca un lapso de 1 segundo antes de la próxima lectura

}
