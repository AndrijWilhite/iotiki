#include <string>
using namespace std;
const string st_blk = "";
const string end_blk = "";
const string decl_id = "";
const string msg_type = "";

class Message {
    private:
    public:
        string content;
        Message(string message);
        int broadcast();
};