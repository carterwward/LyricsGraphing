//
// Created by Cameron Hudson on 4/27/20.
//

#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SUBMITBUTTON_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SUBMITBUTTON_H

#include "Quad.h"
#include <string>
class SubmitButton : public Quad {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    SubmitButton(color fill, point center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    void draw() const override;

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the Button when the user is hovering over it */
    void hover();

    // run a function
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

};

#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SUBMITBUTTON_H
