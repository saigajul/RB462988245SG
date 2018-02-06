WiFiServer server(80);
WiFiClient client;

int WiFLocalAction()
{
    client = server.available();
    
    if(client)
    {
        String Collect = "";
       
        while(client.connected())
        {
			while(!client.available())
			{
				if(!Check_WiFi()) break;
			}
			
			if(!Check_WiFi()) return 0;
			
            while(client.available())
            {
                char c = client.read();
                if(c != '\r')
                {
                    Collect += c;
                }
            }
			
			for (int i = 0; i < collect.length(); i++)
			{
				if (collect.substring(i, i+7) == "\"data\":")
				{
					Actiondata = collect.substring(i+7).toInt();
					SetFireAngle();
					Serial.print("Actiondata: ");
					Serial.println(Actiondata);
					break;
				}
			}
        }
    }
}