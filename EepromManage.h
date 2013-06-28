/*
 * Copyright (c) 2012 Yeelink.net by gordon
 */

#ifndef _EEPROMMANAGE_h
#define _EEPROMMANAGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Defines.h"
namespace EepromManage {
	//	void getEepromLogo(unsigned char* logo);
	void getEepromVersion(unsigned char* version);
	void getEepromMac(unsigned char* mac);
	//	void getEepromBoxId(unsigned char* id);
	void getEepromBoxKey(unsigned char* key);
	//	void getEepromFaceBook(unsigned char* facebook);
	unsigned short getEepromDeviceNum();
	void getEepromDeviceList(eeprom_device_list_t* deviceList, unsigned short num);
	bool checkEepromDeviceByMac(unsigned char* mac);
	//	void setEepromLogo(unsigned char* logo);
	//	void setEepromVersion(unsigned char* version);
	//	void setEepromMac(unsigned char* mac);
	//	void setEepromFaceBook(unsigned char* facebook);
	void setEepromDeviceNum(unsigned short num);
	//	void setEepromDeviceList(eeprom_device_list_t* deviceList, unsigned short num);
	void AddEepromDeviceList(eeprom_device_list_t deviceList);
	//	void RemoveEepromDeviceFromList(unsigned char* mac);
	byte getEepromWhiteListNum();
	void getEepromWhiteListMacByIndex(char* mac, uint8_t index);
	void setEepromWhiteListNum(byte num);
	bool checkEepromWhiteListByMac(char* mac);
	void AddEepromMacToWhiteList(char* mac);
	void resetEepromData();
	uint32_t GetHash(char *fun_name);
};

#endif

