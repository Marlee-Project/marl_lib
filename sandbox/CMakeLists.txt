add_executable(sandbox main.c)
target_include_directories(sandbox PRIVATE ${PROJECT_SOURCE_DIR}/include)
add_dependencies(sandbox marl_lib)
target_link_libraries(sandbox marl_lib)
