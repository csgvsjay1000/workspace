cmake_miniMum_required(VERSION 2.6)
PROJECT(slog)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall )

INCLUDE_DIRECTORIES(./ /usr/local/log4cxx/include/ )
LINK_DIRECTORIES( /usr/local/log4cxx/lib/)

ADD_LIBRARY(slog STATIC  ${SRC_LIST})
TARGET_LINK_LIBRARIES(slog liblog4cxx.a)
