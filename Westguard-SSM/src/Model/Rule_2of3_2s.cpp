/*
 * Rule2of32s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "Rule2of32s.h"
#include "Rule_2of3_2s.h"

/**
 * @class Rule_2of3_2s
 * @details Singleton allow to evaluate Rule_2of3_2s
 */


Rule_2of3_2s* Rule_2of3_2s::ms_instance = nullptr;

Rule_2of3_2s::Rule_2of3_2s() {
	// TODO Auto-generated constructor stub
	m_name = RULE_2OF3_2S;
}

/**
 * @details Destructor
 */
Rule_2of3_2s::~Rule_2of3_2s() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_2of3_2s *Rule_2of3_2s::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_2of3_2s();
	  }
	return ms_instance;
}



ERuleStatement Rule_2of3_2s::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement statement;
	float twoSDmax = mean + SD*2;
	float twoSDmin = mean - SD*2;
	if(this->m_isActive == false || listValues.size() == 1){
		statement = WESTGARD_RULE_DISABLE;
	}
	else{
		list<float>::iterator iteratorList;
		iteratorList = listValues.end();
		iteratorList --;
		if(*iteratorList > twoSDmax){
			iteratorList --;
			if(*iteratorList > twoSDmax) {
				statement = WESTGARD_RULE_FAILED;
			}else{
				iteratorList --;
				if(*iteratorList > twoSDmax) {
					statement = WESTGARD_RULE_FAILED;
				}else {
					statement = WESTGARD_RULE_OK;
				}
			}
		}
		else if (*iteratorList < twoSDmin) {
			iteratorList--;
			if (*iteratorList < twoSDmin) {
				statement = WESTGARD_RULE_FAILED;
			}else {
				iteratorList --;
				if(*iteratorList < twoSDmin) {
					statement = WESTGARD_RULE_FAILED;
				}else {
					statement = WESTGARD_RULE_OK;
				}
			}
		}else {
			statement = WESTGARD_RULE_OK;
			iteratorList --;
			if(*iteratorList > twoSDmax){
				iteratorList --;
				if(*iteratorList > twoSDmax) {
					statement = WESTGARD_RULE_FAILED;
				}
			}
			if(*iteratorList < twoSDmin){
				iteratorList --;
				if(*iteratorList < twoSDmin) {
					statement = WESTGARD_RULE_FAILED;
				}
			}
		}
	}
	return statement;
}
