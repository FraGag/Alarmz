/********************************************************************************
** Form generated from reading UI file 'OptionsDialog.ui'
**
** Created: Wed 28. Jul 20:31:46 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

namespace Alarmz {

class Ui_OptionsDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *languageLabel;
    QComboBox *languageComboBox;
    QCheckBox *autoSaveCheckBox;
    QGroupBox *startupGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *runOnSessionStartupCheckBox;
    QSpacerItem *spacerItem;
    QCheckBox *openThisFileOnStartupCheckBox;
    QSpacerItem *spacerItem1;
    QLineEdit *openThisFileOnStartupLineEdit;
    QToolButton *browseForFileToOpenOnStartupButton;
    QGroupBox *toastsGroupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout1;
    QLabel *colorsLabel;
    QLabel *backgroundLabel;
    QLabel *gradientLabel;
    QLabel *textLabel;
    QSpacerItem *spacerItem2;
    QLabel *toastsLabel;
    QCheckBox *toastBackgroundCheckBox;
    QToolButton *toastBackgroundColor1Button;
    QCheckBox *gradientOnToastBackgroundCheckBox;
    QToolButton *toastBackgroundColor2Button;
    QCheckBox *toastTextCheckBox;
    QToolButton *toastTextColorButton;
    QLabel *snoozeLabel;
    QCheckBox *snoozeButtonBackgroundCheckBox;
    QToolButton *snoozeButtonBackgroundColor1Button;
    QCheckBox *gradientOnSnoozeButtonCheckBox;
    QToolButton *snoozeButtonBackgroundColor2Button;
    QCheckBox *snoozeButtonTextCheckBox;
    QToolButton *snoozeButtonTextColorButton;
    QLabel *closeLabel;
    QCheckBox *closeButtonBackgroundCheckBox;
    QToolButton *closeButtonBackgroundColor1Button;
    QCheckBox *gradientOnCloseButtonCheckBox;
    QToolButton *closeButtonBackgroundColor2Button;
    QCheckBox *closeButtonTextCheckBox;
    QToolButton *closeButtonTextColorButton;
    QCheckBox *useNativeBorderCheckBox;
    QWidget *widget;
    QGridLayout *gridLayout2;
    QLabel *cornerLabel;
    QRadioButton *topLeftCornerRadioButton;
    QRadioButton *topRightCornerRadioButton;
    QSpacerItem *spacerItem3;
    QRadioButton *bottomLeftCornerRadioButton;
    QRadioButton *bottomRightCornerRadioButton;
    QWidget *widget1;
    QHBoxLayout *hboxLayout1;
    QLabel *directionLabel;
    QRadioButton *horizontalDirectionRadioButton;
    QRadioButton *verticalDirectionRadioButton;
    QSpacerItem *spacerItem4;
    QLabel *toastEmergenceLabel;
    QWidget *widget2;
    QHBoxLayout *hboxLayout2;
    QRadioButton *suddenToastEmergenceRadioButton;
    QRadioButton *rollToastEmergenceRadioButton;
    QRadioButton *fadeToastEmergenceRadioButton;
    QSpacerItem *spacerItem5;
    QHBoxLayout *hboxLayout3;
    QCheckBox *playSoundCheckBox;
    QLineEdit *playSoundLineEdit;
    QToolButton *browseForSoundToPlayButton;
    QHBoxLayout *hboxLayout4;
    QLabel *snoozeDurationLabel;
    QSpinBox *snoozeDurationSpinBox;
    QLabel *minutesLabel;
    QSpacerItem *spacerItem6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Alarmz__OptionsDialog)
    {
        if (Alarmz__OptionsDialog->objectName().isEmpty())
            Alarmz__OptionsDialog->setObjectName(QString::fromUtf8("Alarmz__OptionsDialog"));
        Alarmz__OptionsDialog->setSizeIncrement(QSize(8, 8));
        Alarmz__OptionsDialog->setModal(true);
        vboxLayout = new QVBoxLayout(Alarmz__OptionsDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        languageLabel = new QLabel(Alarmz__OptionsDialog);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));

        hboxLayout->addWidget(languageLabel);

        languageComboBox = new QComboBox(Alarmz__OptionsDialog);
        languageComboBox->setObjectName(QString::fromUtf8("languageComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(languageComboBox->sizePolicy().hasHeightForWidth());
        languageComboBox->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(languageComboBox);


        vboxLayout->addLayout(hboxLayout);

        autoSaveCheckBox = new QCheckBox(Alarmz__OptionsDialog);
        autoSaveCheckBox->setObjectName(QString::fromUtf8("autoSaveCheckBox"));

        vboxLayout->addWidget(autoSaveCheckBox);

        startupGroupBox = new QGroupBox(Alarmz__OptionsDialog);
        startupGroupBox->setObjectName(QString::fromUtf8("startupGroupBox"));
        gridLayout = new QGridLayout(startupGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        runOnSessionStartupCheckBox = new QCheckBox(startupGroupBox);
        runOnSessionStartupCheckBox->setObjectName(QString::fromUtf8("runOnSessionStartupCheckBox"));

        gridLayout->addWidget(runOnSessionStartupCheckBox, 0, 0, 1, 4);

        spacerItem = new QSpacerItem(10, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 0, 1, 1);

        openThisFileOnStartupCheckBox = new QCheckBox(startupGroupBox);
        openThisFileOnStartupCheckBox->setObjectName(QString::fromUtf8("openThisFileOnStartupCheckBox"));

        gridLayout->addWidget(openThisFileOnStartupCheckBox, 1, 1, 1, 3);

        spacerItem1 = new QSpacerItem(28, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 2, 0, 1, 3);

        openThisFileOnStartupLineEdit = new QLineEdit(startupGroupBox);
        openThisFileOnStartupLineEdit->setObjectName(QString::fromUtf8("openThisFileOnStartupLineEdit"));
        openThisFileOnStartupLineEdit->setEnabled(false);

        gridLayout->addWidget(openThisFileOnStartupLineEdit, 2, 2, 1, 1);

        browseForFileToOpenOnStartupButton = new QToolButton(startupGroupBox);
        browseForFileToOpenOnStartupButton->setObjectName(QString::fromUtf8("browseForFileToOpenOnStartupButton"));
        browseForFileToOpenOnStartupButton->setEnabled(false);

        gridLayout->addWidget(browseForFileToOpenOnStartupButton, 2, 3, 1, 1);


        vboxLayout->addWidget(startupGroupBox);

        toastsGroupBox = new QGroupBox(Alarmz__OptionsDialog);
        toastsGroupBox->setObjectName(QString::fromUtf8("toastsGroupBox"));
        verticalLayout = new QVBoxLayout(toastsGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        colorsLabel = new QLabel(toastsGroupBox);
        colorsLabel->setObjectName(QString::fromUtf8("colorsLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        colorsLabel->setFont(font);

        gridLayout1->addWidget(colorsLabel, 0, 0, 1, 1);

        backgroundLabel = new QLabel(toastsGroupBox);
        backgroundLabel->setObjectName(QString::fromUtf8("backgroundLabel"));
        backgroundLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(backgroundLabel, 0, 1, 1, 2);

        gradientLabel = new QLabel(toastsGroupBox);
        gradientLabel->setObjectName(QString::fromUtf8("gradientLabel"));
        gradientLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(gradientLabel, 0, 3, 1, 2);

        textLabel = new QLabel(toastsGroupBox);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));
        textLabel->setAlignment(Qt::AlignCenter);

        gridLayout1->addWidget(textLabel, 0, 5, 1, 2);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem2, 0, 7, 4, 1);

        toastsLabel = new QLabel(toastsGroupBox);
        toastsLabel->setObjectName(QString::fromUtf8("toastsLabel"));

        gridLayout1->addWidget(toastsLabel, 1, 0, 1, 1);

        toastBackgroundCheckBox = new QCheckBox(toastsGroupBox);
        toastBackgroundCheckBox->setObjectName(QString::fromUtf8("toastBackgroundCheckBox"));

        gridLayout1->addWidget(toastBackgroundCheckBox, 1, 1, 1, 1);

        toastBackgroundColor1Button = new QToolButton(toastsGroupBox);
        toastBackgroundColor1Button->setObjectName(QString::fromUtf8("toastBackgroundColor1Button"));
        toastBackgroundColor1Button->setEnabled(false);

        gridLayout1->addWidget(toastBackgroundColor1Button, 1, 2, 1, 1);

        gradientOnToastBackgroundCheckBox = new QCheckBox(toastsGroupBox);
        gradientOnToastBackgroundCheckBox->setObjectName(QString::fromUtf8("gradientOnToastBackgroundCheckBox"));

        gridLayout1->addWidget(gradientOnToastBackgroundCheckBox, 1, 3, 1, 1);

        toastBackgroundColor2Button = new QToolButton(toastsGroupBox);
        toastBackgroundColor2Button->setObjectName(QString::fromUtf8("toastBackgroundColor2Button"));
        toastBackgroundColor2Button->setEnabled(false);

        gridLayout1->addWidget(toastBackgroundColor2Button, 1, 4, 1, 1);

        toastTextCheckBox = new QCheckBox(toastsGroupBox);
        toastTextCheckBox->setObjectName(QString::fromUtf8("toastTextCheckBox"));

        gridLayout1->addWidget(toastTextCheckBox, 1, 5, 1, 1);

        toastTextColorButton = new QToolButton(toastsGroupBox);
        toastTextColorButton->setObjectName(QString::fromUtf8("toastTextColorButton"));
        toastTextColorButton->setEnabled(false);

        gridLayout1->addWidget(toastTextColorButton, 1, 6, 1, 1);

        snoozeLabel = new QLabel(toastsGroupBox);
        snoozeLabel->setObjectName(QString::fromUtf8("snoozeLabel"));

        gridLayout1->addWidget(snoozeLabel, 2, 0, 1, 1);

        snoozeButtonBackgroundCheckBox = new QCheckBox(toastsGroupBox);
        snoozeButtonBackgroundCheckBox->setObjectName(QString::fromUtf8("snoozeButtonBackgroundCheckBox"));

        gridLayout1->addWidget(snoozeButtonBackgroundCheckBox, 2, 1, 1, 1);

        snoozeButtonBackgroundColor1Button = new QToolButton(toastsGroupBox);
        snoozeButtonBackgroundColor1Button->setObjectName(QString::fromUtf8("snoozeButtonBackgroundColor1Button"));
        snoozeButtonBackgroundColor1Button->setEnabled(false);

        gridLayout1->addWidget(snoozeButtonBackgroundColor1Button, 2, 2, 1, 1);

        gradientOnSnoozeButtonCheckBox = new QCheckBox(toastsGroupBox);
        gradientOnSnoozeButtonCheckBox->setObjectName(QString::fromUtf8("gradientOnSnoozeButtonCheckBox"));

        gridLayout1->addWidget(gradientOnSnoozeButtonCheckBox, 2, 3, 1, 1);

        snoozeButtonBackgroundColor2Button = new QToolButton(toastsGroupBox);
        snoozeButtonBackgroundColor2Button->setObjectName(QString::fromUtf8("snoozeButtonBackgroundColor2Button"));
        snoozeButtonBackgroundColor2Button->setEnabled(false);

        gridLayout1->addWidget(snoozeButtonBackgroundColor2Button, 2, 4, 1, 1);

        snoozeButtonTextCheckBox = new QCheckBox(toastsGroupBox);
        snoozeButtonTextCheckBox->setObjectName(QString::fromUtf8("snoozeButtonTextCheckBox"));

        gridLayout1->addWidget(snoozeButtonTextCheckBox, 2, 5, 1, 1);

        snoozeButtonTextColorButton = new QToolButton(toastsGroupBox);
        snoozeButtonTextColorButton->setObjectName(QString::fromUtf8("snoozeButtonTextColorButton"));
        snoozeButtonTextColorButton->setEnabled(false);

        gridLayout1->addWidget(snoozeButtonTextColorButton, 2, 6, 1, 1);

        closeLabel = new QLabel(toastsGroupBox);
        closeLabel->setObjectName(QString::fromUtf8("closeLabel"));

        gridLayout1->addWidget(closeLabel, 3, 0, 1, 1);

        closeButtonBackgroundCheckBox = new QCheckBox(toastsGroupBox);
        closeButtonBackgroundCheckBox->setObjectName(QString::fromUtf8("closeButtonBackgroundCheckBox"));

        gridLayout1->addWidget(closeButtonBackgroundCheckBox, 3, 1, 1, 1);

        closeButtonBackgroundColor1Button = new QToolButton(toastsGroupBox);
        closeButtonBackgroundColor1Button->setObjectName(QString::fromUtf8("closeButtonBackgroundColor1Button"));
        closeButtonBackgroundColor1Button->setEnabled(false);

        gridLayout1->addWidget(closeButtonBackgroundColor1Button, 3, 2, 1, 1);

        gradientOnCloseButtonCheckBox = new QCheckBox(toastsGroupBox);
        gradientOnCloseButtonCheckBox->setObjectName(QString::fromUtf8("gradientOnCloseButtonCheckBox"));

        gridLayout1->addWidget(gradientOnCloseButtonCheckBox, 3, 3, 1, 1);

        closeButtonBackgroundColor2Button = new QToolButton(toastsGroupBox);
        closeButtonBackgroundColor2Button->setObjectName(QString::fromUtf8("closeButtonBackgroundColor2Button"));
        closeButtonBackgroundColor2Button->setEnabled(false);

        gridLayout1->addWidget(closeButtonBackgroundColor2Button, 3, 4, 1, 1);

        closeButtonTextCheckBox = new QCheckBox(toastsGroupBox);
        closeButtonTextCheckBox->setObjectName(QString::fromUtf8("closeButtonTextCheckBox"));

        gridLayout1->addWidget(closeButtonTextCheckBox, 3, 5, 1, 1);

        closeButtonTextColorButton = new QToolButton(toastsGroupBox);
        closeButtonTextColorButton->setObjectName(QString::fromUtf8("closeButtonTextColorButton"));
        closeButtonTextColorButton->setEnabled(false);

        gridLayout1->addWidget(closeButtonTextColorButton, 3, 6, 1, 1);


        verticalLayout->addLayout(gridLayout1);

        useNativeBorderCheckBox = new QCheckBox(toastsGroupBox);
        useNativeBorderCheckBox->setObjectName(QString::fromUtf8("useNativeBorderCheckBox"));

        verticalLayout->addWidget(useNativeBorderCheckBox);

        widget = new QWidget(toastsGroupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout2 = new QGridLayout(widget);
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        cornerLabel = new QLabel(widget);
        cornerLabel->setObjectName(QString::fromUtf8("cornerLabel"));

        gridLayout2->addWidget(cornerLabel, 0, 0, 2, 1);

        topLeftCornerRadioButton = new QRadioButton(widget);
        topLeftCornerRadioButton->setObjectName(QString::fromUtf8("topLeftCornerRadioButton"));

        gridLayout2->addWidget(topLeftCornerRadioButton, 0, 1, 1, 1);

        topRightCornerRadioButton = new QRadioButton(widget);
        topRightCornerRadioButton->setObjectName(QString::fromUtf8("topRightCornerRadioButton"));

        gridLayout2->addWidget(topRightCornerRadioButton, 0, 2, 1, 1);

        spacerItem3 = new QSpacerItem(40, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem3, 0, 3, 2, 1);

        bottomLeftCornerRadioButton = new QRadioButton(widget);
        bottomLeftCornerRadioButton->setObjectName(QString::fromUtf8("bottomLeftCornerRadioButton"));

        gridLayout2->addWidget(bottomLeftCornerRadioButton, 1, 1, 1, 1);

        bottomRightCornerRadioButton = new QRadioButton(widget);
        bottomRightCornerRadioButton->setObjectName(QString::fromUtf8("bottomRightCornerRadioButton"));
        bottomRightCornerRadioButton->setChecked(true);

        gridLayout2->addWidget(bottomRightCornerRadioButton, 1, 2, 1, 1);


        verticalLayout->addWidget(widget);

        widget1 = new QWidget(toastsGroupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        hboxLayout1 = new QHBoxLayout(widget1);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        directionLabel = new QLabel(widget1);
        directionLabel->setObjectName(QString::fromUtf8("directionLabel"));

        hboxLayout1->addWidget(directionLabel);

        horizontalDirectionRadioButton = new QRadioButton(widget1);
        horizontalDirectionRadioButton->setObjectName(QString::fromUtf8("horizontalDirectionRadioButton"));

        hboxLayout1->addWidget(horizontalDirectionRadioButton);

        verticalDirectionRadioButton = new QRadioButton(widget1);
        verticalDirectionRadioButton->setObjectName(QString::fromUtf8("verticalDirectionRadioButton"));
        verticalDirectionRadioButton->setChecked(true);

        hboxLayout1->addWidget(verticalDirectionRadioButton);

        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem4);


        verticalLayout->addWidget(widget1);

        toastEmergenceLabel = new QLabel(toastsGroupBox);
        toastEmergenceLabel->setObjectName(QString::fromUtf8("toastEmergenceLabel"));

        verticalLayout->addWidget(toastEmergenceLabel);

        widget2 = new QWidget(toastsGroupBox);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        hboxLayout2 = new QHBoxLayout(widget2);
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        suddenToastEmergenceRadioButton = new QRadioButton(widget2);
        suddenToastEmergenceRadioButton->setObjectName(QString::fromUtf8("suddenToastEmergenceRadioButton"));
        suddenToastEmergenceRadioButton->setChecked(false);

        hboxLayout2->addWidget(suddenToastEmergenceRadioButton);

        rollToastEmergenceRadioButton = new QRadioButton(widget2);
        rollToastEmergenceRadioButton->setObjectName(QString::fromUtf8("rollToastEmergenceRadioButton"));
        rollToastEmergenceRadioButton->setChecked(true);

        hboxLayout2->addWidget(rollToastEmergenceRadioButton);

        fadeToastEmergenceRadioButton = new QRadioButton(widget2);
        fadeToastEmergenceRadioButton->setObjectName(QString::fromUtf8("fadeToastEmergenceRadioButton"));

        hboxLayout2->addWidget(fadeToastEmergenceRadioButton);

        spacerItem5 = new QSpacerItem(84, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);


        verticalLayout->addWidget(widget2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        playSoundCheckBox = new QCheckBox(toastsGroupBox);
        playSoundCheckBox->setObjectName(QString::fromUtf8("playSoundCheckBox"));

        hboxLayout3->addWidget(playSoundCheckBox);

        playSoundLineEdit = new QLineEdit(toastsGroupBox);
        playSoundLineEdit->setObjectName(QString::fromUtf8("playSoundLineEdit"));

        hboxLayout3->addWidget(playSoundLineEdit);

        browseForSoundToPlayButton = new QToolButton(toastsGroupBox);
        browseForSoundToPlayButton->setObjectName(QString::fromUtf8("browseForSoundToPlayButton"));

        hboxLayout3->addWidget(browseForSoundToPlayButton);


        verticalLayout->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        snoozeDurationLabel = new QLabel(toastsGroupBox);
        snoozeDurationLabel->setObjectName(QString::fromUtf8("snoozeDurationLabel"));

        hboxLayout4->addWidget(snoozeDurationLabel);

        snoozeDurationSpinBox = new QSpinBox(toastsGroupBox);
        snoozeDurationSpinBox->setObjectName(QString::fromUtf8("snoozeDurationSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(snoozeDurationSpinBox->sizePolicy().hasHeightForWidth());
        snoozeDurationSpinBox->setSizePolicy(sizePolicy1);
        snoozeDurationSpinBox->setMaximum(1440);

        hboxLayout4->addWidget(snoozeDurationSpinBox);

        minutesLabel = new QLabel(toastsGroupBox);
        minutesLabel->setObjectName(QString::fromUtf8("minutesLabel"));

        hboxLayout4->addWidget(minutesLabel);


        verticalLayout->addLayout(hboxLayout4);


        vboxLayout->addWidget(toastsGroupBox);

        spacerItem6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem6);

        buttonBox = new QDialogButtonBox(Alarmz__OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        languageLabel->setBuddy(languageComboBox);
        cornerLabel->setBuddy(topLeftCornerRadioButton);
        snoozeDurationLabel->setBuddy(snoozeDurationSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(languageComboBox, autoSaveCheckBox);
        QWidget::setTabOrder(autoSaveCheckBox, runOnSessionStartupCheckBox);
        QWidget::setTabOrder(runOnSessionStartupCheckBox, openThisFileOnStartupCheckBox);
        QWidget::setTabOrder(openThisFileOnStartupCheckBox, openThisFileOnStartupLineEdit);
        QWidget::setTabOrder(openThisFileOnStartupLineEdit, browseForFileToOpenOnStartupButton);
        QWidget::setTabOrder(browseForFileToOpenOnStartupButton, toastBackgroundCheckBox);
        QWidget::setTabOrder(toastBackgroundCheckBox, toastBackgroundColor1Button);
        QWidget::setTabOrder(toastBackgroundColor1Button, gradientOnToastBackgroundCheckBox);
        QWidget::setTabOrder(gradientOnToastBackgroundCheckBox, toastBackgroundColor2Button);
        QWidget::setTabOrder(toastBackgroundColor2Button, toastTextCheckBox);
        QWidget::setTabOrder(toastTextCheckBox, toastTextColorButton);
        QWidget::setTabOrder(toastTextColorButton, snoozeButtonBackgroundCheckBox);
        QWidget::setTabOrder(snoozeButtonBackgroundCheckBox, snoozeButtonBackgroundColor1Button);
        QWidget::setTabOrder(snoozeButtonBackgroundColor1Button, gradientOnSnoozeButtonCheckBox);
        QWidget::setTabOrder(gradientOnSnoozeButtonCheckBox, snoozeButtonBackgroundColor2Button);
        QWidget::setTabOrder(snoozeButtonBackgroundColor2Button, snoozeButtonTextCheckBox);
        QWidget::setTabOrder(snoozeButtonTextCheckBox, snoozeButtonTextColorButton);
        QWidget::setTabOrder(snoozeButtonTextColorButton, closeButtonBackgroundCheckBox);
        QWidget::setTabOrder(closeButtonBackgroundCheckBox, closeButtonBackgroundColor1Button);
        QWidget::setTabOrder(closeButtonBackgroundColor1Button, gradientOnCloseButtonCheckBox);
        QWidget::setTabOrder(gradientOnCloseButtonCheckBox, closeButtonBackgroundColor2Button);
        QWidget::setTabOrder(closeButtonBackgroundColor2Button, closeButtonTextCheckBox);
        QWidget::setTabOrder(closeButtonTextCheckBox, closeButtonTextColorButton);
        QWidget::setTabOrder(closeButtonTextColorButton, useNativeBorderCheckBox);
        QWidget::setTabOrder(useNativeBorderCheckBox, topLeftCornerRadioButton);
        QWidget::setTabOrder(topLeftCornerRadioButton, topRightCornerRadioButton);
        QWidget::setTabOrder(topRightCornerRadioButton, bottomLeftCornerRadioButton);
        QWidget::setTabOrder(bottomLeftCornerRadioButton, bottomRightCornerRadioButton);
        QWidget::setTabOrder(bottomRightCornerRadioButton, horizontalDirectionRadioButton);
        QWidget::setTabOrder(horizontalDirectionRadioButton, verticalDirectionRadioButton);
        QWidget::setTabOrder(verticalDirectionRadioButton, suddenToastEmergenceRadioButton);
        QWidget::setTabOrder(suddenToastEmergenceRadioButton, rollToastEmergenceRadioButton);
        QWidget::setTabOrder(rollToastEmergenceRadioButton, fadeToastEmergenceRadioButton);
        QWidget::setTabOrder(fadeToastEmergenceRadioButton, playSoundCheckBox);
        QWidget::setTabOrder(playSoundCheckBox, playSoundLineEdit);
        QWidget::setTabOrder(playSoundLineEdit, browseForSoundToPlayButton);
        QWidget::setTabOrder(browseForSoundToPlayButton, snoozeDurationSpinBox);
        QWidget::setTabOrder(snoozeDurationSpinBox, buttonBox);

        retranslateUi(Alarmz__OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Alarmz__OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Alarmz__OptionsDialog, SLOT(reject()));
        QObject::connect(gradientOnToastBackgroundCheckBox, SIGNAL(toggled(bool)), toastBackgroundColor2Button, SLOT(setEnabled(bool)));
        QObject::connect(gradientOnSnoozeButtonCheckBox, SIGNAL(toggled(bool)), snoozeButtonBackgroundColor2Button, SLOT(setEnabled(bool)));
        QObject::connect(openThisFileOnStartupCheckBox, SIGNAL(toggled(bool)), openThisFileOnStartupLineEdit, SLOT(setEnabled(bool)));
        QObject::connect(openThisFileOnStartupCheckBox, SIGNAL(toggled(bool)), browseForFileToOpenOnStartupButton, SLOT(setEnabled(bool)));
        QObject::connect(gradientOnCloseButtonCheckBox, SIGNAL(toggled(bool)), closeButtonBackgroundColor2Button, SLOT(setEnabled(bool)));
        QObject::connect(toastBackgroundCheckBox, SIGNAL(toggled(bool)), toastBackgroundColor1Button, SLOT(setEnabled(bool)));
        QObject::connect(snoozeButtonBackgroundCheckBox, SIGNAL(toggled(bool)), snoozeButtonBackgroundColor1Button, SLOT(setEnabled(bool)));
        QObject::connect(closeButtonBackgroundCheckBox, SIGNAL(toggled(bool)), closeButtonBackgroundColor1Button, SLOT(setEnabled(bool)));
        QObject::connect(toastTextCheckBox, SIGNAL(toggled(bool)), toastTextColorButton, SLOT(setEnabled(bool)));
        QObject::connect(snoozeButtonTextCheckBox, SIGNAL(toggled(bool)), snoozeButtonTextColorButton, SLOT(setEnabled(bool)));
        QObject::connect(closeButtonTextCheckBox, SIGNAL(toggled(bool)), closeButtonTextColorButton, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Alarmz__OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *Alarmz__OptionsDialog)
    {
        Alarmz__OptionsDialog->setWindowTitle(QApplication::translate("Alarmz::OptionsDialog", "Options", 0, QApplication::UnicodeUTF8));
        languageLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "&Language:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        languageComboBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Lets you choose the language of Alarmz's user interface.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        autoSaveCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, alarms files are automatically saved when another file is opened or when the application exits.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        autoSaveCheckBox->setText(QApplication::translate("Alarmz::OptionsDialog", "&Auto save", 0, QApplication::UnicodeUTF8));
        startupGroupBox->setTitle(QApplication::translate("Alarmz::OptionsDialog", "Startup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        runOnSessionStartupCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Check this to run Alarmz when you log in to your computer.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        runOnSessionStartupCheckBox->setText(QApplication::translate("Alarmz::OptionsDialog", "Run on &session startup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        openThisFileOnStartupCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Check this to open the specified file when Alarmz is run on session startup.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        openThisFileOnStartupCheckBox->setText(QApplication::translate("Alarmz::OptionsDialog", "&Open this file on startup:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        openThisFileOnStartupLineEdit->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Type the name of the alarms file to load on session startup, or click the <b>...</b> button to browse for the file on your file system.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        browseForFileToOpenOnStartupButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Browse for an alarms file on your file system to load on session startup.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        browseForFileToOpenOnStartupButton->setText(QApplication::translate("Alarmz::OptionsDialog", "...", 0, QApplication::UnicodeUTF8));
        toastsGroupBox->setTitle(QApplication::translate("Alarmz::OptionsDialog", "Toasts", 0, QApplication::UnicodeUTF8));
        colorsLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Colors", 0, QApplication::UnicodeUTF8));
        backgroundLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Background", 0, QApplication::UnicodeUTF8));
        gradientLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Gradient", 0, QApplication::UnicodeUTF8));
        textLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Text", 0, QApplication::UnicodeUTF8));
        toastsLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Toasts", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        toastBackgroundCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws either a solid background with the first background color or a linear gradient from the first background color to the second background color on every toast's background. When unchecked, the system's default background color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toastBackgroundCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        toastBackgroundColor1Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "First background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toastBackgroundColor1Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "First background color for toasts.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toastBackgroundColor1Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        gradientOnToastBackgroundCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws a linear gradient from the first background color to the second background color on every toast's background. When unchecked, draws a solid background with the first background color on every toast.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        gradientOnToastBackgroundCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        toastBackgroundColor2Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Second background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toastBackgroundColor2Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Second background color for toasts.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toastBackgroundColor2Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        toastTextCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, uses the specified text color for the message in toasts. When unchecked, the system's default text color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toastTextCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        toastTextColorButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Text color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toastTextColorButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Color of the message in toasts.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        toastTextColorButton->setText(QString());
        snoozeLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Snooze button", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        snoozeButtonBackgroundCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws either a solid background with the first background color or a linear gradient from the first background color to the second background color on Snooze buttons. When unchecked, the system's theme or default background color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        snoozeButtonBackgroundCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        snoozeButtonBackgroundColor1Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "First background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        snoozeButtonBackgroundColor1Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "First background color for the Snooze button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        snoozeButtonBackgroundColor1Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        gradientOnSnoozeButtonCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws a linear gradient from the first background color to the second background color on Snooze buttons. When unchecked, draws a solid background with the first background color on Snooze buttons.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        gradientOnSnoozeButtonCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        snoozeButtonBackgroundColor2Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Second background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        snoozeButtonBackgroundColor2Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Second background color for the Snooze button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        snoozeButtonBackgroundColor2Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        snoozeButtonTextCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, uses the specified text color for Snooze buttons. When unchecked, the system's default text color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        snoozeButtonTextCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        snoozeButtonTextColorButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Text color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        snoozeButtonTextColorButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Text color for the Snooze button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        snoozeButtonTextColorButton->setText(QString());
        closeLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Close button", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        closeButtonBackgroundCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws either a solid background with the first background color or a linear gradient from the first background color to the second background color on Close buttons. When unchecked, the system's theme or default background color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        closeButtonBackgroundCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeButtonBackgroundColor1Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "First background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        closeButtonBackgroundColor1Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "First background color for the Close button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        closeButtonBackgroundColor1Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        gradientOnCloseButtonCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, draws a linear gradient from the first background color to the second background color on Close buttons. When unchecked, draws a solid background with the first background color on Close buttons.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        gradientOnCloseButtonCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeButtonBackgroundColor2Button->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Second background color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        closeButtonBackgroundColor2Button->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Second background color for the Close button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        closeButtonBackgroundColor2Button->setText(QString());
#ifndef QT_NO_WHATSTHIS
        closeButtonTextCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, uses the specified text color for Close buttons. When unchecked, the system's default text color is used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        closeButtonTextCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeButtonTextColorButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Text color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        closeButtonTextColorButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Text color for the Close button.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        closeButtonTextColorButton->setText(QString());
#ifndef QT_NO_WHATSTHIS
        useNativeBorderCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "When checked, uses the native frame border from the windowing system. When unchecked, removes the native frame from the windowing system and draws an outset border.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        useNativeBorderCheckBox->setText(QApplication::translate("Alarmz::OptionsDialog", "Use &native border", 0, QApplication::UnicodeUTF8));
        cornerLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "&Corner:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        topLeftCornerRadioButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Top-left corner", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        topLeftCornerRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Position the first toast in the top-left corner.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        topLeftCornerRadioButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        topRightCornerRadioButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Top-right corner", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        topRightCornerRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Position the first toast in the top-right corner.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        topRightCornerRadioButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        bottomLeftCornerRadioButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Bottom-left corner", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        bottomLeftCornerRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Position the first toast in the bottom-left corner.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        bottomLeftCornerRadioButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        bottomRightCornerRadioButton->setToolTip(QApplication::translate("Alarmz::OptionsDialog", "Bottom-right corner", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        bottomRightCornerRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Position the first toast in the bottom-right corner.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        bottomRightCornerRadioButton->setText(QString());
        directionLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Direction:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        horizontalDirectionRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Stack toasts horizontally (left to right/right to left)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        horizontalDirectionRadioButton->setText(QApplication::translate("Alarmz::OptionsDialog", "&Horizontal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        verticalDirectionRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Stack toasts vertically (top-down/bottom-up)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        verticalDirectionRadioButton->setText(QApplication::translate("Alarmz::OptionsDialog", "&Vertical", 0, QApplication::UnicodeUTF8));
        toastEmergenceLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Toast emergence:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        suddenToastEmergenceRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Toasts appear without any animation.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        suddenToastEmergenceRadioButton->setText(QApplication::translate("Alarmz::OptionsDialog", "S&udden", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        rollToastEmergenceRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Toasts appear at minimum size and expand horizontally or vertically (depending on the direction set above).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        rollToastEmergenceRadioButton->setText(QApplication::translate("Alarmz::OptionsDialog", "&Roll", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        fadeToastEmergenceRadioButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Toasts fade in from completely transparent to completely opaque.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        fadeToastEmergenceRadioButton->setText(QApplication::translate("Alarmz::OptionsDialog", "&Fade", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        playSoundCheckBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Check this to play a sound when a toast appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        playSoundCheckBox->setText(QApplication::translate("Alarmz::OptionsDialog", "&Play sound:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        playSoundLineEdit->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Type the name of the sound to play when a toast appears, or click the <b>...</b> button to browse for the file on your file system.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        browseForSoundToPlayButton->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "Browse for a sound file on your file system to play when a toast appears.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        browseForSoundToPlayButton->setText(QApplication::translate("Alarmz::OptionsDialog", "...", 0, QApplication::UnicodeUTF8));
        snoozeDurationLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "Snooze &duration:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        snoozeDurationSpinBox->setWhatsThis(QApplication::translate("Alarmz::OptionsDialog", "The number of minutes before which a toast reappears since the moment the Snooze button was clicked.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        minutesLabel->setText(QApplication::translate("Alarmz::OptionsDialog", "minutes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

} // namespace Alarmz

namespace Alarmz {
namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui
} // namespace Alarmz

#endif // UI_OPTIONSDIALOG_H
