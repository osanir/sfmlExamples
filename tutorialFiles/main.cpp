#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window( VideoMode(1360, 768), "SFML", Style::Default );
    Vector2f scrCent(window.getSize().x/2, window.getSize().y/2);

    int maxSize = 200;
    int count = 2;

    RectangleShape line( Vector2f(2, maxSize/count) );
    line.setPosition(Vector2f(scrCent.x, scrCent.y+100) );
    line.setFillColor(Color::Green);    
    line.rotate(180);

    RectangleShape line2( Vector2f(2, maxSize/count) );
    line2.setPosition(Vector2f(scrCent) );
    line2.setFillColor(Color::Red);
    line2.rotate(180);

    Event event;
    while( window.isOpen() ){
        while( window.pollEvent(event) ){
            switch (event.type){
                case Event::Closed:
                    window.close();
                
                default:
                    break;
            
            }
            if( event.key.code == Keyboard::W ){
                line.setPosition(Vector2f(scrCent.x, scrCent.y+100) );
                line.rotate(10);
                line2.setPosition(Vector2f(line.getPosition().x + line.getPoint(3).x, line.getPosition().y + line.getPoint(3).y) );
                line2.rotate(-25);
                
            }
            cout << "line x " << line.getPoint(3).x << " y " << line.getPoint(3).y << endl;
            cout << "Point Count: " << line.getPointCount();
        }

//        if( event.key.code == Keyboard::R)
//                convex.rotate(10);
        
        window.clear(sf::Color::Black);
        window.draw(line);
        window.draw(line2);
        window.display();

    }
}