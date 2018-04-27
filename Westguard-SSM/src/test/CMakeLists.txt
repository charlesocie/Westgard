add_executable(Test
	EvaluateControllerTest.h
	Rule_1_2sTest.h
	Rule_1_3sTest.h
	Rule_2_2sTest.h
	Rule_2of3_2sTest.h
	Rule_R_4sTest.h
	Rule_X_1sTest.h
	Rule_XxTest.h
	Rule_XTTest.h
	RulesDataMapperTest.h
	RuleSettingTest.h
	WestgardConfigurationTest.h
	WestgardInterfaceTests.h
		AllTest.cpp
        )


target_link_libraries(Test
	gtest
	pthread
	Controller
	Model
	DataMapper
	Markup
	WESTGARD-SSM
)