cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Block.cpp
        Block.h
        Cab.cpp
        Cab.h
        CarType.h
        Color.h
        Driver.cpp
        Driver.h
        GameFlow.cpp
        GameFlow.h
        LuxuryCab.cpp
        LuxuryCab.h
        Main.cpp
        Map.cpp
        Map.h
        Matrix.cpp
        Matrix.h
        Point.cpp
        Point.h
        StandardCab.cpp
        StandardCab.h
        Status.h
        Trip.cpp
        Trip.h
        Communication.cpp
        Communication.h
        Udp.cpp
        Udp.h
        Socket.cpp
        Socket.h)
set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

add_executable(client ${SOURCE_FILES})


target_link_libraries(client ${Boost_LIBRARIES})