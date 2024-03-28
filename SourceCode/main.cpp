#include"consoleView.h"
#include"user.hpp"
#include<stdlib.h>
#include"semester.hpp"
#include"schoolyear.hpp"
#include"GeneralClass.hpp"


int main() {
	Semester curSemester;
	string curYear;
	string curClass;
START:
	Users user;
	programInterface();
	int choice;
	std::cin >> choice;
	if (choice == 0)
		return 0;
	system("cls");
CHOOSEROLE:
	chooseRole();
	std::cin >> choice;
	system("cls");
	switch (choice) {
	case 0:
		return 0;
	case 1:
		user.isStaff = true;
		break;
	case 2:
		user.isStaff = false;
		break;
	default:
		system("cls");
		goto CHOOSEROLE;
	}
	system("cls");
LOGIN:
	if(!user.login()) {
		system("cls");
		std::cerr << "Wrong password or username!" << std::endl;
	LOGINFAIL:
		loginFail();
		std::cin >> choice;
		system("cls");
		switch (choice) {
		case 0:
			goto CHOOSEROLE;
		case 1:
			goto LOGIN;
		default:
			goto LOGINFAIL;
		}
	}
	if (user.isStaff)
		goto STAFFMENU;
	else
		goto STUDENTMENU;
STAFFMENU:
	staffMainMenu(user.Username);
	std::cin >> choice;
	switch (choice) {
	case 0:
		goto START;
	case 1:
	CREATEYEAR:
		system("cls");
		std::cout << "What schoolYear do you want to create (Ex:202x-202y): " << std::endl;
		cin >> curYear;
		system("cls");
		if (!year_exits(curYear)) {
			createSchoolYearFail();
			while (std::cin >> choice) {
				system("cls");
				inputSchoolYearFail();
				if (choice == 0)
					goto STAFFMENU;
				if (choice == 1)
					goto CREATEYEAR;
			}
		}
		create_School_year(curYear);
		system("cls");
		goto STAFFMENU;
	case 2:
	INPUTYEAR:
		system("cls");
		std::cout << "What schoolYear do you want to edit: "<< std::endl;
		listSchoolYear();
		std::cout << "\n Your choice (Ex:202x-202y): ";
		cin >> curYear;
		system("cls");
		if (year_exits(curYear)) {
			inputSchoolYearFail();
			while (std::cin >> choice) {
				system("cls");
				inputSchoolYearFail();
				if (choice == 0)
					goto STAFFMENU;
				if (choice == 1)
					goto INPUTYEAR;
			}
		}
		system("cls");
		goto EDITSCHOOLYEAR;
	case 3:
		system("cls");
		while (!user.changePassword()) {
			changePasswordFail();
			while (std::cin >> choice) {
				if (choice == 0) {
					system("cls");
					goto STAFFMENU;
				}
				if (choice == 1)
					break;
			}
		}
		break;
	case 4:
		system("cls");
		user.viewProfileInfo();
		std::cout << "Enter to continue" ;
		std::cin.get();
		std::cin.get();
		break;
	default:
		break;
	}
	system("cls");
	goto STAFFMENU;
EDITSCHOOLYEAR:
	editSchoolYearMenu();
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 0:
		goto LOGIN;
	case 1:
		goto GENERALCLASS;
	case 2:
		goto SEMESTER;
	case 3:
		goto INPUTYEAR;
	case 4:
		goto STAFFMENU;
	default:
		goto EDITSCHOOLYEAR;
	}
GENERALCLASS:
	generalClassMenu();
	cin >> choice;
	switch (choice)
	{
	case 0:
		system("cls");
		goto LOGIN;
	case 1:
	CREATECLASS:
		system("cls");
		std::cout << "What general class do you want to create (Ex:20CLC04) : " << std::endl ;
		cin >> curClass;
		system("cls");
		if (class_existed(curYear, curClass)) {
			createClassFail();
			while (std::cin >> choice) {
				system("cls");
				createClassFail();
				if (choice == 0) {
					system("cls");
					goto GENERALCLASS;
				}
				if (choice == 1)
					goto CREATECLASS;
			}
		}
		create_General_class(curYear, curClass);
		system("cls");
		goto GENERALCLASS;
	case 2:
	INPUTCLASS:
		system("cls");
		std::cout << "What general class do you want to edit: " << std::endl;
		view_list_of_general_class(curYear);
		std::cout << "\n Your choice(Ex:20CLC04): ";
		cin >> curClass;
		system("cls");
		if (!class_existed(curYear, curClass)) {
			inputClassFail();
			while (std::cin >> choice) {
				system("cls");
				inputClassFail();
				if (choice == 0) {
					system("cls");
					goto EDITSCHOOLYEAR;
				}
				if (choice == 1)
					goto INPUTCLASS;
			}
		}
		system("cls");
		goto EDITGENERALCLASS;
	case 3:
		system("cls");
		goto STAFFMENU;
	case 4:
		goto EDITSCHOOLYEAR;
	default:
		system("cls");
		goto GENERALCLASS;
	}
EDITGENERALCLASS:
	editGeneralClassMenu();
	cin >> choice;
	switch (choice)
	{
	case 0:
		system("cls");
		goto LOGIN;
	case 1:
		//update in4
	case 2:
		list_of_student(curYear, curClass);
		break;
	case 3:
		//import
	case 4:
		//add1
	case 5:
		system("cls");
		goto INPUTCLASS;
	case 6:
		system("cls");
		goto STAFFMENU;
	default:
		break;
	}
	system("cls");
	goto EDITGENERALCLASS;
SEMESTER:
	semesterMainMenu();
	cin >> choice;
	switch (choice) {
	case 0:
		goto START;
	case 1:
	CREATESEMESTER:
		system("cls");
		std::cout << "What semester do you want to create: " ;
		cin >> curSemester.semester_num;
		system("cls");
		if (checkSemester(curYear, curSemester.semester_num)) {
			inputSemesterFail();
			while (std::cin >> choice) {
				system("cls");
				inputSemesterFail();
				if (choice == 0)
					goto SEMESTER;
				if (choice == 1)
					goto CREATESEMESTER;
			}
		}
		curSemester.createSemester(curYear, curSemester.semester_num);
		system("cls");
		goto SEMESTER;
	case 2:
		//editSemester
	case 3:
		system("cls");
		goto EDITSCHOOLYEAR;
	case 4:
		system("cls");
		goto STAFFMENU;
	default:
		system("cls");
		goto SEMESTER;
		break;
	}

STUDENTMENU:
	
	std::cout << "student is here";
	return 0;
}

