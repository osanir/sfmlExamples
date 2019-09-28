#include "Player.h"

Player::Player(){
    shape.setSize(Vector2f(20, 20));
    shape.setFillColor(Color::Black);
    shape.setPosition(Vector2f(300, 300));
}

RectangleShape Player::getShape(){
    return shape;
}


