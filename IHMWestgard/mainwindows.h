#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include<QtWidgets>
#include"evaluationwindows.h"
#include"updatewindows.h"
#include"configwindows.h"

class MainWindows : public QMainWindow
{
public:
    MainWindows();

private:
    QVBoxLayout *evaluatebox;
    QVBoxLayout *updatebox;
    QVBoxLayout *configbox;
    QWidget *evaluatePage;
    QWidget *updatePage;
    QWidget *configPage;
    EvaluationWindows* EW;
    UpdateWindows* UW;
    ConfigWindows* CW;
    QWidget *mainWidget;
    QTabWidget *tag;
    QPushButton *getConfigBouton;
};

#endif // MAINWINDOWS_H
