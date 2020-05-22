#include "pusher_firmware.h"

PusherFirmware pusher("1", "http://127.0.0.1/PusherServer/server/index.php");

void setup() {
  pusher.begin("WIFI_SSID", "WIFI_PASSWORD");
}

void loop() {
  pusher.trigger("1");
  delay(5000);
  pusher.trigger("0");
  delay(5000);
}
