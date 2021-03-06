/*
 * Rule12s.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULE12S_H_
#define CPP_RULE12S_H_

#include "IRule.h"
#include "../Controller/ERuleStatement.h"

class Rule_1_2s : public IRule {

private:
	/*ATTRIBUTS*/
	/** Rule_1_2s instance*/
	static Rule_1_2s *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_1_2s();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_1_2s();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_1_2s *getInstance();
};

#endif /* CPP_RULE12S_H_ */
