/*
 * Rule_XTTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Model/Rule_XT.h"


namespace{
	class Rule_XTTest : public :: testing::Test{
	protected:
		Rule_XT* rule = Rule_XT::getInstance();
		list<float> listfloat;

	};


	TEST_F(Rule_XTTest, DisableRule) {
	    rule->setIsActive(false);
	    EXPECT_EQ(rule->getIsActive(), false);
	}

	TEST_F(Rule_XTTest, EnableRule) {
	    rule->setIsActive(true);
	    EXPECT_EQ(rule->getIsActive(), true);
	}

	TEST_F(Rule_XTTest, setValue) {
	    rule->setValue(3);
	    EXPECT_EQ(rule->getValue(), 3);
	}

	TEST_F(Rule_XTTest, EvaluateDisableRule) {
	    rule->setIsActive(false);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
	}

	TEST_F(Rule_XTTest, EvaluateValueTrendToUp){
	    rule->setIsActive(true);
	    listfloat.push_back(5);
	    listfloat.push_back(6);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}

	TEST_F(Rule_XTTest, EvaluateValueTrendToDown){
	    rule->setIsActive(true);
	    listfloat.push_back(15);
	    listfloat.push_back(10);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}


	TEST_F(Rule_XTTest, EvaluateValueSwing ){
	    rule->setIsActive(true);
	    listfloat.push_back(5);
	    listfloat.push_back(4);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}


	TEST_F(Rule_XTTest, EvaluateValueAreEquals ){
	    rule->setIsActive(true);
	    listfloat.push_back(10);
	    listfloat.push_back(10);
	    listfloat.push_back(10);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_XTTest, EvaluateWithNotEnoughtValueAndTrendToDown ){
	    rule->setIsActive(true);
	    rule->setValue(5);
	    listfloat.push_back(10);
	    listfloat.push_back(9);
	    listfloat.push_back(8);
	    listfloat.push_back(7);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}
}
