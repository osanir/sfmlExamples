#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();

    bool checkFloorCollision();
    void push(RectangleShape*, Vector2f);
    void createObject(Vector2f position, Vector2f size);
    void importMap();

    float lerp(float x, float y, float z);

    Font font;
    Text text;
    Clock clock;
    int frame = 0;
    float dTime;

    RenderWindow window;
    RectangleShape player;
    RectangleShape player_bottom;
    RectangleShape player_left;
    RectangleShape player_right;

    RectangleShape floor;

    vector<RectangleShape*> gameObjects;

    const float GRAVITY = 0.10;
    const float MAXSPEED = 10;
    const float MAXFALLSPEED = 1000000;
    const Vector2f UP = {0, -1};
    Vector2f VELOCITY;
    Vector2f SPEED;

    bool canJump = false;
    bool isOnFloor = false;

    bool isMovingRight = false;
    bool isMovingLeft = false;
    bool isMovingJump = false;
};