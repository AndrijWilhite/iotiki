//
//  main.cpp
//  node
//
//  Created by John Yates on 9/2/16.
//  Copyright © 2016 iotiki. All rights reserved.
//

#include <iostream>
#include "node.cpp"

int main(int argc, const char * argv[]) {
    string mac = "1234ABCD";
    Node *node = new Node(mac);
    string network_id = "hello";
    node->joinNetworkById(network_id);
    return 0;
}
