#include <string>
using namespace std;

class Node {
    private:
        string mac;
        string network_id;
        string known_networks[300];
    public:
        /* Constructor for only MAC address */
        Node(string mac);
        
        /* Binds a socket listener for all UDP broadcasts */
        void listen();
        
        /* Creates a new Message object and broadcasts it */
        int createMessage(string message);
        
        /* */
        string receiveMessage(string message);
        
        /* Propagates a received message*/
        int propagate(string message);
        
        /* Finds all available IOTiki networks on Subnet */
        int findAvailableNetworks();
        
        /* Joins a specific IOTiki network by Identifier */
        int joinNetworkById(string id);
        
        /* Finds all available networks and joins the first one by Id */
        int joinFirstAvailableNetwork();
};