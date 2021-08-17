#include <iostream>
#include <sstream>
#include <mysql.h>

using namespace std;

MYSQL* connection;

void Save(ProcessDetail pd) {
	connection = mysql_init(0);
	if (connection) {
		std::cout << "connection established";
	}
	else {
		std::cout << "connection failed";
		exit(0);
	}

	connection = mysql_real_connect(connection, "localhost", "root", "password", "screentime", 3306, NULL, 0);

	if (connection) {
		stringstream ss;
		ss << "INSERT INTO screentime(window_title, process_name, process_path, start_date_time, end_date_time)"
			<< "VALUES ('"+ pd.GetWindowTitle() + "', '"+ pd.GetProcessName() +"', '" + pd.GetProcessPath() + "', '" + pd.GetStartDateTime() + "', '" + pd.GetEndDateTime() + "')";
		std::string s = ss.str();
		if (mysql_query(connection, ss.str().c_str())){
			std::cout << "query failed";
		} else
			std::cout << "query succeed";

		mysql_close(connection);	
	}
	else {
		std::cout << "connection failed";
		exit(0);
	}
}