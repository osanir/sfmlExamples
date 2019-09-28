#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

#include "Camera.h"

using namespace sf;
using namespace std;

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768

class Player{
    friend class Game;
public:
    Player();
    void move(sf::Time deltaTime);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void updateRotation(RenderWindow &window, View view);
    Vector2f getPosition();
private:
    sf::RectangleShape body;
    sf::Texture texture;
    sf::Sprite sprite;


    sf::Vector2f movement;
    float speed;

    // states
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
};

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    float getAngleTowardPosition(Vector2f source, Vector2f target);
    
    Camera camera;

    RenderWindow window;
    Player player;

};
