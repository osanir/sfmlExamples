#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(1360, 768), "Circle Şov", Style::Default);

    list<CircleShape> circles;

    int jumpSize = 10;
    int mulx = 1, muly = 1;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
                
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::A){
                        CircleShape *circle = new CircleShape;
                        circle->setFillColor(Color(5*mulx, 5*muly, mulx*muly) );
                        circle->setRadius( 10 );
                        if( mulx* jumpSize > window.getSize().x ){
                            muly++;
                            mulx = 1;
                        }
                        circle->setPosition( Vector2f(jumpSize*(mulx++), jumpSize*muly) );
                        circles.push_back(*circle);
                    }
                    break;
                default:
                    break;
            }
            window.clear();
            list<CircleShape>::iterator iter = circles.begin();
            while(iter != circles.end()){
                window.draw(*iter);
                iter++;
            }
            window.display();

        }
    }
}