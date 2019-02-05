add_library(mylib src/mylib.c)
target_include_directories(mylib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/mylib>
        )
target_include_directories(mylib PRIVATE src)

if(${REPLACE_MALLOC})
    target_compile_options(mylib PRIVATE -include  /usr/local/include/CppUTest/MemoryLeakDetectorMallocMacros.h)
    target_link_libraries(mylib CppUTest CppUTestExt)
endif()

install(TARGETS mylib
        EXPORT mylib-targets
        PUBLIC_HEADER DESTINATION include/mylib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
install(FILES include/mylib/mylib.h DESTINATION include/mylib)
install(EXPORT mylib-targets
        FILE mylib-config.cmake
        DESTINATION lib/cmake/mylib)
