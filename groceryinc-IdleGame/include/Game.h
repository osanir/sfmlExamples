#include "Grocer.h"

class Game{
public:
    Game();
    void run();
    void work();
    void edit();
private:
    Grocer grocer;
    float money;
    float happiness;
    float security;
    Customer customers[10];
};