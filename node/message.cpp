/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   message.cpp
 * Author: johnyates
 *
 * Created on September 2, 2016, 9:34 AM
 */
#include "message.h"
#include <iostream>
using namespace std;

//Message Reference - Allows for 6 Capabilities per Type per node Type
//00 - Party Time (Initiate Party Mode)
//01 - Lighting Scope
//0100 - All Lights Off
//01FF - All Lights On
//010x - Light x Off
//01Fx - Light x On
//02 - Sensor Scope
//0200 - All Sensors Sleep
//02FF - All Sensors Wakeup
//020x - Sensor x Sleep
//02Fx - Sensor x Wakeup
//03 - Action Scope
//0300 - All Actions Stop
//03FF - All Actions Start
//030x - Action x Stop
//03Fx - Action x Start
//04 - Vocalization Scope
//0400 - All Vocalizations Stop
//04FF - All Vocalizations Start
//040x - Vocalization x Stop
//04Fx - Vocalization x Start

Message::Message(char message[]) {
    this->content = st_blk+decl_id+end_blk+st_blk+message+end_blk;
};

int Message::broadcast() {
    cout << "Sending message: " << this->content << endl;
    return 1;
};

