#include "../Headers/bullet.h"
#include <iostream>



Bullet::Bullet(float xPos, float yPos){
    
    this->text = LoadTexture("../sprites/bu.png");
    this->xPos = xPos; 
    this->yPos = yPos; 
    this->width = this->text.width ; 
    this->height = this->text.height ; 
}

Rectangle Bullet::calcDestRect(){
    Rectangle rect{}; 

    rect.x = this->xPos; 
    rect.y = this->yPos; 
    rect.width = this->width; 
    rect.height = this->height; 
    
    return rect; 
}
Rectangle Bullet::calcSourceRect(){
    Rectangle rect{};
        
    rect.x = this->xPos; 
    rect.y = this->yPos;

    rect.width = this->width; 
    rect.height = this->height; 
    return rect; 
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

