#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

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

    TcpSocket socket;
    char connectionType;
    IpAddress ip = IpAddress::getLocalAddress();

    RectangleShape rect1, rect2;

    RenderWindow window;
    bool updateGame = false;
    Vector2f prevPosition, p2Position;

};