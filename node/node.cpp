/*
 * Author: John Yates
 * Date: 2016/9/9
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "node.h"
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

Node::Node() {
    this->mac = 0; //TODO get MAC
};

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
        unsigned slen = sizeof(sockaddr);
        recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);
        printf("received: %s\n", buf);
        this->receiveMessage(buf);
    }
};

void Node::broadcast(Message message) {
    message->encrypt(this->encrypt_key);
};

/* Broadcasts a message to all clients on subnet */
void Node::createMessage(string content) {
    Message* message = new Message(message);
    this->broadcast(message);
};

Node::Message Node::receiveMessage(char raw) {
    Message message = new Message;
    message->parse(raw, this->encrypt_key);
    return message;
};

void Node::propagate(Message message) {
    cout << "Propagating " << message->content << endl;
    this->createMessage(message);
    return 1;
};

/* Asks to join a specific IOTiki network by Identifier */
int Node::attemptNetworkJoin(string network_id) {
    std::cout << "Asking to join Network with Id " << network_id << "..." << endl;
    return 1;
};

int joinNetwork(string network_id, string encrypt_key) {
    this->network_id = network_id;
    this->encrypt_key = encrypt_key;
};

/* Finds all available IOTiki networks on subnet */
string Node::findAvailableNetworks() {
    string networks[10] = {}; 
    return networks;
};

/* Finds all available networks and joins the first one by Id */
int Node::joinFirstAvailableNetwork() {
    std::cout << "Joining first available network..." << endl;
    string networks[] = this->findAvailableNetworks();
    if(networks[0]) {
        this->attemptNetworkJoin(networks[0]);
        return 1;
    } else {
        return 0;
    }
};