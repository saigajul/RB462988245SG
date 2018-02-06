int ReadResponse(char SR)
{
    String collect = "";
    while(!client.available())
    {
      if(!Check_WiFi()) break;
    }

    if(!Check_WiFi()) return 0;
    
    while(client.available())
    {
        char c = client.read(); 
        Serial.print(c);       
        if(c != '\r')
        {
            collect += c;
        }
    }
	
	if(SR == 'S')
	{
		Serial.print(collect);
	}
	
	if(SR == 'R')
	{
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

int SendCloudData()
{
    Body      = "{"+Protocol_Body+Device_Body+Time_Body+Data_Body+Send_Data+"}";
    
    Serial.println("Connecting HOST: "+(String)host);
   
    while(!client.connect(host, httpsPort))
    {
        if(!Check_WiFi()) break;
        Serial.print('.');
    }

    if(!Check_WiFi()) return 0;
        
    Serial.println("Connected to host...");

    client.println(Write_Url);
    client.println(Host);
    client.println(Accept);
    client.println(User);
    client.println(Type_Header);
    client.print(API_Header);
    client.println(API);
    client.print(Length);
    client.println((int)Len(Body));
    client.println(Connection_Close);
    client.println();
    client.println(Body);
    ReadResponse('S'); 
	client.stop();
}

int ReadCloudData()
{
    Serial.println("\nConnecting HOST: "+(String)host);
    
    while(!client.connect(host, httpsPort))
    {
        if(!Check_WiFi()) break;
        Serial.print('.');
    }
    if(!Check_WiFi()) return 0;
    
    Serial.println("Connected to host...");
    client.println(Read_Url);
    client.println(Host);
    client.println(Accept);
    client.println(User);
    client.println(Type_Header);
    client.print(API_Header);
    client.println(API);
    client.println(Connection_Close);
    client.println();
    ReadResponse('R');
	client.stop();
}