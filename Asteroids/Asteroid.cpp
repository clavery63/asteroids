//
//  Asteroid.cpp
//  Asteroids
//
//  Created by Lavery, Chris on 9/17/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#include <math.h>
#include <random>
#include <iostream>
#include "Asteroid.h"

const double TWO_PI = 3.14159 * 2;
const int MAX_SPEED = 8;
int Asteroid::index = 0;

Asteroid::Asteroid(sf::Vector2f windowSize)
: Entity(windowSize, 10.f)
{
    index++;
    srand(time(0) + index);
    angle = 0.f;
    setVertices();
    setPosition(rand() % (int)windowSize.x, rand() % (int)windowSize.y);
    setSpeed(sf::Vector2f((rand() % (2 * MAX_SPEED)) - MAX_SPEED, (rand() % (2 * MAX_SPEED)) - MAX_SPEED));
}

void Asteroid::setVertices()
{
    float inc = 1.f / numPoints;
    for (float f = 0.0; f < 1.0; f += inc)
    {
        relativeVertices.push_back(sf::Vector2f(TWO_PI * f, 20 + (rand() % 80)));
    }
    relativeVertices.push_back(relativeVertices[0]);
}