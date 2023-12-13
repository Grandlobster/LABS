#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    std::ofstream outputFile("test.txt");
    std::cout << "New file successfully created!\n";
    std::cout << "" << std::endl;

    if (!outputFile.is_open())
    {
        std::cerr << "Error opening the file for writing.\n";
        return 1;
    }

    outputFile << "This line is written in test.txt\n";
    outputFile << "This is another line from that file.\n";

    outputFile.close();

    std::ifstream inputFile("test.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file for reading.\n";
        return 1;
    }

    std::cout << "Now reading from the file:\n";
    std::string line;
    while (getline(inputFile, line))
    {
        std::cout << line << "\n";
    }

    inputFile.close();
    return 0;
}