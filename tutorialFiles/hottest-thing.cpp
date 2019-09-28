#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <random>
int main()
{
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Drawing Stuff");
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setOutlineThickness(10);
    shape.setOutlineColor( sf::Color(255, 255, 255));
    int i=255;
    bool flag = 1;
    srand(time(NULL));

    while( renderWindow.isOpen() ){
        sf::Event event;
        while( renderWindow.pollEvent(event) ){
            if( event.type == sf::Event::Closed )
                renderWindow.close();

            renderWindow.clear();
            renderWindow.draw(shape);
            renderWindow.display();
    
    
            shape.setFillColor( sf::Color(i,i,i) );
            shape.setOutlineColor( sf::Color(rand()%255,rand()%255,rand()%255) );
            ;
            shape.setPosition(rand()%(renderWindow.getSize().x),rand()%(renderWindow.getSize().y));
            if( flag == 1 )
                i--;
            else 
                i++;

            if( i == 0 && flag == 1)
                flag = 0;
            if( i == 255 && flag == 0)
                flag = 1;
        }
    }

    return 0;
}