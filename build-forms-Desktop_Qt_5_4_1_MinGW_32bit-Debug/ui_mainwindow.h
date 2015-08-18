/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkBox_aerodrom;
    QCheckBox *checkBox_naselenniyPunkt;
    QCheckBox *checkBox_voinskayaChast;
    QLabel *label_2;
    QCheckBox *checkBox_zima;
    QCheckBox *checkBox_leto;
    QLabel *label_3;
    QCheckBox *checkBox_planoviy;
    QCheckBox *checkBox_perspektivniy;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_sendZapros;
    QTextEdit *textEdit_info;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1044, 587);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 211, 375));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        checkBox_aerodrom = new QCheckBox(verticalLayoutWidget);
        checkBox_aerodrom->setObjectName(QStringLiteral("checkBox_aerodrom"));

        verticalLayout->addWidget(checkBox_aerodrom);

        checkBox_naselenniyPunkt = new QCheckBox(verticalLayoutWidget);
        checkBox_naselenniyPunkt->setObjectName(QStringLiteral("checkBox_naselenniyPunkt"));

        verticalLayout->addWidget(checkBox_naselenniyPunkt);

        checkBox_voinskayaChast = new QCheckBox(verticalLayoutWidget);
        checkBox_voinskayaChast->setObjectName(QStringLiteral("checkBox_voinskayaChast"));

        verticalLayout->addWidget(checkBox_voinskayaChast);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        checkBox_zima = new QCheckBox(verticalLayoutWidget);
        checkBox_zima->setObjectName(QStringLiteral("checkBox_zima"));

        verticalLayout->addWidget(checkBox_zima);

        checkBox_leto = new QCheckBox(verticalLayoutWidget);
        checkBox_leto->setObjectName(QStringLiteral("checkBox_leto"));

        verticalLayout->addWidget(checkBox_leto);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        checkBox_planoviy = new QCheckBox(verticalLayoutWidget);
        checkBox_planoviy->setObjectName(QStringLiteral("checkBox_planoviy"));

        verticalLayout->addWidget(checkBox_planoviy);

        checkBox_perspektivniy = new QCheckBox(verticalLayoutWidget);
        checkBox_perspektivniy->setObjectName(QStringLiteral("checkBox_perspektivniy"));

        verticalLayout->addWidget(checkBox_perspektivniy);

        pushButton_connect = new QPushButton(verticalLayoutWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setEnabled(true);

        verticalLayout->addWidget(pushButton_connect);

        pushButton_sendZapros = new QPushButton(verticalLayoutWidget);
        pushButton_sendZapros->setObjectName(QStringLiteral("pushButton_sendZapros"));

        verticalLayout->addWidget(pushButton_sendZapros);

        textEdit_info = new QTextEdit(verticalLayoutWidget);
        textEdit_info->setObjectName(QStringLiteral("textEdit_info"));

        verticalLayout->addWidget(textEdit_info);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(240, 30, 791, 531));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1044, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\272\320\260\321\200\321\202\321\203", 0));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276 \320\276\320\261\321\212\320\265\320\272\321\202\320\260\320\274 \321\201\321\212\320\265\320\274\320\272\320\270:", 0));
        checkBox_aerodrom->setText(QApplication::translate("MainWindow", "\320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274", 0));
        checkBox_naselenniyPunkt->setText(QApplication::translate("MainWindow", "\320\275\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", 0));
        checkBox_voinskayaChast->setText(QApplication::translate("MainWindow", "\320\262\320\276\320\270\320\275\321\201\320\272\320\260\321\217 \321\207\320\260\321\201\321\202\321\214", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\267\320\276\320\275\320\275\320\276\321\201\321\202\321\214:", 0));
        checkBox_zima->setText(QApplication::translate("MainWindow", "\320\267\320\270\320\274\320\260", 0));
        checkBox_leto->setText(QApplication::translate("MainWindow", "\320\273\320\265\321\202\320\276", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \321\201\321\212\320\265\320\274\320\272\320\270:", 0));
        checkBox_planoviy->setText(QApplication::translate("MainWindow", "\320\277\320\273\320\260\320\275\320\276\320\262\321\213\320\271", 0));
        checkBox_perspektivniy->setText(QApplication::translate("MainWindow", "\320\277\320\265\321\200\321\201\320\277\320\265\320\272\321\202\320\270\320\262\320\275\321\213\320\271", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217", 0));
        pushButton_sendZapros->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\321\200\320\276\321\201", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
