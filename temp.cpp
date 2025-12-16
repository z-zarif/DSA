#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
 * ONLINE 1: Packet Class Implementation
 * ===========================================
 *
 * TASK: Implement the Packet class to work with the given main() function.
 * Study the main() function carefully to understand what methods and constructors
 * your class needs to provide.
 *
 * IMPORTANT RULES:
 * ---------------
 * DO NOT modify ANY code in the main() function
 * DO NOT modify the testFunction() function
 * ONLY implement code inside the Packet class
 * You may include other standard headers if needed
 *
 * DYNAMIC MEMORY REQUIREMENT:
 * --------------------------
 * Your Packet class must use dynamic memory allocation to store character data.
 * - Allocate and deallocate memory properly
 *
 * DYNAMIC MEMORY OPERATIONS:
 * -------------------------
 * To allocate memory dynamically:
 *     char* buffer = (char*)malloc(size * sizeof(char));
 * To reallocate memory dynamically:
 *     buffer = (char*)realloc(buffer, newSize * sizeof(char));
 *
 * To deallocate memory:
 *     free(buffer);
 *
 * DESIGN HINTS:
 * ------------
 * - Look at how Packet objects are created in main()
 * - Notice the different ways add() is called
 * - Pay attention to the expected console output format
 * - Consider what member variables you'll need for dynamic memory
 * - Think about memory management and capacity expansion
 *
 * Study the expected console output format shown in the main() function comments.
 * Your program's output MUST EXACTLY MATCH the Expected Console Output.
 *
 * Submission Instructions:
 * ------------------------
 * - Implement the Packet class below
 * - Ensure your code compiles and runs correctly with the provided main() function
 * - Do not change any other part of the code
 * - Submit only this file for evaluation
 * - The name of the file should be [YourID].cpp
 * - No need to zip the file, submit the .cpp file directly
 */

class Packet
{

    char *buffer;
    int size;
    int capacity;
    // buffer=new char[5];
    void checkcapacity(int newsize)
    {
        if (newsize + 1 > capacity)
        {
            capacity = newsize + 1;
            buffer = (char *)realloc(buffer, capacity * sizeof(char));
        }
    }

public:
    Packet()
    {
        size = 0;
        capacity = 1;
        buffer = (char *)malloc(capacity * sizeof(char));
        buffer[0] = '\0';
    };
    Packet(char *strmain)
    {
        size = strlen(strmain);
        capacity = size + 1;
        buffer = (char *)malloc(capacity * sizeof(char));
        strcpy(buffer, strmain);
    };
    void add(char c)
    {
        checkcapacity(size + 1);
        buffer[size++] = c;
        buffer[size] = '\0';
    }
    void add(char *temp)
    {
        int tempsize = strlen(temp);
        checkcapacity(tempsize + size);
        strcpy(buffer+size,temp);
        size += tempsize;
    }
    void show()
    {
        cout << buffer << endl;

    }
    ~Packet()
    {
        free(buffer);
    }
};

void testFunction()
{
    cout << "--- Inside testFunction ---" << endl;

    char arr[] = "TEMP";
    char arr2[] = "TEST-";
    char arr3[] = "YZ";

    Packet temp1; // temporary packet
    temp1.add(arr);
    temp1.show(); // prints: Packet content: TEMP

    Packet temp2(arr2);
    temp2.add('X');
    temp2.add(arr3);
    temp2.show(); // prints: Packet content: TEST-XYZ

    cout << "--- Leaving testFunction ---" << endl;
    // temp1 and temp2 will be destroyed here
}

int main()
{

    // EXPECTED CONSOLE OUTPUT:
    // --------------------------------
    // Empty packet created
    // Packet content: HELLO
    // --- Inside testFunction ---
    // Empty packet created
    // Packet content: TEMP
    // Packet with initial content created
    // Packet content: TEST-XYZ
    // --- Leaving testFunction ---
    // Packet destroyed
    // Packet destroyed
    // Packet with initial content created
    // Packet content: DATA-123
    // Packet destroyed
    // Packet destroyed
    // --------------------------------

    char arr[] = "DATA-";
    char arr2[] = "123";
    char arr3[] = "ELLO";

    Packet p1; // empty dynamic buffer
    p1.add('H');
    p1.add(arr3); // now contains HELLO
    p1.show();    // prints: Packet content: HELLO

    testFunction(); // call function that creates temporary objects

    Packet p2(arr);
    p2.add(arr2);
    p2.show(); // prints: Packet content: DATA-123

    return 0;
}