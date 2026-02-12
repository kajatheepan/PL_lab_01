#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream inputFile("input.txt"); // Ensure "input.txt" exists in the program's working directory
    std::string line;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
                std::stringstream ss(line); // Create a stringstream from the line
    std::string word;
    std::vector<std::string> words;

    // Read words from the stringstream until there are no more words
    while (ss >> word) {
        words.push_back(word);
    }

    // Print the separated words
    std::cout << "Words separated:" << std::endl;
    for (const std::string& w : words) {
        std::cout << w << std::endl;
    }
        }
        inputFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
        return 1;
    }

    return 0;
}
