/*
 * AllTest.cpp
 *
 *  Created on: 26 mars 2018
 *      Author: charles.socie
 */

#include "gtest/gtest.h"
//#include "../../third_parties/Markup/Markup.h"
#include "EvaluateControllerTest.h"
#include "Rule_1_2sTest.h"
#include "Rule_1_3sTest.h"
#include "Rule_2_2sTest.h"
#include "Rule_2of3_2sTest.h"
#include "Rule_R_4sTest.h"
#include "Rule_X_1sTest.h"
#include "Rule_XTTest.h"
#include "Rule_XxTest.h"
#include "RulesDataMapperTest.h"
#include "RuleSettingTest.h"
#include "WestgardConfigurationTest.h"
#include "WestgardInterfaceTests.h"



int main(int argc, char **argv) {
	/*const char* gs_fileLocation = "../Westgard_Config.xml";
	ifstream infile ("../../Westgard_Config.xml",ifstream::binary);
	infile.seekg(0,infile.end);
	long size = infile.tellg();
	infile.seekg (0);
	char* buffer = new char[size];
	infile.read (buffer,size);
	infile.close();
	remove(gs_fileLocation);
	ofstream outfile (gs_fileLocation,ofstream::binary);
	outfile.write (buffer,size);
	delete[] buffer;
	outfile.close();*/
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
