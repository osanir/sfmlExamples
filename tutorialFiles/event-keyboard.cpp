#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    Window window(sf::VideoMode(800, 600), "My window");
    window.setKeyRepeatEnabled(true);   // basılı tutulduğunda harfin ard arda yazılması olayı
    window.setPosition(sf::Vector2i(100, 100) );
    while( window.isOpen() ){

        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        std::cout << "the escape key was pressed" << std::endl;
                        std::cout << "control:" << event.key.control << std::endl;
                        std::cout << "alt:" << event.key.alt << std::endl;
                        std::cout << "shift:" << event.key.shift << std::endl;
                        std::cout << "system:" << event.key.system << std::endl;
                    }
                    break;

                case sf::Event::Resized:
                    cout << "new width" << event.size.width << endl;
                    cout << "new height" << event.size.height << endl;
                    break;

                case sf::Event::LostFocus:
                    //myGame.pause();
                    break;
                case sf::Event::GainedFocus:
                    //myGame.resume();
                    break;
                
                case sf::Event::TextEntered:
                   // char a = (event.text.unicode < 128) ? static_cast<char>(event.text.unicode) : 48;
                    //cout << "Girilen karakterin unicode değeri: " << a << endl;
                    cout << "Girilen karakterin unicode değeri: " << event.text.unicode << endl;
                    break;
                case sf::Event::MouseWheelMoved:
                    cout << "Mouse wheel moved." << endl;
                
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                        std::cout << "wheel type: vertical" << std::endl;
                    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                        std::cout << "wheel type: horizontal" << std::endl;
                    else
                        std::cout << "wheel type: unknown" << std::endl;
                    std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                    std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                    std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
                    
                    break;

                case sf::Event::MouseButtonPressed:
                    if( event.mouseButton.button == sf::Mouse::Right )
                        cout << "Right mouse button pressed!" << endl;
                    else if( event.mouseButton.button == sf::Mouse::Left )
                        cout << "Left mouse button pressed!" << endl;
                    
                    cout << "mouse x :" << event.mouseButton.x << endl;
                    cout << "mouse y :" << event.mouseButton.y << endl;
                    break;
                
                case sf::Event::MouseMoved:
                    cout << "Mouse moved!" << endl;
                    cout << "mouse x :" << event.mouseButton.x << endl;
                    cout << "mouse y :" << event.mouseButton.y << endl;                    
                    break;

                case sf::Event::MouseEntered:
                    cout << "the mouse cursor has entered the window" << endl;
                    break;

                case sf::Event::MouseLeft:
                    cout << "the mouse cursor has left the window" << endl;
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }

    }
    return 0;
}