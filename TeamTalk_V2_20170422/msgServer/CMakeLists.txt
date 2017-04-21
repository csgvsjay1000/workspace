cmake_miniMum_required(VERSION 2.6)
PROJECT(msg_server)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(../base SRC_LIST1)
AUX_SOURCE_DIRECTORY(../base/pb SRC_LIST2)
#AUX_SOURCE_DIRECTORY(./business/ SRC_LIST2)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall )

INCLUDE_DIRECTORIES(./ ../base ../base/pb  )

LINK_DIRECTORIES(/usr/local/lib )
#LINK_DIRECTORIES(../base ../slog  /usr/local/log4cxx/lib )

ADD_EXECUTABLE(msg_server ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2} )
target_link_libraries(msg_server -lprotobuf -lpthread ) 
#target_link_libraries(msg_server base libslog.a -llog4cxx ) 
