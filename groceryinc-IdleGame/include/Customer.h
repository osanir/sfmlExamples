#include <string>
#include "Dialogue.h"
class Customer{
public:
    Customer();
    int makeConversation();
private:
    std::string name;
    Dialogue dialogue;
};