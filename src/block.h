#include <vector>
#include <string>

class Block {
public:
    int index;                                      // Block number
    std::string timestamp;                          // Time of creation
    std::vector<std::string> transactions;          // List of transactions
    std::string previous_hash;                      // Hash of the previous block
    std::string hash;                               // Hash of this block
    int nonce;                                      // For mining

    Block(int idx, const std::string& prev_hash);

    std::string calculate_hash(const std::string& str) const;             // Generate hash for this block
    void add_transaction(const std::string& tx);                          // Add a transaction to the block
};