#include "Game.h"

Game::Game() 
: window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Incremental Game", Style::Default) 
, panel({1, 1}, {18, 18})
, cookie({300, 300})
{
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    clock.restart();
}

void Game::run(){
    boosterList.createBoosters();
    
    float y = 128;
    for(auto booster : boosterList.getBoosters()){
        Button *newButton = new Button({64,y}, booster.getName());
        buttons.push_back(*newButton);
        y += 64;
    }

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

        for( int i=0; i<buttons.size(); i++){
            if( buttons[i].clicked(window) ){
                if( boosterList.addBooster(i) == false ){
                    cout << "Not enough money" << endl;
                }
            }
        }

        if( cookie.clicked(window) )
            boosterList.addCookie();

    }
}

void Game::update(){

    // EVERY SECONDS
    if( clock.getElapsedTime().asMilliseconds() > 1000 ){
        boosterList.harvestAll();
        clock.restart();
    }
    for( int i=0; i<buttons.size(); i++)
        buttons[i].update();
    cookie.update();

}

void Game::render(){
    boosterList.printBoosters();

    window.clear(Color::Black);
    panel.draw(window);
    for( auto button : buttons)
        button.draw(window);
    cookie.draw(window);
    window.display();
}
