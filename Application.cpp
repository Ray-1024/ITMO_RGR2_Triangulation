//
// Created by skovo on 11.09.2022.
//

#include "Application.h"

#include <utility>

Application::Application(sf::VideoMode _size, std::string _title, unsigned int framerateLimit) {
    title = std::move(_title);
    screenSize = _size;
    window.create(screenSize, title);
    window.setFramerateLimit(framerateLimit);
    watch.restart();
    running = true;
}

void Application::run() {
    while (running) {
        dispatchEvents();
        update();
        draw();
    }
}

void Application::dispatchEvents() {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                running = false;
                break;
            }
            case sf::Event::KeyReleased: {

            }
        }
    }
}

void Application::update() {
}

void Application::draw() {
    window.clear();
    window.display();
}
