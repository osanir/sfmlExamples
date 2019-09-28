#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Booster{
public:
    Booster(string name, double rate, double price);
    
    void addPiece();
    double harvest();

    // GETTERS    
    string getName();
    double getRate();
    double getPrice();
    int    getPiece();
private:
    string _name;
    double _rate;
    double _price;
    int _piece;
};

class BoosterList{
public:
    BoosterList();
    bool addBooster(int pick);
    void harvestAll();
    void addCookie();

    void createBoosters();
    void printBoosters();

    vector<Booster> getBoosters();
private:
    double _totalEarnings;
    vector<string> _boosterNames;
    vector<Booster> _boosters;
};