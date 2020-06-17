//
// Created by teamj on 4/28/2020.
//

#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BOOLEANBUTTON_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BOOLEANBUTTON_H


#include "Quad.h"
#include <string>
class BooleanButton : public Quad {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    BooleanButton(color fill, point center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw() const override;

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the Button when the user is hovering over it */
    void hover();

    /* Change color of the Button when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

};


#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BOOLEANBUTTON_H
