#ifndef AES_H
#define AES_H

#include <vector>
#include <cstdint>

class AES {
  public:
    AES(const std::vector<int8_t>& key);
    std::vector<int8_t> encryptBlock(const std::vector<uint8_t>& block);
    std::vector<int8_t> decryptBlock(const std::vector<uint8_t>& block);

  private:
    void keyExpansion();
    void addRoundKey(uint8_t* state, int round);
    void subBytes(uint8_t* state);
    void shiftRows(uint8_t* state);
    void mixColumns(uint8_t* state);

    std::vector<uint32_t> roundKeys;
    std::vector<uint8_t> key;
    int rounds;
};

#endif