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

void setup() {
  DigiKeyboard.sendKeyStroke(0);
}

void loop() {
  // Appuie sur la touche 'A'
  DigiKeyboard.sendKeyStroke(KEY_A);

  // Attend 2 secondes (2000 millisecondes)
  delay(2000);

  // Relâche toutes les touches (au cas où)
  DigiKeyboard.sendKeyStroke(0);

  for(;;) {}
}

