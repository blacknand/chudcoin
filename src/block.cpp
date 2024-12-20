#include "block.h"
#include "utils.h"
#include <ctime>

Block::Block(int idx, const std::string& prev_hash)
    : index(idx), previous_hash(prev_hash), nonce(0) {
    // TODO: Get current time
}