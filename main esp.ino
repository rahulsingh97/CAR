#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>
#include <ESP8266WebServer.h>

char* mqtt_server = "broker.hivemq.com";

const char* clientID = "remote";
String rcvtp = "remotecar";

WiFiClient wifiClient;
PubSubClient client(mqtt_server, 1883, wifiClient);
PubSubClientTools mqtt(client);

char ssid[] = "remotecar";
char pass[] = "password";

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("wifi connected");
  if (client.connect(clientID))
    mqtt.subscribe(rcvtp, tpc_sub);
}
void tpc_sub(String topic, String msg)
{
  msg.trim();
  msg.toLowerCase();
  Serial.print(msg+"@");
}
void loop()
{
  delay(50);
  client.loop();
}
