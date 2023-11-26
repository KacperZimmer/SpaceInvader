#ifndef MAINPLAYER_H 
#define MAINPLAYER_H

#include "raylib.h"
#include "character.h"
#include "../include//bullet.h"
#include <memory>

class MainPlayer : public Character{
private: 
    const int mainPlayerVelocity{250}; 
    bool shootReady{true};
    float bulletDistance{};
    float ChangeBulletTrajectory();
    void handleBulletLogic(); 
    void handleMovementLogic();
    std::unique_ptr<Bullet> bullet{nullptr};

public:

    static const int scaleVector{4};

    MainPlayer(Texture2D texture, float x, float y);
    std::unique_ptr<Bullet> &getBullet() ;

    void Render() override;
    Rectangle calcDestRect() override;
    Rectangle calcSourceRect() override;

};


#endif