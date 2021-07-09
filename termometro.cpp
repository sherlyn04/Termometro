#include "termometro.h"
#include "ui_termometro.h"

#include <QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);
    //Conectar dialCent ---> cent2Fahr
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));
    //Conectar dialFahr ---> fahr2cent
    connect(ui->cmdFahr,SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));
   //Conectar dialCent ---> cent2kel
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kel(int)));
    //Conectar dialKel ---> kel2cent
    connect(ui->cmdKelvin,SIGNAL(valueChanged(int)),
            this, SLOT(kel2cent(int)));
    //Conectar dialFahr ---> fahr2kel
    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2kel(int)));
    //Conectar dialKel ---> kel2fahr
    connect(ui->cmdKelvin, SIGNAL(valueChanged(int)),
            this, SLOT(kel2fahr(int)));

}

Termometro::~Termometro()
{
    delete ui;
}

void Termometro::cent2fahr(int valor)
{
    if(ui->cmdCent->hasFocus()){
    float f = valor * 9.0 / 5 + 32;
    ui->cmdFahr->setValue(f);
    }
}

void Termometro::fahr2cent(int valor)
{
    if(ui->cmdFahr->hasFocus()){
    float c = (valor - 32) * 5.8/9;
    ui->cmdCent->setValue(c);
    }
}

void Termometro::cent2kel(int valor)
{
    if(ui->cmdCent->hasFocus()){
        float k = valor + 273.15;
        ui->cmdKelvin->setValue(k);
    }

}

void Termometro::kel2cent(int valor)
{
    if(ui->cmdKelvin->hasFocus()){
        float c = valor - 273.15;
        ui->cmdCent->setValue(c);
    }

}

void Termometro::fahr2kel(int valor)
{
    if(ui->cmdFahr->hasFocus()){
        float k = (valor - 32) * 5/9 + 273.15;
        ui->cmdKelvin->setValue(k);
    }
}

void Termometro::kel2fahr(int valor)
{
    if(ui->cmdKelvin->hasFocus()){
        float f = (valor - 273.15) * 9/5 + 32;
        ui->cmdFahr->setValue(f);
    }
}

