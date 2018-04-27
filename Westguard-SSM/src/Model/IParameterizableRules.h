/*
 * ParameterizableRules.h
 *
 *  Created on: 2 mars 2018
 *      Author: charles.socie
 */

#ifndef MODEL_CPP_PARAMETERIZABLERULES_H_
#define MODEL_CPP_PARAMETERIZABLERULES_H_

#include "IRule.h"

class IParameterizable_Rules : public IRule{

protected:
	/*ATTRIBUTS*/
	/** @details Rule's value*/
	int m_value;

public:
	/*DESTRUCTOR*/
	virtual ~IParameterizable_Rules();

	/*METHODES*/
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const  = 0;

	/*GETTER*/
	/**
	 * @details get the Rule's value
	 * @return Rule's value
	 */
	inline virtual int getValue()const {return this->m_value;}

	/*SETTER*/
	/**
	 * @details set the Rule's value
	 * @param value Rule's value
	 */
	inline virtual void setValue(const int value){this->m_value = value;}
};

#endif /* MODEL_CPP_PARAMETERIZABLERULES_H_ */
