#include"subFunction.hpp"

bool createDirectory(const std::string& path) {
#ifdef _WIN32
    if (_mkdir(path.c_str()) != 0) {
#else
    if (mkdir(path.c_str(), 0777) != 0) {
#endif
        return false;
    }
    return true;
}
void createBasicData() {
	createDirectory("Data");
	createDirectory("Data/Account");
	createDirectory("Data/Account/AcademicStaff");
	createDirectory("Data/Account/Student");
	createDirectory("Data/GeneralClasses");
	std::ifstream fIn("Data/SchoolYear.txt");
	if (!fIn.is_open()) {
		std::ofstream fOut("Data/SchoolYear.txt");
		fOut.close();
	}
	else
		fIn.close();

	fIn.open("Data/Account/AcademicStaff/admin.txt");
	if (!fIn.is_open()) {
		std::ofstream fOut("Data/Account/AcademicStaff/adminaccount.txt");
		fOut << "adminaccount\n";
		fOut.close();
	}
	else
		fIn.close();

}