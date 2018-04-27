add_library(DataMapper
	IRulesDataMapper.h
	RulesDataMapper.cpp
	RulesDataMapper.h
)

target_link_libraries(DataMapper
	Controller
	Model
)