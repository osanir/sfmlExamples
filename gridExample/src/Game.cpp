#include "../include/Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Rider", Style::Default) {
    window.setFramerateLimit(24);
    windowCenter.x = SCREEN_WIDTH/2;
    windowCenter.y = SCREEN_HEIGHT/2;
    horizon.x = SCREEN_WIDTH/2;
    horizon.y = 0;
    srand(time(NULL));
    
    gridSize = 16;
}

void Game::run(){
    createGrids();
    Clock clock;
    clock.restart();
    while(window.isOpen() ){
        processEvents(clock);
        update();
        render();
    }
}

void Game::processEvents(Clock clock){
    Event e;
    while( window.pollEvent(e) ){
        switch (e.type){
            case Event::Closed:
                window.close();
                break;
            default:
                break;
        }
        if( clock.getElapsedTime().asSeconds() > 1){
            clock.restart();
            if( Keyboard::isKeyPressed(Keyboard::D) ){
                player.pos.x += gridSize;
            }
            if( Keyboard::isKeyPressed(Keyboard::A) ){
                player.pos.x -= gridSize;
            }
            if( Keyboard::isKeyPressed(Keyboard::W) ){
                player.pos.y -= gridSize;
            }
            if( Keyboard::isKeyPressed(Keyboard::S) ){
                player.pos.y += gridSize;
            }
            player.move();
            //player.body.setPosition(player.pos);
        }
    }
}

void Game::update(){
}

void Game::render(){
    window.clear(Color::White);

    drawLines();
    window.draw(player.body);

    window.display();
}

float Game::lerp(float x, float y, float z) {
    return ((1.0f - z) * x) + (z * y);      
}

void Game::createGrids(){
    for(float i=0; i<SCREEN_WIDTH; i = i+gridSize){
        RectangleShape* rect = new RectangleShape();
        rect->setSize({1, SCREEN_HEIGHT});
        rect->setPosition({i, 0});
        rect->setFillColor(Color::Black);
        lines.push_back(rect);
    }

    for(float i=0; i<SCREEN_HEIGHT; i = i+gridSize){
        RectangleShape* rect = new RectangleShape();
        rect->setSize({SCREEN_WIDTH, 1});
        rect->setPosition({0, i});
        rect->setFillColor(Color::Black);
        lines.push_back(rect);
    }
}

void Game::drawLines(){
    for(auto line : lines){
        window.draw(*line);
    }
}