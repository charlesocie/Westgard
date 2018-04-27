#include "configwindows.h"


void ConfigWindows::InitQTableWidget()
{
    WestgardInterface* wG = WestgardInterface::getInstance();
    WestgardConfiguration wC = wG->getWestgardConfiguration();
    list<RuleSetting> listRule = wC.getListRules();
    list<RuleSetting>::iterator iteratorList;
    iteratorList = listRule.begin();
    int j = 0;
    for(int i= 0; i<21; i++){
        RuleSetting r = *iteratorList;
        if(i%2 == 0 && i< 10){
            itemText[i] = new QTableWidgetItem();
            itemText[i+1] = new QTableWidgetItem();
            itemText[i]->setText(convertERuleNameToString(r.getName()));
            itemText[i+1]->setText(boolToString(r.getIsActive()));
            tableWidget->setItem(j,0,itemText[i]);
            tableWidget->setItem(j,1,itemText[i+1]);
            j++;
            iteratorList++;
        }else if (i == 10 || i == 13 || i == 16){
            itemText[i] = new QTableWidgetItem();
            itemText[i+1] = new QTableWidgetItem();
            itemText[i+2] = new QTableWidgetItem();
            itemText[i]->setText(convertERuleNameToString(r.getName()));
            itemText[i+1]->setText(boolToString(r.getIsActive()));
            std::string s = std::to_string(r.getValue());
            char const *pchar = s.c_str();
            itemText[i+2]->setText(pchar);
            tableWidget->setItem(j,0,itemText[i]);
            tableWidget->setItem(j,1,itemText[i+1]);
            tableWidget->setItem(j,2,itemText[i+2]);
            j++;
            iteratorList++;
        }else if (i == 19){
            itemText[i] = new QTableWidgetItem();
            itemText[i+1] = new QTableWidgetItem();
            QString text = "EvaluateParameterizableRuleIf1_2sSucceed";
            itemText[i]->setText(text);
            itemText[i+1]->setText(boolToString(wC.getEvaluateParameterizableRuleIf1_2sSucceed()));
            tableWidget->setItem(j,0,itemText[i]);
            tableWidget->setItem(j,1,itemText[i+1]);
        }
    }
    QHeaderView* header = tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::ResizeToContents);
//    for(int i = 0 ; i<9; i++){
//        itemBouton[i] = new QPushButton();
//        itemBouton[i]->setText("Modify");
//        tableWidget->setCellWidget(i,3,itemBouton[i]);
//        QObject::connect(itemBouton[i], SIGNAL(clicked()), this, SLOT(modifyRule()));
//    }
}

ConfigWindows::ConfigWindows(QPushButton* getConfigBouton)
{
    tableWidget = new QTableWidget(9, 3, this);
    tableWidget->setGeometry(150,175,421,272);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->verticalHeader()->hide();
    tableWidget->horizontalHeader()->hide();
    InitQTableWidget();
    QObject::connect(getConfigBouton, SIGNAL(clicked()), this, SLOT(InitQTableWidget()));
}

void ConfigWindows::modifyRule(){
    int i = 0;
    QPushButton *button = (QPushButton *)sender();
    while(button != itemBouton[i]){
        i++;
    }
    if(i< 6){
        tableWidget->editItem(itemText[i*2+1]);
    }
    else if (i == 6){
        tableWidget->editItem(itemText[i*2+2]);
    }    else if (i == 7){
        tableWidget->editItem(itemText[i*2+3]);
    }    else if (i == 8){
        tableWidget->editItem(itemText[i*2+4]);
    }

}

const char* ConfigWindows::convertERuleNameToString(ERulesName Erulename){
    char* name;
    switch(Erulename){
        case RULE_1_2S :
            name = "Rule 1 2S";
        break;
        case RULE_1_3S :
            name = "Rule 1 3S";
        break;
        case RULE_2_2S :
            name = "Rule 2 2S";
        break;
        case RULE_2OF3_2S :
            name = "Rule 2of3 2S";
        break;
        case RULE_R_4S :
            name = "Rule R 4S";
        break;
        case RULE_X_1S :
            name = "Rule X 1S";
        break;
        case RULE_XX :
            name = "Rule Xx";
        break;
        case RULE_XT :
            name = "Rule XT";
        break;
        default :
            break;
        }
    const char *cstr = name;
    return cstr;
}


const char* ConfigWindows::boolToString(const bool b) {
    char * statement;
    if(b == true){
        statement = "true";
    }else{
        statement = "false";
    }
    const char *cstr = statement;
    return cstr;
}
