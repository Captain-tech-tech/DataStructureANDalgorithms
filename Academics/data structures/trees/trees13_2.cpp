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









// C++ implementation
// unordered_map to store character frequencies and codes.
// priority_queue to select the two smallest frequency nodes.
// A binary tree to represent Huffman codes.
// Recursion to generate codes.
// Tree traversal to decode the encoded bitstream.
// The priority_queue will work as a min-heap, so the node with the smallest frequency is always available at the top.





















