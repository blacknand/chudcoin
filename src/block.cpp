#include "block.h"
#include "utils.h"
#include "utc_data.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>

Block::Block(int idx, const std::string& prev_hash)
    : index(idx), previous_hash(prev_hash), nonce(0) {
    timestamp = get_utc_time();
    std::cout << timestamp << std::endl;
}