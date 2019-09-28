#include "../include/Customer.h"

Customer::Customer(){
}

int Customer::makeConversation(){
    std::cout << name << std::endl;
    return dialogue.showDialogue();
}