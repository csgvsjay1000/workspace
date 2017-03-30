//
// db_proxy_server.cpp
//
//

#include <stdio.h>
#include "util.h"
#include "DBPool.h"

int main(){
	CDBManager* pDBManager = CDBManager::Instance();
	if(!pDBManager){
		log("DBManager init failed");
		return -1;
	}


	return 0;
}




