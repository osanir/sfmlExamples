#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Rider", Style::Default) {
    window.setFramerateLimit(24);
    windowCenter.x = SCREEN_WIDTH/2;
    windowCenter.y = SCREEN_HEIGHT/2;
    horizon.x = SCREEN_WIDTH/2;
    horizon.y = 0;
    srand(time(NULL));
}

void Game::run(){
    initGameObjects();
    while(window.isOpen() ){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    Event e;
    while( window.pollEvent(e) ){
        switch (e.type){
            case Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(){
    for( auto iter : coins){
        iter->speed *= 0.97;

        Vector2f multiplier(iter->body.getPosition());
        

        iter->body.move({ (iter->targetPos.x ) / iter->speed, (iter->targetPos.y)/iter->speed });
        iter->body.setRadius(iter->body.getRadius()*1.01 );
        iter->body.setOrigin( {iter->body.getRadius() , iter->body.getRadius()});
    }
}

void Game::render(){
    window.clear(Color::White);

    // drawing environment
    for( auto iter : environment)
        window.draw(iter);
    
    for( auto iter : coins)
        window.draw(iter->body);

    window.display();
}

void Game::initGameObjects(){
    createEnvironment();
    createRandomObjects();
}

void Game::createEnvironment(){
   /* VertexArray horizon(sf::LinesStrip, 2);
    horizon[0].position = sf::Vector2f(0, SCREEN_HEIGHT/2);
    horizon[1].position = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT/2);
    horizon[0].color = Color::Black;
    horizon[1].color = Color::Black;
    environment.push_back(horizon);
*/
    VertexArray roadLeft(sf::LinesStrip, 2);
    //roadLeft[0].position = sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    roadLeft[0].position = sf::Vector2f(SCREEN_WIDTH/2, 0);
    roadLeft[1].position = sf::Vector2f(0, SCREEN_HEIGHT);
    roadLeft[0].color = Color::Black;
    roadLeft[1].color = Color::Black;
    environment.push_back(roadLeft);

    VertexArray roadRight(sf::LinesStrip, 2);
    //roadRight[0].position = sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    roadRight[0].position = sf::Vector2f(SCREEN_WIDTH/2, 0);
    roadRight[1].position = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
    roadRight[0].color = Color::Black;
    roadRight[1].color = Color::Black;
    environment.push_back(roadRight);

}

void Game::createRandomObjects(){
    for(int i=0; i<10; i++){
        Coin *myCoin = new Coin;
        myCoin->order = i;
        myCoin->targetPos.x = rand()%SCREEN_WIDTH - SCREEN_WIDTH/2;
        myCoin->targetPos.y = SCREEN_HEIGHT;
        myCoin->body.setFillColor(Color( rand()%255, rand()%255, rand()%255 ));
        myCoin->body.setRadius(2);
        myCoin->body.setPosition({ horizon.x, 0.01});
        myCoin->speed = 7500;
        coins.push_back(myCoin);
    }
}


float Game::lerp(float x, float y, float z) {
    return ((1.0f - z) * x) + (z * y);      
}