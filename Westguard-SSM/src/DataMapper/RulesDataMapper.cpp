/*
 * RulesDataMapper.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */



#include "RulesDataMapper.h"



/** @class RulesDataMapper
 * @details class allow to write and read the Rule's statement and value on a XML file
 */

/**
 * @details Constructor
 */
RulesDataMapper::RulesDataMapper(){
    // TODO Auto-generated constructor stub

}

/**
 * @details Destructor
 */
RulesDataMapper::~RulesDataMapper() {
    // TODO Auto-generated destructor stub
}

/**
 * @details Update a Rule's statement with it name
 * @param ruleName rule's name
 * @param statement rule's statement
 * @return a boolean depending of the result of the update
 */
EUpdateResult RulesDataMapper::updateWithNameAndStatement(const ERulesName ruleName, const bool statement){
    lock.lock();
	CMarkup xmlFile;
	EUpdateResult updateResult = FAILED_FILE_MISSING;
	if(xmlFile.Load(gs_fileLocation)){
	xmlFile.FindElem();
	xmlFile.IntoElem();
	xmlFile.FindElem( "rule" );
	string stringname = xmlFile.GetAttrib("name");
	int i = 0;
	while (convertStringToERulesName(stringname) != ruleName && i<9 && updateResult != FAILED_FILE_CORRUPT) {
		if(stringname == ""){
			updateResult = FAILED_FILE_CORRUPT;
		}
		i++;
		xmlFile.FindElem("rule");
		stringname = xmlFile.GetAttrib("name");
	}
	if(updateResult != FAILED_FILE_CORRUPT){
		if (convertStringToERulesName(stringname) == ruleName) {
			xmlFile.IntoElem();
			if (xmlFile.FindElem("statement")) {
				xmlFile.SetData(boolToString(statement));
				if((ruleName == RULE_2_2S || ruleName == RULE_2OF3_2S) && statement == true ){
					if(updateRule2_2sAnd2of3_2s(ruleName,&xmlFile) == false){
						updateResult = FAILED_FILE_CORRUPT;
					}
				}
				xmlFile.Save(gs_fileLocation);
			} else{
				updateResult = FAILED_FILE_CORRUPT;
			}
			if (updateResult == FAILED_FILE_MISSING){
			updateResult = UPDATE_OK;
			}
		}
		else{
			updateResult = FAILED_RULE_MISSING;
		}
		}
	}
    lock.unlock();
	return updateResult;
}

/**
 * @details Update a Rule's statement for rule_2_2s and 2of3_2s put the opposite rule call to disable
 * @param ruleName rule's name(2_2s or 2of3_2s)
 * @return a boolean to indicate if the update succeed or not
 */
bool RulesDataMapper::updateRule2_2sAnd2of3_2s(ERulesName ruleName, CMarkup *xmlFile){
	bool result =  true;
	if(ruleName == RULE_2_2S){
		ruleName = RULE_2OF3_2S;
	}else{
		ruleName = RULE_2_2S;
	}
	xmlFile->ResetPos();
	xmlFile->FindElem();
	xmlFile->IntoElem();
	xmlFile->FindElem( "rule" );
	string stringname = xmlFile->GetAttrib("name");
	int i = 0;
	while (convertStringToERulesName(stringname) != ruleName && i<9) {
		if(stringname == ""){
			result = false;
		}
		i++;
		xmlFile->FindElem("rule");
		stringname = xmlFile->GetAttrib("name");
	}
	if (convertStringToERulesName(stringname) == ruleName  || result == true) {
			xmlFile->IntoElem();
			if (xmlFile->FindElem("statement")) {
				xmlFile->SetData("false");
			}
	}else{
		result = false;
	}
	return result;
}



/**
 * @details Update a Rule's statement with it name
 * @param ruleName rule's name
 * @param statement rule's statement
 * @param value rule's value
 * @return a boolean depending of the result of the update
 */
EUpdateResult RulesDataMapper::updateWithNameStatementAndValue(const ERulesName ruleName, const bool statement, const int value){
	lock.lock();
	EUpdateResult result = FAILED_FILE_MISSING;
    if(value <= 0 || value > 50){
    	result = FAILED_VALUE_OUT_OF_RANGE;
    }else {
        if (ruleName == RULE_X_1S || ruleName == RULE_XX || ruleName == RULE_XT) {
            CMarkup xmlFile;
            if(xmlFile.Load(gs_fileLocation)){
				xmlFile.FindElem();
				xmlFile.IntoElem();
				xmlFile.FindElem("rule");
				string stringname = xmlFile.GetAttrib("name");
				int i = 0;
				while (convertStringToERulesName(stringname) != ruleName && i<9 && result != FAILED_FILE_CORRUPT ) {
					if(stringname == ""){
						result = FAILED_FILE_CORRUPT;
					}
					i++;
					xmlFile.FindElem("rule");
					stringname = xmlFile.GetAttrib("name");
				}
				if(result != FAILED_FILE_CORRUPT){
					if (convertStringToERulesName(stringname) == ruleName) {
						xmlFile.IntoElem();
						if(xmlFile.FindElem("statement")) {
							xmlFile.SetData(boolToString(statement));
							if (xmlFile.FindElem("value")) {
								xmlFile.SetData(value);
								xmlFile.Save(
										gs_fileLocation);
								result = UPDATE_OK;
							} else {
								result = FAILED_FILE_CORRUPT;
							}
						} else{
							result = FAILED_FILE_CORRUPT;
						}
					} else {
						result = FAILED_RULE_MISSING;
					}
				}
			}
        }else {
			result = FAILED_VALUE_NON_MODIFIABLE;
		}
    }
    lock.unlock();
    return result;
}

/**
 * @details update ParameterizableStatement in the XML File
 * @param statement current statement to update
 * @return the update's result as EUpdateResult
 */
EUpdateResult RulesDataMapper::updateParameterizableStatement(const bool statement){
	lock.lock();
	CMarkup xmlFile;
    EUpdateResult result = UPDATE_OK;
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    if(!xmlFile.FindElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse")){
        result = FAILED_FILE_CORRUPT;
    }
    xmlFile.SetData(boolToString(statement));
    xmlFile.Save(gs_fileLocation);
    lock.unlock();
    return result;
}

/**
 * @details Read and update the Rule's statement and value
 * @param listRules a list of Rule to set
 * @param evaluateParameterizableRulesIf1_2sSucceeded pointer to  evaluateParameterizableRulesIf1_2sSucceeded of the EvaluateController()
 * @return a boolean depending of the result of the reading
 */
bool RulesDataMapper::readToSetListRules(IRule **listRules, bool *evaluateParameterizableRulesIf1_2sSucceeded) {
	lock.lock();
	int i = 0;
    bool result = true;
    IParameterizable_Rules* parameterizableRules;
    CMarkup xmlFile;
    if(!xmlFile.Load(gs_fileLocation)){
    	result = false;
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while(xmlFile.FindElem( "rule" )){
        string stringname = xmlFile.GetAttrib("name");
        ERulesName name = convertStringToERulesName(stringname);
        xmlFile.IntoElem();
        xmlFile.FindElem( "statement" );
        bool statement = getBooleanFromString(xmlFile.GetData());
        int value = 0;
        if(xmlFile.FindElem( "value" )){
            value = stoi(xmlFile.GetData());
        }
        xmlFile.OutOfElem();
        switch(name) {
            case RULE_1_2S: i=0;
                break;
            case RULE_1_3S: i=1;
                break;
            case RULE_2_2S: i=2;
                break;
            case RULE_2OF3_2S: i=3;
                break;
            case RULE_R_4S: i=4;
                break;
            case RULE_X_1S: i=5;
                parameterizableRules = Rule_X_1s::getInstance();
                parameterizableRules->setValue(value);
                break;
            case RULE_XX: i=6;
                parameterizableRules = Rule_Xx::getInstance();
                parameterizableRules->setValue(value);
                break;
            case RULE_XT: i=7;
                parameterizableRules = Rule_XT::getInstance();
                parameterizableRules->setValue(value);
                break;
            default:
            	result = false;
        }
        listRules[i]->setIsActive(statement);
    }
    xmlFile.FindElem( "evaluationParameterizableRulesEvaluationIf1_2sIsPasse" );
    *evaluateParameterizableRulesIf1_2sSucceeded = getBooleanFromString(xmlFile.GetData());
	lock.unlock();
    return result;
}

/**
 * @detail return a boolean from a string
 * @param stringstatement string (true or false)
 * @return boolean from the string
 */
bool RulesDataMapper::getBooleanFromString(const string &stringstatement) const {
    bool statement = false;
    if(stringstatement == "true"){
            statement = true;
        }
    return statement;
}

/**
 * @details Convert a string into a ERulesName
 * @param stringname string to convert
 * @return the ERulesName convertion
 */
ERulesName RulesDataMapper::convertStringToERulesName(const string stringname)const {
	ERulesName ruleName;
	if("RULE_1_2S" == stringname) {
		ruleName = RULE_1_2S;
	} else if("RULE_1_3S" == stringname) {
		ruleName = RULE_1_3S;
	}else if("RULE_2_2S" == stringname) {
		ruleName = RULE_2_2S;
	}else if("RULE_2OF3_2S" == stringname) {
		ruleName = RULE_2OF3_2S;
	}else if("RULE_R_4S" == stringname) {
		ruleName = RULE_R_4S;
	}else if("RULE_X_1S" == stringname) {
		ruleName = RULE_X_1S;
	}else if("RULE_XX" == stringname) {
		ruleName = RULE_XX;
	}else if("RULE_XT" == stringname) {
		ruleName = RULE_XT;
	}
	else{
		ruleName = FALSE_RULE;
	}
	return ruleName;
}


/**
 * @details Read the XML setting File and return all the information of the file
 * @return a board of Westgard configuration
 */
WestgardConfiguration RulesDataMapper::readFileToGetSetting(){
	lock.lock();
    WestgardConfiguration* westgardConfiguration;
    list<RuleSetting> ruleSettingList;
    CMarkup xmlFile;
    xmlFile.Load(gs_fileLocation);
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while(xmlFile.FindElem( "rule" )) {
        string stringname = xmlFile.GetAttrib("name");
        RuleSetting *ruleSetting = new RuleSetting(convertStringToERulesName(stringname));
        xmlFile.IntoElem();
        xmlFile.FindElem("statement");
        bool statement = getBooleanFromString(xmlFile.GetData());
        ruleSetting->setIsActive(statement);
        int value;
        if (xmlFile.FindElem("value")) {
            value = stoi(xmlFile.GetData());
            ruleSetting->setValue(value);
        }
        xmlFile.OutOfElem();
        ruleSettingList.push_back(*ruleSetting);
        delete ruleSetting;
    }
    xmlFile.FindElem("evaluationParameterizableRulesEvaluationIf1_2sIsPasse");
    bool evaluationParameterizableRulesEvaluationIf1_2sIsPasse = getBooleanFromString(xmlFile.GetData());
    westgardConfiguration = new WestgardConfiguration(ruleSettingList,evaluationParameterizableRulesEvaluationIf1_2sIsPasse);
    return *westgardConfiguration;
}

/**
 * @details convert a boolean to a string
 * @param b boolean to convert
 * @return the string of the current boolean
 */
string const RulesDataMapper::boolToString(const bool b) {
	string statement;
	if(b == true){
		statement = "true";
	}else{
		statement = "false";
	}
	lock.unlock();
	return statement;
}

