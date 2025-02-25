#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

/**
takes the string original
looks for strings like oldStr
replaces them with newStr
and appends everything to the string replaced and returns it
*/
std::string replace(const std::string original, const std::string & oldStr, const std::string& newStr) {
    std::string replaced;
    size_t searchPos = 0;
    size_t foundPos;
    size_t oldLength = oldStr.size();

    while ((foundPos = original.find(oldStr, searchPos)) != std::string::npos) {//npos = return value for find if no match
        replaced.append(original, searchPos, foundPos);
        replaced += newStr;
        searchPos = foundPos + oldLength;
    }
    replaced += original.substr(searchPos);
    return replaced;
}

/**
attempts to read a line from stream and safe it to line.
Distinguishes between different kind of errors
Exits on bad read.
*/
bool safeGetLine(std::ifstream&stream, std::string& line) {
	if (stream.eof()) {
		return false;
	}

	if (std::getline(stream, line)) {
		return true;
	} else {
		if (stream.fail()) {
			std::cerr << "A data format or EOF after attempting a read occured. ";
		} else if (stream.bad()) {
			std::cerr << "An error while reading the data occured. ";
		} else {
			std::cerr << "An unknown error occured. ";
		}
		std::cerr << "Byebye! \n";
		std::exit(EXIT_FAILURE);
	}
	return false;
}


std::string readFile(std::string filename) {
	std::ifstream inputStream(filename.c_str());
	std::string line;
	std::string buffer;

    if (!inputStream) { //implicit conversion to bool
        std::cerr << "Error! could not open file: " << filename << "\n";
        std::exit (EXIT_FAILURE);
    }
    while (safeGetLine(inputStream, line)) {
        buffer += line + "\n";
    }
    inputStream.close();
	return buffer;
}

void writeFile(std::string filename, std::string replaced) {
    filename.append(".replace");
    std::ofstream outputStream(filename.c_str());
    if (!outputStream) {
        std::cerr << "Error! could not open file: " << filename << "\n";
        std::exit (EXIT_FAILURE);
    }
    outputStream << replaced;
    outputStream.close();

}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Wrong number of arguments. Execute like this: ./sed_is_for_losers [filename] [string_to_replace] [string_to_replace_with]\n";
        return (1);
    }
    std::string buffer = readFile(argv[1]);
    std::string replaced = replace(buffer, argv[2], argv[3]);
	writeFile(argv[1], replaced);
}
