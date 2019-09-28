#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(640, 480), "My Vertex Title", Style::Default|Style::Resize);

    Vertex vertex;
//    vertex.position = Vector2f(10, 50);
    vertex.position = {10, 50};   //setting position
    vertex.color = Color::Red;      //setting color
    vertex.texCoords = Vector2f(100,100); // setting texture coordinates

    // or using the correct constructor:
    //sf::Vertex vertex(sf::Vector2f(10, 50), sf::Color::Red, sf::Vector2f(100, 100));

    VertexArray triangle(Triangles, 3);

    triangle[0].position = Vector2f(10, 10);
    triangle[1].position = Vector2f(100, 10);
    triangle[2].position = Vector2f(100, 100);

    triangle[0].color = Color::Red;
    triangle[1].color = Color::Green;
    triangle[2].color = Color::Blue;


    VertexArray lines( Lines, 2);
    lines[0].position = Vector2f(200, 200);
    lines[1].position = Vector2f(300, 300);

    lines[0].color = Color::Red;
    lines[1].color = Color::Yellow;

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }

            if(event.MouseMoved){
                lines[1].position = Vector2f( Mouse::getPosition(window) );
            }

            window.clear();
//            window.draw(triangle);
            window.draw(lines);
            window.display();
        }
    }
}
