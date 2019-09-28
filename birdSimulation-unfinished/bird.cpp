#include "bird.h"

Bird::Bird(){
    toward = nullptr;
}

Bird::Bird(int posX, int posY){
    x = posX;
    y = posY;
    toward = nullptr;
}

void Colony::find_nearest(){
    list<Bird>::iterator thisBird;
    list<Bird>::iterator towardedBird;
    thisBird = birds.begin();
    
    while( thisBird != birds.end() ){
        list<Bird>::iterator choosenBird = thisBird;
        towardedBird = choosenBird;
        choosenBird++;
        while(choosenBird != birds.end() ){
            if( difference_between(thisBird->pos, choosenBird->pos) >  )
        }

        thisBird++;
    }
}

int Colony::difference_between(Bird bird1.pos, Bird bird2.pos){
    int sumX, sumY;
    sumX = bird1.x + bird2.x;
    sumY = bird1.y + bird2.y;

    if(sumX < 0)    sumX *= -1;
    if(sumY < 0)    sumY *= -1;

    return sumX + sumY;
}
