//
// Created by Cameron Hudson on 4/27/20.
//

#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H

#include "Graphics.h"

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Quad {
protected:
    color fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill, point center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};

#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_QUAD_H
