#include <clockModule.h>
#include <LogModule.h>
#include <EthernetModule.h>

void setup() {
  Serial.begin(SERIAL_LOGGER_BAUD_RATE);
  set_logging_function(logging_function);
  Serial.println("Welcome!");
  
  EthernetModule.init();
  systemClock.begin();
  // put your setup code here, to run once:

}


bool  networkUp = false;
bool  clockRunning = false;


static const unsigned long DELTA_TIME = 5000;
static unsigned long lastTime = 0;

void loop() {
  EthernetModule.loop();
  networkUp = EthernetModule.isNetworkUp();
  systemClock.loop(networkUp);
  clockRunning = systemClock.clockRunning();

  if(millis()-lastTime > DELTA_TIME){
    Serial.print("Clock source: ");
    Serial.println(systemClock.getClockSourceName());
    Serial.print("Unix timestamp: ");
    Serial.println(systemClock.getEpochTime());
    lastTime = millis();
  }
  
  // put your main code here, to run repeatedly:

}
