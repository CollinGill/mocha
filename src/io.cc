#include "include/io.h"
#include <string>

Io::Io() 
{
    this->file_contents = "";
}

void Io::read_file(const std::string& file_name)
{
    std::ifstream stream(file_name);
    std::string str;

    while (std::getline(stream, str)) {
        this->file_contents.append(str);
        this->file_contents.push_back('\n');
    }
}

std::string Io::get_file_contents()
{
    return this->file_contents;
}
