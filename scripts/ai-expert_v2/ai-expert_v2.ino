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
#include <DigiKeyboard.h>

void setup() {
  // Initialisation si nécessaire
}

void sendKeyPress(byte keyStroke, byte modifiers) {
    // Envoyer la touche appuyée avec modificateurs (si nécessaire)
    DigiKeyboard.sendKeyStroke(keyStroke, modifiers);
}

void releaseKey() {
    // Relâcher toutes les touches
    DigiKeyboard.sendKeyStroke(0);  // Envoie 0 pour signifier qu'aucune touche n'est pressée
}

void sendKeyStrokeWithHold(byte keyStroke, byte modifiers, uint16_t key_down_time) {
    // 1. Envoyer la touche appuyée
    sendKeyPress(keyStroke, modifiers);

    // 2. Maintenir la touche pendant la durée spécifiée (en millisecondes)
    for (uint16_t i = 0; i < key_down_time; i++) {
        DigiKeyboard.delay(1);  // Attendre pendant le temps spécifié
    }

    // 3. Relâcher la touche
    releaseKey();
}

void loop() {
    // Exemple : appuyer sur la touche 'A' sans modificateur pendant 500 ms
    sendKeyStrokeWithHold(KEY_A, 0, 500);

    // Boucle infinie pour éviter que le programme ne fasse rien après
    for(;;) {}
}
