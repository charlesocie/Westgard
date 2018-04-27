/*
 * Rule_1_2s.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */

#include "gtest/gtest.h"
#include "../Model/Rule_1_2s.h"


namespace{
	class Rule_1_2sTest : public :: testing::Test{
	protected:
		Rule_1_2s* rule = Rule_1_2s::getInstance();
		list<float> listfloat;

	};

TEST_F(Rule_1_2sTest, DisableRule) {
    rule->setIsActive(false);
    EXPECT_EQ(rule->getIsActive(), false);
}

TEST_F(Rule_1_2sTest, EnableRule) {
    rule->setIsActive(true);
    EXPECT_EQ(rule->getIsActive(), true);
}

TEST_F(Rule_1_2sTest, EvaluateDisableRule) {
    rule->setIsActive(false);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(9.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_DISABLE);
}

TEST_F(Rule_1_2sTest, EvaluateLastMeasureIn2SDUnderMean) {
  Rule_1_2s* rule = Rule_1_2s::getInstance();
  rule->setIsActive(true);
  listfloat.push_back(6);
  listfloat.push_back(5);
  listfloat.push_back(9.5);
  EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_1_2sTest, EvaluateLastMeasureIn2SDOverMean) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(11.5);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_1_2sTest, EvaluateLastMeasureOn2SD) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(8);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_OK);
}

TEST_F(Rule_1_2sTest, EvaluateLastMeasureOutside2SDUnderMean) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(4);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}


TEST_F(Rule_1_2sTest, EvaluateLastMeasureOutside2SDOverMean) {
    rule->setIsActive(true);
    listfloat.push_back(6);
    listfloat.push_back(5);
    listfloat.push_back(15);
    EXPECT_EQ(rule->evaluate(listfloat, 10.00, 1.0), WESTGARD_RULE_FAILED);
}

}
