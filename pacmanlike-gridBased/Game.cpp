#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game", Style::Default) {
    grid = 32;
    score = 0;
    health = 3;
    
    font.loadFromFile("universal-knowledge.ttf");

    text_score.setFont(font);
    text_score.setPosition({10,0});
    text_score.setString(to_string(score));
    text_score.setCharacterSize(24);
    text_score.setFillColor(Color::Black);

    text_health.setFont(font);
    text_health.setPosition({10,32});
    text_health.setString(to_string(health));
    text_health.setCharacterSize(24);
    text_health.setFillColor(Color::Black);

    player.setSize( {grid, grid} );
    player.setFillColor(Color::White);
    player.setOutlineThickness( -1 );
    player.setOutlineColor( Color::Black );
    player.setPosition( {0, 0} );
    srand(time(NULL));
    for( int i=0; i<4; i++ ){
        enemy[i].setSize( {grid, grid} );
        enemy[i].setFillColor(Color::Red);
        enemy[i].setOutlineThickness( -1 );
        enemy[i].setOutlineColor( Color::Black);
        int x = rand()%SCREEN_WIDTH, y = rand()%SCREEN_HEIGHT;
        x -= x%int(grid);
        y -= y%int(grid);
        enemy[i].setPosition( {float(x), float(y)} );
    }
    //texture.loadFromFile("grid.jpeg");
    //texture.setRepeated(true);
    //bg.setTexture(texture);


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
        switch (e.type){
            case Event::Closed:
                window.close();
                break;
            default:
                break;
        }
        if( Keyboard::isKeyPressed( Keyboard::Right ) )
            direction = 'r';
        if( Keyboard::isKeyPressed( Keyboard::Left ) )
            direction = 'l';
        if( Keyboard::isKeyPressed( Keyboard::Up ) )
            direction = 'u';
        if( Keyboard::isKeyPressed( Keyboard::Down ) )
            direction = 'd';
    }
}

void Game::update(){
    dt = clock.getElapsedTime();
    if( dt.asSeconds() >= 0.3 ){
        movePlayer(); // player move
        moveEnemies();
        checkCollisions();
        text_score.setString(to_string(score));
        text_health.setString(to_string(health));

        //cout << dt.asSeconds() << endl;
        clock.restart();
        dt = Time::Zero;
    }
}

void Game::render(){
    window.clear(Color::White);
    //draw
    for( int i=0; i<4; i++ )
        window.draw(enemy[i]);
    window.draw(player);
    window.draw(text_health);
    window.draw(text_score);
    window.display();
}

void Game::movePlayer(){
    switch ( direction ){
        case 'r':
            player.move( {grid, 0} );
            break;
        case 'l':
            player.move( {-grid, 0} );
            break;
        case 'd':
            player.move( {0, grid} );
            break;
        case 'u':
            player.move( {0, -grid} );
            break;
        default:
            break;
    }
}

void Game::moveEnemies(){
    for(int i=0; i<4; i++){
        char dir = rand()%4;
        switch(dir){
            case 0:
                enemy[i].move( {grid, 0} );
                break;
            case 1:
                enemy[i].move( {-grid, 0} );
                break;
            case 2:
                enemy[i].move( {0, grid} );
                break;
            case 3:
                enemy[i].move( {0, -grid} );
                break;
        }
        if( enemy[i].getPosition().x >= SCREEN_WIDTH)
            enemy[i].move({-grid, 0});
        if( enemy[i].getPosition().x < 0)
            enemy[i].move({grid, 0});
        if( enemy[i].getPosition().y >= SCREEN_HEIGHT)
            enemy[i].move({0, -grid});
        if( enemy[i].getPosition().y < 0)
            enemy[i].move({0, grid});
    }
}

void Game::checkCollisions(){
    for(int i=0; i<4; i++){
        if( enemy[i].getPosition().x == player.getPosition().x && enemy[i].getPosition().y == player.getPosition().y ){
            health--;
        }
    }

    bool collide_wall = false;
    if( player.getPosition().x >= SCREEN_WIDTH ){
        player.move({-grid, 0});
        collide_wall = true;
        direction = '0';
    }
    if( player.getPosition().x < 0 ){
        player.move({grid, 0});
        collide_wall = true;
        direction = '0';
    }
    if( player.getPosition().y >= SCREEN_HEIGHT ){
        player.move({0, -grid});
        collide_wall = true;
        direction = '0';
    }
    if( player.getPosition().y < 0 ){
        player.move({0, grid});
        collide_wall = true;
        direction = '0';
    }
    if( collide_wall == true )
        health--;
}