#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(){
    RenderWindow pencere(VideoMode(1024, 768), "Oyunum", Style::Default );

    CircleShape daire;
    daire.setRadius(60);
    daire.setFillColor(Color::Red);
    daire.setPosition(Vector2f(300, 300));
    
    while( pencere.isOpen() ){

        Event olay;
        while( pencere.pollEvent(olay) ){
            switch (olay.type){
                case Event::Closed:
                    pencere.close();
                default:
                    break;
            }

        }

        pencere.clear();
        daire.move(Vector2f(0.1, 0));
        pencere.draw(daire);
        pencere.display();
    }
    
    return 0;
}