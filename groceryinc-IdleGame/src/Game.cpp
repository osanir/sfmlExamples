#include "../include/Game.h"

Game::Game(){
    money = 100;
    happiness = 100; // 100/200
}

void Game::run(){
    while(1){
        work();
        edit();
    }
}

void Game::work(){
    if( grocer.isOpen() ){
        for(auto customer : customers){
            std::cout << "Happines: " << happiness << std::endl; 
            happiness += customer.makeConversation();
        }
    }

}

void Game::edit(){

}