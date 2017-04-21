cmake_miniMum_required(VERSION 2.6)
PROJECT(msg_server_test)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
#AUX_SOURCE_DIRECTORY(./test/ SRC_LIST1)
#AUX_SOURCE_DIRECTORY(./business/ SRC_LIST2)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall )

INCLUDE_DIRECTORIES(./ ../../base   )


LINK_DIRECTORIES(../../base ../../slog  /usr/local/log4cxx/lib )

ADD_EXECUTABLE(msg_server_test ${SRC_LIST} )
TARGET_LINK_LIBRARIES(msg_server_test base libslog.a -llog4cxx ) 
