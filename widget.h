#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <string>
#include <QMessageBox>

#include "EditText.h"
#include "GAnalyse.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    ~Widget();

private slots:
    void on_btnClose_clicked();

    void on_btnMin_clicked();

    void print_grammer(QString got);

    void on_btnOpen_clicked();

    void on_btnAna_clicked();

private:
    Ui::Widget *ui;
    QPoint z;
    QString in_path;
    QString out_path;
    EditText grammer;
};

#endif // WIDGET_H
