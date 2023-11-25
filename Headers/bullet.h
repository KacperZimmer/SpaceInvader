#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "character.h"

class Bullet : public Character{
private: 
    const Texture buildTxt = LoadTexture("../sprites/bu.png");
    const int txtScale{16}; 
    const float bulletVelocity{5555}; 
 
public: 
    Bullet(float xPos, float yPos);

    virtual Rectangle calcDestRect() override; 
    virtual void Render() override;
    float getVelocity() const; 
    float getYPos() const; 
    Rectangle calcSourceRect() override; 

    Texture getBulletTexture(){
        return this->buildTxt; 
    }
}; 


#endif