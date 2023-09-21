#pragma once


static const unsigned long DEFAULT_BEGIN_INTERVAL = 5000; //In ms

class WiFiModuleClass{
    public:
        void init();
        void loop();
        bool isNetworkUp(){ return networkUp; }
        void setSSID(char* ssid){ this->ssid = ssid;}
        void setPassword(char* password){ this->password = password; }
        void setBeginInterval(unsigned long beginInterval){ this->beginInterval = beginInterval; }
        

    private:
        bool networkUp = false;
        char* ssid = nullptr;
        char* password = nullptr;
        unsigned long lastBeginTime = 0; 
        unsigned long beginInterval = DEFAULT_BEGIN_INTERVAL;
};


extern WiFiModuleClass WiFiModule;