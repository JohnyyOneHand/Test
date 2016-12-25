#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <canvas_test.h>
#include "widget1.h"
#include <canvas_test.h>
#include <qvector.h>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug("Test\n");
//    widget1 k;
//    k.show();
//    TestWidget Tw(&k, qsf::QVector2u(0, 0), qsf::QVector2u(300, 400));
////    //TestWidget Tw(&w, qsf::QVector2u(0, 0), qsf::QVector2u(300, 400));
//    Tw.show();

        qDebug("Test2\n");

//    sf::Window window(sf::VideoMode(300,300),"Yolo");
//    while (window.isOpen())
//    {
//        std::cout<<"Yolo open\n";
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            std::cout<<"Jestem w event while\n";
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//    }

    return a.exec();
}
