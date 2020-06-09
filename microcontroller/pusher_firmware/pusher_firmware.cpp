/* 
  Pusher Official Firmware (WiFi Edition)
  private release ver.1.0.0
  https://github.com/Cleonart/WebSocket-Pusher

  Universitas Katolik De La Salle Manado @2020
*/

#include "pusher_firmware.h"

//constructor
PusherFirmware::PusherFirmware(String channel_, String url_){
  url = url_;
  sensor_channel = channel_;
}

/**
 * Begin function
 */
void PusherFirmware::begin(char ssid_[], char password_[]){
    Serial.begin(115200);
    connectToWifi(ssid_, password_);
}

void PusherFirmware::trigger(String sensor_data){
    httpRequest(sensor_data);
}

void PusherFirmware::httpRequest(String sensor_data){
  
    //constructor
    HTTPClient http;
    String params = "?channel=" + sensor_channel + "&msg=" + sensor_data;
    
    //begin http request
    http.begin(url + params);
    int httpCode = http.GET();
     
    //getting the payload from http
    if(httpCode > 0){
      Serial.println("Sended Successfully");
    }
    else{
      Serial.println("Error while processing http request");
    }

    //close http connection
    http.end();

    //don't do http request when wifi connection isn't available
}

/*
 * Connect To Wifi Fucntion 
 * @params : SSID, PASSWORD 
 */ 
 void PusherFirmware::connectToWifi(char ssid[], char password[]){

  //begin wifi service
  WiFi.begin(ssid, password);
  
  //connecting to wifi
  Serial.print("Connecting..");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  //wifi service started
  Serial.print("Connected.");
  Serial.println("Device is ready to use"); 
  delay(5000); 
}
