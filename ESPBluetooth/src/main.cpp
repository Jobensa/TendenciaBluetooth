#include <Arduino.h>
//#include <BlynkSimpleEsp32_BT.h>
#include "user.h"
//#include <SPI.h>
#include <BluetoothSerial.h>

//#include "user_bluetooth.h"

//Bluetooth
//char auth[] = "Token";

//uint8_t status_menu;
dataI_t dataI;

//uint16data_t value;

//BlynkTransportEsp32_BT connBluetooth;
BluetoothSerial SerialBT;
  
void setup() {
   Serial.begin(115200);
   //Blynk.setDeviceName("SenSASbt");    
   //connBluetooth.begin();  
    
  // Blynk.begin(auth);

  SerialBT.begin("SENSAS_Bt");
  
}

void loop() 
{
       //Bluetooth
     
    if(SerialBT.available()>=3)
    {
             
    }   
   
    if(dataI.valY>4999) dataI.valY=0;    
    dataI.valY++;  
    dataI.valX++;     
    SerialBT.write(dataI.values,sizeof(dataI.values));
    
    //Serial.println(value.value16);
    delay(5);

    //Serial.print(dataI.valY);
    //Serial.print(" ");
    //Serial.println(dataI.valX);
 
}