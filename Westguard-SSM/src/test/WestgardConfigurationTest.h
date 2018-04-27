/*
 * WestgardConfigurationTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Controller/WestgardConfiguration.h"


namespace{
	class WestgardConfigurationTest : public :: testing::Test{
	protected:
		list<RuleSetting> listrule;
		RuleSetting *ruleSetting;
	};

TEST_F(WestgardConfigurationTest, testegal) {
    ruleSetting = new RuleSetting(RULE_1_2S);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_1_3S);
    ruleSetting->setIsActive(false);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2_2S);
    ruleSetting->setIsActive(false);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_2OF3_2S);
    ruleSetting->setIsActive(false);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_R_4S);
    ruleSetting->setIsActive(false);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_X_1S);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(5);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XX);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(5);
    listrule.push_back(*ruleSetting);
    ruleSetting = new RuleSetting(RULE_XT);
    ruleSetting->setIsActive(true);
    ruleSetting->setValue(5);
    listrule.push_back(*ruleSetting);
    WestgardConfiguration *test = new WestgardConfiguration(listrule, true);
    EXPECT_EQ(test, test);
}
}
