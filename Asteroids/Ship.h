//
//  Ship.h
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#ifndef __Asteroids__Ship__
#define __Asteroids__Ship__

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Ship : public Entity
{
public:
    Ship(sf::Vector2f windowCenter);
    sf::VertexArray getShape() { return myShape; }
    
    void turnLeft();
    void turnRight();
    void accelerate();
    void moveForward();
    
private:
    void setVertices();
    void calculateVertices();
    void adjustAngle(float delta);
    void setPosition(double newX, double newY);
    
    std::vector<sf::Vector2f> relativeVertices;
    sf::VertexArray myShape;
    sf::Vector2f center;
    sf::Vector2f windowSize;
    sf::Vector2f speed;
    double angle;
};

#endif /* defined(__Asteroids__Ship__) */
