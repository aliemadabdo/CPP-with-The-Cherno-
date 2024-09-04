#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h>

// #define NO_SURVIVALS 0
// #define LEFT -1
// #define RIGHT 1

/*
constexpr: Variables declared with constexpr are evaluated at compile time,
 just like #define, but they also benefit from the 
 type safety and scoping mentioned above.
*/

constexpr int NO_SURVIVALS = 0;
constexpr int LEFT = -1;
constexpr int RIGHT = 1;

using namespace std;

bool isCollidable(int rightMovingAsteroid, int leftMovingAsteroid){

    if((rightMovingAsteroid > 0) && (leftMovingAsteroid < 0)){
        return true;
    } else{
        return false;
    }
}

int survival(int rightMovingAsteroid, int leftMovingAsteroid){
    if(rightMovingAsteroid == abs(leftMovingAsteroid)){
        return NO_SURVIVALS;
    } else {
        return rightMovingAsteroid > abs(leftMovingAsteroid) ? RIGHT : LEFT;
    }
}

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivedAsteroids;

        for (int asteroid : asteroids){
            bool survivedCurrent = true; // Track if the current asteroid survives

            while( (!survivedAsteroids.empty()) && 
                   (isCollidable(survivedAsteroids.back(), asteroid)) &&
                   (survivedCurrent)){
                
                int survived = survival(survivedAsteroids.back(), asteroid);
                if(survived == RIGHT){
                    survivedCurrent = false; // current asteroid dead
                    break;
                }
                else if(survived == NO_SURVIVALS){
                    survivedAsteroids.pop_back(); // top asteroid dead
                    survivedCurrent = false; // current asteroid dead
                } else {
                    survivedAsteroids.pop_back(); // top asteroid dead
                }
            }

            // Add the current asteroid to the stack if it survived
            if (survivedCurrent) {
                survivedAsteroids.emplace_back(asteroid);
            }
        }

        return survivedAsteroids;
    }
};

int main() {
    Solution solution;

    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = solution.asteroidCollision(asteroids1);
    cout << "Test 1: ";
    for (int a : result1) {
        cout << a << " ";
    }
    cout << endl;

    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = solution.asteroidCollision(asteroids2);
    cout << "Test 2: ";
    for (int a : result2) {
        cout << a << " ";
    }
    cout << endl;

    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = solution.asteroidCollision(asteroids3);
    cout << "Test 3: ";
    for (int a : result3) {
        cout << a << " ";
    }
    cout << endl;

    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = solution.asteroidCollision(asteroids4);
    cout << "Test 4: ";
    for (int a : result4) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
