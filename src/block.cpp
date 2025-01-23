#include "block.h"
#include "utils.h"
#include "utc_data.h"

#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>


Block::Block(int idx, const std::string& prev_hash)
    : index(idx), previous_hash(prev_hash), nonce(0) {
    timestamp = get_utc_time();
    std::cout << "Block created: " << timestamp << std::endl;
    std::cout << "Block index: " << index << std::endl;
    std::cout << "Hash: " << hash << std::endl;
    std::cout << "Previous hash: " << previous_hash << std::endl;
    std::cout << "Nonce: " << nonce << std::endl;
}


std::string Block::calculate_hash(const std::string& str) {
    // https://learnxbyexample.com/cpp/sha256-hashes/
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}


void Block::add_transaction(const std::string& tx) {
    transactions.push_back(tx);
    std::cout << "Transaction added: " << tx << std::endl;
}