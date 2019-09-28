#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include <ctime>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(1360, 768), "SFML", Style::Default);
    srand(time(NULL));
    Clock clock;
    Time elapsed;

    list<CircleShape> circles;

    while( window.isOpen() ){
        Event event;
        while( window.pollEvent(event) ){
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseButtonPressed:{
                    CircleShape *circle = new CircleShape(20);
                    circle->setFillColor(Color(random()%255, random()%255, random()%255));
                    circle->setPosition( Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y) );
                    circles.push_back(*circle);
                    break;
                }
                default:
                    break;
            }
        }
        
        list<CircleShape>::iterator iter;
        iter = circles.begin();
        while( iter != circles.end() ){
            window.draw(*iter);
            iter++;
        }
        
        elapsed += clock.getElapsedTime();
        clock.restart();

        if( elapsed.asMilliseconds() > 5){
            iter = circles.begin();
            while( iter != circles.end() ){
                float x = (Mouse::getPosition(window).x - (*iter).getPosition().x);
                float y = (Mouse::getPosition(window).y - (*iter).getPosition().y);
                if( x < 0) x = -x;
                if( y < 0) y = -y;
                float sum = 250;

                if( Mouse::getPosition(window).x > (*iter).getPosition().x )
                    (*iter).setPosition( Vector2f((*iter).getPosition().x+(x/sum), (*iter).getPosition().y) );
                if( Mouse::getPosition(window).x < (*iter).getPosition().x )
                    (*iter).setPosition( Vector2f((*iter).getPosition().x-(x/sum), (*iter).getPosition().y) );
                if( Mouse::getPosition(window).y > (*iter).getPosition().y )
                    (*iter).setPosition( Vector2f((*iter).getPosition().x, (*iter).getPosition().y+(y/sum)) );
                if( Mouse::getPosition(window).y < (*iter).getPosition().y )
                    (*iter).setPosition( Vector2f((*iter).getPosition().x, (*iter).getPosition().y-(y/sum)) );
                iter++;
            }
            elapsed = seconds(0);
        }


        window.display();
    }
}