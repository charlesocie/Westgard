/*
 * RulesDataMapper.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef DATAMAPPER_CPP_RULESDATAMAPPER_H_
#define DATAMAPPER_CPP_RULESDATAMAPPER_H_

/** @details XML file's location */
static const char *const gs_fileLocation = "../Westgard_Config.xml";

#include "IRulesDataMapper.h"
#include "../Model/IParameterizableRules.h"
#include "../Model/Rule_X_1s.h"
#include "../Model/Rule_Xx.h"
#include "../Model/Rule_XT.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "../../third_parties/Markup/Markup.h"
#include <mutex>

class RulesDataMapper : public IRules_DataMapper {

private:
	/*VARIABLE*/
	std::mutex lock;

	/*METHODES*/
	virtual ERulesName convertStringToERulesName(const string stringname)const ;
	string const boolToString(const bool b);
	bool getBooleanFromString(const string &stringstatement) const;
	bool updateRule2_2sAnd2of3_2s(ERulesName ruleName,CMarkup* xmlFile);

public:
	/*CONSTRUCTOR*/
	RulesDataMapper();

	/*DESTRUCTOR*/
	virtual ~RulesDataMapper();

	/*METHODES*/
	virtual EUpdateResult updateWithNameAndStatement(const ERulesName ruleName, const bool statement);
	virtual EUpdateResult updateWithNameStatementAndValue(const ERulesName ruleName, const bool statement, const int value);
    virtual EUpdateResult updateParameterizableStatement(const bool statement);
	virtual bool readToSetListRules(IRule **listRules, bool *evaluateParameterizableRulesIf1_2sSucceeded);
    virtual WestgardConfiguration readFileToGetSetting();

};

#endif /* DATAMAPPER_CPP_RULESDATAMAPPER_H_ */
