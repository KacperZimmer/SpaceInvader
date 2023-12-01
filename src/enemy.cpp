#include <vector>
#include <iostream>
#include <random>
#include <memory>
#include "../include//bullet.h"
#include "../include//enemy.h"
#include "../include//constValues.h"

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


    return {this->xPos, this->yPos, this->width /2, this->height};
}

Rectangle Enemy::calcSourceRect(){

    float currentxPos = this->text.width / 2 * this->currentFrame;
    float width = this->text.width / 2 - 10 ;
    float height = this->text.height;
    return {currentxPos, 0.f, width, height};
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

Enemy::~Enemy() {

        UnloadTexture(this->text);


}



