//Board = Arduino Uno
#define __AVR_ATmega328P__
#define ARDUINO 101
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

void wdtSetup();
//
//

#include "D:\Program Files\arduino-1.0.1\hardware\arduino\variants\standard\pins_arduino.h" 
#include "D:\Program Files\arduino-1.0.1\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Yeebox_AtmelStudio.ino"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\BoxCOM.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\BoxCOM.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\BoxLogic.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\BoxLogic.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\ButtonPushCheck.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\ButtonPushCheck.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\CommonData.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\CommonData.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Defines.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\EepromManage.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\EepromManage.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Mobile.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Mobile.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Remote.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\Remote.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\SSDP.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\SSDP.h"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\StatusLED.cpp"
#include "C:\Users\Administrator\Documents\GitHub\Yeebox_AtmelStudio\StatusLED.h"
