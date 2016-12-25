#include "vec_extr.h"

std::vector<uint8_t> Vec_Extr::img_extract(sf::Image & image,color_mode flag)
{
    sf::Vector2u Size=image.getSize();
    std::vector<uint8_t> Vec;
    sf::Color pixel;
    switch(flag)
    {
    case none:
        Vec.resize(Size.x*Size.y*4);
        for(unsigned int y=0;y<Size.y;y++)
        {

            for(unsigned int x=0;x<Size.x;x++)
            {
                pixel=image.getPixel(x,y);
                Vec.push_back(pixel.b);
                Vec.push_back(pixel.g);
                Vec.push_back(pixel.r);
                Vec.push_back(pixel.a);
            }
        }
        break;
    case no_alpha:
        Vec.resize(Size.x*Size.y*3);
        for(unsigned int y=0;y<Size.y;y++)
        {

            for(unsigned int x=0;x<Size.x;x++)
            {
                pixel=image.getPixel(x,y);
                Vec.push_back(pixel.b);
                Vec.push_back(pixel.g);
                Vec.push_back(pixel.r);
            }
        }
        break;
    case greyscale:
        Vec.resize(Size.x*Size.y);
        for(unsigned int y=0;y<Size.y;y++)
        {

            for(unsigned int x=0;x<Size.x;x++)
            {
                pixel=image.getPixel(x,y);
                Vec.push_back(pixel.r*0.21+pixel.g*0.72+pixel.b+0.007);
            }
        }
        break;
    case greyscale_avg:
        Vec.resize(Size.x*Size.y);
        for(unsigned int y=0;y<Size.y;y++)
        {

            for(unsigned int x=0;x<Size.x;x++)
            {
                pixel=image.getPixel(x,y);
                Vec.push_back((pixel.r+pixel.g+pixel.b)/3);
            }
        }
        break;
    case invert:
        Vec.resize(Size.x*Size.y*4);
        for(unsigned int y=0;y<Size.y;y++)
        {

            for(unsigned int x=0;x<Size.x;x++)
            {
                pixel=image.getPixel(x,y);
                Vec.push_back(255-pixel.b);
                Vec.push_back(255-pixel.g);
                Vec.push_back(255-pixel.r);
                Vec.push_back(255-pixel.a);
            }
        }
        break;

    }





    for(unsigned int y=0;y<Size.y;y++)
    {

        for(unsigned int x=0;x<Size.x;x++)
        {
            pixel=image.getPixel(x,y);
            Vec.push_back(pixel.r);
            Vec.push_back(pixel.g);
            Vec.push_back(pixel.b);
        }
    };
    return Vec;
}


