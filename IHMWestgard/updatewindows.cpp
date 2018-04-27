#include "updatewindows.h"


UpdateWindows::UpdateWindows()
{
    ruleName = new QComboBox;
    ruleName->addItem("Rule 1 2S", "RULE_1_2S");
    ruleName->addItem("Rule 1 3S", "RULE_1_3S");
    ruleName->addItem("Rule 2 2S", "RULE_2_2S");
    ruleName->addItem("Rule 2 of 3 2S", "RULE_2OF3_2S");
    ruleName->addItem("Rule R 4S", "RULE_R_4S");
    ruleName->addItem("Rule X 1S", "RULE_X_1S");
    ruleName->addItem("Rule Xx", "RULE_XX");
    ruleName->addItem("Rule XT", "RULE_XT");
    ruleName->addItem("Evaluate Parameterizable Rules If 1_2s Succeed", "EvaluateParameterizableRulesIf1_2sSucceed");
    statement = new QComboBox;
    statement->addItem("True", "true");
    statement->addItem("False", "false");
    value = new QLineEdit;
    value->setValidator( new QIntValidator(0, 50, this) );
    updateButton = new QPushButton("Update Rule");

    QObject::connect(updateButton, SIGNAL(clicked()), this, SLOT(update()));

    layout = new QFormLayout;
    layout->addRow("Rule Name", ruleName);
    layout->addRow("Statement", statement);
    layout->addRow("Value", value);
    layout->addWidget(updateButton);

    this->setLayout(layout);
}

void UpdateWindows::update(){
    WestgardInterface* wG = WestgardInterface::getInstance();
    QString qs =ruleName->currentText();
    bool b = StringToBool(statement->currentText());
    QString str = value->text();
    bool ok;
    int dec = str.toInt(&ok, 10);
    std::string current_locale_text = qs.toLocal8Bit().constData();
    if (current_locale_text == "Evaluate Parameterizable Rules If 1_2s Succeed"){
        wG->updateEvaluateParameterizableRulesIf1_2sSucceed(b);
    }
    else if(current_locale_text == "Rule X 1S" || current_locale_text == "Rule Xx" ||current_locale_text == "Rule XT" ){
        wG->updateWithNameStatementAndValue(StringToERuleName(current_locale_text),b,dec);
    }
    else{
       wG->updateWithNameAndStatement(StringToERuleName(current_locale_text),b);
    }

}

bool UpdateWindows::StringToBool(QString string){
    bool boolFromString;
    if(string == "True"){
        boolFromString = true;
    }
    else{
        boolFromString = false;
    }
    return boolFromString;
}

ERulesName UpdateWindows::StringToERuleName(std::string stringname){
    ERulesName rulename;
    if(stringname == "Rule 1 2S"){
        rulename = RULE_1_2S;
    }
    else if(stringname == "Rule 1 2S"){
        rulename = RULE_1_2S;
    }
    else if(stringname == "Rule 1 3S"){
        rulename = RULE_1_3S;
    }
    else if(stringname == "Rule 2 2S"){
        rulename = RULE_2_2S;
    }
    else if(stringname == "Rule 2 of 3 2S"){
        rulename = RULE_2OF3_2S;
    }
    else if(stringname == "Rule R 4S"){
        rulename = RULE_R_4S;
    }
    else if(stringname == "Rule X 1S"){
        rulename = RULE_X_1S;
    }
    else if(stringname == "Rule Xx"){
        rulename = RULE_XX;
    }
    else if(stringname == "Rule XT"){
        rulename = RULE_XT;
    }
    else{
        rulename = 	FALSE_RULE;
    }
    return rulename;
}
