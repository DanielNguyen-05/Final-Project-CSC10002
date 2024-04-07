#include <iostream>
#include <string>
#include<fstream>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

bool createDirectory(const std::string& path);
void createBasicData();