#include <stdio.h>

// Define a struct Batu to store alphabets
struct Batu {
    char abjad;   // Store an alphabet in the stone
    struct Batu *link;   // Pointer to the next stone in the sequence
};

int main() {
    // Initialize stones with the given alphabets
    struct Batu l1 = {'F', NULL};
    struct Batu l2 = {'M', NULL};
    struct Batu l3 = {'A', NULL};
    struct Batu l4 = {'I', NULL};
    struct Batu l5 = {'K', NULL};
    struct Batu l6 = {'T', NULL};
    struct Batu l7 = {'N', NULL};
    struct Batu l8 = {'O', NULL};
    struct Batu l9 = {'R', NULL};

    // Set up the connections between the stones as per the given sequence
    l7.link = &l1;
    l1.link = &l8;
    l8.link = &l2;
    l2.link = &l5;
    l5.link = &l3;
    l3.link = &l6;
    l6.link = &l9;
    l9.link = &l4;
    l4.link = &l7;

    // Access the alphabets in the stones using l3 as the starting point
    printf("%c %c %c %c %c %c %c %c %c %c %c\n",
        l3.link->link->link->abjad,  // Output: "I"
        l3.link->link->link->link->abjad,  // Output: "N"
        l3.link->link->link->link->link->abjad,  // Output: "F"
        l3.link->link->link->link->link->link->abjad,  // Output: "O"
        l3.link->link->abjad,  // Output: "R"
        l3.link->link->link->link->link->link->link->abjad,  // Output: "M"
        l3.abjad,  // Output: "A"
        l3.link->abjad,  // Output: "T"
        l3.link->link->link->abjad,  // Output: "I"
        l3.link->link->link->link->link->link->link->link->abjad,  // Output: "K"
        l3.abjad   // Output: "A"
    );

    return 0;
}