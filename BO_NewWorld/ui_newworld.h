/********************************************************************************
** Form generated from reading UI file 'newworld.ui'
**
** Created: Thu Jun 12 03:53:53 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORLD_H
#define UI_NEWWORLD_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabWidget>
#include <QTableView>
#include <QToolBar>
#include <QToolBox>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWorld
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QFrame *line;
    QStackedWidget *stackedWidgetApp;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonAnnulConnect;
    QPushButton *pushButtonValidConnect;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLogAdmin;
    QLineEdit *lineEditMdpAdmin;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QTableView *tableViewRay;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_6;
    QPushButton *pushButtonUp;
    QPushButton *pushButtonDown;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEditDesRay;
    QPushButton *pushButtonRayValid;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_11;
    QLineEdit *lineEditModifRay;
    QPushButton *pushButtonRayModif;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page_3;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableViewProdActif;
    QComboBox *comboBoxProdAct;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBoxNewProd;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *lineEditProdDesi;
    QPushButton *pushButtonProdValid;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_10;
    QComboBox *comboBoxModifProd;
    QLineEdit *lineEditProdModif;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButtonProdDesac;
    QWidget *page_4;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QTableView *tableViewProdDesact;
    QVBoxLayout *verticalLayout_10;
    QComboBox *comboBoxProdDesact;
    QPushButton *pushButtonProdReact;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NewWorld)
    {
        if (NewWorld->objectName().isEmpty())
            NewWorld->setObjectName(QString::fromUtf8("NewWorld"));
        NewWorld->resize(572, 634);
        centralWidget = new QWidget(NewWorld);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        stackedWidgetApp = new QStackedWidget(centralWidget);
        stackedWidgetApp->setObjectName(QString::fromUtf8("stackedWidgetApp"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(178, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButtonAnnulConnect = new QPushButton(page);
        pushButtonAnnulConnect->setObjectName(QString::fromUtf8("pushButtonAnnulConnect"));

        horizontalLayout_3->addWidget(pushButtonAnnulConnect);

        pushButtonValidConnect = new QPushButton(page);
        pushButtonValidConnect->setObjectName(QString::fromUtf8("pushButtonValidConnect"));

        horizontalLayout_3->addWidget(pushButtonValidConnect);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 3);

        frame = new QFrame(page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(250, 125));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditLogAdmin = new QLineEdit(frame);
        lineEditLogAdmin->setObjectName(QString::fromUtf8("lineEditLogAdmin"));
        lineEditLogAdmin->setEnabled(false);
        lineEditLogAdmin->setReadOnly(false);

        verticalLayout_2->addWidget(lineEditLogAdmin);

        lineEditMdpAdmin = new QLineEdit(frame);
        lineEditMdpAdmin->setObjectName(QString::fromUtf8("lineEditMdpAdmin"));
        lineEditMdpAdmin->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEditMdpAdmin);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        stackedWidgetApp->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tableViewRay = new QTableView(tab);
        tableViewRay->setObjectName(QString::fromUtf8("tableViewRay"));
        tableViewRay->setMaximumSize(QSize(190, 16777215));
        tableViewRay->setDragEnabled(false);
        tableViewRay->setDragDropOverwriteMode(false);
        tableViewRay->setDragDropMode(QAbstractItemView::InternalMove);
        tableViewRay->setDefaultDropAction(Qt::IgnoreAction);
        tableViewRay->setAlternatingRowColors(true);
        tableViewRay->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewRay->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewRay->setGridStyle(Qt::NoPen);

        horizontalLayout_10->addWidget(tableViewRay);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        horizontalLayout_7->addWidget(label_6);


        verticalLayout_5->addLayout(horizontalLayout_7);

        pushButtonUp = new QPushButton(tab);
        pushButtonUp->setObjectName(QString::fromUtf8("pushButtonUp"));

        verticalLayout_5->addWidget(pushButtonUp);

        pushButtonDown = new QPushButton(tab);
        pushButtonDown->setObjectName(QString::fromUtf8("pushButtonDown"));

        verticalLayout_5->addWidget(pushButtonDown);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_8->addWidget(label_7);


        verticalLayout_5->addLayout(horizontalLayout_8);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);

        lineEditDesRay = new QLineEdit(tab);
        lineEditDesRay->setObjectName(QString::fromUtf8("lineEditDesRay"));

        verticalLayout_5->addWidget(lineEditDesRay);

        pushButtonRayValid = new QPushButton(tab);
        pushButtonRayValid->setObjectName(QString::fromUtf8("pushButtonRayValid"));

        verticalLayout_5->addWidget(pushButtonRayValid);

        line_4 = new QFrame(tab);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        horizontalLayout_9->addWidget(label_11);


        verticalLayout_5->addLayout(horizontalLayout_9);

        lineEditModifRay = new QLineEdit(tab);
        lineEditModifRay->setObjectName(QString::fromUtf8("lineEditModifRay"));

        verticalLayout_5->addWidget(lineEditModifRay);

        pushButtonRayModif = new QPushButton(tab);
        pushButtonRayModif->setObjectName(QString::fromUtf8("pushButtonRayModif"));

        verticalLayout_5->addWidget(pushButtonRayModif);


        horizontalLayout_10->addLayout(verticalLayout_5);


        gridLayout_5->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 512, 381));
        gridLayout_7 = new QGridLayout(page_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableViewProdActif = new QTableView(page_3);
        tableViewProdActif->setObjectName(QString::fromUtf8("tableViewProdActif"));
        tableViewProdActif->setMaximumSize(QSize(16777215, 16777215));
        tableViewProdActif->setAlternatingRowColors(true);
        tableViewProdActif->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(tableViewProdActif);

        comboBoxProdAct = new QComboBox(page_3);
        comboBoxProdAct->setObjectName(QString::fromUtf8("comboBoxProdAct"));

        verticalLayout_4->addWidget(comboBoxProdAct);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        comboBoxNewProd = new QComboBox(page_3);
        comboBoxNewProd->setObjectName(QString::fromUtf8("comboBoxNewProd"));

        verticalLayout_6->addWidget(comboBoxNewProd);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_4);

        lineEditProdDesi = new QLineEdit(page_3);
        lineEditProdDesi->setObjectName(QString::fromUtf8("lineEditProdDesi"));

        verticalLayout_6->addWidget(lineEditProdDesi);

        pushButtonProdValid = new QPushButton(page_3);
        pushButtonProdValid->setObjectName(QString::fromUtf8("pushButtonProdValid"));

        verticalLayout_6->addWidget(pushButtonProdValid);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(verticalLayout_7);

        line_3 = new QFrame(page_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);

        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        horizontalLayout_13->addWidget(label_10);


        verticalLayout_8->addLayout(horizontalLayout_13);

        comboBoxModifProd = new QComboBox(page_3);
        comboBoxModifProd->setObjectName(QString::fromUtf8("comboBoxModifProd"));

        verticalLayout_8->addWidget(comboBoxModifProd);

        lineEditProdModif = new QLineEdit(page_3);
        lineEditProdModif->setObjectName(QString::fromUtf8("lineEditProdModif"));

        verticalLayout_8->addWidget(lineEditProdModif);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButtonProdDesac = new QPushButton(page_3);
        pushButtonProdDesac->setObjectName(QString::fromUtf8("pushButtonProdDesac"));

        horizontalLayout_12->addWidget(pushButtonProdDesac);


        verticalLayout_8->addLayout(horizontalLayout_12);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_9);


        gridLayout_7->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("Actif"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 512, 381));
        gridLayout_8 = new QGridLayout(page_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        tableViewProdDesact = new QTableView(page_4);
        tableViewProdDesact->setObjectName(QString::fromUtf8("tableViewProdDesact"));
        tableViewProdDesact->setMaximumSize(QSize(16777215, 16777215));
        tableViewProdDesact->setAlternatingRowColors(true);
        tableViewProdDesact->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_11->addWidget(tableViewProdDesact);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        comboBoxProdDesact = new QComboBox(page_4);
        comboBoxProdDesact->setObjectName(QString::fromUtf8("comboBoxProdDesact"));
        comboBoxProdDesact->setMinimumSize(QSize(155, 0));

        verticalLayout_10->addWidget(comboBoxProdDesact);

        pushButtonProdReact = new QPushButton(page_4);
        pushButtonProdReact->setObjectName(QString::fromUtf8("pushButtonProdReact"));

        verticalLayout_10->addWidget(pushButtonProdReact);


        horizontalLayout_11->addLayout(verticalLayout_10);


        gridLayout_8->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        toolBox->addItem(page_4, QString::fromUtf8("Inactif"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 0, 1, 1, 1);

        stackedWidgetApp->addWidget(page_2);

        verticalLayout->addWidget(stackedWidgetApp);


        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);

        NewWorld->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NewWorld);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 25));
        NewWorld->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NewWorld);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        NewWorld->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NewWorld);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        NewWorld->setStatusBar(statusBar);

        retranslateUi(NewWorld);

        stackedWidgetApp->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NewWorld);
    } // setupUi

    void retranslateUi(QMainWindow *NewWorld)
    {
        NewWorld->setWindowTitle(QApplication::translate("NewWorld", "NewWorld", 0));
        label->setText(QApplication::translate("NewWorld", "Back Office New World ", 0));
        pushButtonAnnulConnect->setText(QApplication::translate("NewWorld", "Annuler", 0));
        pushButtonValidConnect->setText(QApplication::translate("NewWorld", "Valider", 0));
        label_2->setText(QApplication::translate("NewWorld", "Login :", 0));
        label_3->setText(QApplication::translate("NewWorld", "Mot de passe :", 0));
        lineEditLogAdmin->setText(QApplication::translate("NewWorld", "Admin", 0));
        label_6->setText(QApplication::translate("NewWorld", "Ordre :", 0));
        pushButtonUp->setText(QApplication::translate("NewWorld", "/\\", 0));
        pushButtonDown->setText(QApplication::translate("NewWorld", "\\/", 0));
        label_7->setText(QApplication::translate("NewWorld", "Nouveau rayon :", 0));
        label_8->setText(QApplication::translate("NewWorld", "D\303\251signation :", 0));
        pushButtonRayValid->setText(QApplication::translate("NewWorld", "Valider", 0));
        label_11->setText(QApplication::translate("NewWorld", "Modification :", 0));
        pushButtonRayModif->setText(QApplication::translate("NewWorld", "Modifier", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NewWorld", "Les Rayons", 0));
        label_5->setText(QApplication::translate("NewWorld", "Nouveau produit :", 0));
        comboBoxNewProd->clear();
        comboBoxNewProd->insertItems(0, QStringList()
         << QApplication::translate("NewWorld", "Choix du rayon", 0)
        );
        label_4->setText(QApplication::translate("NewWorld", "D\303\251signation :", 0));
        pushButtonProdValid->setText(QApplication::translate("NewWorld", "Valider", 0));
        label_10->setText(QApplication::translate("NewWorld", "Modification : ", 0));
        comboBoxModifProd->clear();
        comboBoxModifProd->insertItems(0, QStringList()
         << QApplication::translate("NewWorld", "Choix du rayon", 0)
        );
        pushButtonProdDesac->setText(QApplication::translate("NewWorld", "D\303\251sactiver", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("NewWorld", "Actif", 0));
        pushButtonProdReact->setText(QApplication::translate("NewWorld", "R\303\251-activer", 0));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("NewWorld", "Inactif", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NewWorld", "Les Produits", 0));
    } // retranslateUi

};

namespace Ui {
    class NewWorld: public Ui_NewWorld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORLD_H
