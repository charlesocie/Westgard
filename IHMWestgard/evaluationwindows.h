#ifndef EVALUATIONWINDOWS_H
#define EVALUATIONWINDOWS_H
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
#include "EUpdateResult.h"
#include "WestgardInterface.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QDateEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QComboBox>

class EvaluationWindows : public QWidget
{
  Q_OBJECT
public:
    EvaluationWindows();

    void setWindows();

    void setTargetAndTolerance();

public slots:
    void addValue();
    void deleteValue();
    void evaluate();
    void addValueAndDateWidget(int i);


private:
    QVBoxLayout *vbox;
    QComboBox* evaluation;
    QTableWidget* tableWidget;
    QPushButton *validation;
    QLineEdit *value;
    QLineEdit *mean;
    QLineEdit *sd;
    QLineEdit *target;
    QLineEdit *tolerence;
    QDateTimeEdit *date;
    QFormLayout *layout;
    QTableWidgetItem *itemText[2];
    std::vector<QTableWidgetItem*> tabValue;
    std::vector<QTableWidgetItem*> tabDate;
    std::vector<QPushButton*> tabButton;
    QPushButton* evaluationButton;
    QTextEdit* evaluationResult;
    void setTableWidget();
    void setRow();
    tm convertQStringTotm(const std::string dateTime);

    void setMeanAndSD();
};

#endif // EVALUATIONWINDOWS_H
