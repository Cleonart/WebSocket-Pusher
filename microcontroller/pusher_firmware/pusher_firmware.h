/* 
  Picro Official Firmware (WiFi Edition)
  private release ver.1.0.0
  http://github.com/Cleonart/picro_firmware.git

  Universitas Katolik De La Salle Manado @2020
*/

#ifndef pf
#define pf

#include "Arduino.h"

//esp8266 library
#include <ESP8266WiFi.h>          
#include "ESP8266HTTPClient.h"

class PusherFirmware{
  public:
    
    //constructor
    PusherServer(String url_);
      
    //this is "begin" function, start and initialize wifi ssid and password ssid
    void begin(String ssid_, String pass_);

}
