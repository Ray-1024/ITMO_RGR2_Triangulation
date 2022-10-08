//
// Created by ray1024 on 08.10.22.
//

#include "Polygon.h"
#include "Utils.h"
#include <iostream>

void Polygon::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(arr, states);

}

Polygon::Polygon() {
    arr.setPrimitiveType(sf::PrimitiveType::LineStrip);
}

void Polygon::addVertex(float x, float y) {
    if (canAdd(x, y))
        arr.append(sf::Vertex(sf::Vector2f(x, y)));
}

void Polygon::clear() {
    arr.clear();
}

void Polygon::isCircled() {
    if (canAdd(arr[0].position.x, arr[0].position.y)) {
        arr.append(arr[0]);
        update();
    }
}

bool Polygon::canAdd(float x, float y) {
    if (arr.getVertexCount() < 2)return true;
    if (arr[arr.getVertexCount() - 1].position == arr[0].position)return false;

    for (int i = 0; i < arr.getVertexCount() - 1; ++i) {
        if (intersects(arr[i].position, arr[i + 1].position, arr[arr.getVertexCount() - 1].position,
                       sf::Vector2f(x, y)))
            return false;
    }
    return true;
}

void Polygon::update() {
    /*std::cout << "--- PRINT ---\n";
    for (int curr = 0; curr < arr.getVertexCount() - 1; ++curr) {
        sf::Vector2f a = getVert(curr - 1), b = getVert(curr), c = getVert(curr + 1);
        float angle = getAngle(a, b, c);
        std::cout << "{ " << b.x << " , " << b.y << " } angle = " << degrees(angle) << '\n';
    }
    std::cout << "-------------\n";*/
    std::vector<int> prev(arr.getVertexCount() - 1), next(arr.getVertexCount() - 1);
    for (int i = 1; i < prev.size() - 1; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    prev[0] = prev.size() - 1;
    prev[prev.size() - 1] = prev.size() - 2;
}

sf::Vector2f Polygon::getVert(int ind) {
    return arr[(ind >= 0) ? (ind % (arr.getVertexCount() - 1)) : (arr.getVertexCount() - 1 -
                                                                  ((-ind) % (arr.getVertexCount() - 1)))].position;
}
