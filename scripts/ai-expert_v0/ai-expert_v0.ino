#include <DigiKeyboard.h>
#include <keylayouts.h>
#include <oddebug.h>
#include <osccal.h>
#include <osctune.h>
#include <scancode-ascii-table.h>
#include <usbboardconfig.h>
#include <usbconfig-prototype.h>
#include <usbconfig.h>
#include <usbdrv.h>
#include <usbportability.h>

//Flèche gauche : 80
//Flèche droite : 79
//Flèche haut : 82
//Flèche bas : 81

#include <usbdrv.h>
#include <util/delay.h>

static uchar reportBuffer[2];  // Définition du buffer de rapport global (2 octets : modificateur et touche)


void setup() {
  DigiKeyboard.sendKeyStroke(0);
}

void sendKeyStroke(byte keyStroke, byte modifiers, uint16_t key_down_time) {
   	while (!usbInterruptIsReady()) {
      // Note: We wait until we can send keystroke
      //       so we know the previous keystroke was
      //       sent.
    	usbPoll();
    	_delay_ms(5);
    }
    
    memset(reportBuffer, 0, sizeof(reportBuffer));
		
    reportBuffer[0] = modifiers;
    reportBuffer[1] = keyStroke;
    
    usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
		
  	while (!usbInterruptIsReady()) {
      // Note: We wait until we can send keystroke
      //       so we know the previous keystroke was
      //       sent.
    	usbPoll();
    	_delay_ms(5);
    }
	
	// Pressing time (in milliseconds) that the key remains pressed
	// until is released. If is zero don't release the key (it should be
	// done manually by sendKeysStroke(0). Therefore minimum time is 1ms
	// and the maximum is 65535ms.
	if (key_down_time) {
		while (key_down_time--) {
			usbPoll();      
			_delay_ms(1);
		}
		// Now send 'no key' pressed
		memset(reportBuffer, 0, sizeof(reportBuffer));
		usbSetInterrupt(reportBuffer, sizeof(reportBuffer));	
	} 
  }

void pressAndHold(uint8_t key, int duration) {
  DigiKeyboard.sendKeyPress(key);  // Maintenir la touche appuyée
  DigiKeyboard.delay(duration);    // Attendre la durée spécifiée (en ms)
  DigiKeyboard.sendKeyStroke(0);   // Relâcher la touche
}

void loop() {
  //pressAndHold(79, 2840)
  //pressAndHold(81, 3960)
  //pressAndHold(82, 850)
  //pressAndHold(80, 400)
  //pressAndHold(82, 4080)
  //pressAndHold(80, 1330)
  //pressAndHold(82, 2010)
  //pressAndHold(79, 500)
  //pressAndHold(82, 1450)
  //pressAndHold(80, 1010)
  //pressAndHold(82, 1870)
  //pressAndHold(79, 1010)
  //pressAndHold(82, 1380)
  //pressAndHold(4, 2000);
  DigiKeyboard.sendKeyStroke(KEY_A,0,300); // Send an A to host, takes 300ms until release

  DigiKeyboard.sendKeyStroke(KEY_C,0,0);    //Send a C to host and keep it pushed
  DigiKeyboard.delay(2000);                 // wait 2 seconds
  DigiKeyboard.sendKeyStroke(0);            // now release any key pressed.

  for(;;) {}

}
