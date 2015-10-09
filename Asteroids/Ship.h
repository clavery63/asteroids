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
    Ship(sf::Vector2f windowSize);
    void fireMissle();
    void moveMissleForward();
    sf::RectangleShape getMissleShape() { return missleShape; };
    
private:
    void setVertices();
    
    sf::Vector2f misslePosition;
    sf::RectangleShape missleShape;
    double missleDirection;
};

#endif /* defined(__Asteroids__Ship__) */
