#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(640, 480), "SFML", Style::Default);

    CircleShape circle(20);
    circle.setFillColor(Color::Red);
    circle.setPosition({200, 200});
    Time dt, elapsed;
    Clock clock;

    CircleShape bullet(10);
    bullet.setFillColor(Color::Yellow);

    list<CircleShape> bullets;

    while(window.isOpen() ){
        Event event;
        while(window.pollEvent(event)){
            switch( event.type ){
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseMoved:
                    cout << "X: " << Mouse::getPosition().x << "  Y: " << Mouse::getPosition().y << endl; 
                    break;
                case Event::KeyPressed:
                    if( event.key.code == Keyboard::A)
                        circle.setPosition(Vector2f( circle.getPosition().x-1, circle.getPosition().y ));
                    if( event.key.code == Keyboard::D)
                                circle.setPosition(Vector2f( circle.getPosition().x+1, circle.getPosition().y ));
                    if( event.key.code == Keyboard::W)
                                circle.setPosition(Vector2f( circle.getPosition().x, circle.getPosition().y-1 ));
                    if( event.key.code == Keyboard::S)
                                circle.setPosition(Vector2f( circle.getPosition().x, circle.getPosition().y+1 ));
                    
                    break;
                default:
                    break;
            }
            if( Mouse::isButtonPressed(Mouse::Button::Left)){
                CircleShape *bullet = new CircleShape(5);
                bullet->setPosition({circle.getPosition().x, circle.getPosition().y});
                bullet->setFillColor(Color::Yellow);
                bullets.push_back(*bullet);

                cout << "bastın!" << endl;
            }

        }

        window.clear();
        window.draw(circle);

        list<CircleShape>::iterator iter;
        if( !bullets.empty() ){
                iter = bullets.begin();
                while( iter != bullets.end() ){
                    window.draw(*iter);
                    iter++;
                }
        }
        //if( !bullets.empty() )
        //    window.draw(*bullets.begin());
        dt = clock.getElapsedTime();
        elapsed += clock.getElapsedTime();
        clock.restart();

        
        if( elapsed.asMilliseconds() > 10){
            cout << "Saniye: " << elapsed.asSeconds() << endl;
            elapsed = seconds(0);

            if( !bullets.empty() ){
                iter = bullets.begin();
                while( iter != bullets.end() ){
                    cout << "XXXXX: "<<(*iter).getPosition().x << endl;
                    iter->setPosition(Vector2f( (*iter).getPosition().x+10, (*iter).getPosition().y ) );
                    iter++;
                }
            }
        }

        window.display();

    }
}
