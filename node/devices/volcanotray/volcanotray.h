/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   volcanotray.h
 * Author: johnyates
 *
 * Created on October 16, 2016, 11:34 AM
 */

class VolcanoTray: public Node {
    private:
    public:
        void shake(int seconds);
        void shakeOn();
        void shakeOff();
        void lightsOn();
        void lightsOff();
};

