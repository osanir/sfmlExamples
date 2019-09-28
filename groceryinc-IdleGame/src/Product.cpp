#include "../include/Product.h"

Product::Product(){
    name = "UNDEFINED";
    price = 0;
    quantity = 0;
}

Product::Product(std::string pName, float pPrice, int pQuantity){
    name = pName;
    price = pPrice;
    quantity = pQuantity;
}