#include "RobotMeteo.h"

RobotMeteo::RobotMeteo(){}

void RobotMeteo::Chargement()
{
    Serial.begin(115200);
    Serial.println();

    // Initialiser le capteur BME280
    if (!m_Capteurs.bme280.begin(0x76)) {
        Serial.println("Impossible de trouver le capteur BME280 !");
    }

    // Connexion au WiFi
    m_Connexion.ConnexionWIFI();

    // Connexion à MQTT
    m_Connexion.ConnexionMQTT(); 
}

void RobotMeteo::Executer()
{
    m_Capteurs.LireDonneesCapteur();
    m_Connexion.PublierDonnees(m_Capteurs.temperature, m_Capteurs.humidite, m_Capteurs.pression, m_Capteurs.altitude);

    delay(2000);
}