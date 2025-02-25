#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "I only take 3 arguments in this format: ./sed_is_for_losers [filename] [s1] [s2]\nTry again. Byebye!\n";
		return(1);
	}
	std::ifstream input_file(argv[1]);
	if (!input_file)
		std::cout << "bad file\n";
}