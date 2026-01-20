cmake_minimum_required(VERSION 4.0)
project(cpplearn)

set(CMAKE_CXX_STANDARD 20)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 链接库目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 指定源文件路径
add_executable(CPPLearn src/main.cpp
                        src/scontrol.cpp)

add_executable(demo1 demos/demo_1.cpp
                    demos/demo_sctrl.cpp)

add_executable(demo2 demos/demo_2.cpp
                    demos/demo_sctrl.cpp)
# 链接库
target_link_libraries(CPPLearn ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)
target_link_libraries(demo1    ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)
#target_link_libraries(demo2    ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)
#target_link_libraries(CPPLearn TcAdsDll)