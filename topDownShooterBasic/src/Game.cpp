#include "../include/Game.h"

Game::Game() 
: window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Agent47", Style::Default) 
, camera(SCREEN_WIDTH/4, SCREEN_HEIGHT/4)
{

}

void Game::run(){
    sf::Clock clock;
    while(window.isOpen() ){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
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
            case sf::Event::KeyPressed:
                player.handlePlayerInput(e.key.code, true);
                break;
            case sf::Event::KeyReleased:
                player.handlePlayerInput(e.key.code, false);
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime){
    player.move(deltaTime);
    //camera.update(player.getPosition(), map.getLayoutSize() );
    //player.updateRotation(window, camera.getView());
    player.updateRotation(window, camera.getView());
}

void Game::render(){

    window.setView(camera.getView());

    window.clear(sf::Color::White);
    //window.draw(player.body);
    window.draw(player.sprite);
    window.display();
}

float Game::getAngleTowardPosition(Vector2f source, Vector2f target){
    float y, y1;
    float x, x1;
    float m;

    x = source.x;
    y = source.y;

    x1 = (target.x - SCREEN_WIDTH/2);
    y1 = (target.y - SCREEN_HEIGHT/2);


    m = (y-y1) / (x-x1);
    m = atan(m);
    m = m * 180 / 3.14159265;
    if( x >= x1) m += 180;
    return m;
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if( key == sf::Keyboard::W )
        isMovingUp = isPressed;
    else if( key == sf::Keyboard::S )
        isMovingDown = isPressed;
    else if( key == sf::Keyboard::A )
        isMovingLeft = isPressed;
    else if( key == sf::Keyboard::D )
        isMovingRight = isPressed;
}

Player::Player()
{
    speed = 50;

    isMovingUp = false;
    isMovingDown= false;
    isMovingRight = false;
    isMovingLeft = false;

    body.setSize({20, 20});
    body.setOrigin({body.getSize().x/2, body.getSize().y/2});
    body.setFillColor(sf::Color::Black);
    body.setPosition({0, 0});

    texture.loadFromFile("res/agent.png");
    sprite.setTexture(texture);
    sprite.setOrigin({texture.getSize().x/2.f, texture.getSize().y/2.f});

}

void Player::move(sf::Time deltaTime){
    movement = {0, 0};
    if( isMovingUp )
        movement.y -= speed;
    if( isMovingDown )
        movement.y += speed;
    if( isMovingRight )
        movement.x += speed;
    if( isMovingLeft )
        movement.x -= speed;

    body.move(movement * deltaTime.asSeconds());

    sprite.setPosition( body.getPosition() );
}

void Player::updateRotation(RenderWindow &window, View view){
    float y, y1;
    float x, x1;
    float m;

    x = body.getPosition().x;
    y = body.getPosition().y;

    x1 = (view.getCenter().x - SCREEN_WIDTH/2)  + Mouse::getPosition(window).x;
    y1 = (view.getCenter().y - SCREEN_HEIGHT/2) + Mouse::getPosition(window).y;


    m = (y-y1) / (x-x1);
    m = atan(m);
    m = m * 180 / 3.14159265;
    if( x >= x1) m += 180;

    sprite.setRotation( m );
}

Vector2f Player::getPosition(){
    return body.getPosition();
}