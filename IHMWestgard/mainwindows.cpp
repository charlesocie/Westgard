#include "mainwindows.h"


MainWindows::MainWindows()
{

    mainWidget = new QWidget;
    tag = new QTabWidget(mainWidget);
    tag->setGeometry(0,0,800,800);

    evaluatePage = new QWidget;
    updatePage = new QWidget;
    configPage = new QWidget;
    getConfigBouton = new QPushButton();
    getConfigBouton->setText("Get XML File Configuration");
    getConfigBouton->setGeometry(600,0,50,50);

    EW = new EvaluationWindows();
    UW = new UpdateWindows();
    CW = new ConfigWindows(getConfigBouton);

    evaluatebox = new QVBoxLayout;
    updatebox = new QVBoxLayout;
    configbox = new QVBoxLayout;

    evaluatebox->addWidget(EW);
    updatebox->addWidget(UW);
    configbox->addWidget(CW);
    configbox->addWidget(getConfigBouton);

    evaluatePage->setLayout(evaluatebox);
    updatePage->setLayout(updatebox);
    configPage->setLayout(configbox);

    tag->addTab(evaluatePage,"Evaluation");
    tag->addTab(updatePage, "Update");
    tag->addTab(configPage, "Get Configuration File");

    setCentralWidget(mainWidget);
}



