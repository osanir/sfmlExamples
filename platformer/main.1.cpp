#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int  main(){
    RenderWindow window(VideoMode(1024,768), "Game", Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);

    Clock clock;
    int frame = 0;
    float dTime;
    dTime = clock.getElapsedTime().asSeconds();

    Font font;
    if (!font.loadFromFile("universal-knowledge.ttf"))
    {
        cout << "Font error!" << endl;
    }
    Text text;
    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Black);


    const float GRAVITY  = 0.10;
    const float MAXSPEED = 10;
    const float MAXFALLSPEED = 10;
    Vector2f VELOCITY;
    Vector2f SPEED(0.5, 0.5);


    RectangleShape player;
    player.setSize(Vector2f(20,20));
    player.setFillColor(Color::Black);
    player.setPosition(Vector2f(300, 300));

    int keyCounter = 0;
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            switch (e.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyReleased:
                    if( e.key.code == Keyboard::A || e.key.code == Keyboard::D )
                        VELOCITY.x = 0;
                    break;
                case Event::KeyPressed:
                
                    if( e.key.code == Keyboard::A && VELOCITY.x > -MAXSPEED ){
                        VELOCITY.x -= SPEED.x;
                        keyCounter++;
                        cout << keyCounter << endl;
                    }
                    if( e.key.code == Keyboard::D && VELOCITY.x < MAXSPEED )
                        VELOCITY.x += SPEED.x;
                    break;
                default:
                    break;
            }
        }

        
        frame++;
        if( clock.getElapsedTime().asSeconds() - dTime  >= 1){
            dTime = clock.getElapsedTime().asSeconds();
            text.setString(to_string(frame));
            frame = 0;
        }
        //*/
        /*
        if( VELOCITY.y < MAXFALLSPEED)
            VELOCITY.y += GRAVITY;
        //*/

        if( player.getPosition().y > 768 )
            player.setPosition(player.getPosition().x, 0);

        player.move(VELOCITY);
        
        window.clear(Color::White);
        window.draw(text);
        window.draw(player);
        window.display();
    }
}