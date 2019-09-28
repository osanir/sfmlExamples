#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main(){
    Sound sound;
    SoundBuffer soundBuffer;
    Music music;
    Clock myClock;
    myClock.restart();
    soundBuffer.loadFromFile("snowfall.ogg");

    cout << "Channel Count: " << soundBuffer.getChannelCount() << endl;
    cout << "Duration: " << soundBuffer.getDuration().asSeconds() << endl;
    cout << "Sample Count: " << soundBuffer.getSampleCount() << endl;
    cout << "Sample Rate: " << soundBuffer.getSampleRate() << endl;
    cout << "Samples: " << soundBuffer.getSamples() << endl;

    sound.setBuffer(soundBuffer);
    sound.setLoop(true);
    sound.play();

    const Int16* samp = soundBuffer.getSamples();
    for(int i=0; i<10; i++){
        cout << samp[i] << endl;
    }
    while(1)
        printf("%2d:%2d\r\r\r\r\r\r", myClock.getElapsedTime().asSeconds()/60, int(myClock.getElapsedTime().asSeconds())%60);
    int ch;
    cin >> ch;
    return 0;
}