//
// Created by ray1024 on 08.10.22.
//

#ifndef RGR2_UTILS_H
#define RGR2_UTILS_H

#include "SFML/Graphics.hpp"
#include <cmath>

float cross(const sf::Vector2f &a, const sf::Vector2f &b, const sf::Vector2f &c, const sf::Vector2f &d) {
    return (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
}

float distance(const sf::Vector2f &a, const sf::Vector2f &b) {
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool intersects(const sf::Vector2f &a, const sf::Vector2f &b, const sf::Vector2f &c, const sf::Vector2f &d) {
    return (cross(a, b, a, c) * cross(a, b, a, d) < 0) && (cross(c, d, c, a) * cross(c, d, c, b) < 0);
}

float getAngle(const sf::Vector2f &a, const sf::Vector2f &b, const sf::Vector2f &c) {
    float Phi = std::asin(cross(b, a, b, c) / (distance(a, b) * distance(b, c)));
    return (Phi >= 0.0f) ? Phi : Phi + 2.0f * M_PI;
}

float degrees(float rad) {
    return (rad / M_PI) * 180.0f;
}

float radians(float deg) {
    return (deg / 180.0f) * M_PI;
}

#endif //RGR2_UTILS_H
