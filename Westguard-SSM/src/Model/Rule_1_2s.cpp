/*
 * Rule12s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */


#include "Rule_1_2s.h"

/**
 * @class Rule_1_2s
 * @details Singleton allow to evaluate Rule_1_2s
 */

Rule_1_2s* Rule_1_2s::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_1_2s::Rule_1_2s(): IRule(){
	// TODO Auto-generated constructor stub
	m_name = RULE_1_2S;
}

/**
 * @details Destructor
 */
Rule_1_2s::~Rule_1_2s(){
	// TODO Auto-generated destructor stub*
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_1_2s *Rule_1_2s::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_1_2s();
	  }
	return ms_instance;
}

ERuleStatement Rule_1_2s::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement statement;
	float twoSDmax = mean + SD*2;
	float twoSDmin = mean - SD*2;
	if(this->m_isActive == false){
        statement = WESTGARD_RULE_DISABLE;
	}
	else{
		if(listValues.back() > twoSDmax || listValues.back() < twoSDmin ){
            statement = WESTGARD_RULE_FAILED;
        }
        else{
            statement = WESTGARD_RULE_OK;
        }
	}
	return statement;
}

