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
    shape.setRadius(1);

    int x = 0, y = 0;
    int count = 0;

    shape.setPosition(x, y);
    window.clear(Color::White);

        int r=0, g=0, b=0;
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

        shape.move(1, 0);

        if(shape.getPosition().x > 1024){
            x = 0;
            y += 1;
            shape.setPosition(x, y);
        }
        int add = 4;
        b += add;

        if( b >= 255){
            g += add;
            b = 0;
        }
        if( g >= 255){
            r += add;
            g = 0;
        }
        if( r >= 255){
            r = 0;
        }

        cout << "r: " << r << "  g: " << g << "  b: " << b << endl;
        shape.setFillColor(Color(r, g, b%255));

        window.draw(shape);
        //for(list<CircleShape>::iterator iter = circles.begin(); iter != circles.end(); iter++)
          //  window.draw(*iter);
        window.display();
    }
}
