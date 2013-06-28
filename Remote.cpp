/*
 * Copyright (c) 2013 Yeelink.net by dapingliu <dapingliu@yeelink.net>
 *
 * This file contains the Remote Control Client of YeeBox. It is used to communicate with
 * Yeelight server to get/put message remotely.
 *
 */

#include "Remote.h"
#include <stdlib.h>

//start SNSClient instance
void Remote::begin(CommonData *cmdata) {
	DNSClient dns;
	
	_cmdata = cmdata;
	connDownTime = 0;
	connHBTime = 0;
	connected = REMOTE_CONN_NOT_RESOLVED;

	//DNS resolve
	dns.begin(Ethernet.dnsServerIP());
  	if(1 == dns.getHostByName(YEELIGHT_SERVER_DOMAIN, remoteIP)) {
		connected = REMOTE_CONN_NOT_REQUEST;
		
		// If any authorized APP, connect to remote server
		if(EepromManage::getEepromWhiteListNum() > 0) {
			connect();
		}
  	}
}

void Remote::getAndSendMacFromEeprom(){
	char mac[E2DA_WHITE_LIST_MAC_LEN + 1];
	byte num = EepromManage::getEepromWhiteListNum();

	// num may be 1~20, if it exceeds 10, treat it as 10
	if(num > MAX_WHITE_LIST_NUM){
		num = MAX_WHITE_LIST_NUM;
	}

	//Send local mac
	for(int i=0; i<(E2DA_WHITE_LIST_MAC_LEN/2); i++) {
		sprintf(&mac[i*2], "%02X", this->_cmdata->mac[i]);
	}

	// Send local mac to remote server
	_client.write(YBOX_LOCAL_MAC);
	_client.write((unsigned char*)mac, E2DA_WHITE_LIST_MAC_LEN);
	_client.write("\n");

	//Send authorized app mac
	for(unsigned short i=0; i<num; i++) {
		EepromManage::getEepromWhiteListMacByIndex(mac, i);
		_client.write(APP_AUTH_MAC);
		_client.write((unsigned char*)mac, E2DA_WHITE_LIST_MAC_LEN);
		_client.write("\n");
	}
}

void Remote::connect() {
  	if(_client.connect(remoteIP, YEELIGHT_SERVER_PORT) == 1) {
		getAndSendMacFromEeprom();
		connected = REMOTE_CONN_CONNECTED;
	}
	else {
		connected = REMOTE_CONN_DISCONN;
		connDownTime = millis();
	}
	connHBTime = 0;
}

void Remote::sendMsgToServer(uint8_t* msg, uint8_t len) {
	if(connected == REMOTE_CONN_CONNECTED) {
		_client.write(msg, len);
	}
}

//used in main loop
void Remote::loop() {
	unsigned long currTime = millis();

	// if no remote server connected, just return
	if(connected == REMOTE_CONN_NOT_REQUEST || connected == REMOTE_CONN_NOT_RESOLVED){
		return;
	}

	// if the remote connection is not established, reconnect it.
	if(connected != REMOTE_CONN_CONNECTED){ 
		// reconect after 20s
		if( (currTime - connDownTime) > YEE_SERVER_RECONNECT_TIME) {
			connect();
		}
		return;
	}

	if( connHBTime != 0 && (currTime - connHBTime) > YEE_SERVER_HB_TIME){
		_client.stop();
		connected = REMOTE_CONN_DISCONN;
		connDownTime = currTime;
		return;
	}
	
	if(_client) {
		if (_client.connected()) {
			while (_client.available()) {
				connHBTime = currTime; // reset HB timer
				char c = _client.read();
				if ((c == '\n') || (_cmdata->mobile->_rxSize >= (REMOTE_RX_BUF_SIZE-2))) {
					//note: use mobile's buffer to receive the data 
					_cmdata->mobile->_rxBuf[_cmdata->mobile->_rxSize] = c;
					_cmdata->mobile->_rxSize++;

					_cmdata->leds->setGlobalFastFlash(500);
					// a message has been get out, handle it
					_cmdata->mobile->processMessage(&_client, _cmdata->mobile->_rxBuf, _cmdata->mobile->_rxSize);
					//reset buffer pointer
					_cmdata->mobile->_rxSize = 0;
					//this->_rxSize = 0;
				}
				else {
					_cmdata->mobile->_rxBuf[_cmdata->mobile->_rxSize] = c;
					_cmdata->mobile->_rxSize++;
				}
			}
			//no more data in W5100 buffer
			_cmdata->mobile->_rxSize = 0;
		}
		else{
			_client.stop();
			connected = REMOTE_CONN_DISCONN;
			connDownTime = currTime;
			connHBTime = 0;
		}
	}
}


