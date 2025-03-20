#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_inchiriere_filme.h"

class inchiriere_filme : public QMainWindow
{
    Q_OBJECT

public:
    inchiriere_filme(QWidget *parent = nullptr);
    ~inchiriere_filme();

private:
    Ui::inchiriere_filmeClass ui;
};
