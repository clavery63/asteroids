//
//  Ship.cpp
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#include <math.h>
#include <random>
#include <iostream>
#include "Ship.h"

const double TWO_PI = 3.14159 * 2;
const double MAX_SPEED = 2.0;

//    sf::Vector2f(0.0, 25.0),
//    sf::Vector2f(TWO_PI * 0.4, 30.0),
//    sf::Vector2f(TWO_PI * 0.5, 15.0),
//    sf::Vector2f(TWO_PI * 0.6, 30.0),
//    sf::Vector2f(0.0, 25.0)
    

Ship::Ship(sf::Vector2f windowSize)
: shipShape(sf::LinesStrip, 5)
, windowSize(windowSize)
{
    setVertices();
    setPosition(windowSize.x / 2, windowSize.y / 2);
    angle = 6.0;
    speed = sf::Vector2f(0.0, 0.0);
    
    shipShape[0].color = sf::Color::White;
    calculateVertices();
}

void Ship::turnLeft()
{
    adjustAngle(0.1);
}

void Ship::turnRight()
{
    adjustAngle(-0.1);
}

void Ship::accelerate()
{

    speed.x += 0.1 * sin(angle);
    speed.y += 0.1 * cos(angle);
}

void Ship::moveForward()
{
    setPosition(center.x + speed.x, center.y + speed.y);
    calculateVertices();
}

void Ship::setPosition(double newX, double newY)
{
    center.x = (int)(newX + windowSize.x) % (int)windowSize.x;
    center.y = (int)(newY + windowSize.y) % (int)windowSize.y;
}

void Ship::calculateVertices()
{
    int i = 0;
    for (auto vertex : relativeVertices)
    {
        float relativeX = sin(vertex.x + angle) * vertex.y;
        float relativeY = cos(vertex.x + angle) * vertex.y;
        shipShape[i++].position = sf::Vector2f(center.x + relativeX, center.y + relativeY);
    }
}

void Ship::adjustAngle(float delta)
{
    angle += delta;
    calculateVertices();
}

void Ship::setVertices()
{
//    srand(time(0));
//    for (float f = 0.0; f < 1.0; f += 0.1)
//    {
//        relativeVertices.push_back(sf::Vector2f(TWO_PI * f, 20 + (rand() % 80)));
//    }
//    relativeVertices.push_back(relativeVertices[0]);
    
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.4, 30.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.5, 15.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.6, 30.0));
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
}









