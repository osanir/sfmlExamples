#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    Window window(sf::VideoMode(800, 600), "My window");

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(10, 50));
    
    // change the size of the window
    window.setSize(sf::Vector2u(640, 480));

    // change the title of the window
    window.setTitle("SFML window");

    // VSync
    window.setVerticalSyncEnabled(true); // call it once, after creating the window // Kare hızı monitör ile senkron hızda olur
    //window.setFramerateLimit(60); // call it once, after creating the window // Kare hızı limiti // Vsync ile beraber kullanılmamalı
    

    while( window.isOpen() ){
        Event event;
        
        while( window.pollEvent(event) ){
            switch ( event.type ){
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}