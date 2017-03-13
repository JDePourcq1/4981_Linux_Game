#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <memory>
#include "HitBox.h"
#include "LTexture.h"
#include <SDL2/SDL.h>

class Entity {
public:
    Entity();
    virtual ~Entity();
    virtual void onCollision() = 0;
    virtual void collidingProjectile(int damage) = 0;
    void setPosition(float x, float y); // Set marine position
    void setX(float px); //set x coordinate
    void setY(float py); //set y coordinate
    float getX() const; // get x coordinate
    float getY() const; // get y coordinate
    void updateHitBoxes(); // update hitbox positions
    void updateRectHitBoxes(); // update hitbox sizes

    void setID(const int& id) {_id = id;};
    int& getID() {return _id;};

    std::shared_ptr<HitBox> movementHitBox;
    std::shared_ptr<HitBox> projectileHitBox;
    std::shared_ptr<HitBox> damageHitBox;
    std::shared_ptr<HitBox> pickupHitBox;

    LTexture texture;
    SDL_Rect spriteClips[1];

private:
    int _id;
    float x = 0; //x coordinate
    float y = 0; //y coordinate

};

#endif
