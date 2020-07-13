#include "user.h"
#include "user_bluetooth.h"
//Bluetooth
#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BT.h>

#include "user.h"

//Bluetooth
char auth[] = "Token";

uint8_t status_menu;
user_data data;

BlynkTransportEsp32_BT connBluetooth;

void Task_bluetooth(void* parameter)
{

  //Bluetooth
  
  Blynk.setDeviceName("DisproBT");
  Blynk.begin(auth);
 
  connBluetooth.begin();  
 

  
  for(;;)
  {
       //Bluetooth
    Blynk.run();

  
    
    if(connBluetooth.available()>=3)
    {
        
     
    }   
   
    if(data.valY>4.99) data.valY=0.01;
    
    data.valY+=0.001;

    data.valX+=1.0;    
    connBluetooth.write(data.values,sizeof(data.values));
    
    vTaskDelay(10);
  }
  
}