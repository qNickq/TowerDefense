#include "menu.h"
#include "game.h"

Menu::Menu(QWidget *parent)
{
    QVBoxLayout * v_box = new QVBoxLayout ();
    this->setLayout(v_box);
    setWindowTitle("Tower Defense");
    setFixedSize(300,300);
    startgame.setText("&Start game");
    quit.setText("&Exit");
    v_box->addWidget(&startgame);
    v_box->addWidget(&quit);
    connect(&startgame, SIGNAL(clicked()), this, SLOT(chooseLvl()));
    connect(&quit, SIGNAL(clicked()), this, SLOT(close()));
    Q_UNUSED(parent);
}

void Menu::chooseLvl()
{
    Game * game  = new Game();
    this->close();
    game->show();
    qDebug()<< game->size();
}
