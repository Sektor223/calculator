#include "mainwindow.h"
#include "ui_mainwindow.h"

double firsNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(ui->pushButton_null, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
     connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(operations()));
     connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
     connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_op()));
     connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_op()));
     connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_op()));
     connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_op()));

     ui->pushButton_divide->setCheckable(true);
     ui->pushButton_mult->setCheckable(true);
     ui->pushButton_plus->setCheckable(true);
     ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers(){

    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(ui->resultat->text().contains(".")&&button->text() == "0"){
        new_label =ui->resultat->text() + button->text();
    } else{
    all_numbers = (ui->resultat->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->resultat->setText(new_label);

}

void MainWindow::operations(){

    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "+/-"){
    all_numbers = (ui->resultat->text()).toDouble();
        all_numbers *= -1;

    new_label = QString::number(all_numbers, 'g', 15);
    ui->resultat->setText(new_label);
    }
    else if(button->text() == "%"){
        all_numbers = (ui->resultat->text()).toDouble();
        all_numbers *= 0.01;

        new_label = QString::number(all_numbers, 'g', 15);
        ui->resultat->setText(new_label);
    }
}

void MainWindow::math_op()
{
    QPushButton *button = (QPushButton *)sender();
    firsNum = ui->resultat->text().toDouble();
    ui->resultat->setText("0");
    button->setChecked(true);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->resultat->text().contains('.'))){
    ui->resultat->setText(ui->resultat->text() + ".");
    }
}


void MainWindow::on_pushButton_reset_clicked()
{
    ui->resultat->setText("0");
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_mult->setChecked(false);
}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNum, secondNum;
    QString new_label;

    secondNum = ui->resultat->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNum = firsNum + secondNum;
        new_label = QString::number(labelNum, 'g', 15);

        ui->resultat->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        labelNum = firsNum - secondNum;
        new_label = QString::number(labelNum, 'g', 15);

        ui->resultat->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_divide->isChecked()){
        if(secondNum==0){
            ui->resultat->setText("0");
        }
        else{
        labelNum = firsNum / secondNum;
        new_label = QString::number(labelNum, 'g', 15);

        ui->resultat->setText(new_label);
        ui->pushButton_divide->setChecked(false);
        }
    }else if(ui->pushButton_mult->isChecked()){
        labelNum = firsNum * secondNum;
        new_label = QString::number(labelNum, 'g', 15);

        ui->resultat->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
}

