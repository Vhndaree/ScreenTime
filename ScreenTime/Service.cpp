#include <iostream>
#include <sstream>
#include <mysql.h>

using namespace std;

MYSQL* conn;

void Connection() {
	conn = mysql_init(0);
	if (conn) {
		std::cout << "connection established";
	}
	else {
		std::cout << "connection failed";
		exit(0);
	}

	conn = mysql_real_connect(conn, "localhost", "root", "password", "screentime", 3306, NULL, 0);
}

void DestroyConnection() {
	if (conn) {
		mysql_close(conn);
	}
}

void Save(ProcessDetail pd) {
	Connection();

	if (conn) {
		stringstream ss;
		string stString = FormattedTimeString(pd.GetStartDateTime());
		string etString = FormattedTimeString(pd.GetEndDateTime());
		string timeDiff = to_string(TimeDiffInSeconds(pd.GetStartDateTime(), pd.GetEndDateTime()));

		ss << "INSERT INTO screentime(window_title, process_name, process_path, start_date_time, end_date_time, time_diff)"
			<< "VALUES ('"+ pd.GetWindowTitle() + "', '"+ pd.GetProcessName() +"', '" + pd.GetProcessPath() + "', '" + stString + "', '" + etString + "', '" + timeDiff + "')";

		if (mysql_query(conn, ss.str().c_str())){
			std::cout << "query succeed";
		} else
			std::cout << "query failed";
	}
	else {
		std::cout << "connection failed";
		exit(0);
	}

	DestroyConnection();
}