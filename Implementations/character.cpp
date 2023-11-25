#include "../Headers/character.h"
#include <iostream>


void Character::setXPos(float xPos){
    this->xPos = xPos; 
}

void Character::setYPos(float yPos){
    this->yPos = yPos; 
}

void Character::setHeight(float height){
    this->height = height; 
}

void Character::setWidth(float width){
    this->width = width; 
}

float Character::getWidth()const{
    return this->width; 
}
float Character::getHeight()const{
    return this->height; 
}

Character::~Character(){
    std::cout << "free resource" << std::endl; 
}
