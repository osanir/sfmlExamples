#include "UserInterface.h"

Panel::Panel(Vector2f pos, Vector2f size){
    _pos.x      = pos.x * tileSize;
    _pos.y      = pos.y * tileSize;
    _size.x  = size.x * tileSize;
    _size.y = size.y * tileSize;
    
    if( !_texture.loadFromFile("res/texture/grey_panel.png") ){
        // error handle
    }


    for( int i=0; i<9; i++)
        _sprites[i].setTexture(_texture);

    // setting texture rects
    _sprites[0].setTextureRect(IntRect(0, 0, tileSize, tileSize));
    _sprites[1].setTextureRect(IntRect(tileSize, 0, tileSize, tileSize));
    _sprites[2].setTextureRect(IntRect(2*tileSize, 0, tileSize, tileSize));
    _sprites[3].setTextureRect(IntRect(0, tileSize, tileSize, tileSize));
    _sprites[4].setTextureRect(IntRect(tileSize, tileSize, tileSize, tileSize));
    _sprites[5].setTextureRect(IntRect(2*tileSize, tileSize, tileSize, tileSize));
    _sprites[6].setTextureRect(IntRect(0, 2*tileSize, tileSize, tileSize));
    _sprites[7].setTextureRect(IntRect(tileSize, 2*tileSize, tileSize, tileSize));
    _sprites[8].setTextureRect(IntRect(2*tileSize, 2*tileSize, tileSize, tileSize));


    // corner settings
    _sprites[0].setPosition({_pos.x, _pos.y});
    _sprites[2].setPosition({_pos.x + _size.x, _pos.y});
    _sprites[6].setPosition({_pos.x, _pos.y + _size.y});
    _sprites[8].setPosition({_pos.x + _size.x, _pos.y + _size.y});
}

void Panel::draw(RenderWindow& window){
    for( int j = _pos.y; j <= _pos.y + _size.y; j += tileSize){
        for( int i = _pos.x; i <= _pos.x + _size.x; i+= tileSize){
            if( j == _pos.y ){                     // TOP
                if( i == _pos.x ){                      // left
                    window.draw(_sprites[0]);
                }                          
                else if( i == _pos.x + _size.x ){        // right
                    window.draw(_sprites[2]);
                }
                else{                               // mid
                    _sprites[1].setPosition({float(i), float(j)});
                    window.draw(_sprites[1]);
                }
            }
            else if( j == _pos.y + _size.x ){      // BOTTOM
                if( i == _pos.x ){                      // left
                    window.draw(_sprites[6]);
                }
                else if( i == _pos.x + _size.x ){        // right
                    window.draw(_sprites[8]);
                }
                else {
                    _sprites[7].setPosition({float(i), float(j)});// mid
                    window.draw(_sprites[7]);
                }
            } 
            else{                           // CENTER
                if( i == _pos.x ){                      // left
                    _sprites[3].setPosition({float(i),float(j)});
                    window.draw(_sprites[3]);
                }                          
                else if( i == _pos.x + _size.x ){        // right
                    _sprites[5].setPosition({float(i),float(j)});
                    window.draw(_sprites[5]);
                }    
                else {
                    _sprites[4].setPosition({float(i), float(j)});// mid
                    window.draw(_sprites[4]);
                }
            }
        }
    }
}


////// BUTTON //////
Button::Button(Vector2f pos){
    _state = 'n'; // n normal, h hover, c click
    _pos = pos;

    _texture[0].loadFromFile("res/texture/cookie1.png");
    _texture[1].loadFromFile("res/texture/cookie2.png");
    _texture[2].loadFromFile("res/texture/cookie3.png");

    _sprite.setTexture(_texture[0]);
    _sprite.setPosition({_pos.x, _pos.y});

    initButton();
}


Button::Button(Vector2f pos, string text){
    // standart settings
    _state = 'n'; // n normal, h hover, c click
    _pos = pos;
    _text.setCharacterSize(24);
    _text.setOrigin({0, float(_text.getCharacterSize()/1.5)});

    // button settings
    _texture[0].loadFromFile("res/texture/button.png");
    _texture[1].loadFromFile("res/texture/button_hover.png");
    _texture[2].loadFromFile("res/texture/button_click.png");

    _sprite.setTexture(_texture[0]);
    _sprite.setPosition({_pos.x, _pos.y});

    _imagePoints[0] = {_texture[0].getSize().x/8.f, _texture[0].getSize().y/2.f};  // icon point
    _imagePoints[1] = {_texture[0].getSize().x/8.f + 20, _texture[0].getSize().y/2.f};  // text point

    // icon settings
    _textureIcon.loadFromFile("res/texture/checkmark.png");
    _spriteIcon.setTexture(_textureIcon);
    _spriteIcon.setOrigin({_textureIcon.getSize().x/2.f, _textureIcon.getSize().y/2.f});
    _spriteIcon.setPosition({_sprite.getPosition().x + _imagePoints[0].x, _sprite.getPosition().y + _imagePoints[0].y});
    _spriteIcon.setColor(Color(115, 205, 75));


    // text settings
    _font.loadFromFile("res/font/future.ttf");
    _text.setFont(_font);
    _text.setString(text);
    _text.setPosition({_sprite.getPosition().x + _imagePoints[1].x, _sprite.getPosition().y + _imagePoints[1].y});
    _text.setFillColor(Color::White);
    _text.setOutlineColor(Color(115, 205, 75));
    _text.setOutlineThickness(2);

    initButton();
}

void Button::draw(RenderWindow& window){
    window.draw(_sprite);
    window.draw(_spriteIcon);
    window.draw(_text);
}

void Button::initButton(){


    _size.x = _texture[0].getSize().x;
    _size.y = _texture[0].getSize().y;

}

void Button::update(){
    switch( _state ){
        case 'n':
            _sprite.setTexture(_texture[0]);
            _spriteIcon.setColor(Color(115, 205, 75));
            break;
        case 'h':
            _sprite.setTexture(_texture[1]);
            _spriteIcon.setColor(Color::White);
            break;
        case 'c':
            _sprite.setTexture(_texture[2]);
            break;
    }
}

bool Button::clicked(RenderWindow& window){
    if( !Mouse::isButtonPressed(Mouse::Button::Left) && _state == 'c' ){
        _state = 'h';
        return true;
    }
    if( isInside(Mouse::getPosition(window)) ){
        _state = 'h';
        if( Mouse::isButtonPressed(Mouse::Button::Left) ){
            _state = 'c';
        }
    } else
        _state = 'n';

    return false;
}

bool Button::isInside(Vector2f pos){
    if( pos.x > _pos.x && pos.x < _pos.x + _size.x && 
        pos.y > _pos.y && pos.y < _pos.y + _size.y)
        return true;
    return false;
}

bool Button::isInside(Vector2i pos){
    if( pos.x > _pos.x && pos.x < _pos.x + _size.x && 
        pos.y > _pos.y && pos.y < _pos.y + _size.y)
        return true;
    return false;
}

void Button::setString(string text){
    _text.setString(text);
}

Vector2f Button::getSize(){
    return _size;
}

Vector2f Button::getPosition(){
    return _pos;
}

string Button::getText(){
    return _text.getString();
}


////// LABEL //////

Label::Label(Vector2f pos, string text){
    _pos = pos;
    _text.setString(text);
    _text.setCharacterSize(20);
    _text.setFillColor(Color::White);
    _text.setOutlineThickness(2);
    _text.setOutlineColor(Color::Black);
}

void Label::draw(RenderWindow& window){
    window.draw(_text);
}

void Label::setPosition(Vector2f pos){
    _text.setPosition(pos);         
}

void Label::setString(string text){
    _text.setString(text);
}

void Label::setCharacterSize(int size){
    _text.setCharacterSize(size);
}

void Label::setFillColor(Color color){ 
    _text.setFillColor(color);
}

void Label::setOutlineColor(Color color){ 
    _text.setOutlineColor(color);
}

Vector2f Label::getPosition(){
    return _text.getPosition();
}
