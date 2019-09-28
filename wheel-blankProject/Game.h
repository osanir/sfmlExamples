#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();

    RenderWindow window;

};