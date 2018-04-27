/*
 * Rule13s.cpp
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

//#include "Rule_1_3s.h"
#include "Rule_1_3s.h"

/**
 * @class Rule_1_3s
 * @details Singleton allow to evaluate Rule_1_3s
 */

Rule_1_3s* Rule_1_3s::ms_instance = nullptr;

/**
 * @details Constructor
 */
Rule_1_3s::Rule_1_3s(): IRule() {
	// TODO Auto-generated constructor stub
	m_name = RULE_1_3S;
}

/**
 * @details Destructor
 */
Rule_1_3s::~Rule_1_3s() {
	// TODO Auto-generated destructor stub
}

/** @details Singleton specification
 *
 * @return The current instance of the Class
 */
Rule_1_3s* Rule_1_3s::getInstance(){
	if (NULL == ms_instance)
	  {
		ms_instance =  new Rule_1_3s();
	  }
	return ms_instance;
}

ERuleStatement Rule_1_3s::evaluate(list<float> listValues, const float mean, const float SD)const  {
    ERuleStatement statement;
    float threeSDmax = mean + SD*3;
    float threeSDmin = mean - SD*3;
    if(this->m_isActive == false){
        //cout << "Rule_1_3s disable" << endl;
        statement = WESTGARD_RULE_DISABLE;
    }
    else{
        if(listValues.back() > threeSDmax || listValues.back() < threeSDmin ){
            //cout << "Rule_1_3s Failed " << endl;
            statement = WESTGARD_RULE_FAILED;
        }
        else{
            //cout << "Rule_1_3s OK " << endl;
            statement = WESTGARD_RULE_OK;
        }
    }

    return statement;
}
