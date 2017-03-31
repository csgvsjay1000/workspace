cmake_miniMum_required(VERSION 2.6)
PROJECT(db_proxy_server)
AUX_SOURCE_DIRECTORY(./ SRC_LIST)
AUX_SOURCE_DIRECTORY(./test/ SRC_LIST1)
AUX_SOURCE_DIRECTORY(./business/ SRC_LIST2)

SET(LIBRARY_OUTPUT_PATH .)

ADD_DEFINITIONS( -g -W -Wall )

INCLUDE_DIRECTORIES(./ ../base/ /usr/local/mysql/include/  )


LINK_DIRECTORIES(../base ../slog  /usr/local/log4cxx/lib /usr/local/mysql/lib/)

ADD_EXECUTABLE(db_proxy_server ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2}) 
TARGET_LINK_LIBRARIES(db_proxy_server base libslog.a -llog4cxx mysqlclient_r ) 
