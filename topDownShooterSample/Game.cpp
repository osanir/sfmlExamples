#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Default) {
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);
    
    player.setSize(Vector2f(20, 20));
    player.setFillColor(Color::Black);
    player.setOrigin(Vector2f(player.getSize().x/2, player.getSize().y/2));
    player.setPosition(Vector2f(0, 0));

    gun.setSize(Vector2f(20, 5));
    gun.setFillColor(Color::Red);
    gun.setOrigin(Vector2f(0, gun.getSize().y/2));

    dTime = clock.getElapsedTime().asSeconds();

    if (!font.loadFromFile("universal-knowledge.ttf"))
        cout << "Font error!" << endl;

    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Black);

    SPEED = Vector2f(0.4, 0.4);
};
void Game::run(){
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    Event e;
    while(window.pollEvent(e)){
        switch (e.type){
            case Event::Closed:
                window.close();
                break;
            case Event::KeyReleased:
                if( e.key.code == Keyboard::A )
                    isMovingLeft = false;
                if( e.key.code == Keyboard::D )
                    isMovingRight = false;
                if( e.key.code == Keyboard::W )
                    isMovingUp = false;
                if( e.key.code == Keyboard::S )
                    isMovingDown = false;
                break;
            default:
                break;
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::A) )
        isMovingLeft = true;
    if(Keyboard::isKeyPressed(Keyboard::D) )
        isMovingRight = true;
    if(Keyboard::isKeyPressed(Keyboard::W) )
        isMovingUp = true;
    if(Keyboard::isKeyPressed(Keyboard::S) )
        isMovingDown = true;
    
    if(Mouse::isButtonPressed(Mouse::Button::Left))
        fire();
}

void Game::update(){
    // Frame show
    frame++;
    if( clock.getElapsedTime().asSeconds() - dTime  >= 1){
        dTime = clock.getElapsedTime().asSeconds();
        text.setString(to_string(frame));
        frame = 0;
    }

    // Movement
    if( isMovingLeft && (VELOCITY.x > -MAXSPEED))
        VELOCITY.x -= SPEED.x;
    if( isMovingRight && (VELOCITY.x < MAXSPEED))
        VELOCITY.x += SPEED.x;
    if( isMovingUp && (VELOCITY.y > -MAXSPEED))
        VELOCITY.y -= SPEED.y;
    if( isMovingDown && (VELOCITY.y < MAXSPEED))
        VELOCITY.y += SPEED.y;

    // Stop, lerp motion
    if( (!isMovingLeft && !isMovingRight)  )
        VELOCITY.x = lerp(VELOCITY.x, 0, 0.1);
    if( (!isMovingUp && !isMovingDown)  )
        VELOCITY.y = lerp(VELOCITY.y, 0, 0.1);
    

    // Teleportation
    if( player.getPosition().y > SCREEN_HEIGHT || player.getPosition().y < 0){
        int newPos = (player.getPosition().y+SCREEN_HEIGHT);
        newPos %= SCREEN_HEIGHT;
        player.setPosition(player.getPosition().x, newPos);
    }
    if( player.getPosition().x > SCREEN_WIDTH || player.getPosition().x < 0 ){
        int newPos = (player.getPosition().x+SCREEN_WIDTH);
        newPos %= SCREEN_WIDTH;
        player.setPosition( newPos, player.getPosition().y);
    }

    setPlayerRotation();

    player.move(VELOCITY);

    gun.setPosition(player.getPosition());
    gun.setRotation(player.getRotation());

    Vector2f pos = player.getPosition();
    Vector2f size = player.getSize();
}

void Game::render(){
    window.clear(Color::White);
    window.draw(text);
    window.draw(player);
    window.draw(gun);
    
    list<CircleShape>::iterator iter = bullets.begin();
    while(iter != bullets.end()){
        window.draw(*iter);
        iter++;
    }
    
    window.display();
}

float Game::lerp(float x, float y, float z) {
    return ((1.0f - z) * x) + (z * y);      
}

float Game::setPlayerRotation(){
    float y, y1;
    float x, x1;
    float m;

    x = player.getPosition().x;
    y = player.getPosition().y;

    x1 = Mouse::getPosition(window).x;
    y1 = Mouse::getPosition(window).y;


    m = (y-y1) / (x-x1);
    m = atan(m);
    m = m * 180 / 3.14159265;
    if( x > x1) m += 180;
    player.setRotation(m);
    return m;
}

void Game::fire(){
    CircleShape bullet(3);
    bullet.setFillColor(Color::Black);
    cout << gun.getPoint(2).x << " " << gun.getPoint(2).y << endl;
    bullet.setPosition(Vector2f(gun.getPosition().x + gun.getPoint(2).x, gun.getPosition().y + gun.getPoint(2).y));
    bullets.push_back(bullet);

}
/*
void Game::updateBullets(){
    list<CircleShape>::iterator iter = bullets.begin();
    while(iter != bullets.end()){
        Vector2f angle;
        iter->move( );
        iter++;
    }
}*/