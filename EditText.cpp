#include "EditText.h"

EditText::EditText(QObject *parent) : QObject(parent)
{

}

void EditText::getCode(QString &path)
{
    QFile file(path);
    QString res;
    if(file.open(QFile::ReadOnly))
    {
        QTextStream fin(&file);
        uint number;
        fin>>number;
        QString temp;
        fin.readLine();
        for(uint i=1;i<=number;i++)
        {
            QString tep=fin.readLine();
            tep[tep.length()-1]='\n';
            temp=temp+tep;
        }
        //QString tt=QFileInfo(path).absolutePath()+'\n';
        //temp=temp+tt;
        emit gottenCode(temp);
        return;

    }
    else{
        res=QString();
         emit gottenCode(res);
        return;
    }

    file.close();

}
