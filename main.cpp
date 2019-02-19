#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace mysqlpp;

void pool();

void example();

int main(int argc,char* argv[]){
    
    return 0;
}

void pool(){

}

void example(){
    printf("====================== usage about mysql connection =======================\n");
    Connection *conn =new Connection("test_db","localhost", "wanjun", "wanjun", 3306);

    Connection *conn2 = new Connection(*conn);
    delete conn2;

    if(conn->ping()){
        printf("ping ok\n");
    }else{
        printf("ping false\n");
    }

    printf("mysql version : [%s]\n",conn->client_version().c_str());

    conn->disconnect();
    conn->connect("test_db","localhost","root","wanjun",3306);
    printf("reconnection mysql\n");

    // [long long unsigned] : [llu]
    printf("count rows about fruits : [%llu]\n",conn->count_rows("fruits"));

    if(conn->create_db("create_db_test")){
        printf("create database [create_db_test] ok\n");
    }else{
        printf("create database [create_db_test] false\n");
    }

    if(conn->drop_db("create_db_test")){
        printf("drop database [create_db_test] ok\n");
    }else{
        printf("drop database [create_db_test] ok\n");
    }

    printf("mysql connection ipc_info [%s]\n",conn->ipc_info().c_str());

    printf("protocol version [%d]\n",conn->protocol_version());
    printf("server version [%s]\n",conn->server_version().c_str());

    Query query = conn->query("select * from fruits");
    StoreQueryResult result = query.store();
    for(auto iter=result.begin();iter!=result.end();++iter){
        Row row = *iter;
        cout<<setw(10)<<row[0]<<
            setw(10)<<row[1]<<
            setw(10)<<row[2]<<
            setw(10)<<row[3]<<endl;
    }

    delete conn;
}
