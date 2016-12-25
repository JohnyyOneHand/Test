#ifndef VIEWER_H
#define VIEWER_H

#include <QTWidgets>
#include <QTimer>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <QWindow>


class QSFML_Viewer : public QWidget, public sf::RenderWindow
{

public :

    QSFML_Viewer(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
    ~QSFML_Viewer();
    sf::RenderWindow app_window;

private :

    virtual void OnInit();

    virtual void OnUpdate();

    void showEvent(QShowEvent*);



    QTimer *myTimer=new QTimer(this);
    bool   myInitialized;
};


QSFML_Viewer::QSFML_Viewer(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime) :
    QWidget       (Parent),
    myInitialized (false) //#TODO fix initializer list QWidget (Parent)

{
    //QSFML_Viewer(QWidget* Parent = nullptr);
    //myInitialized=false;
    // Set strong focus to enable keyboard events to be received
    setFocusPolicy(Qt::StrongFocus);

    // Setup the widget geometry
    move(Position);
    resize(Size);

    // Setup the timer
    myTimer->setInterval(FrameTime);
}


void QSFML_Viewer::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {


        // Create the SFML window with the widget handle

        app_window.create((HWND)this->winId());

        // Let the derived class do its specific stuff
        OnInit();

//        // Setup the timer to trigger a refresh at specified framerate
//        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
//        myTimer.start();

        myInitialized = true;
    }
};

class Viewer_sample : public QSFML_Viewer
{
public:
    Viewer_sample(QWidget* Parent, const QPoint& Position, const QSize& Size):
    QSFML_Viewer(Parent,Position,Size)
    {

    }

private:
    void OnInit()
    {
        sf::Texture img;

        if(!img.loadFromFile("7574_cats-judging-you-1.jpg"))
        {
            QMessageBox::information(this,"Fail ","Fail2");

        }
        sf::Sprite mySprite;
        mySprite.setTexture(img);
        mySprite.setOrigin(img.getSize().x,img.getSize().y);
        app_window.display();
    }

    void OnUpdate()
    {
        app_window.display();
    }
};

#endif // VIEWER_H
