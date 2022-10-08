#include "Application.h"

int main() {
    auto *app = new Application(sf::VideoMode(800, 600), "Triangulation", 60);
    app->run();
    delete app;
    return 0;
}
