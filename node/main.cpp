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
    Node *node = new Node();
    node->joinFirstAvailableNetwork();
    return 1;
}
