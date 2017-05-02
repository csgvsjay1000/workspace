cmake_miniMum_required(VERSION 2.6)
PROJECT(db_proxy_server)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(./hiredis SRC_LIST4)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall -Wno-unused-parameter -Wcpp)

INCLUDE_DIRECTORIES(./ ./hiredis )

LINK_DIRECTORIES(/usr/local/lib )
#LINK_DIRECTORIES(../base ../slog  /usr/local/log4cxx/lib )

ADD_EXECUTABLE(db_proxy_server ${SRC_LIST} ${SRC_LIST4})
target_link_libraries(db_proxy_server -lprotobuf -lpthread hiredis) 
#target_link_libraries(msg_server base libslog.a -llog4cxx ) 
