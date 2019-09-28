#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

using namespace sf;
using namespace std;

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768

class Coin{
public:
    int order;
    float speed;
    Vector2f targetPos;
    CircleShape body;
};

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();

    void initGameObjects();
    void createEnvironment();
    void createRandomObjects();
    
    float lerp(float x, float y, float z);

    Vector2f horizon;
    Vector2f windowCenter;
    vector<Coin*> coins;
    vector<VertexArray> environment;
    RenderWindow window;

};