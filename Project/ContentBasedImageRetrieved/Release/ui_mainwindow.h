/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editPath;
    QPushButton *btnBrowse;
    QLabel *lblImage;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *editDataPath;
    QPushButton *btnDataBrowse;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *lblImageView;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QListWidget *listWidget;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupTechnique;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioHist;
    QRadioButton *radioTemplate;
    QRadioButton *radioFeature;
    QGroupBox *groupAddition;
    QVBoxLayout *verticalLayout_8;
    QLabel *lblAdditional;
    QPushButton *btnChange;
    QSpacerItem *verticalSpacer;
    QPushButton *btnCompare;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupResult;
    QVBoxLayout *verticalLayout_9;
    QListWidget *listResult;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_10;
    QLabel *lblImageResult;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnBack;
    QPushButton *btnCancel;
    QPushButton *btnNext;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(641, 477);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        editPath = new QLineEdit(page);
        editPath->setObjectName(QString::fromUtf8("editPath"));

        horizontalLayout->addWidget(editPath);

        btnBrowse = new QPushButton(page);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));

        horizontalLayout->addWidget(btnBrowse);


        verticalLayout->addLayout(horizontalLayout);

        lblImage = new QLabel(page);
        lblImage->setObjectName(QString::fromUtf8("lblImage"));
        lblImage->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(lblImage);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_2);

        editDataPath = new QLineEdit(page_2);
        editDataPath->setObjectName(QString::fromUtf8("editDataPath"));

        horizontalLayout_3->addWidget(editDataPath);

        btnDataBrowse = new QPushButton(page_2);
        btnDataBrowse->setObjectName(QString::fromUtf8("btnDataBrowse"));
        sizePolicy.setHeightForWidth(btnDataBrowse->sizePolicy().hasHeightForWidth());
        btnDataBrowse->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(btnDataBrowse);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_4);

        lblImageView = new QLabel(page_2);
        lblImageView->setObjectName(QString::fromUtf8("lblImageView"));
        lblImageView->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(lblImageView);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_5);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_6 = new QHBoxLayout(page_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        groupTechnique = new QGroupBox(page_3);
        groupTechnique->setObjectName(QString::fromUtf8("groupTechnique"));
        sizePolicy.setHeightForWidth(groupTechnique->sizePolicy().hasHeightForWidth());
        groupTechnique->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(groupTechnique);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        radioHist = new QRadioButton(groupTechnique);
        radioHist->setObjectName(QString::fromUtf8("radioHist"));
        sizePolicy.setHeightForWidth(radioHist->sizePolicy().hasHeightForWidth());
        radioHist->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(radioHist);

        radioTemplate = new QRadioButton(groupTechnique);
        radioTemplate->setObjectName(QString::fromUtf8("radioTemplate"));
        sizePolicy.setHeightForWidth(radioTemplate->sizePolicy().hasHeightForWidth());
        radioTemplate->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(radioTemplate);

        radioFeature = new QRadioButton(groupTechnique);
        radioFeature->setObjectName(QString::fromUtf8("radioFeature"));
        sizePolicy.setHeightForWidth(radioFeature->sizePolicy().hasHeightForWidth());
        radioFeature->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(radioFeature);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_11->addWidget(groupTechnique);

        groupAddition = new QGroupBox(page_3);
        groupAddition->setObjectName(QString::fromUtf8("groupAddition"));
        verticalLayout_8 = new QVBoxLayout(groupAddition);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lblAdditional = new QLabel(groupAddition);
        lblAdditional->setObjectName(QString::fromUtf8("lblAdditional"));
        sizePolicy.setHeightForWidth(lblAdditional->sizePolicy().hasHeightForWidth());
        lblAdditional->setSizePolicy(sizePolicy);
        lblAdditional->setAlignment(Qt::AlignCenter);
        lblAdditional->setWordWrap(true);

        verticalLayout_8->addWidget(lblAdditional);

        btnChange = new QPushButton(groupAddition);
        btnChange->setObjectName(QString::fromUtf8("btnChange"));
        sizePolicy.setHeightForWidth(btnChange->sizePolicy().hasHeightForWidth());
        btnChange->setSizePolicy(sizePolicy);
        btnChange->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_8->addWidget(btnChange);


        verticalLayout_11->addWidget(groupAddition);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);

        btnCompare = new QPushButton(page_3);
        btnCompare->setObjectName(QString::fromUtf8("btnCompare"));

        verticalLayout_11->addWidget(btnCompare);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        groupResult = new QGroupBox(page_3);
        groupResult->setObjectName(QString::fromUtf8("groupResult"));
        verticalLayout_9 = new QVBoxLayout(groupResult);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        listResult = new QListWidget(groupResult);
        listResult->setObjectName(QString::fromUtf8("listResult"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listResult->sizePolicy().hasHeightForWidth());
        listResult->setSizePolicy(sizePolicy2);

        verticalLayout_9->addWidget(listResult);


        verticalLayout_12->addWidget(groupResult);

        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_10 = new QVBoxLayout(groupBox);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lblImageResult = new QLabel(groupBox);
        lblImageResult->setObjectName(QString::fromUtf8("lblImageResult"));

        verticalLayout_10->addWidget(lblImageResult);


        verticalLayout_12->addWidget(groupBox);


        horizontalLayout_5->addLayout(verticalLayout_12);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(page_3);

        verticalLayout_5->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnBack = new QPushButton(centralWidget);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        horizontalLayout_2->addWidget(btnBack);

        btnCancel = new QPushButton(centralWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setAutoDefault(true);

        horizontalLayout_2->addWidget(btnNext);


        verticalLayout_5->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 24));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Source:", 0, QApplication::UnicodeUTF8));
        btnBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        lblImage->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Data Folder: ", 0, QApplication::UnicodeUTF8));
        btnDataBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Image View:", 0, QApplication::UnicodeUTF8));
        lblImageView->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "List of Image:", 0, QApplication::UnicodeUTF8));
        groupTechnique->setTitle(QApplication::translate("MainWindow", "Choose Technique:", 0, QApplication::UnicodeUTF8));
        radioHist->setText(QApplication::translate("MainWindow", "Comparing Histogram", 0, QApplication::UnicodeUTF8));
        radioTemplate->setText(QApplication::translate("MainWindow", "Template Matching", 0, QApplication::UnicodeUTF8));
        radioFeature->setText(QApplication::translate("MainWindow", "Feature Matching", 0, QApplication::UnicodeUTF8));
        groupAddition->setTitle(QApplication::translate("MainWindow", "Addition:", 0, QApplication::UnicodeUTF8));
        lblAdditional->setText(QApplication::translate("MainWindow", "Additional element", 0, QApplication::UnicodeUTF8));
        btnChange->setText(QApplication::translate("MainWindow", "Change", 0, QApplication::UnicodeUTF8));
        btnCompare->setText(QApplication::translate("MainWindow", "Compare Image =>", 0, QApplication::UnicodeUTF8));
        groupResult->setTitle(QApplication::translate("MainWindow", "Result:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Image:", 0, QApplication::UnicodeUTF8));
        lblImageResult->setText(QString());
        btnBack->setText(QApplication::translate("MainWindow", "< Back", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("MainWindow", "Next >", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
