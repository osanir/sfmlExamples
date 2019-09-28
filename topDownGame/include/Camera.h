#include "GameEngine.h"

<<<<<<< HEAD
class Camera{
public:
    Camera();
    void update(Vector2f, Vector2f);
=======

class Camera{
public:
    Camera();
    void update(Vector2f);
>>>>>>> master
    View getView();
private:
    View view;
    Vector2f position;
};