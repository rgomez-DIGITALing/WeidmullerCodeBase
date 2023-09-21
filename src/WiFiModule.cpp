#include "WiFiModule.h"
#include <WiFi.h>
#include "LogModule.h"



void WiFiModuleClass::init(){
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
    return;
}


void WiFiModuleClass::loop(){

    if(WiFi.status() != WL_CONNECTED){
        if(networkUp) LogInfo("WiFi disconnected.");
        
        networkUp = false;
        
        if(millis()-lastBeginTime > beginInterval){
            WiFi.begin(ssid, password);
            lastBeginTime = millis();
        }
    }

    if(WiFi.status() == WL_CONNECTED){
        if(!networkUp){
            LogInfo("WiFi connected. IP address: %s", WiFi.localIP().toString().c_str());
        }
        networkUp = true;
    }
    return;
}

WiFiModuleClass WiFiModule;
