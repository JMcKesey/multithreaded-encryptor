#ifndef CBC_H
#define CBC_H

#include "aes.hpp"

class AES_CBC {
  public:
    AES_CBC(const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv);
    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext);
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& plaintext);
    
  private:
    AES aes;
    std::vector <uint8_t> iv; // initial vector

    void pad(std::vector<uint8_t>& data);
    void unpad(std::vector<uint8_t>& data);
    void xorBlock(uint8_t* block, const uint8_t iv_or_prev);
};

#endif