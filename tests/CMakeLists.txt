find_package(CppUTest REQUIRED)

add_library(mylib_test EXCLUDE_FROM_ALL mylib_test.cpp)
target_include_directories(mylib_test PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(mylib_test mylib)
target_link_libraries(mylib_test CppUTest CppUTestExt)
add_executable(run_all_tests EXCLUDE_FROM_ALL run_all_tests.cpp)

target_link_libraries(run_all_tests mylib_test)

add_custom_target(check DEPENDS run_all_tests)
add_custom_command(TARGET check POST_BUILD WORKING_DIRECTORY ${CMAKE_BINARY_DIR} COMMAND run_all_tests)
