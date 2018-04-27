#ifndef CONFIGWINDOWS_H
#define CONFIGWINDOWS_H

#ifdef WIN32
#include <windows.h>
#endif
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include<iostream>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <QLibrary>
#include <QTableWidget>
#include <QHeaderView>
#include <string>
#include "WestgardInterface.h"
#include <QComboBox>


class ConfigWindows : public QWidget
{
Q_OBJECT
public:
    ConfigWindows(QPushButton* getConfigBouton);


public slots:
    void modifyRule();
    void InitQTableWidget();

private:

    QTableWidget* tableWidget;
    QTableWidgetItem* itemText[21];
    QPushButton *itemBouton[9];
    QComboBox *statement;

    void setQtableWidgetItem(int i, RuleSetting r, list<RuleSetting>::iterator iteratorList, int j);
    const char* convertERuleNameToString(ERulesName Erulename);
    const char* boolToString(const bool b);

    void setQTableWidgetItem(int j, int i, RuleSetting r);
};

#endif // CONFIGWINDOWS_H
