//
//  Asteroid.h
//  Asteroids
//
//  Created by Lavery, Chris on 9/17/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#ifndef __Asteroids__Asteroid__
#define __Asteroids__Asteroid__

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Asteroid : public Entity
{
public:
    Asteroid(sf::Vector2f windowSize);
    static int index;
    
private:
    void setVertices();
};

#endif /* defined(__Asteroids__Asteroid__) */
