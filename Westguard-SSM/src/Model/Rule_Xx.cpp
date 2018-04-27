/*
 * RuleXx.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "RuleXx.h"
#include "Rule_Xx.h"

/**
 * @class Rule_Xx
 * @details Singleton allow to evaluate Rule_Xx
 */


Rule_Xx* Rule_Xx::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_Xx::Rule_Xx() {
	// TODO Auto-generated constructor stub
	m_name = RULE_XX;
	setValue(10);
}

/**
 * @details Destructor
 */
Rule_Xx::~Rule_Xx() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_Xx *Rule_Xx::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_Xx();
	  }
	return ms_instance;
}



ERuleStatement Rule_Xx::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement result;
	int size = listValues.size();
	if( getValue() <= size) {
		ERuleStatement statement;
		int i = 0;
		if(this->m_isActive == false){
			//cout << "Rule_Xx disable" << endl;
			statement = WESTGARD_RULE_DISABLE;
		}
		else{
			list<float>::iterator iteratorList;
			iteratorList = listValues.end();
			iteratorList --;
			if(*iteratorList > mean){
				while(*iteratorList > mean && i < getValue()){
					iteratorList --;
					i++;
				}
				if(i != getValue()){
					//cout << "Rule_Xx OK " << endl;
					statement = WESTGARD_RULE_OK;
				}else{
					//cout << "Rule_Xx Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			}
			else if(*iteratorList < mean){
				while(*iteratorList < mean && i < getValue()){
					iteratorList --;
					i++;
				}
				if(i != getValue()){
					//cout << "Rule_Xx OK " << endl;
					statement = WESTGARD_RULE_OK;
				}else{
					//cout << "Rule_Xx Failed " << endl;
					statement = WESTGARD_RULE_FAILED;
				}
			}else {
				//cout << "Rule_Xx OK " << endl;
				statement = WESTGARD_RULE_OK;
			}
		}
		result = statement;
	} else{
		result = WESTGARD_RULE_OK;
	}
	return result;
}
