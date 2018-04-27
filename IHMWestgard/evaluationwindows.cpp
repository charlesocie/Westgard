#include "evaluationwindows.h"



void EvaluationWindows::setMeanAndSD()
{
    mean = new QLineEdit;
    QDoubleValidator *validatormean = new QDoubleValidator(this);
    validatormean->setLocale(QLocale::C);
    mean->setValidator( validatormean );
    sd = new QLineEdit;
    QDoubleValidator *validatorsd = new QDoubleValidator(this);
    validatorsd->setLocale(QLocale::C);
    sd->setValidator( validatorsd );
    layout->insertRow(4,"Mean",mean);
    layout->insertRow(5,"Standard deviation",sd);
    if(tableWidget != NULL){
        layout->addWidget(tableWidget);
        layout->addWidget(evaluationButton);
        if(evaluationResult!=NULL){
            layout->addWidget(evaluationResult);
        }
    }
}

void EvaluationWindows::setTargetAndTolerance()
{
    target = new QLineEdit;
    QDoubleValidator *validatortarget = new QDoubleValidator(this);
    validatortarget->setLocale(QLocale::C);
    target->setValidator( validatortarget );
    tolerence = new QLineEdit;
    QDoubleValidator *validatortolerance = new QDoubleValidator(this);
    validatortolerance->setLocale(QLocale::C);
    tolerence->setValidator( validatortolerance );

    layout->insertRow(4,"Target",target);
    layout->insertRow(5,"Tolerence",tolerence);
    if(tableWidget != NULL){
        layout->addWidget(tableWidget);
        layout->addWidget(evaluationButton);
        if(evaluationResult!=NULL){
            layout->addWidget(evaluationResult);
        }
    }
}

void EvaluationWindows::addValueAndDateWidget(int i)
{
    if(value == NULL){
        value = new QLineEdit;
        QDoubleValidator *validatorvalue= new QDoubleValidator(this);
        validatorvalue->setLocale(QLocale::C);
        value->setValidator( validatorvalue );
        date = new QDateTimeEdit(QDateTime::currentDateTime(), this);
        date->setDisplayFormat("dd/MM/yyyy hh:mm:ss");
        validation = new QPushButton("add value");

        QObject::connect(validation, SIGNAL(clicked()), this, SLOT(addValue()));

        layout->addRow("Valeur", value);
        layout->addRow("Date", date);
        layout->addWidget(validation);
    }
    if(layout->rowCount() > 4 && layout->rowCount() != 6 && layout->rowCount() != 7){
        layout->removeRow(4);
        layout->removeRow(4);
    }else if((mean != NULL ||target != NULL) && tableWidget == NULL && layout->rowCount() != 4){
        layout->removeRow(4);
        layout->removeRow(4);
    }
    this->setLayout(layout);
    if(evaluation->currentIndex() == 2){
        setMeanAndSD();
    }
    if(evaluation->currentIndex() == 3){
        setTargetAndTolerance();
    }
}

EvaluationWindows::EvaluationWindows(): QWidget()
{

    layout = new QFormLayout;
    evaluation = new QComboBox;
    evaluation->addItem("","");
    evaluation->addItem("Evaluate Westgard Rules with a list of Measure only", "EvaluateWestgardOnly");
    evaluation->addItem("Evaluate Westgard Rules with a list of Measure, the mean and the standard deviation", "EvaluateWestgardWithMean");
    evaluation->addItem("Evaluate Westgard Rules with a list of Measure, the target and the tolerance", "EvaluateWestgardWithTarget");
    QObject::connect(evaluation, SIGNAL(currentIndexChanged(int)), this, SLOT(addValueAndDateWidget(int)));

    layout->addRow("Evaluation mode",evaluation);
    value = NULL;
    tableWidget = NULL;
    evaluationResult = NULL;

    this->setLayout(layout);

}

void EvaluationWindows::setRow()
{
    QTableWidgetItem* itemValue = new QTableWidgetItem;
    itemValue->setText(value->text());
    tableWidget->setItem(1,0,itemValue);
    tabValue.push_back(itemValue);
    QTableWidgetItem* itemDate = new QTableWidgetItem;
    itemDate->setText(date->text());
    tableWidget->setItem(1,1,itemDate);
    tabDate.push_back(itemDate);
    QPushButton* button = new QPushButton("delete");
    tabButton.push_back(button);
    tableWidget->setCellWidget(1,2,button);
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(deleteValue()));
}

void EvaluationWindows::setTableWidget()
{
    tableWidget = new QTableWidget(2, 3, this);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->hide();
    itemText[0] = new QTableWidgetItem();
    itemText[1] = new QTableWidgetItem();
    itemText[0]->setText("Values");
    itemText[1]->setText("Date");
    tableWidget->setItem(0,0,itemText[0]);
    tableWidget->setItem(0,1,itemText[1]);
    setRow();
    evaluationButton = new QPushButton;
    evaluationButton->setText("Evaluate");
    QObject::connect(evaluationButton, SIGNAL(clicked()), this, SLOT(evaluate()));
}

void EvaluationWindows::addValue(){
    if(tableWidget == NULL){
        setTableWidget();
        layout->addWidget(tableWidget);
        layout->addWidget(evaluationButton);
        this->setLayout(layout);
    }else{
        tableWidget->insertRow(1);
        setRow();
    }
}

void EvaluationWindows::deleteValue(){
    QPushButton *button = (QPushButton *)sender();
    int i = 0 ;
    while(button != tabButton[i]){
        i++;
    }
    tableWidget->removeRow(tabButton.size()-i);
    tabButton.erase(tabButton.begin()+i);
    tabValue.erase(tabValue.begin()+i);
    tabDate.erase(tabDate.begin()+i);
}

tm EvaluationWindows::convertQStringTotm(const std::string dateTime)
{
    int yy, month, dd, hh, mm, ss;
    struct tm whenStart;
    const char *zStart = dateTime.c_str();

    sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
    whenStart.tm_year = yy;
    whenStart.tm_mon = month;
    whenStart.tm_mday = dd;
    whenStart.tm_hour = hh;
    whenStart.tm_min = mm;
    whenStart.tm_sec = ss;
    return whenStart;
}

void EvaluationWindows::evaluate(){
    if(evaluationResult == NULL){
        evaluationResult = new QTextEdit;
        evaluationResult->setEnabled(false);
    }
    list<Measure> listMeasure;
    for(unsigned int i = 0 ; i < tabValue.size(); i++){
        float value = tabValue[i]->text().toFloat();
        QString dateqstring = tabDate[i]->text();
        std::string current_locale_text = dateqstring.toLocal8Bit().constData();
        struct tm tminfo = convertQStringTotm(current_locale_text);
        Measure* m = new Measure(value,tminfo);
        listMeasure.push_back(*m);
    }
    WestgardInterface* wI = WestgardInterface::getInstance();
    WestgardResult wR;
    if(evaluation->currentIndex() == 1){
        wR = wI->WGevaluateWithListOnly(listMeasure);
    }
    else if(evaluation->currentIndex() == 2){
        wR = wI->WGevaluateWithListMeanAnd1SD(listMeasure,mean->text().toFloat(),sd->text().toFloat());
    }
    else if(evaluation->currentIndex() == 3){
        wR = wI->WGevaluateWithListTargetAndTolerance(listMeasure,target->text().toFloat(),tolerence->text().toFloat());
    }
    QString qstr = QString::fromStdString(wR.Tostring());
    evaluationResult->setText(qstr);
    layout->addWidget(evaluationResult);
    this->setLayout(layout);
}

