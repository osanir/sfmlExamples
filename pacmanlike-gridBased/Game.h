#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using namespace sf;
using namespace std;

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();
    void movePlayer();
    void moveEnemies();
    void checkCollisions();
    float grid;

    int score;
    int health;
    Font font;
    Text text_score;
    Text text_health;

    Clock clock;
    Time dt;

    Sprite bg;
    Texture texture;

    RenderWindow window;
    RectangleShape player;
    RectangleShape enemy[4];
    char direction;
};