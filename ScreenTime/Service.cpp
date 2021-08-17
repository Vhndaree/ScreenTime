#include <iostream>
#include <sstream>
#include <mysql.h>


using namespace std;

MYSQL* connection;

void Save(ProcessDetail pd) {
	connection = mysql_init(0);
	if (connection) {
		OutputDebugString(L"connection created");
	}
	else
		OutputDebugString(L"connection failed 1");
	connection = mysql_real_connect(connection, "localhost", "root", "password", "screentime", 3306, NULL, 0);
	if (connection) {
		OutputDebugString(L"connection database");
		stringstream ss;
		ss << "INSERT INTO screentime(windowTitle, processName, processPath)"
			<< "VALUES ('"+ pd.GetWindowTitle() + "', '"+ pd.GetProcessName() +"', '" + pd.GetProcessPath() + "')";

		if (mysql_query(connection, ss.str().c_str())){
			OutputDebugString(L"insertion failed");
		} else
			OutputDebugString(L"insertion complete");
		mysql_close(connection);	
	}
	else
		OutputDebugString(L"connection failed 2");

}