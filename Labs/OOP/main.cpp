#include <iostream>
#include <cmath> // For atan and atan2 functions
#include <array> // For std::array
//#include <string> // For std::string
#include "log.cpp"

using namespace std; // to use all standerds directly

class Interfacing {
public:
    virtual int getDirection() = 0;
};


class Entity :public Interfacing{

public:
    float x, y;
    string name;
    array<string, 9> skills;

    explicit Entity(int a, int b) // to avoid implicit type conversion
        : x(a), y(b) { // initializer list
        name = "";
    }

    virtual void print() {
        cout << x << " " << y << endl;
    }

    int getDirection() {
        return atan(y/x) * 180 / 3.14 ;
    }

    string getName() {
        return name;
    }


    void setName(const string s) {
        name = s;
    }

};

class Player : public Entity { // Inheritance 
private:
    int level; // abstraction -->

public:
    Player(float a = 0, float b = 0) : Entity(a, b), level(0) {}

    void setLevel(int); // <-- abstraction

    void print() override { // polymorphism
        cout << level << endl;
    }

    int getDirection() {
        return atan(y / x) * 180 / 3.14;
    }
};

class Monester : public Entity { // Inheritance 
public:
    Monester(float a = 0, float b = 0) : Entity(a, b) {} // call it a nested constructor

};


void Player::setLevel(int l) { // a use of ::
    level = l;
} 


void printdata(Entity* e) { // to test virtual functions
    e->print();
}

int direction(Entity* e) {
    return e->getDirection();
}

int main() {

    Log log;
    log.setLogLevel(infoLevel);

    Player player(3,1);
    player.setLevel(10);
    
    Entity* player2 = new Player(2, 5);
    Entity* monester1 = new Monester(8, 9);

    player2->x = 3;
    player2->y = 4;
    monester1->x = 4;
    monester1->y = 3;

    player2->setName("ali");
    cout << player2->getName() << endl;

    cout << direction(player2) << endl;
    cout << direction(monester1) << endl;

    log.print("INFO", "player level was set to 10");
    log.print("WARN", "player level was set to 10");
    log.print("ERROR", "player level was set to 10");
     
    printdata(&player);

    delete player2;

    
    return 0;
}
 

