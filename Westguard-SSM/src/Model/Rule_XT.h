/*
 * RuleXT.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULEXT_H_
#define CPP_RULEXT_H_

#include "IParameterizableRules.h"
using namespace std;
class Rule_XT : public IParameterizable_Rules {

private:
	/*ATTRIBUTS*/
	/** Rule_XT instance*/
	static Rule_XT *ms_instance;

protected:
	/*CONSTRUCTOR*/
	Rule_XT();

public:
	/*DESTRUCTOR*/
	virtual ~Rule_XT();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const ;

	/*GETTER*/
	static Rule_XT *getInstance();
};

#endif /* CPP_RULEXT_H_ */
