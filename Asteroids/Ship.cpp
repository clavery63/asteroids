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

Ship::Ship(sf::Vector2f windowSize)
: Entity(windowSize, 4.f)
, missleShape(sf::RectangleShape(sf::Vector2f(3.f, 3.f)))
{
    angle = 6.0;
    setVertices();
    setPosition(windowSize.x / 2, windowSize.y / 2);
    missleShape.setFillColor(sf::Color::White);
}

void Ship::setVertices()
{
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.4, 30.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.5, 15.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.6, 30.0));
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
}

void Ship::fireMissle()
{
    missleDirection = angle;
    misslePosition = myShape[0].position;
    missleShape.setPosition(misslePosition);
}

void Ship::moveMissleForward()
{
    misslePosition = sf::Vector2f(misslePosition.x + sin(missleDirection) * 10, misslePosition.y + cos(missleDirection) * 10);
    missleShape.setPosition(misslePosition);
}






