#include <vector>
#include <iostream>
#include <random>
#include <memory>
#include "../Headers/bullet.h"
#include "../Headers/enemy.h"
#include "../Headers/constValues.h"

std::mt19937 gen(std::random_device{}());

    int generateNumber(){
    std::uniform_int_distribution<int> dist(1, 10000);
    return dist(gen);
}


Enemy::Enemy(){

}
Enemy::Enemy(float xPos, float yPos){


    this->text = LoadTexture("../sprites/spritesheet.png");
    this->xPos = xPos;
    this->yPos = yPos;
    this->height = (this->text.height) / 14;
    this->width = (this->text.width) / 14;

    this->bulletDistance = this->yPos;

}

float Enemy::bulletSpeed(){

    bulletDistance += 10;
    return bulletDistance;
}

void Enemy::bulletMove(){
    bullet->setYPos(bulletSpeed());
}

void Enemy::shootingAction(){
    if (generateNumber() >= 9970 && shootReady){
        this->shootReady = false;
        this->bullet = std::make_unique<Bullet>(this->xPos, this->yPos + 30);
        this->bulletDistance = this->yPos + 30;
    }

}

void Enemy::handleBulletLogic(){

    if(bullet->getYPos() >= HEIGHT){
        this->bulletDistance = this->yPos;
        this->bullet.reset();
        this->shootReady = true;
    }else{
        this->bulletMove();
        this->bullet->Render();
    }
}


Rectangle Enemy::calcDestRect(){
    Rectangle rect{};
    rect.x = this->xPos;
    rect.y = this->yPos;
    rect.height = this->height ;
    rect.width = this->width / 2;
    return rect;
}

Rectangle Enemy::calcSourceRect(){
   Rectangle rect{};
    rect.x = this->text.width / 2 * this->currentFrame;
    rect.y = 0.f;
    rect.height = this->text.height;
    rect.width = this->text.width / 2;
    return rect;
}



void Enemy::frameUpdate() {
    float deltaTime = GetFrameTime();

    if (currentFrame <= totalFramesToRender) {
        runningTime += deltaTime;

        if (runningTime > timeToDrawFrame) {
            runningTime = 0.0f;
            ++currentFrame;
        }
    } else {
        runningTime = 0.0f;{}
        currentFrame = 1;
    }
}


void Enemy::Render(){

    this->shootingAction();
    frameUpdate();
    DrawTexturePro(this->text, calcSourceRect(), calcDestRect(),Vector2{},0.f,WHITE);

    if(this->bullet){
        this->handleBulletLogic();
    }

}

const std::unique_ptr<Bullet> &Enemy::getBullet() const {
    return bullet;
}



