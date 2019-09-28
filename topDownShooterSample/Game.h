#include <iostream>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

using namespace std;
using namespace sf;

class Game{
public:
    Game();
    void run();
private:
    // System functions
    void processEvents();
    void update();
    void render();

    // Math functions
    float lerp(float x, float y, float z);

    // Game funcitons
    float setPlayerRotation();
    void fire();
    void updateBullets();

    Font font;
    Text text;
    Clock clock;
    int frame = 0;
    float dTime;

    RenderWindow window;
    RectangleShape player;
    RectangleShape gun;
    list<CircleShape> bullets;
    
    const float MAXSPEED = 10;
    const Vector2f UP = {0, -1};
    Vector2f VELOCITY;
    Vector2f SPEED;

    bool isMovingRight = false;
    bool isMovingLeft = false;
    bool isMovingUp = false;
    bool isMovingDown = false;
};