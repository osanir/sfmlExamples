#include "Game.h"

Game::Game() : window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Rider", Style::Default) {
    window.setFramerateLimit(60);

    rect1.setSize({20,20});
    rect2.setSize({20,20});
    
    rect1.setPosition({0,0});
    rect2.setPosition({0,0});
    
    rect1.setFillColor(Color::Red);
    rect2.setFillColor(Color::Green);
}

void Game::run(){
    cout << "Enter s for server, c for client" << endl;
    cin >> connectionType;

    string text = "Connected to ";

    if( connectionType == 's' ){
        TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
        text += "server";
    } 
    else if( connectionType == 'c'){
        socket.connect("192.168.1.23", 2000);
        text += "client";
    }


    socket.setBlocking(false);

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
            case Event::GainedFocus:
                updateGame = true;
                break;
            case Event::LostFocus:
                updateGame = false;
                break;
            default:
                break;
        }
    }

    prevPosition = rect1.getPosition();
    if(updateGame){
        if( Keyboard::isKeyPressed(Keyboard::Right))
            rect1.move({1.0, 0.0});
        if( Keyboard::isKeyPressed(Keyboard::Left))
            rect1.move({-1.0, 0.0});
        if( Keyboard::isKeyPressed(Keyboard::Up))
            rect1.move({0.0, -1.0});
        if( Keyboard::isKeyPressed(Keyboard::Down))
            rect1.move({0.0, 1.0});
    }

    Packet packet;
    if( prevPosition != rect1.getPosition() ){
        packet << rect1.getPosition().x << rect1.getPosition().y;
        socket.send(packet);
    }

    socket.receive(packet);
    if( packet >> p2Position.x >> p2Position.y )
        rect2.setPosition(p2Position);
}

void Game::update(){

}

void Game::render(){
    window.clear(Color::Black);
    window.draw(rect1);
    window.draw(rect2);
    window.display();
}