/*
 * Copyright (c) 2012 Yeelink.net by dapingliu <dapingliu@yeelink.net>
 */

#ifndef _BOXLOGIC_h
#define _BOXLOGIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Defines.h"
#include "CommonData.h"

class BoxLogic
{
	 private:
	 class CommonData *_cmdata;
	 public:
	 void begin(CommonData *cmdata);
	 void loop();

	 //when there is a device status message comes from zigbee network
	 void updateDeviceStatus(char* mac, uint8_t type, char *online, char *R, char *G,
	 char *B, char *L, char *powerStatus, char *LQI, bool isNewDevice);
	 void deviceOnlineChange(uint8_t deviceIndex, bool online, bool isNewDevice);
};

#endif

