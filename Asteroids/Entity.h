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
    Entity(sf::Vector2f windowCenter, float numPoints);
    sf::VertexArray getShape() { return myShape; }
    
    void turnLeft();
    void turnRight();
    void accelerate();
    void moveForward();

protected:
    void setPosition(double newX, double newY);
    void setSpeed(sf::Vector2f s) { speed = s; }
    
    std::vector<sf::Vector2f> relativeVertices;
    sf::VertexArray myShape;
    float numPoints;
    double angle;
    
private:
    virtual void setVertices() = 0;
    void calculateVertices();
    void adjustAngle(float delta);
    
    sf::Vector2f center;
    sf::Vector2f windowSize;
    sf::Vector2f speed;
};

#endif /* defined(__Asteroids__Entity__) */
