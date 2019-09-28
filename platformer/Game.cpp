#include "Game.h"

Game::Game() : window(VideoMode(1024, 768), "Game", Style::Default) {
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);
    
    player.setSize(Vector2f(20, 20));
    player.setFillColor(Color::Black);
    player.setPosition(Vector2f(300, 300));

    player_right.setSize(Vector2f(4, player.getSize().y));
    player_right.setFillColor(Color::Red);
    player_left.setSize(Vector2f(4, player.getSize().y));
    player_left.setFillColor(Color::Red);
    player_bottom.setSize(Vector2f(player.getSize().x,1));
    player_bottom.setFillColor(Color::Red);

    floor.setSize(Vector2f(900,10));
    floor.setPosition(Vector2f(0,500) );
    floor.setFillColor(Color::Black);

    dTime = clock.getElapsedTime().asSeconds();

    if (!font.loadFromFile("universal-knowledge.ttf"))
        cout << "Font error!" << endl;

    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Black);

    SPEED = Vector2f(0.4, -2);
    isOnFloor = false;
};
void Game::run(){
    importMap();
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
                    isMovingJump = false;
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
        isMovingJump = true;
        
}

void Game::update(){
    cout << isMovingLeft << ":" << isMovingJump << ":" << isMovingRight << " : " << VELOCITY.x << endl;

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
    if( isMovingJump && isOnFloor ){
        VELOCITY.y += SPEED.y;
    }

    // Stop, lerp motion
    if( !isMovingLeft && !isMovingRight )
        VELOCITY.x = lerp(VELOCITY.x, 0, 0.1);
    
    // floor collision detector
    if( checkFloorCollision() ){
        if( isOnFloor == false){
            VELOCITY.y = 0;
            isOnFloor = true;    
        }
    } else
        isOnFloor = false;   
    
    if( isOnFloor == false && VELOCITY.y < MAXFALLSPEED )
        VELOCITY.y += GRAVITY;


    // Teleportation
    if( player.getPosition().y > 768 )
        player.setPosition(player.getPosition().x, 0);
    if( player.getPosition().x > 1024 || player.getPosition().x < 0 ){
        int newPos = (player.getPosition().x+1024);
        newPos %= 1024;
        player.setPosition( newPos, player.getPosition().y);
    }

    player.move(VELOCITY);

    Vector2f pos = player.getPosition();
    Vector2f size = player.getSize();
    player_left.setPosition(Vector2f(pos.x-4, pos.y));
    player_right.setPosition(Vector2f(pos.x + size.x, pos.y));
    player_bottom.setPosition(Vector2f(pos.x, pos.y + size.y));
    
}

void Game::render(){
    window.clear(Color::White);
/*
    vector<RectangleShape*>::iterator iter = gameObjects.begin();
    while( iter != gameObjects.end() ){
        window.draw(**iter);
        iter++;
    }
*/
    window.draw(text);


    window.draw(player);
    window.draw(player_right);
    window.draw(player_left);
    window.draw(player_bottom);

    
    window.draw(floor);

    window.display();
}

bool Game::checkFloorCollision(){
    if( player_bottom.getGlobalBounds().intersects(floor.getGlobalBounds()) ){
        if( player.getGlobalBounds().intersects(floor.getGlobalBounds()) )
            push(&player, UP);
        return true;
    } else {
        return false;
    }

}

void Game::push(RectangleShape *shape, Vector2f dir){
    //shape->move(dir);
    shape->setPosition(Vector2f(shape->getPosition().x, shape->getPosition().y + SPEED.y) );
}

void Game::createObject(Vector2f position, Vector2f size){
    RectangleShape *shape = new RectangleShape;
    shape->setSize(size);
    shape->setPosition(position);
    shape->setFillColor(Color::Black);
    //gameObjects.push_back(shape);
}

void Game::importMap(){
    createObject(Vector2f(0,700), Vector2f(1024, 10) );
}

float Game::lerp(float x, float y, float z) {
        return ((1.0f - z) * x) + (z * y);      
}