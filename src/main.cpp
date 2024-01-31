#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "Seu Wi-fi";
const char *password = "Sua Senha";

const int ledPin = 2;
bool ledStatus = false;

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = "<html><head>";
    html += "<style>";
    html += "body { font-family: Arial, sans-serif; text-align: center; }";
    html += "h1 { color: #333; }";
    html += "a { display: inline-block; margin: 10px; padding: 10px 20px; text-decoration: none; color: #fff; background-color: #4285f4; border-radius: 5px; }";
    html += "</style>";
    html += "<script>";
    html += "function updateStatus(status) { document.getElementById('status').innerHTML = status; }";
    html += "</script>";
    html += "</head><body>";
    html += "<h1>Controle do LED</h1>";
    html += "<p><a href='#' onclick='ligarLed();'>Ligar LED</a></p>";
    html += "<p><a href='#' onclick='desligarLed();'>Desligar LED</a></p>";
    html += "<p>Status: <span id='status'>LED desligado</span></p>";
    html += "<script>";
    html += "function ligarLed() { updateStatus('LED ligado'); fetch('/ligar'); }";
    html += "function desligarLed() { updateStatus('LED desligado'); fetch('/desligar'); }";
    html += "</script>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/ligar", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(ledPin, HIGH);
    ledStatus = true;
  });

  server.on("/desligar", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(ledPin, LOW);
    ledStatus = false;
  });

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  server.begin();
}

void loop() {
  //Não precisa colocar nada aqui
}
