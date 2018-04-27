/*
 * Rule2of32s.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULE2OF32S_H_
#define CPP_RULE2OF32S_H_

#include "IRule.h"

class Rule_2of3_2s : public IRule {

private:
	/*ATTRIBUTS*/
	/** Rule_2of3_2s instance*/
	static Rule_2of3_2s *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_2of3_2s();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_2of3_2s();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_2of3_2s *getInstance();
};

#endif /* CPP_RULE2OF32S_H_ */
