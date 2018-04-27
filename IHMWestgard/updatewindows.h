#ifndef UPDATEWINDOWS_H
#define UPDATEWINDOWS_H
#ifdef WIN32
#include <windows.h>
#endif
#include <QObject>
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
#include "EUpdateResult.h"
#include <QComboBox>
#include <ERulesName.h>
#include "WestgardInterface.h"

class UpdateWindows : public QWidget
{  
Q_OBJECT
public:
  UpdateWindows();


public slots:
  void update();


private:
  QPushButton *updateButton;
  QComboBox *ruleName;
  QComboBox *statement;
  QLineEdit *value;
  QFormLayout *layout;
  ERulesName eName;

  bool StringToBool(QString string);
  ERulesName StringToERuleName(std::string stringname);
};

#endif // UPDATEWINDOWS_H
