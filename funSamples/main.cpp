#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <iostream>

using namespace std;
using namespace sf;

struct pos{
    float y, x;
    CircleShape shape;
    pos(int posx, int posy){
        y = posy; x = posx;
        shape.setFillColor(Color::Black);
        shape.setPosition(Vector2f(x, y));
        shape.setRadius(4);
    }
};

int main(){
    RenderWindow window(VideoMode(1024, 768), "Follow the mouse", Style::Default);

    list<pos> points;

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
            if(Mouse::isButtonPressed(Mouse::Button::Left)){
                pos point(Mouse::getPosition(window).x , Mouse::getPosition(window).y);
                points.push_back(point);
            }
            if(Mouse::isButtonPressed(Mouse::Button::Right) || points.size() > 10){
                points.pop_front();
            }
        }
        
        bool flag = true;
        for(list<pos>::iterator iter = points.begin(); iter != points.end(); iter++){
            list<pos>::iterator comp = iter;
            flag = true;
            for(list<pos>::iterator iter2 = ++comp; iter2 != points.end(); iter++){
                if(iter->y == iter2->y && iter->x == iter2->x){
                    flag = false;
                    break;
                }
            }
            if(flag){
                iter->x += (Mouse::getPosition().x - iter->x) / 10;
                iter->y += (Mouse::getPosition().y - iter->y) / 10;
                iter->shape.setPosition(Vector2f(iter->x, iter->y));
            }

        }


        window.clear(Color::White);
        for(list<pos>::iterator iter = points.begin(); iter != points.end(); iter++)
            window.draw(iter->shape);
        window.display();
    }
}