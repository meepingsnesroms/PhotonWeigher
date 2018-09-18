#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QListWidgetItem>

#include <cmath>

//光子かわいいですか。はい光子かわいいです


#define FIRST_USER_ATTRIBUTE 1000


static double nmToEv(double nm){
   return pow(nm / 1240.0, -1.0);
}

static double evToKg(double ev){
   return ev * 1.782662E-36;//weight of an electron volt in kilograms, 5.60959*10^35electronVolts = 1kiloGram, 1.782662*10^-36kiloGrams = 1electronVolt, taken from wolfram alpha website
}

static double parseToEv(QString valueString){
   QString extension = "";
   double inputNumber;
   double ev;

   if(valueString.length() >= 2){
      extension.push_front(valueString.back());
      valueString.chop(1);
      extension.push_front(valueString.back());
      valueString.chop(1);
   }

   inputNumber = valueString.toDouble();

   if(extension == "eV")
      ev = inputNumber;
   else if(extension == "nm")
      ev = nmToEv(inputNumber);
   else if(extension == "um")
      ev = nmToEv(inputNumber * 1000.0);
   else if(extension == "mm")
      ev = nmToEv(inputNumber * 1000000.0);
   else if(extension == "cm")
      ev = nmToEv(inputNumber * 10000000.0);
   else
      ev = 0.0;

   return ev;
}

static QString weighPhoton(QString energy){
   return QString::number(evToKg(parseToEv(energy)))+ "kg";
}

MainWindow::MainWindow(QWidget* parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow){
   ui->setupUi(this);

   ui->photonTypes->addItem("WIFI 2.4ghz");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "12.5cm");
   ui->photonTypes->addItem("WIFI 5.8ghz");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "5.17cm");
   ui->photonTypes->addItem("Red 650nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Red");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "650nm");
   ui->photonTypes->addItem("Green 520nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Green");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "520nm");
   ui->photonTypes->addItem("Blue 450nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Blue");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "450nm");
   ui->photonTypes->addItem("UVA 380nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Violet");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "380nm");
   ui->photonTypes->addItem("UVB 310nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Violet");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "310nm");
   ui->photonTypes->addItem("UVC 250nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setBackgroundColor("Violet");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "250nm");
   ui->photonTypes->addItem("Soft Xray 10nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "10nm");
   ui->photonTypes->addItem("Hard Xray 0.1nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "0.1nm");
   ui->photonTypes->addItem("Gamma Ray 0.0001nm");
   ui->photonTypes->item(ui->photonTypes->count() - 1)->setData(FIRST_USER_ATTRIBUTE, "0.0001nm");
}

MainWindow::~MainWindow(){
   delete ui;
}

void MainWindow::on_weigh_clicked(){
   ui->weight->setText("Your Photon Weighs:" + weighPhoton(ui->wavelength->text()));
   ui->weight->repaint();
}

void MainWindow::on_photonTypes_itemClicked(QListWidgetItem* item){
    ui->wavelength->setText(item->data(FIRST_USER_ATTRIBUTE).toString());
    ui->weight->repaint();
}
