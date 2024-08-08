#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "ERROR: Not enough aruments\n";
        return 1;
    }

    std::string file_name = std::string(argv[1]);
    if (!file_name.ends_with(".mocha")) {
        std::cerr << "ERROR: " << file_name << " is not a valid Mocha file\n";
        return 1;
    }

    return 0;
}
