#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "viewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Viewer_def_size{800,600},
    open(false),
  logo(":/images/logo.png")

{
     std::cout<<"setupUI!\n";
    ui->setupUi(this);
     //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(opennew()));
    //connect(this,SIGNAL(destroyed(QObject*)),this,SIGNAL(pass_on_close()));
    //Viewer(sf::VideoMode(800,600),"Viewer");
    //UNCOMMENT BELOW FOR PREVIOUS WAY
    //Viewer.create(sf::VideoMode(Viewer_def_size.x,Viewer_def_size.y),"Viewer");
    //Viewer.setFramerateLimit(1);
    //Viewer.setSize((800,600));
    Viewer.setVisible(false);
    Viewer.setActive(false);
    Viewer.setKeyRepeatEnabled(false);
    std::cout<<"window created!\n";
    //open=true;
    ui->progress_label->setText("Hello\n");

    if(!SFML_logo(Trio))
    {
        ui->progress_label->setText("Unable to load logo\n");
    }
    //Trio=new SFML_objects;

}

MainWindow::~MainWindow()
{
    std::cout<<"Destructor called\n";
    Viewer.close();
    std::cout<<"Viewer.close called\n";
    delete ui;
}





void MainWindow::on_load_pushButton_clicked()
{


    QStringList file_list=QFileDialog::getOpenFileNames(this,"Wybor plikow","","All (*.*);;BMP (*.bmp *dib)");

    QString text=QString("%1  %2").arg(file_list.size(),sf::Texture::getMaximumSize());
    unsigned int siz=sf::Texture::getMaximumSize();
    text.append(QString::number(siz));

    for ( QStringList::const_iterator it = file_list.begin(); it != file_list.end(); ++it )
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        QFileInfo f=(*it);
        newItem->setText(f.fileName());
        QVariant data(*it);
        newItem->setData(Qt::WhatsThisRole,data);
        ui->listWidget->addItem(newItem);
        ui->progress_label->setText(QString("Loaded ")+f.fileName());

    }
}

bool MainWindow::quit_ask()
{
    QMessageBox::StandardButton reply; reply = QMessageBox::question(this, "Quit", "Do you want to quit?",
    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        qDebug() << "Yes was clicked";
        return true;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (quit_ask()) {
        Viewer.close();

        event->accept();
    } else {
        event->ignore();
    }
}





void MainWindow::opennew()
{
   TestWidget nowy(0,qsf::QVector2u(0, 0), qsf::QVector2u(300, 400));
    //nowy->show();
    nowy.show();
}

void MainWindow::MainWindow::SFML_clear(SFML_objects& obj)
{
    qDebug() <<"clear wywolany";

//    obj.Sprite->~Drawable();
//    obj.Texture->~Texture();
////    delete obj.Sprite;
////    delete obj.Texture;
//    sf::Texture temp;
////      obj.Texture->operator =(temp);
////      obj.Sprite->setTexture(*obj.Texture);
//    obj.Sprite=new sf::Sprite;
//    obj.Texture=new sf::Texture;

    if(!SFML_logo(Trio))
    {
        ui->progress_label->setText("Unable to load logo\n");
    }

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
        //MainWindow::SFML_display(item);

    if(!Viewer.isOpen())
    {
        std::cout<<"Recreating window!\n";
        Viewer.create(sf::VideoMode(Viewer_def_size.x,Viewer_def_size.y),"Viewer");
        //Viewer.setSize((800,600));
        Viewer.setVisible(false);
        Viewer.setActive(false);
        open=true;

    }
    else
    {
        qDebug()<<"Viewer already open!\n";
        return;
    }

    Trio.Sprite->setScale(1,1);

    qDebug() <<"Double click before display\n";


    MainWindow::SFML_display(item,Trio);



    SFML_clear(Trio);
    qDebug() <<"SFML Clear wywolany\n";



}

bool MainWindow::SFML_load(QListWidgetItem* item,SFML_objects &obj)
{

    std::string name= item->data(Qt::WhatsThisRole).toString().toStdString();

    if(!obj.Texture->loadFromFile(name))
    {
        SFML_logo(obj);
        Viewer.clear();
        Viewer.draw(*obj.Sprite);
        Viewer.display();
        //QMessageBox::information(this,"Fail ","Failed to load the file!");
        ui->progress_label->setText("Failed to load the image to texture!\n");
        ui->progress_label->repaint();
        return false;
    };


    obj.Sprite->setTexture(*obj.Texture,true);

    Scale scale(Viewer.getSize().x,Viewer.getSize().y);
    scale.adjust(obj.Texture->getSize().x,obj.Texture->getSize().y);
    obj.Sprite->setScale(scale.getXScale(),scale.getYScale());
    unsigned int pos_x=(Viewer.getSize().x-obj.Sprite->getScale().x*obj.Texture->getSize().x)/2;
    unsigned int pos_y=(Viewer.getSize().y-obj.Sprite->getScale().y*obj.Texture->getSize().y)/2;
    obj.Sprite->setPosition(pos_x,pos_y);

    //ui->progress_label->setText(QString("Loaded" +QString::fromStdString(name)));
    //ui->progress_label->repaint();
    return true;
}

bool MainWindow::SFML_logo(SFML_objects & obj)
{
    if(!obj.Texture->loadFromMemory((const void*)logo.data(),(std::size_t)logo.size(),sf::IntRect()))
        return false;
    obj.Sprite->setTexture(*obj.Texture,true);

    return true;
}

void MainWindow::SFML_display(QListWidgetItem* item,SFML_objects &obj)
{
    std::cout<<"Double clicked!\n";
    //SFML_clear(obj);
//    if(!open)
//    {
//        std::cout<<"Recreating window!\n";
//        Viewer.create(sf::VideoMode(Viewer_def_size.x,Viewer_def_size.y),"Viewer");
//        //Viewer.setSize((800,600));
//        Viewer.setVisible(false);
//        Viewer.setActive(false);
//        open=true;

//    }

    QListWidget *QList=item->listWidget();
    QList->setCurrentItem(item);

    qDebug() <<"items in list"<<QList->count();
    qDebug() <<"current item row "<<QList->currentRow();
    int index=QList->currentRow();
    Viewer.clear();
    Viewer.setVisible(true);


    SFML_load(item,obj);


//    std::string name= item->data(Qt::WhatsThisRole).toString().toStdString();

//    //img - Image removed, idk what to do with it, double buffered in memory
//    //sf::Image *img= obj.Image;
//    //sf::Texture *obj.Texture=obj.Texture;
//    //sf::Sprite *obj.Sprite=obj.Sprite;


//    if(!obj.Texture->loadFromFile(name))
//    {
//        QMessageBox::information(this,"Fail ","Failed to load the file!");
//        return;
//    }

//    obj.Sprite->setScale(1,1);
//    obj.Sprite->setTexture(*obj.Texture,true);





//FITTING DOES NOT WORK AS INTENDED. SCALE IS FINE. POSITION NOT

//    Scale scale(Viewer.getSize().x,Viewer.getSize().y);
//    scale.adjust(obj.Texture->getSize().x,obj.Texture->getSize().y);
//    obj.Sprite->setScale(scale.getXScale(),scale.getYScale());

    //ONLY IF not scalled upward - BUT ITS NOT WORKING AS INTENDED
    //Sprite->setPosition(win_x-scale.getXScale()*Texsizex/2,win_y*scale.getYScale()*Texsizey/2);

    std::cout<<"Before loop!\n";
    Viewer.draw(*obj.Sprite);
    Viewer.display();
    sf::Event event;
    while (Viewer.isOpen()) //loop works(?) - when getting new image- less memory, when closing - something drops. When reopening with new  - even less.
    {
      //std::cout<<"inside isOpen loop for Double Click\n";
        while (Viewer.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                qDebug() <<"\tEvent closed activated\n";
                //Delete uncommented because it destroys object in SFML_objects
                //delete Sprite;
                //delete Tex;



                //Tex.loadFromFile("41033583edibd_sm.jpg"); //sample file
                //Sprite.setTexture(Tex);

                open=false;
                //obj.Sprite.~Drawable();
                //obj.Texture.~Texture();
                SFML_logo(obj);
                Viewer.clear();
                Viewer.close();

                return;
            }

            if (event.type==sf::Event::Resized)
            {
                std::cout << "Resized: [" << event.size.width << "; " << event.size.height << "]" << std::endl;
                Scale scale(event.size.height,event.size.width);
                scale.adjust(obj.Texture->getSize().x,obj.Texture->getSize().y);
                Viewer.clear();
                Viewer.draw(*obj.Sprite);
                Viewer.display();
            }

            if(event.type==sf::Event::KeyPressed)
            {
                qDebug()<<"pre index"<<index;
                qDebug()<<"key pressed\n";
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    if(++index>=QList->count())
                    {
                        index=0;
                    }
                    qDebug() <<"index="<<index;


                    QList->setCurrentRow(index);
                    item=QList->currentItem();
                    if(!SFML_load(item,obj))
                    {
                        ui->progress_label->setText("Failed to load the image!\n");
                        ui->progress_label->repaint();
                    }
                    Viewer.clear();
                    Viewer.draw(*obj.Sprite);
                    Viewer.display();




                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    if(--index<0)
                    {
                        index=QList->count()-1;
                    }
                    qDebug() <<"index="<<index;
                    QList->setCurrentRow(index);
                    item=QList->currentItem();
                    if(!SFML_load(item,obj))
                    {
                        ui->progress_label->setText("Failed to load the image!\n");
                        ui->progress_label->repaint();
                    }
                    Viewer.clear();
                    Viewer.draw(*obj.Sprite);
                    Viewer.display();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    open=false;
                    SFML_logo(obj);
                    Viewer.clear();
                    Viewer.close();
                }

            }

             // process event...
        }



       };

          //commenting out the loop = not able to close the window on demand, BUT IT CLEARS THE MEMORY!
          //#ADD A SMALL SAMPLE IMAGE. IT CAN OVERRIDE THIS SHIT
     /*  while (Viewer.isOpen())
       {
           //std::cout<<"inside isOpen loop for Double Click\n";
           sf::Event event;
           while (Viewer.pollEvent(event))
           {

               //std::cout<<"inside while .pollEvent loop\n";
               if (event.type == sf::Event::Closed)
               {   std::cout<<"Viewer closed!\n";
                   open=false;
                   Viewer.close();
               }
               if (event.type==sf::Event::Resized)
               {
                   std::cout << "Resized: [" << event.size.width << "; " << event.size.height << "]" << std::endl;
                   Viewer.clear();
                   Viewer.draw(Sprite);
                   Viewer.display();
//                    fit_top=float(event.size.width)/Texsizex;
//                    fit_width=float(event.size.height)/Texsizey;
//                   if(fit_top<1.0 && fit_width<1.0)
//                   {
//                       if(fit_top<fit_width)
//                           Sprite.setScale(fit_top,fit_top);
//                       else
//                           Sprite.setScale(fit_width,fit_width);
//                   }
//                   //else if(fit_top>1.0 && fit_width>1.0)
//                       //Sprite.setScale(Tex.getSize().x,Tex.getSize().y);
//                   else if(fit_top<1.0 && fit_width>1.0)
//                       Sprite.setScale(fit_top,1);
//                   else if(fit_top>1.0 && fit_width<1.0)
//                       Sprite.setScale(1,fit_width);
               }

               //if (event.type==sf::Event::)

               // you only get here when there is at least one event.
           }




       };*/
    //Viewer.clear();
    //return;

}


void MainWindow::on_remove_selected_pushButton_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));

        qDebug("Removed item\n");
    }
    items.clear();

    return;
}






void MainWindow::on_convert_pushbutton_clicked()
{

    //RUN conversion
    if(ui->radioButton->isChecked())
        ;//set param
    else if(ui->radioButton_2->isChecked())
        ;//set param
    else if(ui->radioButton_3->isChecked())
       ;//set apram

    std::time_t start = std::time(NULL);
    unsigned index = ui->listWidget->count();
    for(int i=index-1;i>=0;--i)
    {
        sf::Image image;
        QListWidgetItem* item=ui->listWidget->takeItem(i);

        if(!image.loadFromFile(item->data(Qt::WhatsThisRole).toString().toStdString()))
        {
            ui->progress_label->setText("failed to convert "+ item->text());
            ui->progress_label->repaint();
            //ADD somekind of report structure,file

        }
        else
        {
            std::vector<uint8_t> vector;
            vector=Vec_Extr::img_extract(image,Vec_Extr::no_alpha);
            qDebug() <<i<<". processed\n";
            //INSERT CONVERTING METHOD

            qDebug("Removed item\n");
            ui->progress_label->setText("converted "+ item->text());
            ui->progress_label->repaint();
        }



    }
    ui->progress_label->setText("total time: " + QString::number(std::difftime(std::time(NULL), start))+" sec");


    return;


}
