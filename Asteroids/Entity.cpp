//
//  Entity.cpp
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#include <math.h>
#include <random>
#include <iostream>
#include "Entity.h"

const double TWO_PI = 3.14159 * 2;
const double MAX_SPEED = 8.0;

Entity::Entity(sf::Vector2f windowSize, float numPoints)
: windowSize(windowSize)
, numPoints(numPoints)
{
    myShape = sf::VertexArray(sf::LinesStrip, numPoints + 1);
    myShape[0].color = sf::Color::White;
    speed = sf::Vector2f(0.0, 0.0);
}

void Entity::turnLeft()
{
    adjustAngle(0.1);
}

void Entity::turnRight()
{
    adjustAngle(-0.1);
}

void Entity::accelerate()
{
    speed.x += 0.1 * sin(angle);
    speed.y += 0.1 * cos(angle);
}

void Entity::moveForward()
{
    if (speed.x > MAX_SPEED)
        speed.x = MAX_SPEED;
    if (speed.x < -MAX_SPEED)
        speed.x = -MAX_SPEED;
    if (speed.y > MAX_SPEED)
        speed.y = MAX_SPEED;
    if (speed.y < -MAX_SPEED)
        speed.y = -MAX_SPEED;
    setPosition(center.x + speed.x, center.y + speed.y);
    calculateVertices();
}

void Entity::setPosition(double newX, double newY)
{
    center.x = newX;
    if (center.x > windowSize.x)
        center.x -= windowSize.x;
    if (center.x < 0)
        center.x += windowSize.x;
    center.y = newY;
    if (center.y > windowSize.y)
        center.y -= windowSize.y;
    if (center.y < 0)
        center.y += windowSize.y;
}

void Entity::calculateVertices()
{
    int i = 0;
    for (auto vertex : relativeVertices)
    {
        float relativeX = sin(vertex.x + angle) * vertex.y;
        float relativeY = cos(vertex.x + angle) * vertex.y;
        myShape[i++].position = sf::Vector2f(center.x + relativeX, center.y + relativeY);
    }
}

void Entity::adjustAngle(float delta)
{
    angle += delta;
    calculateVertices();
}











