/*
  Testes para o sensor de temperatura DS18B20, do tipo sonda.
*/

#include <Arduino.h>
#include <OneWire.h> //biblioteca OneWire incluída
#include <DallasTemperature.h> //biblioteca DallasTemperature incluída
 
//definindo o pino digital utilizado pelo sensor
#define DS18B20 4 

// declarando função para deep sleep
void deepSleep();

OneWire ourWire(DS18B20); // configura uma instância ONEWIRE para se comunicar com o sensor
DallasTemperature sensors(&ourWire); // biblioteca DallasTemperature utiliza a OneWire

void setup() {
  Serial.begin(9600); // inicializa a serial
  sensors.begin(); // inicializa o sensor
  delay(1000); // intervalo de 1 segundo
}

void loop() {
  sensors.requestTemperatures();//solicita que a funão informe a temperatura do sensor
  Serial.print("Temperatura: "); //imprime o texto na serial
  Serial.print(sensors.getTempCByIndex(0)); //imprime na serial o valor de temperatura medido
  Serial.println("*C"); //imprime o texto na serial
}

// implementação da função deepSleep
void deepSleep() {

}
