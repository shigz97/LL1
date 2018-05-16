/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *MianWindow;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_Left;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *input_grammer;
    QFrame *frame_button;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *input_string;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnOpen;
    QPushButton *btnAna;
    QFrame *frame_Right;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *out_first;
    QTextEdit *out_follow;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *out_process;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(976, 722);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MianWindow = new QWidget(Widget);
        MianWindow->setObjectName(QStringLiteral("MianWindow"));
        MianWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(MianWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(MianWindow);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        btnMin = new QPushButton(MianWindow);
        btnMin->setObjectName(QStringLiteral("btnMin"));
        btnMin->setMinimumSize(QSize(42, 42));
        btnMin->setMaximumSize(QSize(42, 42));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(24);
        btnMin->setFont(font1);
        btnMin->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"}\n"
"QPushButton:hover{	\n"
"	background-color: rgb(240, 240, 240);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(223, 223, 223);\n"
"}"));

        horizontalLayout_2->addWidget(btnMin);

        btnClose = new QPushButton(MianWindow);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setMinimumSize(QSize(42, 42));
        btnClose->setMaximumSize(QSize(42, 42));
        btnClose->setFont(font1);
        btnClose->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(238, 0, 0);\n"
"}"));

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_2);

        frame = new QFrame(MianWindow);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame_Left = new QFrame(frame);
        frame_Left->setObjectName(QStringLiteral("frame_Left"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_Left->sizePolicy().hasHeightForWidth());
        frame_Left->setSizePolicy(sizePolicy1);
        frame_Left->setFrameShape(QFrame::StyledPanel);
        frame_Left->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_Left);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        input_grammer = new QTextEdit(frame_Left);
        input_grammer->setObjectName(QStringLiteral("input_grammer"));

        verticalLayout_2->addWidget(input_grammer);

        frame_button = new QFrame(frame_Left);
        frame_button->setObjectName(QStringLiteral("frame_button"));
        frame_button->setFrameShape(QFrame::StyledPanel);
        frame_button->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_button);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        input_string = new QLineEdit(frame_button);
        input_string->setObjectName(QStringLiteral("input_string"));

        horizontalLayout_4->addWidget(input_string);


        verticalLayout_2->addWidget(frame_button);

        frame_2 = new QFrame(frame_Left);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btnOpen = new QPushButton(frame_2);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));

        horizontalLayout_5->addWidget(btnOpen);

        btnAna = new QPushButton(frame_2);
        btnAna->setObjectName(QStringLiteral("btnAna"));

        horizontalLayout_5->addWidget(btnAna);


        verticalLayout_2->addWidget(frame_2);

        verticalLayout_2->setStretch(0, 12);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_3->addWidget(frame_Left);

        frame_Right = new QFrame(frame);
        frame_Right->setObjectName(QStringLiteral("frame_Right"));
        sizePolicy1.setHeightForWidth(frame_Right->sizePolicy().hasHeightForWidth());
        frame_Right->setSizePolicy(sizePolicy1);
        frame_Right->setFrameShape(QFrame::StyledPanel);
        frame_Right->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_Right);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        out_first = new QTextEdit(frame_Right);
        out_first->setObjectName(QStringLiteral("out_first"));

        horizontalLayout_6->addWidget(out_first);

        out_follow = new QTextEdit(frame_Right);
        out_follow->setObjectName(QStringLiteral("out_follow"));

        horizontalLayout_6->addWidget(out_follow);


        verticalLayout_3->addLayout(horizontalLayout_6);

        frame_3 = new QFrame(frame_Right);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setSpacing(1);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        out_process = new QTextEdit(frame_3);
        out_process->setObjectName(QStringLiteral("out_process"));

        horizontalLayout_7->addWidget(out_process);


        verticalLayout_3->addWidget(frame_3);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 6);

        horizontalLayout_3->addWidget(frame_Right);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout->addWidget(frame);


        horizontalLayout->addWidget(MianWindow);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "    LL1\350\257\255\346\263\225\345\210\206\346\236\220\345\231\250", Q_NULLPTR));
        btnMin->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        btnClose->setText(QApplication::translate("Widget", "\303\227", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        btnAna->setText(QApplication::translate("Widget", "\345\210\206\346\236\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
