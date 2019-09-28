#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <iostream>

using namespace std;
using namespace sf;

bool insideOf(CircleShape shape, CircleShape redShape);


int main(){
    RenderWindow window(VideoMode(1024, 768), "Follow the mouse", Style::Default);

    CircleShape shape;
    shape.setFillColor(Color::Black);
    shape.setPosition(Vector2f(300, 300));
    shape.setRadius(4);

    CircleShape redShape;
    redShape.setFillColor(Color::Red);
    redShape.setPosition(Vector2f(600, 600));
    redShape.setRadius(40);
    float x, y;
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            switch (e.type){
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        
        
        if( shape.getGlobalBounds().intersects(redShape.getGlobalBounds()) ){
            printf("shape: x: %f\ty:%f\n", shape.getPosition().x, shape.getPosition().y);
            redShape.setFillColor(Color::Magenta);
            /*CircleShape circ;
            circ.setFillColor(Color::Blue);
            circ.setRadius(shape.getRadius());
            circ.setPosition(Vector2f(shape.getPosition().x, shape.getPosition().y));
            circles.push_back(circ);
        */}
        else
            redShape.setFillColor(Color::Red);

            x += (Mouse::getPosition(window).x - shape.getPosition().x) / 1000;
            y += (Mouse::getPosition(window).y - shape.getPosition().y) / 1000;
            shape.setPosition(Vector2f(x, y));


        window.clear(Color::White);
        window.draw(redShape);
        window.draw(shape);
        //for(list<CircleShape>::iterator iter = circles.begin(); iter != circles.end(); iter++)
          //  window.draw(*iter);
        window.display();
    }
}

