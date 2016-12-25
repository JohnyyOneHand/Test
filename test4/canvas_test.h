#ifndef CANVAS_TEST_H
#define CANVAS_TEST_H


//#include <QSFML/qresourcestream.hpp>
#include <QSFMLCanvas.hpp>
#include <qvector2.hpp>
//#include <QSFML/string.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QFileDialog>
class TestWidget
: public qsf::QSFMLWidget
{
    Q_OBJECT

public:
    //zmiana z QMainWindow do QWidget
    TestWidget(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~TestWidget();

    void OnInit();
    void OnUpdate();

private:
    //qsf::QResourceStream fontStream;

    size_t fontSize;

    //sf::Font bitFont;
    //sf::Text bitText;
    sf::Sprite sprite;
    float TextColorR;
    float TextColorG;

    int colorModR;
    int colorModG;

    int counter;
};




#endif // CANVAS_TEST_H
