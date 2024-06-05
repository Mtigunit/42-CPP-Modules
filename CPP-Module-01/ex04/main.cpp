#include <string>
#include <fstream>
#include <iostream>

void usage( void ) {
    std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
    std::cout << "Replace occurrences of s1 with s2 in the file <filename>." << std::endl;
}

int	main( int argc, char **argv ) {
	(void)argv;
	if (argc != 4) {
		std::cout << "Error: Number of argument is incorrect!" << std::endl;
		usage();
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "Error: cannot open intputFile." << std::endl;
        return (1);
	}
	std::ofstream outputFile(std::strcat(argv[1], ".replace"));
	if (!outputFile.is_open()) {
		std::cout << "Error: cannot create outputFile." << std::endl;
        return (1);
	}
	std::string	line;
	while (getline(inputFile, line)) {
		std::size_t pos = line.find(s1);
		if (pos != std::string::npos) {
			line.erase(pos, s1.length()).insert(pos, s2);
		}
		outputFile << line;
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	outputFile.close();
	inputFile.close();
	return (0);
}
