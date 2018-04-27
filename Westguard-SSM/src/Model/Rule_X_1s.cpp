/*
 * RuleX1s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "RuleX1s.h"
#include "Rule_X_1s.h"

/**
 * @class Rule_X_1s
 * @details Singleton allow to evaluate Rule_X_1s
 */


Rule_X_1s* Rule_X_1s::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_X_1s::Rule_X_1s() {
	// TODO Auto-generated constructor stub
	m_name = RULE_X_1S;
	setValue(4);
}

/**
 * @details Destructor
 */
Rule_X_1s::~Rule_X_1s() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_X_1s *Rule_X_1s::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_X_1s();
	  }
	return ms_instance;
}

ERuleStatement Rule_X_1s::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement result;
	int size = listValues.size();
	if( getValue() <= size) {
		ERuleStatement statement;
		float oneSDmax = mean + SD;
		float oneSDmin = mean - SD;
		int i = 0;
		if(this->m_isActive == false){
			//cout << "Rule_X_1s disable" << endl;
			statement = WESTGARD_RULE_DISABLE;
		}
		else{
			list<float>::iterator iteratorList;
			iteratorList = listValues.end();
			iteratorList --;
			if(*iteratorList > oneSDmax){
				while(*iteratorList > oneSDmax && i < getValue()){
					iteratorList --;
					i++;
				}
				if(i != getValue()){
					//cout << "Rule_X_1s OK " << endl;
					statement = WESTGARD_RULE_OK;
				}else{
					//cout << "Rule_X_1s Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			}
			else if(*iteratorList < oneSDmin){
				while(*iteratorList < oneSDmin && i < getValue()){
					iteratorList --;
					i++;
				}
				if(i != getValue()){
					//cout << "Rule_X_1s OK " << endl;
					statement = WESTGARD_RULE_OK;
				}else{
					//cout << "Rule_X_1s Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			}else {
				//cout << "Rule_X_1s OK " << endl;
				statement = WESTGARD_RULE_OK;
			}
		}
		result = statement;
	} else{
		result = WESTGARD_RULE_OK;
	}
	return result;
}
