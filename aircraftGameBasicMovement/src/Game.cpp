#include "../include/Game.h"

Game::Game() 
    : mWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Aircraft", sf::Style::Default) 
    , mTexture()
    , mPlayer()
{
        //mWindow.setFramerateLimit(60);
        if(!mTexture.loadFromFile("res/texture/airplane.png")){
            // Handle loading error
        }
        mPlayer.setTexture(mTexture);
        mPlayer.setPosition(100.f, 100.f);
}

void Game::run(){
    sf::Clock clock;
    while(mWindow.isOpen() ){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents(){
    sf::Event e;
    while( mWindow.pollEvent(e) ){
        switch (e.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(e.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(e.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime){
    sf::Vector2f movement(0.f, 0.f);
    float speed = 500.f;
    if( mIsMovingUp )
        movement.y -= speed;
    if( mIsMovingDown )
        movement.y += speed;
    if( mIsMovingRight )
        movement.x += speed;
    if( mIsMovingLeft )
        movement.x -= speed;

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
    mWindow.clear(sf::Color::White);
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if( key == sf::Keyboard::W )
        mIsMovingUp = isPressed;
    else if( key == sf::Keyboard::S )
        mIsMovingDown = isPressed;
    else if( key == sf::Keyboard::A )
        mIsMovingLeft = isPressed;
    else if( key == sf::Keyboard::D )
        mIsMovingRight = isPressed;
}
