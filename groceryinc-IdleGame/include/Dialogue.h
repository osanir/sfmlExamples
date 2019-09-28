#include <iostream>
#include <string>


struct DialogueNode{
    std::string text;
    std::string opiton1, option2;
    DialogueNode *next1, *next2;
    int effect1, effect2;
};

class Dialogue{
public:
    Dialogue();
    int showDialogue();
    void setDialogue();
private:
    struct DialogueNode *root;
    int effect;
    struct DialogueNode all_dialogues[4];
};
