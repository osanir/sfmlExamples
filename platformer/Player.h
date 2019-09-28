#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player{
public:
    Player();
    RectangleShape getShape();

private:
    const float GRAVITY  = 0.10;
    const float MAXSPEED = 1;
    Vector2f SPEED;
    RectangleShape shape;
};