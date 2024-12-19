// leetCode_Zigzag_conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

std::string convert(std::string s, int numRows) {
    if (numRows == 1)
        return s;
    char** m = (char**)malloc(numRows * sizeof(char*));
    int stepRow = 1;
    int stepCol = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int v = 1;
    int sSize = s.size();
    while (count < sSize) {
        if (v)
            m[i] = (char*)malloc(sSize * sizeof(char));
        m[i][j] = s[count];
        if (i == numRows - 1)
        {
            stepRow = -1;
            stepCol = 1;
            v = 0;
        }
        if (i == 0)
        {
            stepRow = 1;
            stepCol = 0;
        }
        count++;
        i += stepRow;
        j += stepCol;
    }
    std::string res;
    for (int i = 0; i < numRows && i < sSize; i++)
    {
        for (int z = 0; z <= j; z++)
        {
            if (m[i][z] == '.' || m[i][z] == ',' || toupper(m[i][z]) < 96 && toupper(m[i][z]) > 64)
            {
                res += m[i][z];
            }
        }
        free(m[i]);
    }
    free(m);
    return res;

}

int main()
{
    std::cout << convert("PAYPALISHIRING", 3);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
