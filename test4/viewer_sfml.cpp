#include "QSFMLCanvas.hpp"
#include "ui_viewer_sfml.h"

Viewer_SFML::Viewer_SFML(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Viewer_SFML)
{
    ui->setupUi(this);
}

Viewer_SFML::~Viewer_SFML()
{
    delete ui;
}
