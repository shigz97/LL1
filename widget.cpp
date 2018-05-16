#include "widget.h"
#include "ui_widget.h"

#include "EditText.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);


    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(10);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);
    ui->MianWindow->setGraphicsEffect(shadow);

    ui->input_string->setPlaceholderText(QString("输入串"));
    ui->input_grammer->setPlaceholderText(QString("文法"));
    ui->out_first->setPlaceholderText(QString("first集"));
    ui->out_follow->setPlaceholderText(QString("follow集"));

    connect(&grammer,SIGNAL(gottenCode(QString)),
            this,SLOT(print_grammer(QString)));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    if(this->z==QPoint())
        return;
    QPoint y=event->globalPos();
    QPoint x=y-z;
    this->move(x);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint x=this->geometry().topLeft();
    QPoint y=event->globalPos();
    this->z=y-x;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z=QPoint();
}

void Widget::on_btnClose_clicked()
{
    this->close();
}

void Widget::on_btnMin_clicked()
{
    this->showMinimized();
}



void Widget::print_grammer(QString got)
{
    ui->input_grammer->setText(got);
}

void Widget::on_btnOpen_clicked()
{
    ui->input_grammer->clear();
    ui->input_string->clear();
    ui->out_first->clear();
    ui->out_follow->clear();
    ui->out_process->clear();
    QString path=QFileDialog::getOpenFileName(this,tr("选择文件"),".",tr("txt(*.txt)"));
    this->in_path=QFileInfo(path).absolutePath();
    grammer.getCode(path);
}

void Widget::on_btnAna_clicked()
{
    string p=this->in_path.toStdString();

    GAnalyse ana(p);

    //string pp=ana.test();
    QString in=ui->input_string->text();
    QString tempath=this->in_path+"/string.txt";
    qDebug()<<tempath;
    QFile file(tempath);
    if(file.open(QFile::WriteOnly))
    {
        qDebug()<<"a";
        QTextStream out(&file);
        QString outt=in+"#";
        out<<outt;
    }
    file.close();





    //ui->out_first->setText(QString::fromStdString(pp));
    /*int res=ana.executeGAna();
    string ppf="a"+res;
    QString pf=QString::fromStdString(ppf);
    ui->out_first->setText(pf);*/



    int res=ana.executeGAna();
    QString firstpath=this->in_path+"/first.txt";
    QString followpath=this->in_path+"/follow.txt";
    QString selectpath=this->in_path+"/select.txt";
    QString processpath=this->in_path+"/process.txt";
    QFile first(firstpath);
    first.open(QFile::ReadOnly);
    QString outfirst=first.readAll();
    QFile follow(followpath);
    follow.open(QFile::ReadOnly);
    QString outfollow=follow.readAll();
    QFile select(selectpath);
    select.open(QFile::ReadOnly);
    QString outselect=select.readAll();
    QFile process(processpath);
    process.open(QFile::ReadOnly);
    QTextStream pro(&process);
    pro.setCodec("gb2312");
    QString outprocess=pro.readAll();
    if(res==1){
        ui->out_first->setText(outfirst);
        ui->out_follow->setText(outfollow);
        ui->out_process->setText(outselect);
        ui->out_process->append(QString("-----------------------"));
        ui->out_process->append(outprocess);
        QMessageBox::information(this,QString("结果"),QString("分析成功"));
    }
    else if(res==2) //不是LL1文法
    {
        ui->out_first->setText(outfirst);
        ui->out_follow->setText(outfollow);
        ui->out_process->setText(outselect);
        QMessageBox::information(this,QString("结果"),QString("该文法不是LL1文法"));
    }
    else{    //规约失败
        ui->out_first->setText(outfirst);
        ui->out_follow->setText(outfollow);
        ui->out_process->setText(outselect);
        QMessageBox::information(this,QString("结果"),QString("规约失败"));
    }
    //ui->out_first->setText(QString::fromStdString(ana.test()));
}
