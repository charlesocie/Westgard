/*
 * RuleX1s.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULEX1S_H_
#define CPP_RULEX1S_H_

#include "IParameterizableRules.h"

class Rule_X_1s : public IParameterizable_Rules {

private:
	/*ATTRIBUTS*/
	/** Rule_X_1s instance*/
	static Rule_X_1s *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_X_1s();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_X_1s();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_X_1s *getInstance();
};

#endif /* CPP_RULEX1S_H_ */
