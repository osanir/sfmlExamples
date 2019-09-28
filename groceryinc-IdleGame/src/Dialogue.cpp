#include "../include/Dialogue.h"

Dialogue::Dialogue(){
    setDialogue();
    
}

int Dialogue::showDialogue(){
    while(1){
        std::cout << (*root).text << std::endl;
        if( (root->next1 == NULL ) && (root->next2 == NULL ) ){
            std::cout << "henüz değil" << std::endl;
            return effect;
        }
        std::cout << "1. " << (*root).opiton1 << std::endl;
        std::cout << "2. " << (*root).option2 << std::endl;
        int ch;
        std::cin >> ch;
        if( ch == 1 ){
            effect += root->effect1;
            root = root->next1;
        } 
        if( ch == 2 ){
            effect += root->effect2;
            root = root->next2;
        } 
    
    }
}

void Dialogue::setDialogue(){
    all_dialogues[0] = {
        "Merhaba, nasılsın?",                          // 0
        "Teşekkür ederim, iyiyim", "Seni sormalı.", 
        &all_dialogues[1], &all_dialogues[2],
        -10, 10};
    all_dialogues[1] = {
        "Benim nasıl olduğumu neden sormuyorsun?",     // 1
        "Merak etmiyorum.", "Haklısın, sen nasılsın?",
        &all_dialogues[3], &all_dialogues[2],
        -10, 10};
    all_dialogues[2] = {
        "Ahh, teşekkür ederim evladım. Ben de iyiyim.", // 2
        "a", "b",
        NULL, NULL,
        0,0};
    all_dialogues[3] = {
        "Terbiyesiz çocuk!",                           // 3
        "c", "d",
        NULL, NULL,
        0,0};
    root = &all_dialogues[0];
}