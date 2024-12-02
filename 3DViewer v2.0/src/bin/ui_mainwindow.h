/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_openFile;
    QAction *action_close;
    QAction *action_saveSettings;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    MyOpenGLWidget *openGLWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_rot_X_p;
    QPushButton *pushButton_rot_Y_p;
    QPushButton *pushButton_rot_Z_p;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_rot_X_m;
    QPushButton *pushButton_rot_Y_m;
    QPushButton *pushButton_rot_Z_m;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_euler_x;
    QLabel *label_euler_y;
    QLabel *label_euler_z;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_trans_X_p;
    QPushButton *pushButton_trans_Y_p;
    QPushButton *pushButton_trans_Z_p;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_trans_X_m;
    QPushButton *pushButton_trans_Y_m;
    QPushButton *pushButton_trans_Z_m;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_scale_p;
    QPushButton *pushButton_scale_m;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_BMP;
    QPushButton *pushButton_JPEG;
    QPushButton *pushButton_gif;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QPushButton *pushButton_bcgWhite;
    QPushButton *pushButton_bcgGreen;
    QPushButton *pushButton_bcgBrown;
    QPushButton *pushButton_bcgPurple;
    QPushButton *pushButton_bcgYellow;
    QPushButton *pushButton_bcgBlack;
    QPushButton *pushButton_bcgPink;
    QPushButton *pushButton_bcgBlue;
    QPushButton *pushButton_bcgGrey;
    QPushButton *pushButton_bcgOrange;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_AutoRot;
    QPushButton *pushButton_switchisProj;
    QPushButton *pushButton_modeDraw;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_drawVerices;
    QPushButton *pushButton_VSize_p;
    QPushButton *pushButton_VSize_m;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_vertexYellow;
    QPushButton *pushButton_vertexWhite;
    QPushButton *pushButton_vertexPink;
    QPushButton *pushButton_vertexBrown;
    QPushButton *pushButton_vertexPurple;
    QPushButton *pushButton_vertexBlack;
    QPushButton *pushButton_vertexGrey;
    QPushButton *pushButton_vertexBlue;
    QPushButton *pushButton_vertexGreen;
    QPushButton *pushButton_vertexOrange;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_dashedLine;
    QPushButton *pushButton_lineSize_p;
    QPushButton *pushButton_lineSize_m;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_edgePink;
    QPushButton *pushButton_edgeBrown;
    QPushButton *pushButton_edgePurple;
    QPushButton *pushButton_edgeWhite;
    QPushButton *pushButton_edgeYellow;
    QPushButton *pushButton_edgeBlue;
    QPushButton *pushButton_edgeGrey;
    QPushButton *pushButton_edgeBlack;
    QPushButton *pushButton_edgeGreen;
    QPushButton *pushButton_edgeOrange;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 921);
        action_openFile = new QAction(MainWindow);
        action_openFile->setObjectName(QString::fromUtf8("action_openFile"));
        action_close = new QAction(MainWindow);
        action_close->setObjectName(QString::fromUtf8("action_close"));
        action_saveSettings = new QAction(MainWindow);
        action_saveSettings->setObjectName(QString::fromUtf8("action_saveSettings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new MyOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(64, 64));

        horizontalLayout->addWidget(openGLWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_rot_X_p = new QPushButton(groupBox);
        pushButton_rot_X_p->setObjectName(QString::fromUtf8("pushButton_rot_X_p"));

        horizontalLayout_2->addWidget(pushButton_rot_X_p);

        pushButton_rot_Y_p = new QPushButton(groupBox);
        pushButton_rot_Y_p->setObjectName(QString::fromUtf8("pushButton_rot_Y_p"));

        horizontalLayout_2->addWidget(pushButton_rot_Y_p);

        pushButton_rot_Z_p = new QPushButton(groupBox);
        pushButton_rot_Z_p->setObjectName(QString::fromUtf8("pushButton_rot_Z_p"));

        horizontalLayout_2->addWidget(pushButton_rot_Z_p);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_rot_X_m = new QPushButton(groupBox);
        pushButton_rot_X_m->setObjectName(QString::fromUtf8("pushButton_rot_X_m"));

        horizontalLayout_3->addWidget(pushButton_rot_X_m);

        pushButton_rot_Y_m = new QPushButton(groupBox);
        pushButton_rot_Y_m->setObjectName(QString::fromUtf8("pushButton_rot_Y_m"));

        horizontalLayout_3->addWidget(pushButton_rot_Y_m);

        pushButton_rot_Z_m = new QPushButton(groupBox);
        pushButton_rot_Z_m->setObjectName(QString::fromUtf8("pushButton_rot_Z_m"));

        horizontalLayout_3->addWidget(pushButton_rot_Z_m);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_euler_x = new QLabel(groupBox);
        label_euler_x->setObjectName(QString::fromUtf8("label_euler_x"));

        horizontalLayout_11->addWidget(label_euler_x);

        label_euler_y = new QLabel(groupBox);
        label_euler_y->setObjectName(QString::fromUtf8("label_euler_y"));

        horizontalLayout_11->addWidget(label_euler_y);

        label_euler_z = new QLabel(groupBox);
        label_euler_z->setObjectName(QString::fromUtf8("label_euler_z"));

        horizontalLayout_11->addWidget(label_euler_z);


        verticalLayout_2->addLayout(horizontalLayout_11);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_trans_X_p = new QPushButton(groupBox);
        pushButton_trans_X_p->setObjectName(QString::fromUtf8("pushButton_trans_X_p"));
        pushButton_trans_X_p->setEnabled(true);

        horizontalLayout_4->addWidget(pushButton_trans_X_p);

        pushButton_trans_Y_p = new QPushButton(groupBox);
        pushButton_trans_Y_p->setObjectName(QString::fromUtf8("pushButton_trans_Y_p"));
        pushButton_trans_Y_p->setEnabled(true);

        horizontalLayout_4->addWidget(pushButton_trans_Y_p);

        pushButton_trans_Z_p = new QPushButton(groupBox);
        pushButton_trans_Z_p->setObjectName(QString::fromUtf8("pushButton_trans_Z_p"));
        pushButton_trans_Z_p->setEnabled(true);

        horizontalLayout_4->addWidget(pushButton_trans_Z_p);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_trans_X_m = new QPushButton(groupBox);
        pushButton_trans_X_m->setObjectName(QString::fromUtf8("pushButton_trans_X_m"));
        pushButton_trans_X_m->setEnabled(true);

        horizontalLayout_7->addWidget(pushButton_trans_X_m);

        pushButton_trans_Y_m = new QPushButton(groupBox);
        pushButton_trans_Y_m->setObjectName(QString::fromUtf8("pushButton_trans_Y_m"));
        pushButton_trans_Y_m->setEnabled(true);

        horizontalLayout_7->addWidget(pushButton_trans_Y_m);

        pushButton_trans_Z_m = new QPushButton(groupBox);
        pushButton_trans_Z_m->setObjectName(QString::fromUtf8("pushButton_trans_Z_m"));
        pushButton_trans_Z_m->setEnabled(true);

        horizontalLayout_7->addWidget(pushButton_trans_Z_m);


        verticalLayout_2->addLayout(horizontalLayout_7);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_scale_p = new QPushButton(groupBox);
        pushButton_scale_p->setObjectName(QString::fromUtf8("pushButton_scale_p"));
        pushButton_scale_p->setEnabled(true);

        horizontalLayout_6->addWidget(pushButton_scale_p);

        pushButton_scale_m = new QPushButton(groupBox);
        pushButton_scale_m->setObjectName(QString::fromUtf8("pushButton_scale_m"));
        pushButton_scale_m->setEnabled(true);

        horizontalLayout_6->addWidget(pushButton_scale_m);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_BMP = new QPushButton(groupBox_2);
        pushButton_BMP->setObjectName(QString::fromUtf8("pushButton_BMP"));

        horizontalLayout_8->addWidget(pushButton_BMP);

        pushButton_JPEG = new QPushButton(groupBox_2);
        pushButton_JPEG->setObjectName(QString::fromUtf8("pushButton_JPEG"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_JPEG->sizePolicy().hasHeightForWidth());
        pushButton_JPEG->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(pushButton_JPEG);

        pushButton_gif = new QPushButton(groupBox_2);
        pushButton_gif->setObjectName(QString::fromUtf8("pushButton_gif"));

        horizontalLayout_8->addWidget(pushButton_gif);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setFocusPolicy(Qt::NoFocus);
        groupBox_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_bcgWhite = new QPushButton(groupBox_3);
        pushButton_bcgWhite->setObjectName(QString::fromUtf8("pushButton_bcgWhite"));

        gridLayout->addWidget(pushButton_bcgWhite, 0, 4, 1, 1);

        pushButton_bcgGreen = new QPushButton(groupBox_3);
        pushButton_bcgGreen->setObjectName(QString::fromUtf8("pushButton_bcgGreen"));

        gridLayout->addWidget(pushButton_bcgGreen, 0, 5, 1, 1);

        pushButton_bcgBrown = new QPushButton(groupBox_3);
        pushButton_bcgBrown->setObjectName(QString::fromUtf8("pushButton_bcgBrown"));

        gridLayout->addWidget(pushButton_bcgBrown, 0, 9, 1, 1);

        pushButton_bcgPurple = new QPushButton(groupBox_3);
        pushButton_bcgPurple->setObjectName(QString::fromUtf8("pushButton_bcgPurple"));

        gridLayout->addWidget(pushButton_bcgPurple, 0, 2, 1, 1);

        pushButton_bcgYellow = new QPushButton(groupBox_3);
        pushButton_bcgYellow->setObjectName(QString::fromUtf8("pushButton_bcgYellow"));

        gridLayout->addWidget(pushButton_bcgYellow, 0, 1, 1, 1);

        pushButton_bcgBlack = new QPushButton(groupBox_3);
        pushButton_bcgBlack->setObjectName(QString::fromUtf8("pushButton_bcgBlack"));

        gridLayout->addWidget(pushButton_bcgBlack, 0, 3, 1, 1);

        pushButton_bcgPink = new QPushButton(groupBox_3);
        pushButton_bcgPink->setObjectName(QString::fromUtf8("pushButton_bcgPink"));

        gridLayout->addWidget(pushButton_bcgPink, 0, 8, 1, 1);

        pushButton_bcgBlue = new QPushButton(groupBox_3);
        pushButton_bcgBlue->setObjectName(QString::fromUtf8("pushButton_bcgBlue"));

        gridLayout->addWidget(pushButton_bcgBlue, 0, 6, 1, 1);

        pushButton_bcgGrey = new QPushButton(groupBox_3);
        pushButton_bcgGrey->setObjectName(QString::fromUtf8("pushButton_bcgGrey"));

        gridLayout->addWidget(pushButton_bcgGrey, 0, 0, 1, 1);

        pushButton_bcgOrange = new QPushButton(groupBox_3);
        pushButton_bcgOrange->setObjectName(QString::fromUtf8("pushButton_bcgOrange"));

        gridLayout->addWidget(pushButton_bcgOrange, 0, 7, 1, 1);


        verticalLayout_4->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton_AutoRot = new QPushButton(groupBox_4);
        pushButton_AutoRot->setObjectName(QString::fromUtf8("pushButton_AutoRot"));

        verticalLayout_5->addWidget(pushButton_AutoRot);

        pushButton_switchisProj = new QPushButton(groupBox_4);
        pushButton_switchisProj->setObjectName(QString::fromUtf8("pushButton_switchisProj"));

        verticalLayout_5->addWidget(pushButton_switchisProj);

        pushButton_modeDraw = new QPushButton(groupBox_4);
        pushButton_modeDraw->setObjectName(QString::fromUtf8("pushButton_modeDraw"));

        verticalLayout_5->addWidget(pushButton_modeDraw);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_drawVerices = new QPushButton(groupBox_5);
        pushButton_drawVerices->setObjectName(QString::fromUtf8("pushButton_drawVerices"));

        horizontalLayout_9->addWidget(pushButton_drawVerices);

        pushButton_VSize_p = new QPushButton(groupBox_5);
        pushButton_VSize_p->setObjectName(QString::fromUtf8("pushButton_VSize_p"));

        horizontalLayout_9->addWidget(pushButton_VSize_p);

        pushButton_VSize_m = new QPushButton(groupBox_5);
        pushButton_VSize_m->setObjectName(QString::fromUtf8("pushButton_VSize_m"));

        horizontalLayout_9->addWidget(pushButton_VSize_m);


        verticalLayout_6->addLayout(horizontalLayout_9);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_vertexYellow = new QPushButton(groupBox_5);
        pushButton_vertexYellow->setObjectName(QString::fromUtf8("pushButton_vertexYellow"));

        gridLayout_3->addWidget(pushButton_vertexYellow, 0, 1, 1, 1);

        pushButton_vertexWhite = new QPushButton(groupBox_5);
        pushButton_vertexWhite->setObjectName(QString::fromUtf8("pushButton_vertexWhite"));

        gridLayout_3->addWidget(pushButton_vertexWhite, 0, 4, 1, 1);

        pushButton_vertexPink = new QPushButton(groupBox_5);
        pushButton_vertexPink->setObjectName(QString::fromUtf8("pushButton_vertexPink"));

        gridLayout_3->addWidget(pushButton_vertexPink, 0, 8, 1, 1);

        pushButton_vertexBrown = new QPushButton(groupBox_5);
        pushButton_vertexBrown->setObjectName(QString::fromUtf8("pushButton_vertexBrown"));

        gridLayout_3->addWidget(pushButton_vertexBrown, 0, 9, 1, 1);

        pushButton_vertexPurple = new QPushButton(groupBox_5);
        pushButton_vertexPurple->setObjectName(QString::fromUtf8("pushButton_vertexPurple"));

        gridLayout_3->addWidget(pushButton_vertexPurple, 0, 2, 1, 1);

        pushButton_vertexBlack = new QPushButton(groupBox_5);
        pushButton_vertexBlack->setObjectName(QString::fromUtf8("pushButton_vertexBlack"));

        gridLayout_3->addWidget(pushButton_vertexBlack, 0, 3, 1, 1);

        pushButton_vertexGrey = new QPushButton(groupBox_5);
        pushButton_vertexGrey->setObjectName(QString::fromUtf8("pushButton_vertexGrey"));

        gridLayout_3->addWidget(pushButton_vertexGrey, 0, 0, 1, 1);

        pushButton_vertexBlue = new QPushButton(groupBox_5);
        pushButton_vertexBlue->setObjectName(QString::fromUtf8("pushButton_vertexBlue"));

        gridLayout_3->addWidget(pushButton_vertexBlue, 0, 6, 1, 1);

        pushButton_vertexGreen = new QPushButton(groupBox_5);
        pushButton_vertexGreen->setObjectName(QString::fromUtf8("pushButton_vertexGreen"));

        gridLayout_3->addWidget(pushButton_vertexGreen, 0, 5, 1, 1);

        pushButton_vertexOrange = new QPushButton(groupBox_5);
        pushButton_vertexOrange->setObjectName(QString::fromUtf8("pushButton_vertexOrange"));

        gridLayout_3->addWidget(pushButton_vertexOrange, 0, 7, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);


        verticalLayout->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(widget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_7 = new QVBoxLayout(groupBox_6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_dashedLine = new QPushButton(groupBox_6);
        pushButton_dashedLine->setObjectName(QString::fromUtf8("pushButton_dashedLine"));

        horizontalLayout_10->addWidget(pushButton_dashedLine);

        pushButton_lineSize_p = new QPushButton(groupBox_6);
        pushButton_lineSize_p->setObjectName(QString::fromUtf8("pushButton_lineSize_p"));

        horizontalLayout_10->addWidget(pushButton_lineSize_p);

        pushButton_lineSize_m = new QPushButton(groupBox_6);
        pushButton_lineSize_m->setObjectName(QString::fromUtf8("pushButton_lineSize_m"));

        horizontalLayout_10->addWidget(pushButton_lineSize_m);


        verticalLayout_7->addLayout(horizontalLayout_10);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_edgePink = new QPushButton(groupBox_6);
        pushButton_edgePink->setObjectName(QString::fromUtf8("pushButton_edgePink"));

        gridLayout_2->addWidget(pushButton_edgePink, 0, 8, 1, 1);

        pushButton_edgeBrown = new QPushButton(groupBox_6);
        pushButton_edgeBrown->setObjectName(QString::fromUtf8("pushButton_edgeBrown"));

        gridLayout_2->addWidget(pushButton_edgeBrown, 0, 9, 1, 1);

        pushButton_edgePurple = new QPushButton(groupBox_6);
        pushButton_edgePurple->setObjectName(QString::fromUtf8("pushButton_edgePurple"));

        gridLayout_2->addWidget(pushButton_edgePurple, 0, 2, 1, 1);

        pushButton_edgeWhite = new QPushButton(groupBox_6);
        pushButton_edgeWhite->setObjectName(QString::fromUtf8("pushButton_edgeWhite"));

        gridLayout_2->addWidget(pushButton_edgeWhite, 0, 4, 1, 1);

        pushButton_edgeYellow = new QPushButton(groupBox_6);
        pushButton_edgeYellow->setObjectName(QString::fromUtf8("pushButton_edgeYellow"));

        gridLayout_2->addWidget(pushButton_edgeYellow, 0, 1, 1, 1);

        pushButton_edgeBlue = new QPushButton(groupBox_6);
        pushButton_edgeBlue->setObjectName(QString::fromUtf8("pushButton_edgeBlue"));

        gridLayout_2->addWidget(pushButton_edgeBlue, 0, 6, 1, 1);

        pushButton_edgeGrey = new QPushButton(groupBox_6);
        pushButton_edgeGrey->setObjectName(QString::fromUtf8("pushButton_edgeGrey"));

        gridLayout_2->addWidget(pushButton_edgeGrey, 0, 0, 1, 1);

        pushButton_edgeBlack = new QPushButton(groupBox_6);
        pushButton_edgeBlack->setObjectName(QString::fromUtf8("pushButton_edgeBlack"));

        gridLayout_2->addWidget(pushButton_edgeBlack, 0, 3, 1, 1);

        pushButton_edgeGreen = new QPushButton(groupBox_6);
        pushButton_edgeGreen->setObjectName(QString::fromUtf8("pushButton_edgeGreen"));

        gridLayout_2->addWidget(pushButton_edgeGreen, 0, 5, 1, 1);

        pushButton_edgeOrange = new QPushButton(groupBox_6);
        pushButton_edgeOrange->setObjectName(QString::fromUtf8("pushButton_edgeOrange"));

        gridLayout_2->addWidget(pushButton_edgeOrange, 0, 7, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);


        verticalLayout->addWidget(groupBox_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_openFile);
        menu->addAction(action_saveSettings);
        menu->addAction(action_close);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3DViewer", nullptr));
        action_openFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_close->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        action_saveSettings->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\220\321\204\321\204\320\270\320\275\320\276\320\262\321\213 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        pushButton_rot_X_p->setText(QCoreApplication::translate("MainWindow", "+X", nullptr));
        pushButton_rot_Y_p->setText(QCoreApplication::translate("MainWindow", "+Y", nullptr));
        pushButton_rot_Z_p->setText(QCoreApplication::translate("MainWindow", "+Z", nullptr));
        pushButton_rot_X_m->setText(QCoreApplication::translate("MainWindow", "-X", nullptr));
        pushButton_rot_Y_m->setText(QCoreApplication::translate("MainWindow", "-Y", nullptr));
        pushButton_rot_Z_m->setText(QCoreApplication::translate("MainWindow", "-Z", nullptr));
        label_euler_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_euler_y->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_euler_z->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        pushButton_trans_X_p->setText(QCoreApplication::translate("MainWindow", "+X", nullptr));
        pushButton_trans_Y_p->setText(QCoreApplication::translate("MainWindow", "+Y", nullptr));
        pushButton_trans_Z_p->setText(QCoreApplication::translate("MainWindow", "+Z", nullptr));
        pushButton_trans_X_m->setText(QCoreApplication::translate("MainWindow", "-X", nullptr));
        pushButton_trans_Y_m->setText(QCoreApplication::translate("MainWindow", "-Y", nullptr));
        pushButton_trans_Z_m->setText(QCoreApplication::translate("MainWindow", "-Z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        pushButton_scale_p->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_scale_m->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \321\215\320\272\321\200\320\260\320\275\320\260:", nullptr));
        pushButton_BMP->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        pushButton_JPEG->setText(QCoreApplication::translate("MainWindow", "JPEG", nullptr));
        pushButton_gif->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        pushButton_bcgWhite->setText(QString());
        pushButton_bcgGreen->setText(QString());
        pushButton_bcgBrown->setText(QString());
        pushButton_bcgPurple->setText(QString());
        pushButton_bcgYellow->setText(QString());
        pushButton_bcgBlack->setText(QString());
        pushButton_bcgPink->setText(QString());
        pushButton_bcgBlue->setText(QString());
        pushButton_bcgGrey->setText(QString());
        pushButton_bcgOrange->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274\321\213 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_AutoRot->setToolTip(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\262\320\276\321\200\320\276\321\202 \320\241\321\202\320\260\321\200\321\202/\320\241\321\202\320\276\320\277", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_AutoRot->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\262\320\276\321\200\320\276\321\202 (\320\274\320\270\321\200\320\276\320\262\320\276\320\271)", nullptr));
        pushButton_switchisProj->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217 / \320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_modeDraw->setToolTip(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_modeDraw->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213:", nullptr));
        pushButton_drawVerices->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        pushButton_VSize_p->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_VSize_m->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_vertexYellow->setText(QString());
        pushButton_vertexWhite->setText(QString());
        pushButton_vertexPink->setText(QString());
        pushButton_vertexBrown->setText(QString());
        pushButton_vertexPurple->setText(QString());
        pushButton_vertexBlack->setText(QString());
        pushButton_vertexGrey->setText(QString());
        pushButton_vertexBlue->setText(QString());
        pushButton_vertexGreen->setText(QString());
        pushButton_vertexOrange->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270:", nullptr));
        pushButton_dashedLine->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        pushButton_lineSize_p->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_lineSize_m->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_edgePink->setText(QString());
        pushButton_edgeBrown->setText(QString());
        pushButton_edgePurple->setText(QString());
        pushButton_edgeWhite->setText(QString());
        pushButton_edgeYellow->setText(QString());
        pushButton_edgeBlue->setText(QString());
        pushButton_edgeGrey->setText(QString());
        pushButton_edgeBlack->setText(QString());
        pushButton_edgeGreen->setText(QString());
        pushButton_edgeOrange->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
