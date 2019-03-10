add_library(PHPModule MODULE
    factory.cpp
)
set_target_properties(PHPModule PROPERTIES PREFIX "zia-")
target_link_libraries(PHPModule
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
