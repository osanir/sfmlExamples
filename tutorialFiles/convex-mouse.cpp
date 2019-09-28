#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window( VideoMode(640, 480), "SFML", Style::Default );
    srand(time(NULL));


    vector<Vector2f> count;
    sf::ConvexShape convex;
    convex.setPointCount(count.size());
    convex.setFillColor(Color::Red);
    convex.setOutlineThickness(4);
    convex.setOutlineColor(Color::Green);
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
                
        }
        if( Mouse::isButtonPressed(Mouse::Button::Left) ){
            Vector2f pos;
            pos.x = Mouse::getPosition().x; 
            pos.y = Mouse::getPosition().y; 
            count.push_back(pos);
            convex.setPointCount(count.size());
            for(int i=0; i<count.size(); i++){
                convex.setPoint(i, count[i]);
            }
        }

//        if( event.key.code == Keyboard::R)
//                convex.rotate(10);
        
        window.clear(sf::Color::Black);
        window.draw(convex);
        window.display();

    }
}