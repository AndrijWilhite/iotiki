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

Message::Message(string message) {
    this->content = st_blk+decl_id+end_blk+st_blk+message+end_blk;
};

int Message::broadcast() {
    cout << "Sending message: " << this->content << endl;
    return 1;
};

