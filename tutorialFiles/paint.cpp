#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
using namespace sf;

int main(){
    RenderWindow window( VideoMode(640, 480), "SFML", Style::Fullscreen );


    srand(time(NULL));

    CircleShape player(30);
    bool drawMode = 1 ; // 1 on, 0 off
    Event event;
    while( window.isOpen() ){
        while( window.pollEvent(event) ){
            switch (event.type){
                case Event::Closed:
                    window.close();
                
                default:
                    break;
            }
            if( event.key.code == Keyboard::W )
                player.setRadius( player.getRadius()+5 );
            if( event.key.code == Keyboard::S )
                player.setRadius( player.getRadius()-5 );
            if( Mouse::isButtonPressed(Mouse::Button::Left) )
                player.setFillColor(Color( rand()%255, rand()%255, rand()%255 ) );

            if( Event::MouseMoved && drawMode )
                player.setPosition( Vector2f( Mouse::getPosition(window).x - player.getRadius(), Mouse::getPosition(window).y - player.getRadius()) );
        
            if( Mouse::isButtonPressed(Mouse::Button::Left) )
                drawMode = 1;
            if( event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonReleased  )
                drawMode = 0;
                
        }

        //window.clear(sf::Color::Black);
        window.draw(player);
        window.display();

    }
}