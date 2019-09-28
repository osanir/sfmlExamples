#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(1024, 768), "Denemeler", Style::Default);
    window.setFramerateLimit(60);

    Texture texture;
    if( !texture.loadFromFile("tankRed.png") ){
        cout << "Could not load image" << endl;
    }

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setColor(Color::Yellow);
    sprite.setPosition(600, 600);

    RectangleShape shape;
    shape.setSize({100, 100});
    shape.setFillColor(Color::Blue);
    shape.setPosition(100, 100);
    shape.setRotation(45);
    shape.setOutlineColor(Color::Red);
    shape.setOutlineThickness(4);
    shape.setOrigin({shape.getSize().x/2, shape.getSize().y/2});

    Clock clock;
    int dt = clock.getElapsedTime().asSeconds();
    int frame = 0;

    float speed = 4;

    int i=0;
    while( window.isOpen() ){
        Event event;
        while( window.pollEvent(event) ){
            switch ( event.type ){
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        if( Keyboard::isKeyPressed(Keyboard::D) )
            sprite.move({speed,0});
        if( Keyboard::isKeyPressed(Keyboard::A) )
            sprite.move({-speed,0});
        if( Keyboard::isKeyPressed(Keyboard::W) )
            sprite.move({0,-speed});
        if( Keyboard::isKeyPressed(Keyboard::S) )
            sprite.move({0,speed});

        frame++;
        if( (clock.getElapsedTime().asSeconds() - dt) > 1 ){
            dt = clock.getElapsedTime().asSeconds();
            cout << frame << endl;
            frame = 0;
        }

        if( sprite.getGlobalBounds().intersects(shape.getLocalBounds()) )
            cout << "Çarpışma: " << ++i << endl;
        window.clear(Color::White);
        window.draw(shape);
        window.draw(sprite);
        window.display();

    }

    return 0;
}