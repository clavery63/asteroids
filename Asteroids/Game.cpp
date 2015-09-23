//
//  Game.cpp
//  Asteroids
//
//  Created by Lavery, Chris on 9/12/15.
//  Copyright (c) 2015 Chris Lavery. All rights reserved.
//

#include "Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode::getFullscreenModes()[0], "Asteroids", sf::Style::Fullscreen)
, ship(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y))
, asteroid(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y))
, asteroid_2(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y))
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            
            processEvents();
            update();
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
    handleKeyboard();
}

void Game::update()
{
    ship.moveForward();
    asteroid.moveForward();
    asteroid_2.moveForward();
}

void Game::render()
{
    mWindow.clear(sf::Color(0, 0, 0, 255));
    mWindow.draw(ship.getShape());
    mWindow.draw(asteroid.getShape());
    mWindow.draw(asteroid_2.getShape());
    mWindow.display();
}

void Game::handleKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        mWindow.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        ship.turnLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        ship.turnRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        ship.accelerate();
    }
}


































