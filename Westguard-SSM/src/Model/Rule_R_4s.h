/*
 * RuleR4s.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULER4S_H_
#define CPP_RULER4S_H_

#include "IRule.h"

class Rule_R_4s : public IRule {

private:
	/*ATTRIBUTS*/
	/** Rule_R_4s instance*/
	static Rule_R_4s *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_R_4s();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_R_4s();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_R_4s *getInstance();
};

#endif /* CPP_RULER4S_H_ */
