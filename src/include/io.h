#pragma once

#include <fstream>
#include <string>

class Io {
public:
    Io();

    void read_file(const std::string& file_name);
    std::string get_file_contents();

private:
    std::string file_contents;

};
