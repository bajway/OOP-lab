/*You’re building a next-level game engine, and you need a system to keep track of all the important
stuff—like where things are and how badly they’re injured. To do this, you decide to create two
almighty base classes:
 Position – This class ensures that your game objects know where they are in 3D space
because teleporting randomly isn’t a great gameplay feature (unless you're making a glitch
simulator). It will have three trusty coordinates: x, y, and z—so objects don’t accidentally
fall into the void.
 Health – Because what’s a game without damage? This class keeps track of an object’s
health, making sure your characters don’t just shrug off dragon attacks like minor
inconveniences.
Now, things get even more interesting. You create the Character class, which inherits from both
Position and Health (because why settle for just one inheritance when you can have both?). This
class will represent the heroes and warriors of your game, complete with their own special abilities
and actions. Finally, in your main function, you’ll create a Character object, set its position and
health, and then show it off—because what’s the point of writing all this glorious code if you don’t
get to see your hero standing (or limping) in 3D space? So, fire up your keyboard, prepare for some

legendary multiple inheritance, and let’s build a game world that doesn’t instantly collapse into
chaos!*/

#include <iostream>
#include <string>

using namespace std;
class Coordinates {
private:
    float coordinateX, coordinateY, coordinateZ;
public:
    Coordinates(float x, float y, float z) : coordinateX(x), coordinateY(y), coordinateZ(z) {}

    void updatePosition(float x, float y, float z) {
        coordinateX = x;
        coordinateY = y;
        coordinateZ = z; }

    void showPosition() const {
        cout << "Position: \n X: " << coordinateX << " Y: " << coordinateY << " Z: " << coordinateZ; }
};

class HealthStatus {
private:
    int healthPoints;
public:
    HealthStatus(int hp) : healthPoints(hp) {}
    void takeDamage(int damage) 
{        healthPoints -= damage;
        if (healthPoints < 0) 
            healthPoints = 0; }

    void recoverHealth(int heal) {
        healthPoints += heal; }

    void showHealth() const {
        cout << "Health: " << healthPoints << endl; }
};

class GameCharacter : public Coordinates, public HealthStatus {
private:
    string characterName;
public:
    GameCharacter(string name, float x, float y, float z, int hp) : Coordinates(x, y, z), HealthStatus(hp), characterName(name) {}

    void showCharacter() const 
{       cout << "Character: " << characterName << endl;
        showPosition();
        showHealth(); }
};
int main() {
    GameCharacter player("Aragon", 105.5, 22.3, 40.8, 1200);
    player.showCharacter();
    player.takeDamage(450);
    cout << "After taking damage:" << endl;
    player.showCharacter();
    player.recoverHealth(300);
    cout << "After healing:" << endl;
    player.showCharacter();
    return 0;
}
