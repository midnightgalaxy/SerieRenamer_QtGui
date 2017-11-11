#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "episoderenamer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SerieRenamer");
    //this->setFixedSize(1000, 800);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText("");

    std::string path = ui->lineEdit_14->text().toStdString();
    std::string name = ui->lineEdit->text().toStdString();
    std::string season = ui->lineEdit_4->text().toStdString();
    std::string fileType = ui->lineEdit_2->text().toStdString();
    std::string extra = ui->lineEdit_3->text().toStdString();


    if (ui->checkBox->isChecked()) {
        EpisodeRenamer renamer(path, name, season, fileType, extra);
        renamer.execute();
        ui->textEdit->setText(renamer.getInformationOutput().c_str());
    } else {
        EpisodeRenamer renamer(path, name, season, fileType);
        renamer.execute();
        ui->textEdit->setText(renamer.getInformationOutput().c_str());
    }
}
