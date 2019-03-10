add_library(DEBUGModule MODULE
    factory.cpp
)
set_target_properties(DEBUGModule PROPERTIES PREFIX "zia-")
target_link_libraries(DEBUGModule
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
