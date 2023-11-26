#ifndef ENEMY_H 
#define ENEMY_H 

#include "raylib.h"
#include "character.h"
#include <vector>
#include "../include//bullet.h"
#include <memory>

class Enemy : public Character{
private: 


    std::unique_ptr<Bullet>bullet{nullptr};
    
    bool shootReady{true};
    float bulletDistance{};
    const float timeToDrawFrame{1.f / 8.f};
    const int totalFramesToRender{2}; 
    float runningTime{0.f};


    Texture2D text{}; 
    int currentFrame{1}; 
    void frameUpdate(); 
    void shootingAction();
    void handleBulletLogic(); 
    void bulletMove(); 
    float bulletSpeed();

public:
    const std::unique_ptr<Bullet> &getBullet() const;


public: 
    virtual Rectangle calcDestRect() override; 
    virtual Rectangle calcSourceRect() override; 
    virtual void Render() override; 
    float getxPos(){
        return this->xPos; 
    }
    float getYPos(){
        return this->yPos; 
    }
    Texture2D getTexture() const{
        return this->text; 
    }

    
    Enemy(float xPos, float yPos);
    Enemy();

};




#endif 