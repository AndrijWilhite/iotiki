/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <bigkahuna.h>
#include <node.h>
#include <wiringPi.h>

BigKahuna::greeting() {
    
};

BigKahuna::dispense() {
    
};

BigKahuna::dispenseOverride() {
    
};

BigKahuna::eyesOn() {
    
};

BigKahuna::eyesOff() {
    
};

BigKahuna::partyTime() {
    if(mode > 0) {
        pinMode(pin, OUTPUT);
    } else {
        pinMode(pin, INPUT);
    }
}