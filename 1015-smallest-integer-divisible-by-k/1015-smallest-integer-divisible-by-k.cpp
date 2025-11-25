class Solution {
public:
    int smallestRepunitDivByK(int k) {
          if (k % 2 == 0 || k % 5 == 0) {
        return -1; // Return -1 as per problem requirements
    }

    int remainder = 0; // Initialize remainder to 0. This will store the current '1's number modulo k.
    int length = 0;    // Initialize length to 0. This counts the number of '1's.

    // A set to store remainders seen so far.
    // This helps detect cycles. If we encounter a remainder we've seen before,
    // it means we are in an infinite loop and no solution exists within k iterations.
    set<int> seen_remainders;

    // The loop continues as long as the remainder is not 0.
    // The Pigeonhole Principle guarantees that if a solution exists, it will be found within k iterations.
    // If a remainder repeats before reaching 0, it means no solution exists.
    while (remainder != 0 || length == 0) { // Keep going until remainder is 0 (found solution) or if length is 0 (first iteration)
        length++; // Increment the length of the number '1...1'
        
        // Calculate the next number composed of '1's modulo k.
        // It's equivalent to (remainder * 10 + 1) % k.
        // For example:
        // If remainder = 0, next_remainder = (0 * 10 + 1) % k = 1 % k
        // If remainder = 1 % k, next_remainder = ( (1 % k) * 10 + 1) % k = 11 % k
        remainder = (remainder * 10 + 1) % k;

        // If the current remainder is 0, we found a number '1...1' divisible by k.
        if (remainder == 0) {
            return length; // Return the current length
        }

        // Check if we've seen this remainder before.
        // If we have, it means we're in a cycle, and no solution exists.
        if (seen_remainders.count(remainder)) {
            return -1; // Return -1, indicating no solution
        }
        
        // Add the current remainder to the set of seen remainders.
        seen_remainders.insert(remainder);

        // Optimization: According to the Pigeonhole Principle, if a solution exists,
        // it must have a length at most k. If we exceed k iterations and haven't found a solution,
        // it means no solution exists. This also prevents infinite loops if the set check somehow fails
        // or for larger k where the set might get very large, though the set approach is more robust.
        if (length > k) {
            return -1;
        }
    }

    return -1;
    }
};