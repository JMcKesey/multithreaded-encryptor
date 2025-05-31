#include "Cryption.hpp"
#include "cbc.hpp"
#include "../processes/Task.hpp"
#include "../fileHandling/ReadEnv.cpp"
#include <ctime>
#include <iomanip>

int executeCryption(const std::string &taskData){
  Task task = Task::fromString(taskData);
  ReadEnv env;

  std::string envKey = env.getenv();
  int key = std::stoi(envKey);
  std::vector<uint8_t> key(16, 0x2b);
  std::vector<uint8_t> iv(16, 0x00);

  AES_CBC aes_cbc(key, iv);

  if(task.action == Action::ENCRYPT){
    // encryption
    char ch;
    while(task.f_stream.get(ch)){
      // TODO: implement more secure encryption algorithm later
      ch = (ch+key)%256;
      task.f_stream.seekp(-1, std::ios::cur);
      task.f_stream.put(ch);
    }
    task.f_stream.close();
  } else {
    // decryption
    char ch;
    while(task.f_stream.get(ch)){
      ch = (ch-key+256)%256;
      task.f_stream.seekp(-1, std::ios::cur);
      task.f_stream.put(ch);
    }
    task.f_stream.close();
  }
  std::time_t t = std::time(nullptr);
  std::tm* now = std::localtime(&t);
  std::cout<<"Exiting the encryption/decryption at: "<<std::put_time(now, "%Y-%m-%d %H:%M:%S")<<std::endl;
  return 0;
}