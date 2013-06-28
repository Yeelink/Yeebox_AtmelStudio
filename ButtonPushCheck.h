/*
 * Copyright (c) 2012 Yeelink.net by gordon tang
 */

#ifndef _BUTTONPUSHCHECK_h
#define _BUTTONPUSHCHECK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "CommonData.h"
class ButtonPushCheck
{
	 private:
	 class CommonData *_cmdata;
	 unsigned long buttonDownTime;

	 public:
	 //	unsigned long lastShortBtnPushTime;
	 void begin(CommonData *cmdata);
	 void loop();
	 void checkButtonPushLongTerm();
};


#endif

