/*
 * Rule22s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "Rule22s.h"
#include "Rule_2_2s.h"

/**
 * @class Rule_2_2s
 * @details Singleton allow to evaluate Rule_2_2s
 */


Rule_2_2s* Rule_2_2s::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_2_2s::Rule_2_2s() {
	// TODO Auto-generated constructor stub
	m_name = RULE_2_2S;
}

/**
 * @details Destructor
 */
Rule_2_2s::~Rule_2_2s() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_2_2s *Rule_2_2s::getInstance(){

	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_2_2s();
	  }
	return ms_instance;
}



ERuleStatement Rule_2_2s::evaluate(list<float> listValues, const float mean, const float SD)const {
	ERuleStatement statement;
	float twoSDmax = mean + SD*2;
	float twoSDmin = mean - SD*2;
	if(this->m_isActive == false || listValues.size() == 1){
		//cout << "Rule_2_2s disable" << endl;
		statement = WESTGARD_RULE_DISABLE;
	}
	else{
		list<float>::iterator iteratorList;
		iteratorList = listValues.end();
		iteratorList --;
        if(*iteratorList > twoSDmax){
            iteratorList --;
            if(*iteratorList > twoSDmax) {
                //cout << "Rule_2_2s Failed " << endl;
                statement = WESTGARD_RULE_FAILED;
            }else{
                //cout << "Rule_2_2s OK " << endl;
                statement = WESTGARD_RULE_OK;
            }
        }
        else if (*iteratorList < twoSDmin) {
            iteratorList--;
            if (*iteratorList < twoSDmin) {
                //cout << "Rule_2_2s Failed " << endl;
                statement = WESTGARD_RULE_FAILED;
            }else {
                //cout << "Rule_2_2s OK " << endl;
                statement = WESTGARD_RULE_OK;
            }
        }else {
            //cout << "Rule_2_2s OK " << endl;
            statement = WESTGARD_RULE_OK;
        }
    }
	return statement;
}
