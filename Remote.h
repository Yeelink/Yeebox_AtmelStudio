/*
 * Copyright (c) 2012 Yeelink.net by dapingliu <dapingliu@yeelink.net>
 */

#ifndef _REMOTE_h
#define _REMOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Ethernet.h>
#include <EthernetUdp.h>
#include "CommonData.h"
#include "dns.h"

#define REMOTE_RX_BUF_SIZE		64
#define YEE_SERVER_RECONNECT_TIME 20000
#define YEE_SERVER_HB_TIME 30000

// Identify remote connection status
#define REMOTE_CONN_NOT_REQUEST 1
#define REMOTE_CONN_DISCONN 2
#define REMOTE_CONN_CONNECTED 3
#define REMOTE_CONN_NOT_RESOLVED 4
class Remote
{
	private:
	class CommonData *_cmdata;
	IPAddress remoteIP;
	unsigned long connDownTime;
	unsigned long connHBTime;

	public:
	EthernetClient _client;
	byte connected;
	void begin(CommonData *cmdata);
	void loop();
	void getAndSendMacFromEeprom();
	void connect();
	void sendMsgToServer(uint8_t* msg, uint8_t len);
};

#endif

