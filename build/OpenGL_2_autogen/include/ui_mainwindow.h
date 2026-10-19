/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mainview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *settingsBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *rotationBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QDial *RotationDialX;
    QDial *RotationDialY;
    QDial *RotationDialZ;
    QPushButton *ResetRotationButton;
    QGroupBox *scalingBox;
    QVBoxLayout *verticalLayout_4;
    QSlider *ScaleSlider;
    QPushButton *ResetScaleButton;
    QGroupBox *shadingBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *NormalButton;
    QRadioButton *PhongButton;
    QRadioButton *GouraudButton;
    MainView *mainView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1048, 569);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        settingsBox = new QGroupBox(centralWidget);
        settingsBox->setObjectName("settingsBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settingsBox->sizePolicy().hasHeightForWidth());
        settingsBox->setSizePolicy(sizePolicy);
        settingsBox->setMinimumSize(QSize(220, 0));
        settingsBox->setMaximumSize(QSize(220, 16777215));
        verticalLayout_3 = new QVBoxLayout(settingsBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        rotationBox = new QGroupBox(settingsBox);
        rotationBox->setObjectName("rotationBox");
        sizePolicy.setHeightForWidth(rotationBox->sizePolicy().hasHeightForWidth());
        rotationBox->setSizePolicy(sizePolicy);
        rotationBox->setMinimumSize(QSize(205, 0));
        rotationBox->setMaximumSize(QSize(205, 16777215));
        verticalLayout = new QVBoxLayout(rotationBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        RotationDialX = new QDial(rotationBox);
        RotationDialX->setObjectName("RotationDialX");
        RotationDialX->setMaximum(359);
        RotationDialX->setWrapping(true);
        RotationDialX->setNotchTarget(12.000000000000000);
        RotationDialX->setNotchesVisible(true);

        horizontalLayout_2->addWidget(RotationDialX);

        RotationDialY = new QDial(rotationBox);
        RotationDialY->setObjectName("RotationDialY");
        RotationDialY->setMaximum(359);
        RotationDialY->setWrapping(true);
        RotationDialY->setNotchTarget(12.000000000000000);
        RotationDialY->setNotchesVisible(true);

        horizontalLayout_2->addWidget(RotationDialY);

        RotationDialZ = new QDial(rotationBox);
        RotationDialZ->setObjectName("RotationDialZ");
        RotationDialZ->setMaximum(359);
        RotationDialZ->setWrapping(true);
        RotationDialZ->setNotchTarget(12.000000000000000);
        RotationDialZ->setNotchesVisible(true);

        horizontalLayout_2->addWidget(RotationDialZ);


        verticalLayout->addLayout(horizontalLayout_2);

        ResetRotationButton = new QPushButton(rotationBox);
        ResetRotationButton->setObjectName("ResetRotationButton");

        verticalLayout->addWidget(ResetRotationButton);


        verticalLayout_3->addWidget(rotationBox);

        scalingBox = new QGroupBox(settingsBox);
        scalingBox->setObjectName("scalingBox");
        sizePolicy.setHeightForWidth(scalingBox->sizePolicy().hasHeightForWidth());
        scalingBox->setSizePolicy(sizePolicy);
        scalingBox->setMinimumSize(QSize(205, 0));
        scalingBox->setMaximumSize(QSize(205, 16777215));
        verticalLayout_4 = new QVBoxLayout(scalingBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        ScaleSlider = new QSlider(scalingBox);
        ScaleSlider->setObjectName("ScaleSlider");
        ScaleSlider->setMinimum(1);
        ScaleSlider->setMaximum(1000);
        ScaleSlider->setValue(100);
        ScaleSlider->setOrientation(Qt::Horizontal);
        ScaleSlider->setInvertedAppearance(false);
        ScaleSlider->setInvertedControls(false);
        ScaleSlider->setTickPosition(QSlider::NoTicks);

        verticalLayout_4->addWidget(ScaleSlider);

        ResetScaleButton = new QPushButton(scalingBox);
        ResetScaleButton->setObjectName("ResetScaleButton");

        verticalLayout_4->addWidget(ResetScaleButton);


        verticalLayout_3->addWidget(scalingBox);

        shadingBox = new QGroupBox(settingsBox);
        shadingBox->setObjectName("shadingBox");
        sizePolicy.setHeightForWidth(shadingBox->sizePolicy().hasHeightForWidth());
        shadingBox->setSizePolicy(sizePolicy);
        shadingBox->setMinimumSize(QSize(205, 0));
        shadingBox->setMaximumSize(QSize(205, 16777215));
        verticalLayout_2 = new QVBoxLayout(shadingBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        NormalButton = new QRadioButton(shadingBox);
        NormalButton->setObjectName("NormalButton");
        NormalButton->setChecked(true);

        verticalLayout_2->addWidget(NormalButton);

        PhongButton = new QRadioButton(shadingBox);
        PhongButton->setObjectName("PhongButton");
        PhongButton->setChecked(false);

        verticalLayout_2->addWidget(PhongButton);

        GouraudButton = new QRadioButton(shadingBox);
        GouraudButton->setObjectName("GouraudButton");

        verticalLayout_2->addWidget(GouraudButton);


        verticalLayout_3->addWidget(shadingBox);


        horizontalLayout->addWidget(settingsBox);

        mainView = new MainView(centralWidget);
        mainView->setObjectName("mainView");

        horizontalLayout->addWidget(mainView);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        settingsBox->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        rotationBox->setTitle(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
#if QT_CONFIG(tooltip)
        RotationDialX->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Rotation along the X-axis</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RotationDialY->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Rotation along the Y-axis</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RotationDialZ->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Rotation along the Z-axis</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ResetRotationButton->setText(QCoreApplication::translate("MainWindow", "Reset Rotation", nullptr));
        scalingBox->setTitle(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        ResetScaleButton->setText(QCoreApplication::translate("MainWindow", "Reset Scaling", nullptr));
        shadingBox->setTitle(QCoreApplication::translate("MainWindow", "Shading", nullptr));
        NormalButton->setText(QCoreApplication::translate("MainWindow", "Nor&mal", nullptr));
        PhongButton->setText(QCoreApplication::translate("MainWindow", "Pho&ng", nullptr));
        GouraudButton->setText(QCoreApplication::translate("MainWindow", "&Gouraud", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
