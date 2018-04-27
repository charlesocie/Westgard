add_subdirectory(Controller)
add_subdirectory(DataMapper)
add_subdirectory(Model)
add_subdirectory(test)


set(PUBLIC_HEADERS
Westgard_Config.xml
        WestgardInterface.h
        WestgardInterface.cpp
)

add_library(WESTGARD-SSM SHARED
    WestgardInterface.h
    WestgardInterface.cpp
)


target_link_libraries(WESTGARD-SSM
        Model
        Controller
        DataMapper
        Markup
)




set_target_properties(WESTGARD-SSM PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")
set_target_properties(WESTGARD-SSM PROPERTIES VERSION 0.1)
install(TARGETS WESTGARD-SSM
    PUBLIC_HEADER DESTINATION include/
    LIBRARY DESTINATION lib # .so destination on linux
    RUNTIME DESTINATION lib # .dll destination on win32
)
