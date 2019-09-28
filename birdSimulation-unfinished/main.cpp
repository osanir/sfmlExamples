#include <SFML/Graphics.hpp>
#include <iostream>
#include "bird.h"

using namespace sf;

int main(){
    RenderWindow window(VideoMode(1024, 768), "Birds", Style::Default);

    while( window.isOpen() ){
        Event event;
        while( window.pollEvent(event) ){
            switch (event.type ) {
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
            
        }
    }
}