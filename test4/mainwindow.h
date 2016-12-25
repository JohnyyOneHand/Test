#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <ctime>
#include <vector>
#include <QMainWindow>
#include <QString>
#include <QListWidgetItem>
#include <QTWidgets>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <iterator>
#include <string>
#include <sstream>
#include <QDebug>
#include <iostream>
#include <canvas_test.h>
#include <scale.h>
#include <vec_extr.h>
#include <new>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void file_list_getter();
    void file_list_setter();
signals:
    void load_new();
public slots:
        void opennew();
private slots:

    //void load_pushButton_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_load_pushButton_clicked();


    void on_remove_selected_pushButton_clicked();



    void on_convert_pushbutton_clicked();

private:
    QResource logo;
    class SFML_objects
    {
    public:
        sf::Texture *Texture;
        sf::Sprite *Sprite;
        sf::Image *Image;

        SFML_objects()
        {
            std::cout<<"SFML_objects created!\n";
            Texture=new sf::Texture;
            Sprite =new sf::Sprite;
            Image= new sf::Image;
        }

        ~SFML_objects()
        {
            std::cout<<"SFML_objects destroyed!\n";
            delete Texture;
            delete Sprite;
            delete Image;
        }


    };

    bool quit_ask();
    bool SFML_load(QListWidgetItem *,SFML_objects &);
    void SFML_display(QListWidgetItem*, SFML_objects &);
    void SFML_clear(SFML_objects &);
    bool SFML_logo(SFML_objects&);
    SFML_objects Trio;
    Ui::MainWindow *ui;
    QStringList file_list;
    struct default_size
    {
        unsigned int x;
        unsigned int y;
    };
    default_size Viewer_def_size;
    sf::RenderWindow Viewer;
    bool open;
};

#endif // MAINWINDOW_H
