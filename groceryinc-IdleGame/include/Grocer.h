#include <list>
#include "Assistant.h"
#include "Product.h"
#include "Customer.h"

class Grocer{
public:
    Grocer();

    void openGrocery();
    void closeGrocery();

    bool isOpen();
    int getCustomerCapacity();
    int getProductCapacity();
    int setCustomerCapacity(int);
    int setProductCapacity(int);
private:
    bool groceryIsOpen;
    int customerCapacity;
    int productCapacity;
    int assistantCapacity;
    
    std::list<Assistant> assistants;
    std::list<Product> products;
};