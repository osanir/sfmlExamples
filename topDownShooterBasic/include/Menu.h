#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#define MAX_ITEM_SIZE 3

class Menu{
public:
    Menu(float width, float height);
    int run();

private:
    void moveUp();
    void moveDown();
    void render();

    sf::RenderWindow menuWindow;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Font font;
    
    sf::String menuItems[3] = {"Play", "Options", "Exit"};
    sf::Text menuText[MAX_ITEM_SIZE];
    
    int selectedItem;

};