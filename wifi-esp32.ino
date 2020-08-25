#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>

#define SERVER_PORT 5003

WiFiServer server(SERVER_PORT);

void setup() {
  Serial.begin(9600);

  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  wifiManager.autoConnect();

  server.begin();
}

void loop() {
  Serial.println(WiFi.localIP());
  delay(500);
}
