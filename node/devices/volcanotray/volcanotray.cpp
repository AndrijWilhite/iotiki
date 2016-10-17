/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "node.h";
#include <wiringPi.h>;
#include "volcanotray.h"

VolcanoTray::shake(int seconds) {
    this->shakeOn();
    delay(seconds*1000);
    this->shakeOff();
};

VolcanoTray::shakeOn() {
    digitalWrite(this->shakePin, HIGH);
};

VolcanoTray::shakeOff() {
    digitalWrite(this->shakePin, LOW);
};

VolcanoTray::lightsOn() {
    digitalWrite(this->lightPin, HIGH);
};

VolcanoTray::lightsOff() {
    digitalWrite(this->lightPin, LOW);
};

