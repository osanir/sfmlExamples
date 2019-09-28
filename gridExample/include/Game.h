#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

using namespace sf;
using namespace std;

struct Player{
    RectangleShape body;
    Vector2f pos;
    Player(){
        body.setSize({16,16});
        body.setPosition({0,0});
        body.setFillColor(Color::Red);
    }
    void move(){
        body.setPosition({((1.0f - 0.1) * body.getPosition().x) + (0.1 * pos.x), ((1.0f - 0.1) * body.getPosition().y) + (0.1 * pos.y)});
    }
};

class Game{
public:
    Game();
    void run();
private:
    void processEvents(Clock clock);
    void update();
    void render();
    
    float lerp(float x, float y, float z);

    void createGrids();
    void drawLines();

    vector<RectangleShape*> lines;

    Player player;

    int gridSize;
    Vector2f horizon;
    Vector2f windowCenter;
    RenderWindow window;

};