// The Dutch National Flag algorithm is a clever way to sort an array of three different types of elements—like
// 0s, 1s, and 2s—in just a single pass. Created by computer scientist Edsger Dijkstra, it is named after the
// Dutch flag because it groups similar elements together into three distinct blocks, just like the flag's 
// three horizontal stripes. Instead of using slow sorting methods, it uses three pointers (low, mid, and high)
// to scan the list from left to right. As it scans, it instantly throws all 0s to the far left, leaves 1s 
// in the middle, and pushes all 2s to the far right. This allows the algorithm to sort the entire 
// collection in one quick go without using extra memory, making it incredibly fast and efficient.





// The Core Idea : 
// Three groups: Sorts elements into three distinct zones
// Three pointers: Tracks the boundaries of each zone.
// One pass: Loops through the data exactly once.
// Zero extra space: Swaps elements directly in place.





// The logic on repeat 
// See a 0? Swap it with low. Move low and mid forward.
// See a 1? Leave it alone. Just move mid forward.
// See a 2? Swap it with high. Move high backward.


