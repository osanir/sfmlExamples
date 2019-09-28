#include "../include/MapEditor.h"

MapEditor::MapEditor()
: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Editor", sf::Style::Default)
, paletteWindow(sf::VideoMode(320,320), "Palette", sf::Style::Titlebar | sf::Style::None )
{
    std::string filename = "res/tilemap.png";
    if (!tilemapTexture.loadFromFile(filename) ){
        std::cout << "Tilemap could not load from " << filename << std::endl;
    }
    gridSize = 32;
    tilemapSize.x = tilemapTexture.getSize().x / gridSize;
    tilemapSize.y = tilemapTexture.getSize().y / gridSize;

    tilemapSprite.setTexture(tilemapTexture);
    tilemapSprite.setPosition({0,0});
    
    selectedGrid.setFillColor(sf::Color(255,0,0,0));
    selectedGrid.setOutlineThickness(2.0);
    selectedGrid.setOutlineColor(sf::Color::Red);
    selectedGrid.setSize({float(gridSize), float(gridSize)});

    currentTilePos = {1,1};
}

void MapEditor::run(){
    paletteWindow.clear();
    paletteWindow.draw(tilemapSprite);
    paletteWindow.display();
    paletteWindow.setSize({tilemapSize.x*gridSize, tilemapSize.y*gridSize});
    while(window.isOpen() ){
        processEvents();
        update();
        render();
    }
}

void MapEditor::processEvents(){
    sf::Event event;
// MAIN WINDOW
    while( window.pollEvent(event) ){
        switch(event.type){
            case sf::Event::Closed:
                paletteWindow.close();
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                tileset.push_back({{selectedGrid.getPosition().x, selectedGrid.getPosition().y}, currentTilePos});
                break;
            case sf::Event::GainedFocus:
                focusMainWindow = true;
                break;
            case sf::Event::LostFocus:
                focusMainWindow = false;
                break;
            case sf::Event::MouseMoved:
                if( focusMainWindow ){
                    int x = sf::Mouse::getPosition(window).x;
                    int y = sf::Mouse::getPosition(window).y;

                    x -= x % gridSize;
                    y -= y % gridSize;

                    selectedGrid.setPosition({float(x), float(y)});
                }
                break;
        }
    }


// PALETTE WINDOW
    while( paletteWindow.pollEvent(event) ){
        switch(event.type){
            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse button pressed" << std::endl;
                break;
            case sf::Event::GainedFocus:
                focusPaletteWindow = true;
                break;
            case sf::Event::LostFocus:
                focusPaletteWindow = false;
                break;
            case sf::Event::MouseMoved:
                if( focusMainWindow ){
                    int x = sf::Mouse::getPosition(paletteWindow).x;
                    int y = sf::Mouse::getPosition(paletteWindow).y;

                    x -= x % gridSize;
                    y -= y % gridSize;
                    selectedGrid.setPosition({float(x), float(y)});
                    if( sf::Mouse::isButtonPressed(sf::Mouse::Left) ){

                    }
                }
                break;
        }

    }
}

void MapEditor::update(){

}

void MapEditor::render(){
    window.clear(sf::Color(128,128,128));
    if( focusMainWindow )
        window.draw(selectedGrid);
    // TODO Tile 'a sprite ekle
    window.display();

}
