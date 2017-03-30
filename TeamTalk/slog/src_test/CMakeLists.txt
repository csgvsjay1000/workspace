cmake_minimum_required(VERSION 2.8)
PROJECT(test_slog)
SET(SRC_LIST test_slog.cpp)
INCLUDE_DIRECTORIES(./ ../)
LINK_DIRECTORIES(../ /usr/local/log4cxx/lib/ )
ADD_EXECUTABLE(test ${SRC_LIST})

TARGET_LINK_LIBRARIES(test libslog.a -llog4cxx) 
