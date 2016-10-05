/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <wiringPi.h>
#include gpio.h

GPIO::dPinOn(int pin) {
    digitalWrite(pin, HIGH);
    return 1;
};

GPIO::dPinOff(int pin) {
    digitalWrite(pin, LOW);
    return 1;
};

GPIO::aPinOn(int pin, int val) {
    analogWrite(pin, val);
    return 1;
};

GPIO::aPinOff(int pin) {
    analogWrite(pin, 0);
    return 1;
};

GPIO::pinState(int pin) {
    return digitalRead(pin);
};

GPIO::algPinState(int pin) {
    return analogRead(pin);
};

GPIO::allOff() {
    for(var i=0; i<maxPin; i++) {}
};