// This file is for ESP8266 wifi module 
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <String>


const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

String payload;
String output;
String temp;
String shrink;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){ // WAIT FOR THE WIFI CONNECTION

        delay(500);
        Serial.println("bekle for con");
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WiFi.status()==WL_CONNECTED){
   
   HTTPClient http;
   
   http.begin("YOUR_WEBSERVICE_URL_OR_SOMETHING_CHANGE_THIS_STRING!.../WebService.asmx/Get");
   int httpCode = http.GET();

   if (httpCode > 0){
         payload = http.getString();                 // GET RESPONSE PAYLOAD
         shrink= payload.substring(72);
         
          output="";
          if(shrink.indexOf("false") >= 0)
          {
              output="f";
              Serial.println(output);
          }
          else if(shrink.indexOf("false") < 0)
          {
              if(shrink.indexOf("bir") >= 0)
              {
                output="1";
                Serial.println(output);
              }
              if(shrink.indexOf("iki") >= 0)
              {
                output="2";
                Serial.println(output);
              }
          }
   }

   http.end();  // close connection
   
  }else{
    Serial.println("Error con");
  }

  delay(6000); // send request every 30 sec

}