#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{
    Window window(sf::VideoMode(800, 600), "My window");
    int i=0;
    while( window.isOpen() ){
        Event event;
        while( window.pollEvent(event) ){
            switch ( event.type ){
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseWheelMoved:
                    cout << "Fare Tekerleği" << endl;
                    break;
                case Event::MouseMoved:
                    cout << "Fare Oynatıldı " << endl;
                    break;
                case Event::GainedFocus:
                    cout << "Fokuslandı " << endl;
                    break;
                default:
                    break;
            }                
        }

    }

    return 0;
}