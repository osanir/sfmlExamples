#include "SFML/Graphics.hpp"

using namespace sf;

class Camera{
public:
    Camera(float width, float height);
    void update(Vector2f playerPos, Vector2f layoutSize);
    View getView();
private:
    float SCREEN_WIDTH, SCREEN_HEIGHT;
    View view;
    Vector2f position;
};