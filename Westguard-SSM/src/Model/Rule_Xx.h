/*
 * RuleXx.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULEXX_H_
#define CPP_RULEXX_H_

#include "IParameterizableRules.h"
using namespace std;
class Rule_Xx : public IParameterizable_Rules {

private:
	/*ATTRIBUTS*/
	/** Rule_Xx instance*/
	static Rule_Xx *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_Xx();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_Xx();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_Xx *getInstance();
};

#endif /* CPP_RULEXX_H_ */
