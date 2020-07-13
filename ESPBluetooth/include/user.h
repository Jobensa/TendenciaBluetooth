#ifndef USER_H
#define USER_H
#include <stdint.h>
#include <Arduino.h>
//#include "RTClib.h"

typedef union 
{
    struct 
    {
        uint8_t dummy;
        unsigned dummy2:7;
        unsigned DN:1;
    };
    uint16_t Preset;
}SENSAS_TIMER;

/*
extern SENSAS_TIMER tmr_test;
extern SENSAS_TIMER tmr_serial;
extern SENSAS_TIMER tmr_rtc;
*/
//extern RTC_Micros rtc;
extern String DateTimeWiFi;
#endif