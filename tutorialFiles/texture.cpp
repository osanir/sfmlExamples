#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(640, 480), "My Window Title", Style::Default);

    CircleShape circle(20);
    circle.setFillColor(Color::Red);

    Texture texture;
    if( !texture.loadFromFile("greenleather.jpg") ){
        //error
    }
    Sprite sprite;
    sprite.setTexture(texture);

    sprite.setTextureRect(IntRect(10,10,50,50));
    int size = 50;
    int flag = 1;
    while( window.isOpen() ){
        Event event;
        while(window.pollEvent(event)){
            switch( event.type ){
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if( event.key.code == Keyboard::Space){
                        sprite.setTextureRect(IntRect(10,10,size++,50));
                        if( flag )
                            sprite.setColor(Color::Red);
                        else
                            sprite.setColor(Color(255, 255, 255));
                        flag = 1 - flag;
                    }
                        

                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}