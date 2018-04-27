/*
 * Rule13s.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULE13S_H_
#define CPP_RULE13S_H_

#include "IRule.h"
#include<list>

class Rule_1_3s : public IRule {

private:
	/*ATTRIBUTS*/
	/** Rule_1_3s instance*/
	static Rule_1_3s* ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_1_3s();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_1_3s();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_1_3s* getInstance();
};

#endif /* CPP_RULE13S_H_ */
