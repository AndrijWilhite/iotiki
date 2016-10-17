/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <bigkahuna.h>
#include <node.h>
#include <wiringPi.h>

BigKahuna::greeting() {
    digitalWrite(this->greetingPin, HIGH);
    delay(1000);
    digitalWrite(this->greetingPin, LOW);
};

BigKahuna::dispense() {
    digitalWrite(this->dispensePin, HIGH);
    delay(5000);
    digitalWrite(this->dispensePin, LOW);
};

BigKahuna::dispenseOverride() {
    digitalWrite(this->dispensePin, LOW);
};

BigKahuna::eyesOn() {
    digitalWrite(this->lightPin, HIGH);
};

BigKahuna::eyesOff() {
    digitalWrite(this->lightPin, LOW);
};

BigKahuna::startParty() {
    this->partyTime = 1;
    this->dispense();
    this->greeting();
    while(this->partyTime) {
        this->eyesOn();
        delay(2000);
        this->eyesOff();
        delay(2000);
    }
}

BigKahuna::stopParty() {
    this->partyTime = 0;
    this->dispenseOverride();
    this->eyesOff();
}