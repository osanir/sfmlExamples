#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768

struct Tile{
    sf::Vector2f pos;
    sf::Vector2f tile;
};

class MapEditor{
public:
    MapEditor();
    void run();
private:
    void exportMap();
    void processEvents();
    void update();
    void render();

    int gridSize;
    sf::Vector2u tilemapSize;

    sf::Texture tilemapTexture;
    sf::Sprite tilemapSprite;

    sf::RectangleShape selectedGrid;

    bool focusMainWindow = false;
    bool focusPaletteWindow = false;


    sf::Vector2f currentTilePos;
    std::vector<Tile> tileset;

    sf::RenderWindow window;
    sf::RenderWindow paletteWindow;
};
