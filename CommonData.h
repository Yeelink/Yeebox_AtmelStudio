/*
 * Copyright (c) 2012 Yeelink.net by dapingliu <dapingliu@yeelink.net>
 */

#ifndef _COMMONDATA_h
#define _COMMONDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Defines.h"
#include "BoxLogic.h"
#include "SSDP.h"
#include "Mobile.h"
#include "BoxCOM.h"
#include "StatusLED.h"
#include "EepromManage.h"
#include "ButtonPushCheck.h"
#include "Remote.h"

class CommonData
{
	public:
	byte mac[E2DA_BOX_MAC_LEN]; //MAC address for YeeBox
	unsigned char version[E2DA_VERSION_LEN];
	byte key[E2DA_BOX_KEY_LEN+1];
	uint8_t deviceCount;
	device_node_t deviceList[MAX_SUPPORTED_LAMPS]; //list to store lamp status

	//Box mode related
	boxMode_t _mode;
	unsigned long _waitStartTime;

	//pointer to each component
	class BoxLogic *logic;
	class SSDP *ssdp;
	class Mobile *mobile;
	class BoxCOM *com;
	class StatusLED *leds;
	class ButtonPushCheck *btn;
	class Remote *remote;

	void setup();
	bool addNewDevice(char* mac, uint8_t type);
	bool isNumorLetter(char *c);
};

#endif

