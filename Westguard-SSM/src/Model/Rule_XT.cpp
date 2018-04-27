/*
 * RuleXT.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "RuleXT.h"
#include "Rule_XT.h"

/**
 * @class Rule_XT
 * @details Singleton allow to evaluate Rule_XT
 */


Rule_XT* Rule_XT::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_XT::Rule_XT() {
	// TODO Auto-generated constructor stub
	m_name = RULE_XT;
	setValue(7);
}

/**
 * @details Destructor
 */
Rule_XT::~Rule_XT() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_XT *Rule_XT::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_XT();
	  }
	return ms_instance;
}

ERuleStatement Rule_XT::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement result;
	int size = listValues.size();
	if( getValue() <= size) {
		ERuleStatement statement;
		int i = 1;
		if (this->m_isActive == false) {
			//cout << "Rule_XT disable" << endl;
			statement = WESTGARD_RULE_DISABLE;
		} else {
			list<float>::iterator iteratorList;
			float lastValue;
			iteratorList = listValues.end();
			iteratorList--;
			lastValue = *iteratorList;
			iteratorList--;
			if (*iteratorList > lastValue) {
				while (*iteratorList > lastValue && i < getValue()) {
					lastValue = *iteratorList;
					iteratorList--;
					i++;
				}
				if (i != getValue()) {
					//cout << "Rule_XT OK " << endl;
					statement = WESTGARD_RULE_OK;
				} else {
					//cout << "Rule_XT Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			} else if (*iteratorList < lastValue) {
				while (*iteratorList < lastValue && i < getValue()) {
					lastValue = *iteratorList;
					iteratorList--;
					i++;
				}
				if (i != getValue()) {
					//cout << "Rule_XT OK " << endl;
					statement = WESTGARD_RULE_OK;
				} else {
					//cout << "Rule_XT Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			} else {
				//cout << "Rule_XT OK " << endl;
				statement = WESTGARD_RULE_OK;
			}
		}
		result = statement;
	} else{
		result = WESTGARD_RULE_OK;
	}
	return result;
}
