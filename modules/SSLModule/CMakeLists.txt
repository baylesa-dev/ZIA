add_library(SSLModule MODULE
    factory.cpp
)
set_target_properties(SSLModule PROPERTIES PREFIX "zia-")
target_link_libraries(SSLModule
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
