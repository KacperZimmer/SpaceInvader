#include "../include/bullet.h"
#include <iostream>



Bullet::Bullet(float xPos, float yPos){
    
    this->text = LoadTexture("../sprites/bu.png");
    this->xPos = xPos; 
    this->yPos = yPos; 
    this->width = this->text.width ; 
    this->height = this->text.height ; 
}

Rectangle Bullet::calcDestRect(){

    return {this->xPos, this->yPos, this->width, this->height};
}
Rectangle Bullet::calcSourceRect(){

    return {this->xPos, this->yPos, this->width, this->height};
}

float Bullet::getYPos()const{
    return this->yPos; 
}

float Bullet::getVelocity() const{
    return this->bulletVelocity; 
}

void Bullet::Render(){
    DrawTexturePro(getBulletTexture(),calcSourceRect(),calcDestRect(),Vector2{},0.f, WHITE); 
}

Bullet::~Bullet() {
    UnloadTexture(this->text);
}

