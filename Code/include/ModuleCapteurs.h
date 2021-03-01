#pragma once

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ArduinoJson.h>

class ModuleCapteurs
{
    private:
    StaticJsonDocument<500> documentDonnees;

    public:
    Adafruit_BME280 bme280;
    float temperature, humidite, pression, altitude;    
    
    ModuleCapteurs();   
    void LireDonneesCapteur();
    void SerialiserDonnees();
};