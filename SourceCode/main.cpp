#include "consoleView.hpp"
#include "user.hpp"
#include "semester.hpp"
#include "schoolyear.hpp"
#include "generalClass.hpp"
#include "course.hpp"
#include "studentControl.hpp"
#include <stdlib.h>

int main() {
	Semester curSemester;
	std::string curYear;
	std::string curClass;
	Course curCourse;
	std::string path;
	Student curStudent;
	StudentControl curStudentControl;
	createBasicData();

START:
	system("cls");
	Users user;
	user.Username = "";
	user.Password = "";
	programInterface();
	int choice;
	std::cin >> choice;
	if (choice == 0)
		return 0;
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
			goto START;
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
		system("pause");
		goto START;
	case 1:
	CREATEYEAR:
		system("cls");
		std::cout << "]\tWhat school year do you want to create (Ex:2023-2024): ";
		cin >> curYear;
		system("cls");
		if (!yearExisted(curYear)) {
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
		createSchoolYear(curYear);
		system("cls");
		goto STAFFMENU;
	case 2:
	INPUTYEAR:
		system("cls");
		std::cout << "\tWhat school year do you want to edit: " << std::endl;
		listSchoolYear();
		std::cout << "\n- Your choice (Ex:2023-2024): ";
		cin >> curYear;
		system("cls");
		if (yearExisted(curYear)) {
			inputSchoolYearFail();
			while (std::cin >> choice) {
				system("cls");
				inputSchoolYearFail();
				if (choice == 0) {
					system("cls");
					goto STAFFMENU;
				}
				if (choice == 1) {
					system("cls");
					goto INPUTYEAR;
				}
			}
		}
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
				if (choice == 1) {
					system("cls");
					break;
				}
			}
		}
		system("pause");
		break;
	case 4:
		system("cls");
		user.viewProfileInfo();
		system("pause");
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
		goto START;
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
		goto START;
	case 1:
	CREATECLASS:
		system("cls");
		std::cout << "\tWhat general class do you want to create (Ex: 20CLC04) : " ;
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
				if (choice == 1) {
					system("cls");
					goto CREATECLASS;
				}
			}
		}
		createGeneralClass(curYear, curClass);
		system("cls");
		goto GENERALCLASS;
	case 2:
	INPUTCLASS:
		system("cls");
		std::cout << "\tWhat general class do you want to edit: " <<std::endl;
		viewListOfGeneralClass(curYear);
		std::cout << "\n- Your choice (Ex: 20CLC04): ";
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
		goto START;
	case 1:
		listOfStudent(curYear, curClass);
		break;
	case 2:
		importStudent(curYear, curClass);
		break;
	case 3:
		addOneStudentToClass(curYear, curClass);
		break;
	case 4:
		system("cls");
		goto INPUTCLASS;
	case 5:
		system("cls");
		goto STAFFMENU;
	default:
		break;
	}
	system("cls");
	goto EDITGENERALCLASS;
SEMESTER:
	system("cls");
	semesterMainMenu();
	cin >> choice;
	switch (choice) {
	case 0:
		goto START;
	case 1:
	CREATESEMESTER:
		system("cls");
		std::cout << "\tWhat semester do you want to create: " ;
		cin >> curSemester.semester_num;
		system("cls");
		if (checkSemester(curYear, curSemester.semester_num)) {
			createSemesterFail();
			while (std::cin >> choice) {
				system("cls");
				createSemesterFail();
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
	INPUTSEMESTER:
		system("cls");
		std::cout << "\tWhat semester do you want to edit: ";
		cin >> curSemester.semester_num;
		system("cls");
		if (!checkSemester(curYear, curSemester.semester_num)) {
			inputSemesterFail();
			while (std::cin >> choice) {
				system("cls");
				inputSemesterFail();
				if (choice == 0)
					goto SEMESTER;
				if (choice == 1)
					goto INPUTSEMESTER;
			}
		}
		curSemester.loadSemesterData(curYear, curSemester.semester_num);
		goto EDITSEMESTER;
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
EDITSEMESTER:
	editSemesterMenu();
	cin >> choice;
	switch (choice)
	{
	case 0:
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		system("cls");
		goto START;
	case 1:
	CREATECOURSE:
		system("cls");
		std::cout << "\tWhat course do you want to create (Ex: CS161-23CLC03): ";
		cin >> curCourse.ID;
		system("cls");
		if (curSemester.findCourse(curCourse)) {
			createCourseFail();
			while (std::cin >> choice) {
				system("cls");
				createCourseFail();
				if (choice == 0) {
					system("cls");
					goto EDITSEMESTER;
				}
				if (choice == 1) goto CREATECOURSE;
			}
		}
		curSemester.createCourse(curYear, curCourse);
		system("cls");
		goto EDITSEMESTER;
	case 2:
		curSemester.viewCourseList();
		system("pause");
		system("cls");
		goto EDITSEMESTER;
	case 3:
	INPUTCOURSE:
		system("cls");
		std::cout << "\tWhat course do you want to modify (Ex: CS161-23CLC03): ";
		cin >> curCourse.ID;
		system("cls");
		if (!curSemester.findCourse(curCourse)) {
			inputCourseFail();
			while (std::cin >> choice) {
				system("cls");
				inputCourseFail();
				if (choice == 0) {
					system("cls");
					goto EDITSEMESTER;
				}
				if (choice == 1)
					goto INPUTCOURSE;
			}
		}
		curCourse.loadData(curYear, curSemester.semester_num);
		system("cls");
		goto MODIFYCOURSE;
	case 4:
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		system("cls");
		goto SEMESTER;
	default:
		system("cls");
		goto EDITSEMESTER;
	}
MODIFYCOURSE:
	modifyCourseMenu();
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 0:
		curCourse.saveData(curYear, curSemester.semester_num);
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		system("cls");
		goto START;
	case 1:
		curCourse.viewStudent();
		system("pause");
		system("cls");
		goto MODIFYCOURSE;
	case 2:
		importStudent();
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			system("cls");
			std::cout << "- Enter the path of your input file: ";
			std::cin.ignore();
			std::getline(std::cin, path);
			curCourse.inputCSV(path);
			curCourse.matchStudentPoint();
			break;
		case 2:
			curCourse.addStudent();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
		goto MODIFYCOURSE;
	case 3:
		curCourse.deleteStudent();
		system("pause");
		system("cls");
		goto MODIFYCOURSE;
	case 4:
		system("cls");
		goto COURSEPOINT;
	case 5:
		curSemester.deleteCourse(curYear, curCourse.ID);
		system("pause");
		system("cls");
		goto EDITSEMESTER;
	case 6:
		curSemester.updateCourse();
		system("cls");
		goto MODIFYCOURSE;
	case 7:
		system("cls");
		curCourse.saveData(curYear, curSemester.semester_num);
		curCourse.students.deallocate();
		curCourse.points.deallocate();
		goto EDITSEMESTER;
	default:
		system("cls");
		goto MODIFYCOURSE;
	}
COURSEPOINT:
	editCoursePointMenu();
	cin >> choice;
	switch (choice){
	case 0:
		curCourse.saveData(curYear, curSemester.semester_num);
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		system("cls");
		goto START;
	case 1:
		system("cls");
		std::cout << "- Enter the path of your input file: ";
		std::cin.ignore();
		std::getline(std::cin, path);
		curCourse.importScoreboard(path);
		system("cls");
		goto COURSEPOINT;
	case 2:
		curCourse.viewScoreboard();
		system("pause");
		system("cls");
		goto COURSEPOINT;
	case 3:
		curCourse.updateResult();
		system("cls");
		goto COURSEPOINT;
	case 4:
		system("cls");
		curCourse.saveData(curYear, curSemester.semester_num);
		goto MODIFYCOURSE;
	default:
		system("cls");
		goto COURSEPOINT;
	}
	goto COURSEPOINT;
STUDENTMENU:
	studentMenu();
	std::cin >> choice;
	system("cls");
	switch (choice) {
	case 0:
		goto START;
	case 1:
		user.viewProfileInfo();
		break;
	case 2:
	STUDENTYEAR:
		system("cls");
		studentChooseYear(user.Username);
		listSchoolYear();
		std::cout << "\n- Your choice (Ex: 2023-2024): ";
		cin >> curYear;
		system("cls");
		if (yearExisted(curYear)) {
			inputSchoolYearFail();
			while (std::cin >> choice) {
				system("cls");
				inputSchoolYearFail();
				if (choice == 0)
					goto START;
				if (choice == 1)
					goto STUDENTYEAR;
			}
		}
		system("cls");
		std::cout << "- Enter your semester you want to check (Ex: 2): ";
	STUDENTSEMESTER:
		system("cls");
		std::cout << "\tWhat semester do you want to check: ";
		cin >> curSemester.semester_num;
		system("cls");
		if (!checkSemester(curYear, curSemester.semester_num)) {
			inputSemesterFail();
			while (std::cin >> choice) {
				system("cls");
				inputSemesterFail();
				if (choice == 0)
					goto STUDENTYEAR;
				if (choice == 1)
					goto STUDENTSEMESTER;
			}
		}
		curSemester.loadSemesterData(curYear, curSemester.semester_num);
		curSemester.loadCourseData(curYear);
		curStudentControl.loadStudentCoursesData(curSemester, user.Username);
		goto STUDENTVIEW;
		break;
	case 3:
		user.changePassword();
		break;
	default:
		goto STUDENTMENU;
		break;
	}
	system("pause");
	system("cls");
	goto STUDENTMENU;
STUDENTVIEW:
	system("cls");
	studentView();
	std::cin >> choice;
	system("cls");
	switch (choice) {
	case 0:
		curSemester.deallocate();
		curStudentControl.stu_courses.deallocate();
		goto START;
	case 1:
		curStudentControl.viewScoreboard();
		system("pause");
		break;
	case 2:
		curStudentControl.viewCourses();
		system("pause");
		break;
	case 3:
		curSemester.deallocate();
		curStudentControl.stu_courses.deallocate();
		system("cls");
		goto STUDENTMENU;
	default:
		break;
	}
	goto STUDENTVIEW;
	curSemester.deallocate();
	return 0;
}

