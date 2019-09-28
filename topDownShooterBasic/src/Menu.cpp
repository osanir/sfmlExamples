#include "../include/Menu.h"

Menu::Menu(float width, float height)
: menuWindow(sf::VideoMode(width, height), "Menu", sf::Style::Default)
{
    menuWindow.setKeyRepeatEnabled(false);
    if( font.loadFromFile("res/8bit.ttf")){
        //error handle
    }

    if( !buffer.loadFromFile("res/blip.wav") ){
    }
    sound.setBuffer(buffer);


    for(int i=0; i<MAX_ITEM_SIZE; i++){
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(24);
        menuText[i].setString(menuItems[i]);
        menuText[i].setFillColor(sf::Color::White);
        menuText[i].setOrigin({menuText[i].getCharacterSize() * menuText[i].getString().getSize() /2.f, 0 });
        menuText[i].setPosition({width/2, (height/(MAX_ITEM_SIZE+1))*(i+1) });
    }
    selectedItem = 0;
    menuText[0].setFillColor(sf::Color::Red);
}

int Menu::run(){
    while(menuWindow.isOpen()){
        sf::Event event;
        while(menuWindow.pollEvent(event)){
            if( event.type == sf::Event::Closed ){
                    menuWindow.close();
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
                moveUp();
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
                moveDown();
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) ){
                menuWindow.close();
                return selectedItem;
            }

        }
        menuWindow.clear();
        for(int i=0; i<MAX_ITEM_SIZE; i++)
            menuWindow.draw(menuText[i]);
        menuWindow.display();
    }
}


void Menu::moveUp(){
    sound.play();
    menuText[selectedItem].setFillColor(sf::Color::White);
    selectedItem--;
    selectedItem += MAX_ITEM_SIZE;
    selectedItem %= MAX_ITEM_SIZE;
    menuText[selectedItem].setFillColor(sf::Color::Red);
}

void Menu::moveDown(){
    sound.play();
    menuText[selectedItem].setFillColor(sf::Color::White);
    selectedItem++;
    selectedItem += MAX_ITEM_SIZE;
    selectedItem %= MAX_ITEM_SIZE;
    menuText[selectedItem].setFillColor(sf::Color::Red);
}