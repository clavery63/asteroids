//
//  Game.h
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#ifndef __Asteroids__Game__
#define __Asteroids__Game__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Game : private sf::NonCopyable
{
public:
    Game();
    void run();
    
private:
    void processEvents();
    void update();
    void render();
    void handleKeyboard();
    void handleInput(sf::Keyboard::Key key);
    
private:
    static const sf::Time TimePerFrame;
    static const int windowHeight;
    static const int windowWidth;
    
    sf::RenderWindow mWindow;
    sf::Vector2f center;
    Ship ship;
};

#endif /* defined(__Asteroids__Game__) */
