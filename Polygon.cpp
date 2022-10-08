//
// Created by ray1024 on 08.10.22.
//

#include "Polygon.h"

void Polygon::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(arr, states);
}

Polygon::Polygon() {
    arr.setPrimitiveType(sf::PrimitiveType::LineStrip);
}

void Polygon::addVertex(float x, float y) {
    if (arr.getVertexCount() > 2 && arr[arr.getVertexCount() - 1].position == arr[0].position)return;
    arr.append(sf::Vertex(sf::Vector2f(x, y)));
}

void Polygon::clear() {
    arr.clear();
}

void Polygon::circled() {
    if (arr.getVertexCount() > 2 && arr[arr.getVertexCount() - 1].position != arr[0].position)
        arr.append(arr[0]);
}
