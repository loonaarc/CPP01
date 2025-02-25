#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool safeGetLine(std::ifstream&stream, std::string& line) {
    if (!std::getline(stream, line)) {
        std::cerr << "Error while getting input. Byebye!";
        std::exit(EXIT_FAILURE);
    }
    return true;
}

std::string replace(const std::string original, const std::string & oldStr, const std::string& newStr) {
    std::string replaced;
    int currentPos = 0;
    size_t foundPos;
    int oldLength = oldStr.size();

    while ((foundPos = original.find(oldStr, currentPos)) != std::string::npos) {//npos = return value for find if no match
        replaced.append(original, currentPos, foundPos);

        replaced += newStr;

        currentPos = foundPos + oldLength;
    }

    replaced += original.substr(currentPos);

    return replaced;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Wrong number of arguments. Execute like this: ./sed_is_for_losers [filename] [string_to_replace] [string_to_replace_with]\n";
        return (1);
    }

    std::ifstream input_stream(argv[1]);
    if (!input_stream) { //implicit conversion to bool
        std::cout << "bad file\n";
        return (1);
    }

    std::string line;
    std::string buffer;
    while (safeGetLine(input_stream, line)) {
        buffer += line + "\n";
    }
    input_stream.close();

    std::string replaced = replace(buffer, argv[2], argv[3]);


    std::string filename = argv[1];
    filename.append(".replace");
    std::ofstream outputStream(filename.c_str());
    if (!outputStream) {
        std::cout << "bad output file";
        return (1);
    }

    outputStream << replaced;

    outputStream.close();



}