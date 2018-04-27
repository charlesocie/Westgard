/*
 * Rule_XxTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */

#include "gtest/gtest.h"
#include "../Model/Rule_Xx.h"


namespace{
	class Rule_XxTest : public :: testing::Test{
	protected:
		Rule_Xx* rule = Rule_Xx::getInstance();
		list<float> listfloat;

	};

TEST_F(Rule_XxTest, DisableRule) {
    rule->setIsActive(false);
    EXPECT_EQ(rule->getIsActive(), false);
}

TEST_F(Rule_XxTest, EnableRule) {
    rule->setIsActive(true);
    EXPECT_EQ(rule->getIsActive(), true);
}

TEST_F(Rule_XxTest, setValue) {
    rule->setValue(3);
    EXPECT_EQ(rule->getValue(), 3);
}

TEST_F(Rule_XxTest, EvaluateDisableRule) {
    rule->setIsActive(false);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(9.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
}

TEST_F(Rule_XxTest, EvaluateWithAllValueOnSameSideOverMean) {
    rule->setIsActive(true);
    listfloat.push_back(15);
    listfloat.push_back(12);
    listfloat.push_back(10.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}

TEST_F(Rule_XxTest, EvaluateWithAllValueOnSameSideUnderMean) {
    rule->setIsActive(true);
    listfloat.push_back(9);
    listfloat.push_back(9.9);
    listfloat.push_back(5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}

TEST_F(Rule_XxTest, EvaluateWithAllValueOnSameSideOnMean) {
    rule->setIsActive(true);
    listfloat.push_back(10);
    listfloat.push_back(10);
    listfloat.push_back(10);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}


TEST_F(Rule_XxTest, EvaluateWithAllValueOnSameSideOverMeanAndOneOnMean) {
    Rule_Xx* rule = Rule_Xx::getInstance();
    rule->setIsActive(true);
    list<float> listfloat;
    listfloat.push_back(15);
    listfloat.push_back(10);
    listfloat.push_back(10.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_XxTest, EvaluateWithAllValueOnSameSideUnderMeanAndOneOnMean) {
    rule->setIsActive(true);
    listfloat.push_back(9);
    listfloat.push_back(10);
    listfloat.push_back(5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_XxTest, EvaluateWithNotEnoughtValueAndAllUnderMean ){
    rule->setIsActive(true);
    rule->setValue(5);
    listfloat.push_back(9.9);
    listfloat.push_back(9);
    listfloat.push_back(8);
    listfloat.push_back(7);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}
}


