#include <string>
class Assistant{
public:
    Assistant();

    std::string getName();
    float getCost();
    float getFriendliness();
    float getDexterity();
private:
    std::string name;
    float cost;
    float friendliness;
    float dexterity;
};