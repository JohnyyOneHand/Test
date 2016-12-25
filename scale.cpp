#include <scale.h>

//default constructor
Scale::Scale()
{
    XScale=YScale=1;
}
//constructor - grabs size of displaying window in pixels
Scale::Scale(unsigned int frame_x,unsigned int frame_y)
{

    win_x=frame_x;
    win_y=frame_y;

    XScale=YScale=1;
}




Scale::~Scale()
{
    std::cout<<"Scale obj destroyed\n";
}

void Scale::adjust(const unsigned int x,const unsigned int y,mode arg)
{
    if(win_x==0 || win_y==0)
    {
        std::cout<<"win_x and/or win_y are NOT set!\n";
        return;

    }
    setX(x);
    setY(y);
    flag_t=arg;
    switch (flag_t)
    {//keep_ratio and fit_to_screen - create method - scale down and replace 2 lines)
    case keep_ratio:
        XScale=(win_x>img_x? 1 : float(win_x)/img_x);
        YScale=(win_y>img_y? 1 : float(win_y)/img_y);
        XScale>YScale? XScale=YScale : YScale=XScale;
        break;

    case fit_to_screen:
        XScale=(win_x>img_x? 1 : float(win_x)/img_x);
        YScale=(win_y>img_y? 1 : float(win_y)/img_y);
        break;
    case stretch_and_keep_ratio:
        XScale=(float(win_x)/img_x);
        YScale=(float(win_y)/img_y);
        break;
    case stretch_to_fit:
        XScale=(float(win_x)/img_x);
        YScale=(float(win_y)/img_y);
        break;

    }
    std::cout<<"Adjusted scale "<<XScale<<" "<<YScale<<"\n";

}

void Scale::adjust()
{
    if(win_x==0 || win_y==0)
    {
        std::cout<<"win_x and/or win_y are NOT set!\n";
        return;

    }
    XScale=(win_x>img_x? 1 : float(win_x)/img_x);
    YScale=(win_y>img_y? 1 : float(win_y)/img_y);
    std::cout<<"Adjusted scale "<<XScale<<" "<<YScale<<"\n";
}

float Scale::getXScale()
{
    return XScale;
}

float Scale::getYScale()
{
    return YScale;
}



void Scale::setX(unsigned int x)
{
    img_x=x;
}
void Scale::setY(unsigned int y)
{
    img_y=y;
}
