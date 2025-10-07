cmake_minimum_required(VERSION 3.30)
project(CustomHttpClass)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

#execute_process(
#        COMMAND wx-config --cxxflags
#        OUTPUT_VARIABLE wxWidgets_CXX_FLAGS
#        OUTPUT_STRIP_TRAILING_WHITESPACE
#)
#
#execute_process(
#        COMMAND wx-config --libs
#        OUTPUT_VARIABLE wxWidgets_LIBS
#        OUTPUT_STRIP_TRAILING_WHITESPACE
#)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")

add_executable(CustomHttpClass src/main.cpp
        src/Client.cpp
        src/Client.h
        src/Server.cpp
        src/Server.h
        src/ClientSession.cpp
        src/ClientSession.h
        src/Parser.cpp
        src/Parser.h
        src/HttpRequest.h
)

target_link_libraries(CustomHttpClass
        Boost::headers)
        #${wxWidgets_LIBS})