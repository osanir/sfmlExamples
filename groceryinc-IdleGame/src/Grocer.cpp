#include "../include/Grocer.h"

Grocer::Grocer(){
    groceryIsOpen = true;
}

void Grocer::openGrocery(){
    groceryIsOpen = true;
}

void Grocer::closeGrocery(){
    groceryIsOpen= false;
}


// Getters & Setters

bool Grocer::isOpen(){
    return groceryIsOpen;
}

int Grocer::getCustomerCapacity(){
    return customerCapacity;
}

int Grocer::getProductCapacity(){
    return productCapacity;
}

int Grocer::setCustomerCapacity(int val){
    customerCapacity = val;
}

int Grocer::setProductCapacity(int val){
    productCapacity = val;
}