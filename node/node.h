#include <string>
using namespace std;

class Node {
    private:
        string mac;
        string network_id;
        string encrypt_key;
        string known_networks[300];
    public:
        /* Constructor for only MAC address */
        Node();
        ~Node();
        
        /* Binds a socket listener for all UDP broadcasts */
        void listen();
        
        void broadcast(Message message);
        
        /* Creates a new Message object and broadcasts it */
        void createMessage(string content);
        
        /* */
        Message receiveMessage(char raw);
        
        /* Propagates a received message*/
        void propagate(Message message);
        
        /* Finds all available IOTiki networks on Subnet */
        string findAvailableNetworks();
        
        /* Asks to join a specific IOTiki network by Identifier */
        int attemptNetworkJoin(string network_id);
        
        /* Joins a network when it has gained permission and received key */
        int joinNetwork(string network_id, string encrypt_key);
        
        /* Finds all available networks and joins the first one by Id */
        int joinFirstAvailableNetwork();
        
        struct Message {
            string content;
            Message parse(string raw, string encrypt_key) {
                this->content = raw;
                this->decrypt(encrypt_key);
            };
            
            void encrypt(string encrypt_key) {
                
            };
            
            void decrypt(string encrypt_key) {
                
            };
        };
};