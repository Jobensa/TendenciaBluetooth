#include "user.h"
#include "user_bluetooth.h"
//Bluetooth
#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BT.h>
extern char mensajes[10][32];
typedef union 
{
  struct 
  {
      float valY;
      float valX;
  };
  uint8_t values[16];
  
}user_data;

typedef union 
{
  struct 
  {  
      uint8_t length;  
      uint8_t code;
      uint8_t command;
      uint8_t ind;
      char *data;
  };
  uint8_t data_stream[37];
}protocol_t;



//Bluetooth
char auth[] = "Token";

uint8_t status_menu;

BlynkTransportEsp32_BT connBluetooth;

void Task_bluetooth(void* parameter)
{

  //Bluetooth
  
  Blynk.setDeviceName("DisproBT");
  Blynk.begin(auth);
 
  connBluetooth.begin();
  //status_menu=0;
  //user_data data;
  protocol_t request;
  strcpy(mensajes[0],"Mensaje 1");
  strcpy(mensajes[1],"Mensaje 2");
  strcpy(mensajes[2],"Mensaje 3");
  strcpy(mensajes[3],"Mensaje 4");
  strcpy(mensajes[4],"Mensaje 5");

  strcpy(mensajes[5],"Mensaje 6");
  strcpy(mensajes[6],"Mensaje 7");
  strcpy(mensajes[7],"Mensaje 8");
  strcpy(mensajes[8],"Mensaje 9");
  strcpy(mensajes[9],"Mensaje 10");


  for(;;)
  {
       //Bluetooth
    Blynk.run();

  
    
    if(connBluetooth.available()>=3)
    {
        
        //String str1=WiFi.localIP().toString();
        
        
        connBluetooth.read(request.data_stream,connBluetooth.available());
        if (request.code!=123)continue;

        switch (request.command)
        {
        case 1:  //Mensajes de lectura          
          strcpy(request.data,mensajes[request.ind]);
          connBluetooth.write(request.data_stream,sizeof(request)+strlen(mensajes[request.ind]));
          break;

        case 2:  //Mensaje de escritura       
          strcpy(mensajes[request.ind],request.data);
          break;

        case 3: //Rotar a la izquierda

          break;  
        default:
          break;
        }      


        Serial.println(request.code);      
        String s="Configuración,12345";         
        connBluetooth.write(s.c_str(),s.length()+1);
     
   }   
   
   

  /*
    if(data.valY>4.99) data.valY=0.01;
    
    data.valY+=0.001;

    data.valX+=1.0;    
    connBluetooth.write(data.values,sizeof(data.values));
    */
    vTaskDelay(10);
  }
  
}