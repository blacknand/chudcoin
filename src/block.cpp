#include "block.h"
#include "utils.h"
#include <ctime>
#include <chrono>
#include <iostream>

Block::Block(int idx, const std::string& prev_hash)
    : index(idx), previous_hash(prev_hash), nonce(0) {
    // TODO: Get current time
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
}