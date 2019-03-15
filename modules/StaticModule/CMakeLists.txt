add_library(StaticModule MODULE
    factory.cpp
)
set_target_properties(StaticModule PROPERTIES PREFIX "zia-")
target_link_libraries(StaticModule
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
