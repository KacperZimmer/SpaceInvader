#ifndef MAINPLAYER_H 
#define MAINPLAYER_H

#include "raylib.h"
#include "character.h"
#include "../Headers/bullet.h"
#include <memory>

class MainPlayer : public Character{
private: 
    const int mainPlayerVelocity{250}; 
    bool showRectangle{false}; 
    bool shootReady{true}; 
    float bulletDistance{};
    float SetBulletTrajectory();
    float ChangeBulletTrajectory();
    void handleBulletLogic(); 
    void handleMovementLogic(); 
public: 

    std::unique_ptr<Bullet> bullet{nullptr}; 
    static const int scaleVector{4}; 

    MainPlayer(Texture2D texture, float x, float y); 
    virtual void Render() override; 
    virtual Rectangle calcDestRect() override; 
    virtual Rectangle calcSourceRect() override; 

};


#endif