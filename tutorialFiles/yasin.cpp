#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

using namespace sf;

int main()
{
    int flag = 0 ;


    RenderWindow app(VideoMode(1000, 500), "c");
    app.setFramerateLimit(60);


    CircleShape circle;
    CircleShape circle2;

    circle2.setRadius(20.f);
    circle2.setFillColor(Color::Yellow);

    circle.setRadius(50.f);
    circle.setFillColor(Color::Red);

    circle.setPosition(Vector2f(0 , 10.f));
    circle2.setPosition(Vector2f(0 , app.getSize().y - circle2.getRadius()*3));

//    RectangleShape sqr(Vector2f(100.f , 100.f));
//    sqr.setFillColor(Color::Red);
//    sqr.setPosition(app.getSize().x / 2 , app.getSize().y / 2);



//    CircleShape circle (50.f) ;
//    CircleShape circle2 (25.f) ;
//    RectangleShape rect(Vector2f(50.f , 100.f));
//
//
//    //TRINGLE
//
//    CircleShape triangle;
//    triangle.setRadius(50.f);
//    triangle.setPointCount(3); //number of vertex
//    triangle.setFillColor(Color::Black);
//    triangle.setOutlineThickness(5.f);
//    triangle.setOutlineColor(Color::Blue);
//
//    //LINE
//
//    Vertex line [] = {Vertex(Vector2f(100.f , 400.f)) , Vertex(Vector2f(100.f,100.f))};
//
//    //CONVEX
//
//    ConvexShape convex;
//    convex.setPosition(Vector2f(300.f , 300.f));
//    convex.setPointCount(5);
//
//    convex.setPoint(0 , Vector2f(0,0));
//    convex.setPoint(1 , Vector2f(150,10));
//    convex.setPoint(2 , Vector2f(120,90));
//    convex.setPoint(3 , Vector2f(600,100));
//    convex.setPoint(4 , Vector2f(0,50));
//
//
//
//
//
//    circle.setFillColor(Color::Red);
//    rect.setFillColor(Color::Red);
//    circle2.setFillColor(Color::White);
//
//    circle2.setPosition(Vector2f(125.f,50.f));
//    rect.setPosition(Vector2f(100.f,100.f));
//    circle.setPosition(Vector2f(100.f,50.f));

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if  (event.type == sf::Event::Closed)
                app.close();
//            if  (event.type == Event::KeyPressed && event.key.code == Keyboard::Num1)
//                app.close();
        }


//        if(Keyboard::isKeyPressed(Keyboard::W ) && sqr.getPosition().y > 0){
//                sqr.move(0.f , -5.f);
//
//        }
//        if(Keyboard::isKeyPressed(Keyboard::A ) && sqr.getPosition().x > 0){
//                sqr.move(-5.f , 0.f);
//
//        }
//        if(Keyboard::isKeyPressed(Keyboard::S ) && sqr.getPosition().y + sqr.getSize().y < app.getSize().y){
//                sqr.move(0.f , 5.f);
//
//
//        }
//        if(Keyboard::isKeyPressed(Keyboard::D ) && sqr.getPosition().x + sqr.getSize().x < app.getSize().x){
//                sqr.move(5.f , 0.f);
//
//        }

//        if(Keyboard::isKeyPressed(Keyboard::A)){
//         app.close();
//        }

//        if(Mouse::isButtonPressed(Mouse::Left))
//            app.close();
//        circle2.move(0.f,0.5f);
//        circle.move(0.2f,0.3f);
//        rect.move(-0.2f , 0.4f);
//        app.clear(Color::Yellow);

//        circle.rotate(-1.f);
//        circle2.rotate(-1.f);
//        rect.rotate(1.2f);
//
//        app.draw(triangle);
//        app.draw(convex);
//        app.draw(line ,2 , Lines);
//        app.draw(circle2);

//        app.draw(circle);
//        app.draw(rect);

            circle2.setPosition(Mouse::getPosition().x ,  circle2.getPosition().y);

//        Right and left
            if(flag == 1)
                circle.move(-5.f , 0.f);

            else if(flag == 0)
                circle.move(5.f , 0.f);

            if(circle.getRadius()*2 + circle.getPosition().x == app.getSize().x){
                flag = 1;

            }
            else if(circle.getPosition().x < 0){
                flag = 0;
            }




        app.clear();
        app.draw(circle2);
        app.draw(circle);

        app.display();
    }

    return EXIT_SUCCESS;
}