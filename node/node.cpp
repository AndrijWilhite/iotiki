/*
 * Author: John Yates
 * Date: 2016/9/9
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "node.h"
#include "message.cpp"
#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

Node::Node(string mac) {
    this->mac = mac;
};

int main(int argc, const char * argv[]) {
    string mac = "1234ABCD";
    Node *node = new Node(mac);
    string network_id = "hello";
    node->joinNetworkById(network_id);
    string message = "0011FFEE00";
    node->createMessage(message);
    return 1;
}

void Node::listen() {
    sockaddr_in si_me, si_other;
    int s;
    assert((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))!=-1);
    int port=6000;
    int broadcast=1;

    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);

    memset(&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = INADDR_ANY;

    assert(::bind(s, (sockaddr *)&si_me, sizeof(sockaddr))!=-1);

    while(1) {
        char buf[10000];
        unsigned slen=sizeof(sockaddr);
        recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);
        printf("received: %s\n", buf);
        this->receiveMessage(buf);
    }
};

/* Broadcasts a message to all clients on subnet */
int Node::createMessage(string message) {
    Message* msg = new Message(message);
    msg->broadcast();
    return 1;
};

string Node::receiveMessage(string message) {
    return message;
};

int Node::propagate(string message) {
    cout << "Propagating " << message << endl;
    this->createMessage(message);
    return 1;
};
        
/* Finds all available IOTiki networks on subnet */
int Node::findAvailableNetworks() {
    return 1;
};

/* Joins a specific IOTiki network by Identifier */
int Node::joinNetworkById(string id) {
    this->network_id = id;
    std::cout << "Joining Network with Id " << id << "." << endl;
    return 1;
};

/* Finds all available networks and joins the first one by Id */
int Node::joinFirstAvailableNetwork() {
    return 1;
};