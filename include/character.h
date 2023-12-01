#ifndef CHARACTER_H
#define CHARACTER_H 

#include "raylib.h"



class Character{

protected: 
    float xPos{}; 
    float yPos{}; 
    float width{}; 
    float height{}; 
    float DeltaTime{}; 
    Texture2D text{}; 



public: 
    virtual void Render() = 0; 
    virtual Rectangle calcDestRect() = 0; 
    virtual Rectangle calcSourceRect() = 0; 

    virtual void setXPos(float xPos); 
    virtual void setYPos(float yPos); 

    virtual void setWidth(float width); 
    virtual void setHeight(float height); 

    virtual float getWidth() const; 
    virtual float getHeight() const;

    virtual float getYPos() const;


};
#endif