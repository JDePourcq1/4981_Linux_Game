#ifndef WEAPONDROP_H
#define WEAPONDROP_H
#include <string>
#include "LTexture.h"
#include "HitBox.h"
#include "Entity.h"
#include "CollisionHandler.h"
#include "weapons/Weapon.h"
#include <SDL2/SDL.h>

class WeaponDrop: public Entity{
public:
    WeaponDrop(int32_t wId);
    WeaponDrop(const WeaponDrop &wd);
    ~WeaponDrop();
    void setPosition(int x, int y);
    void onCollision();
    int32_t getId();

    void collidingProjectile(int damage);
    
    int getX() const;
    int getY() const;
    int32_t getWeaponId();


private:
    int xCoord;
    int yCoord;
    int32_t weaponId;
};


#endif
