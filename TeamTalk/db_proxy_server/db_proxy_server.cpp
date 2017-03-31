//
// db_proxy_server.cpp
//
//

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "util.h"
#include "DBPool.h"
#include "business/UserModel.h"

#include "test/DBTestUser.h"

int main(){
	CDBManager* pDBManager = CDBManager::Instance();
	if(!pDBManager){
		log("DBManager init failed");
		return -1;
	}
	
    CDBUserTest	 testUser;
	testUser.TestInsert();


	return 0;
}




