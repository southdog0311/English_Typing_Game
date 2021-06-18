#ifndef RANKLIST_H
#define RANKLIST_H

#include <QDialog>

namespace Ui {
class ranklist;
}

class ranklist : public QDialog
{
    Q_OBJECT

public:
    explicit ranklist(QWidget *parent = nullptr);
    ~ranklist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ranklist *ui;
};

#endif // RANKLIST_H
