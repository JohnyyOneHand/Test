#ifndef RECOLOR_H
#define RECOLOR_H

#include <vector>
#include <SFML/Graphics.hpp>

/*Class for extracting  vector of pixels from SFML object Image
 */
class Vec_Extr
{
public:
    enum color_mode{invert,greyscale,greyscale_avg,no_alpha,none};
    Vec_Extr();
    ~Vec_Extr();
    static std::vector<uint8_t> img_extract(sf::Image & image,color_mode flag=none);
private:
    color_mode mode;



};

#endif // RECOLOR_H
