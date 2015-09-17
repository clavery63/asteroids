//
//  Ship.h
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#ifndef __Asteroids__Entity__
#define __Asteroids__Entity__

#include <vector>
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(sf::Vector2f windowCenter);
    virtual sf::VertexArray getShape() { return myShape; }
    
    virtual void turnLeft();
    virtual void turnRight();
    virtual void accelerate();
    virtual void moveForward();
    
private:
    virtual void setVertices();
    virtual void calculateVertices();
    virtual void adjustAngle(float delta);
    virtual void setPosition(double newX, double newY);
    
    std::vector<sf::Vector2f> relativeVertices;
    sf::VertexArray myShape;
    sf::Vector2f center;
    sf::Vector2f windowSize;
    sf::Vector2f speed;
    double angle;
};

#endif /* defined(__Asteroids__Entity__) */
