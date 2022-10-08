//
// Created by ray1024 on 08.10.22.
//

#ifndef RGR2_POLYGON_H
#define RGR2_POLYGON_H

#include "SFML/Graphics.hpp"

class Polygon : public sf::Drawable {

private:
    sf::VertexArray arr;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool canAdd(float x, float y);

    void update();

    sf::Vector2f getVert(int ind);

public:
    Polygon();


    void addVertex(float x, float y);

    void clear();

    void isCircled();

};


#endif //RGR2_POLYGON_H
