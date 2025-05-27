#ifndef CRYPTION_HPP
#define CRYPTION_HPP

#include <string>

int executeCryption(const std::string &taskData);
void intializeAesSbox(uint8_t sbox[256]);

#endif