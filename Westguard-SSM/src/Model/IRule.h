/*
 * Rule.h
 *
 *  Created on: 27 f�vr. 2018
 *      Author: charles.socie
 */

#ifndef CPP_RULE_H_
#define CPP_RULE_H_

#include<list>
#include<iostream>
#include "../Controller/ERuleStatement.h"
#include "../Controller/ERulesName.h"

using namespace std;

class IRule {

public:

	/*DESTRUCTOR*/
	virtual ~IRule();

	/*METHODES*/
    /**
    * @details Evaluate if the current Rule is OK or not
    * @param listValues list of values to evaluate
    * @param mean mean of the list of value
    * @param SD standard deviation of the list of value
    * @return ERuleStatement who can take 3 different values
    */
	virtual ERuleStatement evaluate(list<float> listValues, const float mean, const float SD)const  = 0;

	/*SETTER*/
	/**
	 * @details set the Rule's statement
	 * @param isActive Rule's statement
	 */
	inline virtual void setIsActive(const bool isActive){this->m_isActive = isActive;}

	/**
	 * @details set the Rule's name
	 * @param isActive Rule's name
	 */
	inline virtual void setName(const ERulesName name){this->m_name = name;}

	/*GETTER*/
	/**
	 * @details get the Rule's statement
	 * @return Rule's statement
	 */
	inline virtual bool getIsActive()const {return this->m_isActive;}

	/**
	 * @details get the Rule's name
	 * @return Rule's name
	 */
	inline virtual ERulesName getName()const {return this->m_name;}


protected:
	/*ATTRIBUTS*/
	/** @details Rule's statement*/
	bool m_isActive;
	/** @details Rule's name*/
	ERulesName m_name;
};

#endif /* CPP_RULE_H_ */
