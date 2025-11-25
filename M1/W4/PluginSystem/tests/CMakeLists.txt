add_executable(plugin_tests
    test_loading.cpp
    ${PROJECT_SOURCE_DIR}/src/PluginManager.cpp
)

target_include_directories(plugin_tests PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(plugin_tests PRIVATE Catch2::Catch2WithMain)

if(UNIX AND NOT APPLE)
    target_link_libraries(plugin_tests PRIVATE dl)
endif()

include(Catch)
catch_discover_tests(plugin_tests)
