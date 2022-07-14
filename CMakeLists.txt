cmake_minimum_required(VERSION 3.18)

project(osgLearn LANGUAGES CXX)
set(OpenSceneGraph_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OSG/cmake)

#find_package(OpenSceneGraph CONFIG REQUIRED COMPONENTS osgDB osgViewer)

#if(OpenSceneGraph_FOUND)
#   message("find OSG")
#endif()

set(OSG_INCLUDE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/OSG/include)

set(OSG_LINK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OSG/lib)

set(OSG_EXTRA_LIBS 
    osgDBd 
    osgViewerd
    osgd
)

add_executable(main main.cpp)
#file(GLOB sources  CONFIGURE_DEPENDS *.cpp *.h)
#target_sources(main PUBLIC ${sources})

target_include_directories(main PRIVATE ${OSG_INCLUDE_DIR})

target_link_directories(main PRIVATE ${OSG_LINK_DIR})

target_link_libraries(main PUBLIC ${OSG_EXTRA_LIBS})