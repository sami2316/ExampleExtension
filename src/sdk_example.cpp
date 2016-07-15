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
  Status status = osquery::queryExternal(lquery, qd);
  if(status.ok()) {
    for (auto& row: qd ) {
     //iterator for no of columns in corresponding query
     for(pt iter = row.rbegin(); iter != row.rend(); iter++) {
       std::cout << iter->second << "   ";
      }
       std::cout<<std::endl;
    } 
  }
  return 0;
}
