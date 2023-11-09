#include <iostream>
#include <fstream>
#include <string>

std::string reader(char *s) {
	std::string str(s);
	std::string line;
	std::string content;
	std::ifstream in(s);
	if (in.is_open())
	{
		while (std::getline(in, line))
			content += line + "\n";
	}
	in.close();
	return content;
}

void writer(std::string content, char *file, char *occurrence, char *changer) {
	std::string out_file(file);
	std::string occur(occurrence);
	std::string change(changer);
	std::ofstream out((out_file + ".replace").c_str());
    unsigned long long i = 0;
    while(content[i] != '\0') {
        if (content.find(occur, i) != std::string::npos && content.substr(i, occur.length()) == occur) {
            out << change;
            i += occur.length();
        }
        else {
            out << content[i];
            i += 1;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4)
    {
        std::cout << "Wrong arguments" << std::endl;
        return 1;
    }
	std::string content;
	content = reader(argv[1]);
	writer(content, argv[1], argv[2], argv[3]);
	return 0;
}
