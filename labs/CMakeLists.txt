cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(kulikova_d_m)

add_subdirectory(complex)
add_subdirectory(rational)
add_subdirectory(dynamic_array)
add_subdirectory(matrix_ana)
add_subdirectory(stack_on_list)
add_subdirectory(queue_on_array)
add_subdirectory(dynamic_array_t)