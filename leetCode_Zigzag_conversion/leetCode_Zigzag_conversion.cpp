// leetCode_Zigzag_conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    int sSize = s.size();
    std::string res;
    std::vector<std::string> rows(std::min(numRows, sSize));

    int currentRow = 0;
    bool goingDown = false;


    for (char c : s) {
        rows[currentRow] += c;

        if (currentRow == 0 || currentRow == numRows - 1)
            goingDown = !goingDown;

        currentRow += goingDown ? 1 : -1;
    }

    for (const std::string& row : rows) {
        res += row;
    }

    return res;
}


int main()
{
    std::cout << convert("ABCDEF", 4) << std::endl;
    std::cout << "PAHNAPLSIIGYIR" << std::endl;
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
