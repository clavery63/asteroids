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
{
    angle = 6.0;
    setVertices();
    setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Ship::setVertices()
{
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.4, 30.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.5, 15.0));
    relativeVertices.push_back(sf::Vector2f(TWO_PI * 0.6, 30.0));
    relativeVertices.push_back(sf::Vector2f(0.0, 25.0));
}






