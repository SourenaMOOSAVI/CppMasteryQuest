add_library(EchoPlugin SHARED EchoPlugin.cpp)

target_include_directories(EchoPlugin PUBLIC ${PROJECT_SOURCE_DIR}/include)
