#include "ranklist.h"
#include "ui_ranklist.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QTime>
#include<QDebug>
#include<QtAlgorithms>
#include <QSet>
ranklist::ranklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ranklist)
{
    ui->setupUi(this);
}

ranklist::~ranklist()
{
    delete ui;
}

void ranklist::on_pushButton_clicked()
{
    QFile file("D:\English_Typing_Game-main\test4.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
     {
           QMessageBox::warning(this,"title","system error");
     }
     QTextStream in(&file);
     QString text=in.readAll();
     QStringList list;

     std::sort(text.begin(), text.end(), [](const QString& s1, const QString& s2)
     {
         return s1.toInt() < s2.toInt();

     });
     int count = ui->listWidget->count();
     for(int i=0;i<count;i++)
     {
          QListWidgetItem* it =  ui->listWidget->takeItem(0);
          delete it;
     }
     int len=text.size();
     for(int i =0; i<len; i=i+1)
     {
         list << text.left(1);
         text = text.mid(1);
     }
     ui->listWidget->addItems(list);

     file.close();

}
