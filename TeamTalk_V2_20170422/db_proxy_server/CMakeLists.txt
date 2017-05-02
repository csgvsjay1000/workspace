cmake_miniMum_required(VERSION 2.6)
PROJECT(db_proxy_server)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(../base SRC_LIST1)
AUX_SOURCE_DIRECTORY(../base/pb SRC_LIST2)
AUX_SOURCE_DIRECTORY(./business SRC_LIST3)
AUX_SOURCE_DIRECTORY(./hiredis SRC_LIST4)
AUX_SOURCE_DIRECTORY(./test SRC_LIST5)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall -Wno-unused-parameter -Wcpp )
#ADD_DEFINITIONS( -g -W -Wall -Wno-unused-parameter -Wcpp -D_DEBUG_)

INCLUDE_DIRECTORIES(./ ./business ./hiredis ../base ../base/pb /usr/local/mysql/include/ )

LINK_DIRECTORIES(/usr/local/mysql/lib/ )
#LINK_DIRECTORIES(../base ../slog  /usr/local/log4cxx/lib )

ADD_EXECUTABLE(db_proxy_server ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4} ${SRC_LIST5})
target_link_libraries(db_proxy_server -lprotobuf -lpthread -lhiredis mysqlclient_r) 
#target_link_libraries(msg_server base libslog.a -llog4cxx ) 
