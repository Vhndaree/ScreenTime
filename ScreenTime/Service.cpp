#include <iostream>
#include <mysql.h>

using namespace std;

MYSQL* conn;

void DBConnection() {
	conn = mysql_init(0);
	if (conn) {
		OutputDebugString(L"connection created");
	}
	else
		OutputDebugString(L"connection failed 1");
	conn = mysql_real_connect(conn, "localhost", "root", "password", "screentime", 3306, NULL, 0);
	if (conn) {
		OutputDebugString(L"connection database");
	}
	else
		OutputDebugString(L"connection failed 2");
}