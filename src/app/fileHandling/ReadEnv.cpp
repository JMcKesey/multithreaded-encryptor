#include <iostream>
#include <string>
#include <fstream>
#include "IO.hpp"
#include <sstream>

class ReadEnv{
  public:
    std::string getEnv(){
      std::string env_path = ".env";
      IO io(env_path);
      std::fstream f_stream = io.getFileStream();
      std::stringstream buffer;
      buffer << f_stream.rdbuf();
      std::string content = buffer.str();
      return content;
    }
};