// Huffman Encoding

// Huffman Encoding is a "lossless data compression algorithm" that reduces the number of bits required to represent data.
// Lossless means that when we compress the data and then decompress it, we get exactly the original message back.

// Instead of giving every character the same number of bits, Huffman Encoding assigns shorter codes to frequent characters and 
// longer codes to less frequent characters. This reduces the total number of bits required to store the message.
// Important: Huffman Encoding is a greedy algorithm because, at each step, it selects the two nodes with the smallest
// frequencies and combines them.



// Character frequency means the number of times a particular character appears in a message.
// To construct a Huffman tree, we first count how many times each character occurs.
// The frequency tells us how important a character is in terms of its occurrence.
// Huffman Encoding uses frequency to decide how many bits should be assigned to each character.
// High frequency → shorter code.
// Low frequency → longer code.



// Standard ASCII representation
// In standard ASCII, each character is represented using 8 bits.
// Suppose we have 20 characters.
// Without compression: 20 * 8 = 160 bits
// So, we need 160 bits to store the message using 8-bit character


// Huffman representation
// Huffman assigns different code lengths to different characters.
// then the total number of bits.
// Total bits=∑(frequency*code length)
// here in this case 45 bits will be use to store the same 20 character data

// The formula for compression percentage is:
// Compression = ((Original size - Compressed size )/ Original size) * 100
// For our example:
//     = ((160-45)/160) * 100  =  71.875%
 





// Huffman Encoding uses a binary tree in which:
// Leaf nodes contain characters and their frequencies.
// Internal nodes contain the sum of the frequencies of their children.
// Every internal node has two children.

// After constructing the tree, we assign binary values to its edges:
// Every left edge gets 0.
// Every right edge gets 1.
// To find a character's code, start at the root and follow the path until you reach that character.



// Decoding algorithm
// Start at the root of the Huffman tree.
// Read one bit from the encoded message.
// If the bit is 0, move to the left child.
// If the bit is 1, move to the right child.
// When you reach a leaf node, output its character.
// Return to the root.
// Repeat until all bits are processed.





// Original Message
// AAABBBBBCCCCCCDDDDEE
//         |
// Calculate Character Frequencies
// A=3, B=5, C=6, D=4, E=2
//         |
// Construct Huffman Tree
// Using a min-priority queue
//         |
// Generate Binary Codes
// D=00, E=010, A=011, B=10, C=11
//         |
// Encode the Message
// Convert every character into its Huffman code.
//         |
// Decoding
// Recover the Original Message





// It is called greedy algorithm because it makes the locally optimal choice: combine the two nodes with the smallest frequencies.
// This greedy strategy produces an optimal prefix-free binary code for the given character frequencies.




// C++ implementation
// unordered_map to store character frequencies and codes.
// priority_queue to select the two smallest frequency nodes.
// A binary tree to represent Huffman codes.
// Recursion to generate codes.
// Tree traversal to decode the encoded bitstream.
// The priority_queue will work as a min-heap, so the node with the smallest frequency is always available at the top.









#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

// ============================================
// 1. HUFFMAN TREE NODE
// ============================================

struct Node {

    unsigned char ch;

    int frequency;

    shared_ptr<Node> left;
    shared_ptr<Node> right;

    // Leaf node constructor
    Node(unsigned char c, int freq) {

        ch = c;
        frequency = freq;

        left = nullptr;
        right = nullptr;
    }

    // Internal node constructor
    Node(shared_ptr<Node> l,
         shared_ptr<Node> r) {

        ch = 0;

        frequency = l->frequency + r->frequency;

        left = l;
        right = r;
    }

    // Check whether node is a leaf
    bool isLeaf() const {

        return left == nullptr &&
               right == nullptr;
    }
};


// ============================================
// 2. MIN HEAP COMPARATOR
// ============================================

struct Compare {

    bool operator()(
        const shared_ptr<Node>& a,
        const shared_ptr<Node>& b) const {

        return a->frequency > b->frequency;
    }
};


// ============================================
// 3. HUFFMAN CODING CLASS
// ============================================

class Huffman {

private:

    shared_ptr<Node> root;

    unordered_map<unsigned char, int> frequency;

    unordered_map<unsigned char, string> codes;


    // ========================================
    // GENERATE HUFFMAN CODES RECURSIVELY
    // ========================================

    void generateCodes(
        shared_ptr<Node> node,
        string code) {

        if (node == nullptr)
            return;

        // If leaf node, save its code
        if (node->isLeaf()) {

            // Special case: only one character
            if (code.empty())
                code = "0";

            codes[node->ch] = code;

            return;
        }

        // Left edge = 0
        generateCodes(node->left, code + "0");

        // Right edge = 1
        generateCodes(node->right, code + "1");
    }


public:

    // ========================================
    // 4. CALCULATE CHARACTER FREQUENCIES
    // ========================================

    void calculateFrequency(const string& text) {

        frequency.clear();
        codes.clear();

        for (unsigned char ch : text) {

            frequency[ch]++;
        }
    }


    // ========================================
    // 5. BUILD HUFFMAN TREE
    // ========================================

    void buildTree() {

        priority_queue<
            shared_ptr<Node>,
            vector<shared_ptr<Node>>,
            Compare
        > minHeap;

        // Insert all characters into min heap
        for (auto& item : frequency) {

            unsigned char ch = item.first;

            int freq = item.second;

            minHeap.push(
                make_shared<Node>(ch, freq)
            );
        }

        // Empty input check
        if (minHeap.empty()) {

            root = nullptr;

            return;
        }

        // Combine two minimum nodes repeatedly
        while (minHeap.size() > 1) {

            // Extract smallest frequency node
            auto left = minHeap.top();

            minHeap.pop();

            // Extract second smallest frequency node
            auto right = minHeap.top();

            minHeap.pop();

            // Create new internal node
            auto parent = make_shared<Node>(
                left, right
            );

            // Insert combined node into heap
            minHeap.push(parent);
        }

        // Remaining node is the root
        root = minHeap.top();

        // Generate binary codes
        codes.clear();

        generateCodes(root, "");
    }


    // ========================================
    // 6. DISPLAY CHARACTER FREQUENCIES
    // ========================================

    void displayFrequency() {

        cout << "\nCharacter Frequencies:\n";

        for (auto& item : frequency) {

            cout << item.first
                 << " : "
                 << item.second << endl;
        }
    }


    // ========================================
    // 7. DISPLAY HUFFMAN CODES
    // ========================================

    void displayCodes() {

        cout << "\nHuffman Codes:\n";

        for (auto& item : codes) {

            cout << item.first
                 << " : "
                 << item.second << endl;
        }
    }


    // ========================================
    // 8. ENCODING
    // ========================================

    string encode(const string& text) {

        string encoded = "";

        for (unsigned char ch : text) {

            auto it = codes.find(ch);

            if (it == codes.end()) {

                throw runtime_error(
                    "Character not found in Huffman table"
                );
            }

            encoded += it->second;
        }

        return encoded;
    }


    // ========================================
    // 9. DECODING
    // ========================================

    string decode(const string& encoded) {

        if (root == nullptr) {

            if (encoded.empty())
                return "";

            throw runtime_error("Empty Huffman tree");
        }

        string decoded = "";

        // Special case: only one unique character
        if (root->isLeaf()) {

            for (char bit : encoded) {

                if (bit != '0')
                    throw runtime_error("Invalid encoded bit");

                decoded += static_cast<char>(root->ch);
            }

            return decoded;
        }

        auto current = root;

        for (char bit : encoded) {

            // Follow left or right edge
            if (bit == '0') {

                current = current->left;
            }
            else if (bit == '1') {

                current = current->right;
            }
            else {

                throw runtime_error(
                    "Encoded data must contain only 0 and 1"
                );
            }

            if (current == nullptr) {

                throw runtime_error(
                    "Invalid Huffman bitstream"
                );
            }

            // Character found at leaf
            if (current->isLeaf()) {

                decoded +=
                    static_cast<char>(current->ch);

                // Return to root for next character
                current = root;
            }
        }

        // Make sure the bitstream ended at a leaf
        if (current != root) {

            throw runtime_error(
                "Incomplete Huffman bitstream"
            );
        }

        return decoded;
    }


    // ========================================
    // 10. DISPLAY ORIGINAL AND COMPRESSED SIZE
    // ========================================

    void displayCompression(
        const string& original,
        const string& encoded) {

        int originalBits = original.size() * 8;

        int compressedBits = encoded.size();

        cout << "\nCompression Information:\n";

        cout << "Original size (8-bit bytes): "
             << originalBits << " bits\n";

        cout << "Encoded size (bitstream): "
             << compressedBits << " bits\n";

        if (originalBits > 0) {

            double percentage =
                (double)(originalBits - compressedBits)
                / originalBits * 100.0;

            cout << "Space reduction: "
                 << percentage << "%\n";
        }
    }

};


// ============================================
// 11. MAIN FUNCTION
// ============================================

int main() {

    try {

        Huffman huffman;

        string message;

        cout << "Enter original message: ";

        getline(cin, message);

        // STEP 1: Calculate frequencies
        huffman.calculateFrequency(message);

        huffman.displayFrequency();

        // STEP 2: Construct Huffman tree
        huffman.buildTree();

        // STEP 3: Generate and display codes
        huffman.displayCodes();

        // STEP 4: Encode original message
        string encoded = huffman.encode(message);

        cout << "\nEncoded Message:\n";

        cout << encoded << endl;

        // STEP 5: Display compression information
        huffman.displayCompression(message, encoded);

        // STEP 6: Decode encoded message
        string decoded = huffman.decode(encoded);

        cout << "\nDecoded Message:\n";

        cout << decoded << endl;

        // STEP 7: Verify original and decoded messages
        if (message == decoded) {

            cout << "\nDecoding Successful!\n";

            cout << "Original and decoded messages match.\n";
        }
        else {

            cout << "\nDecoding Failed!\n";
        }

    }

    catch (const exception& e) {

        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}














