#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditTamanho->setValidator(new QIntValidator(1,999));
    ui->lineEditTamanho->setFocus();
    ui->pushButtonOrdenar->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGerar_clicked()
{
    QString saida;
    int tamanho;

    try
    {
        if(ui->lineEditTamanho->text()=="" || ui->lineEditTamanho->text().toInt()==0)
        {
            throw QString("Inválido.");
        }

        ui->pushButtonOrdenar->setEnabled(true);

        tamanho=ui->lineEditTamanho->text().toInt();

        n1=new bry::Ordenar(tamanho);

        saida=n1->getDesordenado();

        ui->textEditConjOri->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditTamanho->clear();
        ui->lineEditTamanho->setFocus();
        ui->pushButtonOrdenar->setEnabled(false);
        ui->textEditConjOrdenado->clear();
        ui->textEditConjOri->clear();
    }
}


void MainWindow::on_pushButtonOrdenar_clicked()
{
    QString saida;

    try
    {
        if(ui->lineEditTamanho->text()=="" || ui->lineEditTamanho->text().toInt()==0)
        {
            throw QString("Inválido.");
        }

        saida=n1->ordenarFila();

        ui->textEditConjOrdenado->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditTamanho->clear();
        ui->lineEditTamanho->setFocus();
        ui->pushButtonOrdenar->setEnabled(false);
        ui->textEditConjOrdenado->clear();
        ui->textEditConjOri->clear();
    }
}

