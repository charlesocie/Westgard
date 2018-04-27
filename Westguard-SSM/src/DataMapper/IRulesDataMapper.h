/*
 * IRulesDataMapper.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef DATAMAPPER_IRULESDATAMAPPER_H_
#define DATAMAPPER_IRULESDATAMAPPER_H_


#include <iostream>
#include <list>
#include "../Controller/ERulesName.h"
#include "../Model/IRule.h"
#include "../Controller/EUpdateResult.h"
#include "../Controller/WestgardConfiguration.h"

using namespace std;

/**
 * @class I_Rules_DataMapper
 * @details Rules_DataMapper's Interface
 */
class IRules_DataMapper {
public:

	/*METHODES*/
	virtual EUpdateResult updateWithNameAndStatement(const ERulesName ruleName, const bool statement) = 0;
	virtual EUpdateResult updateWithNameStatementAndValue(const ERulesName ruleName, const bool statement, const int value)= 0;
    virtual EUpdateResult updateParameterizableStatement(const bool statement)=0;
	virtual bool readToSetListRules(IRule* listRules[], bool* evaluateParameterizableRulesIf1_2sSucceeded)= 0;
    virtual WestgardConfiguration readFileToGetSetting() = 0;
};

#endif /* DATAMAPPER_IRULESDATAMAPPER_H_ */

