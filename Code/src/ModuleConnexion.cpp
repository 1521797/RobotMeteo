#include "ModuleConnexion.h"
#include "Configurations.h"
#include <PubSubClient.h>

// Si on place "WiFiClient" et "PubSubClient" en données membres de la classe, va compiler avec des erreurs.
// Mentionne 2 erreurs, l'une qui parle de non-reconnaissance de type, et l'autre qu'il y a plusieurs définitions de "client"
// Fonctionne ici dans le cpp seulement, utilisé comme de simples variables.
WiFiClient espClient;
PubSubClient client(espClient);

ModuleConnexion::ModuleConnexion(){}

void ModuleConnexion::ConnexionWIFI()
{
  //wm.resetSettings();
  Serial.println("\n");
  Serial.print("Tentative de connexion à :");
  Serial.println(MYSSID);

  WiFi.begin(AP_HOST, AP_PWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  
  Serial.println(WiFi.localIP());
}

void ModuleConnexion::ConnexionMQTT()
{
  client.setServer(MQTT_SERVER, MQTT_PORT);

  Serial.println("Connexion à MQTT...");
  if (client.connect("ESP32Client", MQTT_USER, MQTT_PWD))
  {
    Serial.println("Robot connecté");
  }
  else
  {
    Serial.print("failed with state ");
    Serial.print(client.state());
    delay(2000);
  }
}

void ModuleConnexion::PublierDonnees(float p_temperature, float p_humidite, float p_pression, float p_altitude)
{
  // Publier
  client.publish(TOPIC_TEMPERATURE, String(p_temperature).c_str());
  client.publish(TOPIC_HUMIDITE, String(p_humidite).c_str());
  client.publish(TOPIC_PRESSION, String(p_pression).c_str());
  client.publish(TOPIC_ALTITUDE, String(p_altitude).c_str());
}