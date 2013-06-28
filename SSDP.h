/*
 * Copyright (c) 2012 Yeelink.net by dapingliu <dapingliu@yeelink.net>
 */

#ifndef _SSDP_h
#define _SSDP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Ethernet.h>
#include <EthernetUdp.h>
#include "CommonData.h"

class SSDP
{
	private:
	class CommonData *_cmdata;
	EthernetUDP _udp;
	public:
	void begin(CommonData *cmdata);
	void loop();
};

#endif

