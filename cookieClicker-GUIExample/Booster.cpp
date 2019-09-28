#include "Booster.h"

Booster::Booster(string name, double rate, double price){
    _name = name;
    _rate = rate;
    _price = price;
    _piece = 0;

}

void Booster::addPiece(){
    _piece++;
    _price *= 1.2;
}

double Booster::harvest(){
    return _piece * _rate;
}

// GETTERS
string Booster::getName(){
    return _name;
}

double Booster::getRate(){
    return _rate;
}

double Booster::getPrice(){
    return _price;
}

int Booster::getPiece(){
    return _piece;
}



////// BOOSTER LIST //////

BoosterList::BoosterList()
:_boosterNames({"Cursor", "Grandma", "Farm", "Mine", "Factory", "Bank", "Temple", "Wizard"})
{
    _totalEarnings = 0;
}

bool BoosterList::addBooster(int pick){
    if(_boosters.size() < pick ){
        return false;
    }
    if( _totalEarnings < _boosters[pick].getPrice() ){
        return false;
    }

    _totalEarnings -= _boosters[pick].getPrice();
    _boosters[pick].addPiece();
}

void BoosterList::harvestAll(){
    for( auto booster : _boosters ){
        _totalEarnings += booster.harvest();
    }
    // print
    //printBoosters();
}

void BoosterList::addCookie(){
    _totalEarnings += 1;
}

void BoosterList::createBoosters(){
    Booster newBooster(_boosterNames[0], 0.1, 10.0);
    _boosters.push_back(newBooster);
    for(int i=1; i<_boosterNames.size(); i++){
        Booster newBooster(_boosterNames[i], _boosters[i-1].getRate()*6.28318,  _boosters[i-1].getPrice()*6);
        _boosters.push_back(newBooster);
    }
}

void BoosterList::printBoosters(){
    cout << string(100, '\n');
    cout << "      Name     Piece      Rate     Price     Per second" << endl;
    for(auto booster : _boosters){
        printf("%10s", booster.getName().c_str());
        printf("%10d", booster.getPiece());
        printf("%10.1lf", booster.getRate());
        printf("%10.0lf", booster.getPrice());
        printf("%15.1lf", booster.getPiece()*booster.getRate());
        cout << endl;
    }

    cout << "Total Earnings : " << _totalEarnings << endl << endl;
}

vector<Booster> BoosterList::getBoosters(){
    return _boosters;
}
