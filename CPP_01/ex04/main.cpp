#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inFile(argv[1], std::ifstream::in);

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str(), std::ifstream::out);

	std::string line;
	std::string content;
	while (getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	outFile << content;

	inFile.close();
	outFile.close();
}