#include <list>
using namespace std;

typedef struct Bird{
    Bird();
    Bird(int, int);

    struct pos{
        int x;
        int y;
    };
    Bird *toward;
};

class Colony{
public:
    void addBird();
    void find_nearest();
    int difference_between(Bird, Bird);
private:
    list<Bird> birds;
}