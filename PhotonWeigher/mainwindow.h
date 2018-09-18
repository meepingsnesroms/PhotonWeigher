#pragma once

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow{
   Q_OBJECT

public:
   explicit MainWindow(QWidget* parent = nullptr);
   ~MainWindow();

private slots:
   void on_weigh_clicked();

   void on_photonTypes_itemClicked(QListWidgetItem* item);

private:
   Ui::MainWindow* ui;
};
