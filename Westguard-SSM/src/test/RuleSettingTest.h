/*
 * RuleSettingTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */


#include "gtest/gtest.h"
#include "../Controller/RuleSetting.h"


namespace{
	class RuleSettingTest : public :: testing::Test{
	protected:

	};
TEST_F(RuleSettingTest, testegal){
	RuleSetting* r = new RuleSetting(RULE_X_1S);
	EXPECT_EQ(*r, *r);
}

/*TEST_F(RuleSettingTest, testpasegalnom){
	RuleSetting* r = new RuleSetting(RULE_X_1S);
	RuleSetting* r1 = new RuleSetting(RULE_1_2S);
	EXPECT_FALSE(*r == *r1);
}

TEST_F(RuleSettingTest, testpasegalstatement){
	RuleSetting* r = new RuleSetting(RULE_X_1S);
	RuleSetting* r1 = new RuleSetting(RULE_X_1S);
	r->setIsActive(true);
	r1->setIsActive(false);
	EXPECT_FALSE(*r == *r1);
}

TEST_F(RuleSettingTest, testpasegalvaleur){
	RuleSetting* r = new RuleSetting(RULE_X_1S);
	RuleSetting* r1 = new RuleSetting(RULE_1_2S);
	r->setValue(5);
	r1->setValue(12);
	EXPECT_FALSE(*r == *r1);
}*/
}
