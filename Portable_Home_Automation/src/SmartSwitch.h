#include<WiFi.h>

const int		AC_Pin			= 5; //D0;
const int		Zero_Pin		= 17;//D6;
const int 		Mnual_Pin		= 14;//D5;

#define Len(a)	a.length()
volatile int	Actiondata		= 0;
volatile int	Fireangle		= 0;
volatile int	Send_Data		= 0;

//Client connect....
const char* host        = "api.carriots.com";
const int httpsPort     = 443;

//Headers.......
String Write_Url        = "POST /streams HTTP/1.1";
String Read_Url         = "GET /streams/?max=1&order=-1 HTTP/1.1";
String Host             = "Host: "+(String)host;
String Accept           = "Accept: application/json";
String Device_Name      = "esp@saigajul.saigajul";
String User             = "User-Agent: "+Device_Name;
String Type_Header      = "Content-Type: application/json";
String API_Header       = "carriots.apikey: ";
String API              = "2703cac800d2719294bbb51caa93720b39698df8181e89d989380452d43eaff4";
String Length           = "Content-Length: ";
String Connection_Close = "Connection: close";

//Body.......
String Protocol_Body    = "\"protocol\": \"v2\",";
String Device_Body      = "\"device\":\""+Device_Name+"\",";
String Time_Body        = "\"at\": \"now\",";
String Data_Body        = "\"data\":";
String Body             = "";

/**************************PIN-Action************************************/

void SetFireAngle();
void ZeroCrossing();

/**************************WiF-Local-Action******************************/

int WiFLocalAction();

/**************************WiF-Cloud-Action******************************/

int ReadResponse();
int SendCloudData();
int ReadCloudData();

/**************************Manual-Action*********************************/

void ManualControl();

/**************************WifiConnect**********************************/

void Connect_WiFi();
void Smart_Config();
void WiFi_Status();
int Check_WiFi();