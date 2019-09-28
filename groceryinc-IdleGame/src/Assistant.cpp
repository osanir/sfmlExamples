#include "../include/Assistant.h"

Assistant::Assistant(){
    name = "Adem Havva";
    cost = 25;
    friendliness = 0.5;
    dexterity = 0.7;
}

std::string Assistant::getName(){
    return name;
}

float Assistant::getCost(){
    return cost;
}

float Assistant::getFriendliness(){
    return friendliness;
}

float Assistant::getDexterity(){
    return dexterity;
}