cmake_minimum_required(VERSION 3.12)
project(pathplanning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2 -Wall -Wextra")
set(SOURCE_FILES
        tinyxml2.cpp
        xmllogger.cpp
        isearch.cpp
        mission.cpp
        map.cpp
        dijkstra.cpp
        config.cpp
        astar.cpp
        main.cpp
        environmentoptions.cpp
        tinyxml2.h
        node.h
        gl_const.h
        xmllogger.h
        isearch.h
        mission.h
        map.h
        ilogger.h
        dijkstra.h
        config.h
        astar.h
        searchresult.h
        environmentoptions.h
        CellCoords.h ClosedCellsContainer.h ClosedCellsContainer.cpp OpenCellsContainer.h OpenCellsContainer.cpp)

add_executable(pathplanning ${SOURCE_FILES})