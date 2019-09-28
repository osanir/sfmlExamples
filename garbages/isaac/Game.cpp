#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Default) {

}

void Game::run(){
    while( window.isOpen() ){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    Event e;
    while( window.pollEvent(e) ){
        switch ( e.type ){
            case 1:
                break;
            default:
                break;
        }
    }
}

void Game::update(){

}

void Game::render(){
    window.clear(Color::White);
    //window.draw();
    window.display();
}