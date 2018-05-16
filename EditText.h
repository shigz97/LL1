#ifndef EDITTEXT_H
#define EDITTEXT_H

#include <QObject>

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>

class EditText : public QObject
{
    Q_OBJECT
public:
    explicit EditText(QObject *parent = nullptr);

signals:
    void gottenCode(QString code);

public slots:
    void getCode(QString &path);

};

#endif // EDITTEXT_H
