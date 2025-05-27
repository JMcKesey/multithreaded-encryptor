#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../fileHandling/ReadEnv.cpp"
#include <ctime>
#include <iomanip>
#define ROTL8(x, shift) ((uint8_t)) ((x) << (shift)) | ((x) >> (8 - (shift)))

int executeCryption(const std::string &taskData){
  Task task = Task::fromString(taskData);
  ReadEnv env;

  std::string envKey = env.getenv();
  int key = std::stoi(envKey);

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

// rijndael lookup table
void intializeAesSbox(uint8_t sbox[256]) {
  uint8_t p = 1, q = 1;

  do {
    p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);
    q ^= 1 << 1;
    q ^= q << 2;
    q ^= q << 4;
    q ^= q & 0x80 ? 0x09 : 0;

    uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

    sbox[p] = xformed ^ 0x63;
  } while (p != 1);

  sbox[0] = 0x63;
}