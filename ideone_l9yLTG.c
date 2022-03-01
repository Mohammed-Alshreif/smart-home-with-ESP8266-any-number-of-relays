#include "DHT.h"
#define DHTPIN D4    
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
//################################
 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>
 
#include <RemoteXY.h>
 
// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "*******************"
#define REMOTEXY_WIFI_PASSWORD "***************"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "########################"// the platform will give you this
 
 
// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,24,0,2,0,135,1,10,117,2,
  2,0,0,1,22,11,1,1,22,11,
  34,25,31,31,79,78,0,79,70,70,
  0,2,0,22,1,22,11,1,12,22,
  11,34,25,31,31,79,78,0,79,70,
  70,0,7,12,48,53,36,9,36,90,
  26,9,3,26,2,2,7,12,4,53,
  36,9,0,90,27,9,3,26,33,2,
  2,0,44,1,22,11,1,23,22,11,
  34,25,31,31,79,78,0,79,70,70,
  0,2,0,66,1,22,11,1,34,22,
  11,34,25,31,31,79,78,0,79,70,
  70,0,2,0,0,13,22,11,1,45,
  22,11,34,25,31,31,79,78,0,79,
  70,70,0,2,0,22,13,22,11,1,
  56,22,11,34,25,31,31,79,78,0,
  79,70,70,0,2,0,44,13,22,11,
  1,67,22,11,34,25,31,31,79,78,
  0,79,70,70,0,2,0,66,13,22,
  11,1,78,22,11,34,25,31,31,79,
  78,0,79,70,70,0,2,0,0,26,
  22,11,40,1,22,11,34,25,31,31,
  79,78,0,79,70,70,0,2,0,22,
  26,22,11,40,12,22,11,34,25,31,
  31,79,78,0,79,70,70,0,2,0,
  44,26,22,11,40,23,22,11,34,25,
  31,31,79,78,0,79,70,70,0,2,
  0,66,26,22,11,40,34,22,11,34,
  25,31,31,79,78,0,79,70,70,0,
  2,0,0,38,22,11,40,45,22,11,
  34,25,31,31,79,78,0,79,70,70,
  0,2,0,22,38,22,11,40,56,22,
  11,34,25,31,31,79,78,0,79,70,
  70,0,2,0,44,38,22,11,40,67,
  22,11,34,25,31,31,79,78,0,79,
  70,70,0,2,0,66,38,22,11,40,
  78,22,11,34,25,31,31,79,78,0,
  79,70,70,0,66,1,90,36,9,25,
  26,54,10,35,2,26,66,0,89,1,
  10,27,26,13,10,35,2,26 };
 
// this structure defines all the variables and events of your control interface 
struct {
 
    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  float HUMIDITY;
  float TEMP;
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 
  uint8_t switch_5; // =1 if switch ON and =0 if OFF 
  uint8_t switch_6; // =1 if switch ON and =0 if OFF 
  uint8_t switch_7; // =1 if switch ON and =0 if OFF 
  uint8_t switch_8; // =1 if switch ON and =0 if OFF 
  uint8_t switch_9; // =1 if switch ON and =0 if OFF 
  uint8_t switch_10; // =1 if switch ON and =0 if OFF 
  uint8_t switch_11; // =1 if switch ON and =0 if OFF 
  uint8_t switch_12; // =1 if switch ON and =0 if OFF 
  uint8_t switch_13; // =1 if switch ON and =0 if OFF 
  uint8_t switch_14; // =1 if switch ON and =0 if OFF 
  uint8_t switch_15; // =1 if switch ON and =0 if OFF 
  uint8_t switch_16; // =1 if switch ON and =0 if OFF 
 
    // output variables
  int8_t TEMP1; // =0..100 level position 
  int8_t HUMIDITY1; // =0..100 level position 
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 
 
 
} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
 
#define ser D1
#define latch D2
#define clk D3
void setup() 
{
  RemoteXY_Init (); 
 
  pinMode (ser, OUTPUT);
  pinMode (latch, OUTPUT);
  pinMode (clk, OUTPUT);
  // TODO you setup code
 
}
void dht1(){
   float h = dht.readHumidity();
  float t = dht.readTemperature();
   RemoteXY.HUMIDITY1=h;
   RemoteXY.TEMP1=t;
 RemoteXY.HUMIDITY=h;
   RemoteXY.TEMP=t;
}
 
 
void loop() 
{ 
  RemoteXY_Handler ();
 
   dht1();
 
 digitalWrite(latch,LOW);
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_1==0)?HIGH:LOW);//////////1
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_2==0)?HIGH:LOW);//////////2
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_3==0)?HIGH:LOW);//////////3
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_4==0)?HIGH:LOW);//////////4
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_5==0)?HIGH:LOW);//////////5
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_6==0)?HIGH:LOW);//////////6
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_7==0)?HIGH:LOW);//////////7
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_8==0)?HIGH:LOW);//////////8
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_9==0)?HIGH:LOW);//////////9
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_10==0)?HIGH:LOW);//////////10
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_11==0)?HIGH:LOW);//////////11
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_12==0)?HIGH:LOW);//////////12
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_13==0)?HIGH:LOW);//////////13
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_14==0)?HIGH:LOW);//////////14
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_15==0)?HIGH:LOW);//////////15
digitalWrite(clk,LOW);
digitalWrite(clk,HIGH);
digitalWrite(ser, (RemoteXY.switch_16==0)?HIGH:LOW);//////////16
digitalWrite(clk,LOW);
 
digitalWrite(clk,HIGH);
digitalWrite(ser,LOW);//
digitalWrite(latch,HIGH);
 
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
 
 
}