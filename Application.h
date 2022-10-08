//
// Created by skovo on 11.09.2022.
//

#ifndef RGR2_APPLICATION_H
#define RGR2_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Polygon.h"

class Application {
public:
    Application(sf::VideoMode size, std::string title, unsigned int framerateLimit);

    void run();

private:
    sf::RenderWindow window;
    sf::Clock watch;
    sf::Event event;
    sf::VideoMode screenSize;
    std::string title;
    bool running;
    Polygon polygon;


    void dispatchEvents();

    void update();

    void draw();

};


#endif //RGR2_APPLICATION_H
