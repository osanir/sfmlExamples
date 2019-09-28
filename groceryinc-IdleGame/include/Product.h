#include <string>
class Product{
public:
    Product();
    Product(std::string name, float price, int quantity);

private:
    std::string name;
    float price;
    int quantity;
};