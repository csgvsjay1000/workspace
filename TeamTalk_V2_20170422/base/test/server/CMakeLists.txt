cmake_miniMum_required(VERSION 2.6)
PROJECT(server)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(../../ SRC_LIST1)
AUX_SOURCE_DIRECTORY(../../pb SRC_LIST2)
#AUX_SOURCE_DIRECTORY(./business/ SRC_LIST2)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall )

INCLUDE_DIRECTORIES(./ ../../ ../../pb  )

LINK_DIRECTORIES(/usr/local/lib )
#LINK_DIRECTORIES(../base ../slog  /usr/local/log4cxx/lib )

ADD_EXECUTABLE(server ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2} )
target_link_libraries(server -lprotobuf -lpthread ) 
#target_link_libraries(msg_server base libslog.a -llog4cxx ) 
