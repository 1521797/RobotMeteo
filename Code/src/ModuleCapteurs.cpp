#include "ModuleCapteurs.h"
#define SEALEVELPRESSURE_HPA (1013.25)

ModuleCapteurs::ModuleCapteurs(){}

void ModuleCapteurs::LireDonneesCapteur()
{

    temperature = bme280.readTemperature();
    humidite = bme280.readHumidity();
    pression = bme280.readPressure();
    altitude = bme280.readAltitude(SEALEVELPRESSURE_HPA);

    SerialiserDonnees();
}

void ModuleCapteurs::SerialiserDonnees()
{
    documentDonnees["temperature"] = temperature;
    documentDonnees["humidite"] = humidite;
    documentDonnees["pression"] = pression;
    documentDonnees["altitude"] = altitude;

    serializeJsonPretty(documentDonnees, Serial);
}