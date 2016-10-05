/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gpio.h
 * Author: johnyates
 *
 * Created on October 5, 2016, 9:46 AM
 */

#ifndef GPIO_H
#define GPIO_H



#endif /* GPIO_H */
class GPIO {
    private:
    public:
        int pinMode(int pin, int mode);
        int dPinOn(int pin);
        int dPinOff(int pin);
        int aPinOn(int pin, int val);
        int aPinOff(int pin);
        int dPinState(int pin);
        int aPinState(int pin);
        void allOff();      
};

