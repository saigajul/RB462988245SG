void Smart_Config()
{
    WiFi.mode(WIFI_STA);
    WiFi.beginSmartConfig();
    Serial.println("\nWaiting For SmartConfig.");

    while(1)
    {        
        Serial.print('.');
        delay(1000);
        if(WiFi.smartConfigDone())
        {
            break;
        }
    }
    
    Serial.println();
    Serial.println("SmartConfing received \nWaiting for WiFi Connection");   
    WiFi.begin();
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(5);
    }
}

void WiFi_Status()
{
    Serial.println();
    Serial.println("Connected to: "+WiFi.SSID());
    Serial.print("IP Address:   ");
    Serial.println(WiFi.localIP());
    //server.begin();
}

void Connect_WiFi()
{
    int check = 0;
    Serial.println("Connecting to Router");
    while(WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin();
        for(check = 0; check < 20; check ++)
        {
            Serial.print('.');
            delay(1000);
            if(WiFi.status() == WL_CONNECTED) check = 21 ;
        }
        
        if(check == 19)
        {
            Serial.println("\nIs Router ON...? or Reset Device/router");
            delay(10000);       
        }

        if(WiFi.status() != WL_CONNECTED)
        {
            Serial.println("Please config device with router credentials.");
            Smart_Config();
        }
    }
    WiFi_Status();
}

int Check_WiFi()
{
    if(WiFi.status() == WL_CONNECTED)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}