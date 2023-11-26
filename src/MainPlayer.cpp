#include "../include//enemy.h"
#include "../include//MainPlayer.h"
#include "../include//gamePanel.h"
#include <memory>
#include <iostream>

MainPlayer::MainPlayer(Texture2D texture, float x, float y) {
    text = texture;
    height = (texture.height) / scaleVector;
    width = (texture.width) / scaleVector;
    xPos = x;
    yPos = y;
}

Rectangle MainPlayer::calcDestRect() {

    Rectangle rect{};
    rect.x = xPos;
    rect.y = yPos;
    rect.width = getWidth();
    rect.height = getWidth();

    return rect;
}

Rectangle MainPlayer::calcSourceRect(){

    Rectangle rect; 
    rect.x = 0.f; 
    rect.y = 0.f; 
    rect.width = text.width; 
    rect.height = text.height; 

    return rect; 
}

float MainPlayer::ChangeBulletTrajectory(){
    bulletDistance -= 4; 
    return bulletDistance; 
}

void MainPlayer::handleBulletLogic(){
    
    if (this->bullet && bullet->getYPos() > 0) {
        bullet->setYPos(ChangeBulletTrajectory()); 
        bullet->Render();

    }else{ 
        shootReady = true;
        bullet.reset();
    }

}
void MainPlayer::handleMovementLogic(){
 DeltaTime = GetFrameTime(); 
 
    if (IsKeyDown(KEY_A)) {
        xPos -= (DeltaTime) * mainPlayerVelocity;
    } else if (IsKeyDown(KEY_D)) {
        xPos += (DeltaTime) * mainPlayerVelocity;
    }
    
    if (IsKeyDown(KEY_SPACE) && shootReady) {
        shootReady = false;
        bulletDistance = yPos;

        bullet = std::make_unique<Bullet>(xPos + width/2.04f, yPos);

    }
}

void MainPlayer::Render() {

    handleMovementLogic(); 
    handleBulletLogic(); 
    DrawTexturePro(text, calcSourceRect(), calcDestRect(), Vector2{}, 0.f, WHITE);

    std::cout << xPos << std::endl ;
}

 std::unique_ptr<Bullet> &MainPlayer::getBullet() {
    return bullet;
}
