#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <Update.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WifiManager.h>
#include <Wire.h>

class ModuleConnexion
{
    private:
    WiFiManager vm;

    public:
    ModuleConnexion();
    void ConnexionWIFI();
    void ConnexionMQTT();
    void PublierDonnees(float p_temperature, float p_humidite, float p_pression, float p_altitude);
};