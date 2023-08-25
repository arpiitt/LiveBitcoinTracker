#include <LiquidCrystal.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const int rs = 0;
const int en = 1;
const int d4 = 2;
const int d5 = 3;
const int d6 = 4;
const int d7 = 5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char* ssid = "your wifi username";      
const char* password = "password";  
const char* apiEndpoint = "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=inr";

void setup() {
  lcd.begin(16, 2);  

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    
    http.begin(apiEndpoint);
    int httpResponseCode = http.GET();
    
    if (httpResponseCode == 200) {
      String response = http.getString();
      
      
      DynamicJsonDocument doc(1024);
      DeserializationError error = deserializeJson(doc, response);
      
      if (error) {
        Serial.print("JSON parsing error: ");
        Serial.println(error.c_str());
      } else {
        float bitcoinPrice = doc["bitcoin"]["inr"];
        String priceString = String(bitcoinPrice, 2);
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Bitcoin Price:");
        
        lcd.setCursor(0, 1);
        lcd.print("INR ");
        lcd.print(priceString);
      }
    } else {
      Serial.print("HTTP error code: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  }
  
  delay(5000);  
}
