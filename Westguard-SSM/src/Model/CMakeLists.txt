add_library(Model
	IParameterizableRules.h
	IParameterizableRules.cpp
	IRule.cpp
	IRule.h
	Rule_1_2s.cpp
	Rule_1_2s.h
	Rule_1_3s.cpp
	Rule_1_3s.h
	Rule_2_2s.cpp
	Rule_2_2s.h
	Rule_2of3_2s.cpp
	Rule_2of3_2s.h
	Rule_R_4s.cpp
	Rule_R_4s.h
	Rule_X_1s.cpp
	Rule_X_1s.h
	Rule_Xx.cpp
	Rule_Xx.h
	Rule_XT.cpp
	Rule_XT.h
)

target_link_libraries(Model
	Controller
)