#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
bool isCommentLine(const std::string& line) {
    // Remove leading whitespace
    std::string trimmedLine = line;
    trimmedLine.erase(trimmedLine.begin(), std::find_if(trimmedLine.begin(), trimmedLine.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    // Check if the line starts with // or is a block comment
    return trimmedLine.empty() || trimmedLine.find("//") == 0 || trimmedLine.find("/*") == 0 || trimmedLine.find("*") == 0;
}
bool isEmptyLine(const std::string& line) {
    // Check if the line is empty or contains only whitespace
    return line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
}
bool containsCode(const std::string& line) {
    // Check if the line contains any non-comment code
    std::string trimmedLine = line;
    trimmedLine.erase(trimmedLine.begin(), std::find_if(trimmedLine.begin(), trimmedLine.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    // Remove comments from the line
    size_t commentPos = trimmedLine.find("//");
    if (commentPos != std::string::npos) {
        trimmedLine = trimmedLine.substr(0, commentPos);
    }
    // Check if the remaining line is not empty
    return !trimmedLine.empty();
}
int countCodeLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return -1;
    }
    int codeLineCount = 0;
    std::string line;
    bool inBlockComment = false;
    while (std::getline(file, line)) {
        if (inBlockComment) {
            // Check if the block comment ends in this line
            size_t blockCommentEnd = line.find("*/");
            if (blockCommentEnd != std::string::npos) {
                inBlockComment = false;
                line = line.substr(blockCommentEnd + 2);
            } else {
                continue; // Skip the entire line if it's still in a block comment
            }
        }
        // Check if the line starts a block comment
        size_t blockCommentStart = line.find("/*");
        if (blockCommentStart != std::string::npos) {
            inBlockComment = true;
            line = line.substr(0, blockCommentStart);
        }
        // Skip empty lines and comment-only lines
        if (isEmptyLine(line) || isCommentLine(line)) {
            continue;
        }
        // Check if the line contains code
        if (containsCode(line)) {
            codeLineCount++;
        }
    }
    file.close();
    return codeLineCount;
}
int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    int codeLines = countCodeLines(filename);
    if (codeLines != -1) {
        std::cout << "Number of code lines: " << codeLines << std::endl;
    }
    return 0;
}