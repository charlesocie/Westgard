/*
 * Rule_2_2s.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Model/Rule_2_2s.h"


namespace{
	class Rule_2_2sTest : public :: testing::Test{
	protected:
		Rule_2_2s* rule = Rule_2_2s::getInstance();
		list<float> listfloat;

	};


	TEST_F(Rule_2_2sTest, DisableRule) {
	    rule->setIsActive(false);
	    EXPECT_EQ(rule->getIsActive(), false);
	}

	TEST_F(Rule_2_2sTest, EnableRule) {
	    rule->setIsActive(true);
	    EXPECT_EQ(rule->getIsActive(), true);
	}

	TEST_F(Rule_2_2sTest, EvaluateDisableRule) {
	    rule->setIsActive(false);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(9.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureIn2SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(9);
	    listfloat.push_back(8.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureIn2SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(10.5);
	    listfloat.push_back(11.5);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureOn2SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(12);
	    listfloat.push_back(12);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureOn2SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(8);
	    listfloat.push_back(8);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureOutside2SDUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(4);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}


	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureOutside2SDOverMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(18);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
	}

	TEST_F(Rule_2_2sTest, EvaluateLast2MeasureOutside2SDOneOnMeanOneUnderMean) {
	    rule->setIsActive(true);
	    listfloat.push_back(6);
	    listfloat.push_back(5);
	    listfloat.push_back(15);
	    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
	}
}
