#include"subFunction.hpp"

bool createDirectory(const std::string& path) {
#ifdef _WIN32
    if (_mkdir(path.c_str()) != 0) {
#else
    if (mkdir(path.c_str(), 0777) != 0) {
#endif
        std::cerr << "Error creating directory: " << path << std::endl;
        return false;
    }
    return true;
}