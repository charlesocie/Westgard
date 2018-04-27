/*
 * RuleR4s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "RuleR4s.h"
#include "Rule_R_4s.h"

/**
 * @class Rule_R_4s
 * @details Singleton allow to evaluate Rule_R_4s
 */


Rule_R_4s* Rule_R_4s::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_R_4s::Rule_R_4s() {
	// TODO Auto-generated constructor stub
	m_name = RULE_R_4S;
}

/**
 * @details Destructor
 */
Rule_R_4s::~Rule_R_4s() {
	// TODO Auto-generated destructor stub
}


/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_R_4s *Rule_R_4s::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_R_4s();
	  }
	return ms_instance;
}

ERuleStatement Rule_R_4s::evaluate(list<float> listValues, const float mean, const float SD)const {
    ERuleStatement statement;
    float twoSDmax = mean + SD*2;
    float twoSDmin = mean - SD*2;
    if(this->m_isActive == false || listValues.size() == 1){
        //cout << "Rule_R_4s disable" << endl;
        statement = WESTGARD_RULE_DISABLE;
    }
    else{
        list<float>::iterator iteratorList;
        iteratorList = listValues.end();
        iteratorList --;
        if(*iteratorList > twoSDmax){
            iteratorList --;
            if(*iteratorList < twoSDmin) {
                //cout << "Rule_R_4s Failed " << endl;
                statement = WESTGARD_RULE_FAILED;
            }else{
                //cout << "Rule_R_4s OK " << endl;
                statement = WESTGARD_RULE_OK;
            }
        }
        else if (*iteratorList < twoSDmin) {
            iteratorList--;
            if (*iteratorList > twoSDmax) {
                //cout << "Rule_R_4s Failed " << endl;
                statement = WESTGARD_RULE_FAILED;
            }else {
                //cout << "Rule_R_4s OK " << endl;
                statement = WESTGARD_RULE_OK;
            }
        }else {
            //cout << "Rule_R_4s OK " << endl;
            statement = WESTGARD_RULE_OK;
        }
    }
    return statement;
}
