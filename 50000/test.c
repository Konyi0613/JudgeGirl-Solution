#include <stdio.h>
#include <stdbool.h>

int main()
{
    int k, input;
    scanf("%d", &k); // Read k

    int pos = 0;                 // Tracks position in the input
    int sign = 0;                // Tracks current sign: 1 (positive), -1 (negative)
    int conti = 0;               // Tracks consecutive k numbers
    int alternating = 0;         // Alternating sequence counter
    int head = -1;               // Start position of a valid sequence
    int max_length = 0;          // Tracks the maximum length of a k-alternating sequence
    bool valid_sequence = false; // Flag to track ongoing valid sequence

    // Read input numbers until 0 is encountered
    while (scanf("%d", &input) != EOF)
    {
        if (input == 0) // Input termination
        {
            if (valid_sequence && alternating >= 3)
            {
                int length = pos - head;
                if (length > max_length)
                    max_length = length;
            }
            printf("%d\n", max_length);
            break;
        }

        // Handle the first positive k block
        if (!valid_sequence)
        {
            if (input > 0)
            {
                conti++;
                if (conti == k) // First valid k positives found
                {
                    head = pos - k + 1; // Start position of sequence
                    sign = -1;          // Next block must be negative
                    alternating = 1;
                    valid_sequence = true;
                    conti = 0;
                }
            }
            else
                conti = 0; // Reset if we encounter a negative before k positives
        }
        else
        {
            // Inside a valid sequence: check for alternating k blocks
            if (input * sign > 0) // Current input matches expected sign
            {
                conti++;
                if (conti == k) // Completed a k block
                {
                    alternating++;
                    sign *= -1; // Flip sign for next block
                    conti = 0;
                }
            }
            else // Invalid input for current block
            {
                if (alternating >= 3)
                {
                    int length = pos - head;
                    if (length > max_length)
                        max_length = length;
                }

                // Reset and search for a new valid sequence
                valid_sequence = false;
                conti = (input > 0) ? 1 : 0; // Start counting again
                head = (input > 0) ? pos : -1;
                sign = (input > 0) ? -1 : 0;
                alternating = (input > 0) ? 1 : 0;
            }
        }
        pos++; // Increment position
    }
    return 0;
}
