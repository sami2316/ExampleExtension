#include <iostream>
#include <string>
#include <vector>
#include <osquery/sdk.h>

using namespace osquery;


int main() {

  QueryData qd;
  typedef std::map<std::string, std::string>::const_reverse_iterator pt;
  LOG(WARNING) << "Initilizing SDK example"; 
  std::string lquery = "SELECT * FROM users";
  
  auto sql = SQL(lquery);
	if (sql.ok()) {
	  LOG(INFO) << "============================";
	  for (const auto& row : sql.rows()) {
	    for (const auto& it : row) {
	      LOG(INFO) << it.first << " => " << it.second;
	    }
	    LOG(INFO) << "============================";
	  }
	} else {
	  LOG(ERROR) << sql.getMessageString();
	}

  return 0;
}
