#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    Window window(sf::VideoMode(800, 600), "My window");
    window.setKeyRepeatEnabled(true);   // basılı tutulduğunda harfin ard arda yazılması olayı
    window.setPosition(sf::Vector2i(100, 100) );

    
    while( window.isOpen() ){

        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::KeyPressed:
                    switch ( event.key.code ){
                        case sf::Keyboard::Right:
                            sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x+10, sf::Mouse::getPosition().y));    
                            break;
                        case sf::Keyboard::Left:
                            sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x-10, sf::Mouse::getPosition().y ) );    
                            break;
                        case sf::Keyboard::Down:
                            sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y+10));    
                            break;
                        case sf::Keyboard::Up:
                            sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y-10));    
                            break;

                    }
                    break;
                 
                // we don't process other types of events
                default:
                    break;
            }
        }

    }
    return 0;
}