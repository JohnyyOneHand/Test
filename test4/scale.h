#ifndef SCALE_H
#define SCALE_H

#include <iostream>

/*  Class for calculating & storing image scale
    Constructor grabs size of the displaying frame
    You can set the size of image by
    -adjust() with parameters x,y
    -setX/Y()

    New adjust() is needed after using setX/Y
    enum mode - determines type of scalling
*/
class Scale
{
public:
    Scale();
    Scale(unsigned int frame_x,unsigned int frame_y);
    ~Scale();
    enum mode {keep_ratio,fit_to_screen,stretch_and_keep_ratio,stretch_to_fit};
    void adjust(unsigned int x,unsigned int y,mode =keep_ratio);
    void adjust();
    float getXScale();
    float getYScale();
    void setX(unsigned int x);
    void setY(unsigned int y);
private:

    mode flag_t;
    unsigned int img_x;
    unsigned int img_y;
    unsigned int win_x;
    unsigned int win_y;
    float XScale;
    float YScale;



};



#endif // SCALE_H
