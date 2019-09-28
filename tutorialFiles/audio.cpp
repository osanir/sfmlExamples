#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <random>
#include <cmath>
#include <SFML/Audio.hpp>
#define PI 3.14159265
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16 ;
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Drawing Stuff", sf::Style::Default, settings);
    sf::Music music;
    if( !music.openFromFile("music.ogg") ){
        return -1;
    }
    music.play();
    
    srand(time(NULL));
    // CIRCLE
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setOutlineThickness(10);
    shape.setOutlineColor( sf::Color(100, 255, 25));
    shape.setPosition( renderWindow.getSize().x/2-shape.getRadius(), renderWindow.getSize().y/2-shape.getRadius() );    // center of the renderWindow
    
    shape.setPointCount(8);
    
    // CONVEX
    sf::ConvexShape convex;
    convex.setPointCount(3);
    
    convex.setPoint(0, sf::Vector2f(renderWindow.getSize().x/2, renderWindow.getSize().y/2));
    convex.setPoint(1, sf::Vector2f(renderWindow.getSize().x/2+100, renderWindow.getSize().y/2));
    convex.setPoint(2, sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) );
    //convex.setPoint(3, sf::Vector2f(30, 10000));
    //convex.setPoint(4, sf::Vector2f(0, 50));
    
    convex.setFillColor( sf::Color(12, 56, 250) );

    //LINE
    sf::RectangleShape line( sf::Vector2f(150, 1) );
    sf::RectangleShape line2( sf::Vector2f(150, 1) );
    line.setPosition( renderWindow.getSize().x/2, renderWindow.getSize().y/2);    // center of the renderWindow
    line2.setPosition( renderWindow.getSize().x/2, renderWindow.getSize().y/2);    // center of the renderWindow

    sf::RectangleShape rect[10];
    for(int i=0; i<10; i++){
        rect[i].setSize(sf::Vector2f(50, 150));
        rect[i].rotate(180);
    }

    sf::Vector2f scrCenter;
    scrCenter.x = renderWindow.getSize().x/2;
    scrCenter.y = renderWindow.getSize().y/2;
    
    sf::Event event;
    while( renderWindow.isOpen() ){
        while( renderWindow.pollEvent(event) ){
            if( event.type == sf::Event::Closed )
                renderWindow.close();
            if( event.key.code == sf::Keyboard::F )
                renderWindow.setTitle("Fullscr");
            convex.setPoint(1, sf::Vector2f(sf::Mouse::getPosition(renderWindow).x, renderWindow.getSize().y/2) );
            convex.setPoint(2, sf::Vector2f(sf::Mouse::getPosition(renderWindow).x, sf::Mouse::getPosition(renderWindow).y) );
            //line.rotate(10);
            
            float kom = sf::Mouse::getPosition(renderWindow).x - scrCenter.x;
            float kar = sf::Mouse::getPosition(renderWindow).y - scrCenter.y ;
            //std::cout << "Kom: "<< kom << " Kar: " << kar << " " << kom/kar << " \t AÇI: " << sin(kom/kar)/(3.141593/180.0) << std::endl; 
            if( sf::Mouse::getPosition(renderWindow).x < scrCenter.x )
                line.setRotation( (atan(kar/kom)*180/PI) +180 );
            else
                line.setRotation((atan(kar/kom)*180)/PI);
            
            line2.setRotation(rand()%360);
            
            renderWindow.clear();
            //renderWindow.draw(convex);
            //renderWindow.draw(shape);
            renderWindow.draw(line);
            renderWindow.draw(line2);
            
            int color = sf::Mouse::getPosition(renderWindow).x + sf::Mouse::getPosition(renderWindow).y;
            
            convex.setFillColor(sf::Color( rand()%255, rand()%255, rand()%255 ) );
            line.setFillColor(sf::Color( rand()%255, rand()%255, rand()%255 ) );
            line2.setFillColor(sf::Color( rand()%255, rand()%255, rand()%255 ) );
            line.setSize(sf::Vector2f( rand()%200, 2 ) );
            line2.setSize(sf::Vector2f( rand()%200, 2 ) );
            
            std::cout << music.getPitch() << std::endl;
            //music.setPitch( (sf::Mouse::getPosition(renderWindow).x)/640.0 +0.5 );
            
            if( event.key.code == sf::Keyboard::Space ){
                music.setPitch( shape.getPointCount()/5.0);
                shape.setPointCount(rand()%10);
            }
        
            
            for(int i=0; i<10; i++){
                rect[i].setPosition( sf::Vector2f( 64*i, 480 ) );
                rect[i].setFillColor( sf::Color( i*rand()%64, i*rand()%32, i*rand()%16) );

                if( rand()%2 == 1)
                    rect[i].setSize( sf::Vector2f(50, rect[i].getSize().y+1) );
                else
                    rect[i].setSize( sf::Vector2f(50, rect[i].getSize().y-1) );                
                renderWindow.draw(rect[i]);        
            }


            renderWindow.display();   
            
        }
    }

    return 0;
}