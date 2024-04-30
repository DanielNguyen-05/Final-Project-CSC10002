#include "consoleView.hpp"
#include "user.hpp"
#include "semester.hpp"
#include "schoolyear.hpp"
#include "generalClass.hpp"
#include "course.hpp"
#include "studentControl.hpp"
#include <stdlib.h>
#include "student.hpp"

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
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	Users user;
	user.Username = "";
	user.Password = "";
	programInterface();
	int choice;
	std::cin >> choice;
	if (choice == 0)
		return 0;
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
LOGIN:
	if(!user.login()) {
		#ifdef _WIN32
   			system("cls");
		#else
			system("clear");
		#endif
		std::cerr << "Wrong password or username!" << std::endl;
	LOGINFAIL:
		loginFail();
		std::cin >> choice;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
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
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
	staffMainMenu(user.Username);
	std::cin >> choice;
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
	switch (choice) {
	case 0:
		std::cout << "You are logging out..." << std::endl;
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		goto START;
	case 1:
	CREATEYEAR:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		createNewSchoolYear();
		std::cout << "What school year do you want to create (Ex:2023-2024): ";
		cin >> curYear;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (!yearExisted(curYear)) {
			createSchoolYearFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				inputSchoolYearFail();
				if (choice == 0)
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto STAFFMENU;
				if (choice == 1)
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto CREATEYEAR;
			}
		}
		createSchoolYear(curYear);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto STAFFMENU;
	case 2:
	INPUTYEAR:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "\tWhat school year do you want to edit: " << std::endl;
		listSchoolYear();
		std::cout << "\n- Your choice (Ex:2023-2024): ";
		cin >> curYear;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (yearExisted(curYear)) {
			inputSchoolYearFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				inputSchoolYearFail();
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto STAFFMENU;
				}
				if (choice == 1) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto INPUTYEAR;
				}
			}
		}
		goto EDITSCHOOLYEAR;
	case 3:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		while (!user.changePassword()) {
			changePasswordFail();
			while (std::cin >> choice) {
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto STAFFMENU;
				}
				if (choice == 1) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					break;
				}
			}
		}
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		break;
	case 4:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		user.viewProfileInfo();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		break;
	default:
		break;
	}
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	goto STAFFMENU;
EDITSCHOOLYEAR:
	editSchoolYearMenu();
	cin >> choice;
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
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
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto START;
	case 1:
	CREATECLASS:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What general class do you want to create (Ex: 20CLC04) : " ;
		cin >> curClass;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (classExisted(curYear, curClass)) {
			createClassFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				createClassFail();
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto GENERALCLASS;
				}
				if (choice == 1) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto CREATECLASS;
				}
			}
		}
		createGeneralClass(curYear, curClass);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif	
		goto GENERALCLASS;
	case 2:
	INPUTCLASS:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What general class do you want to edit: " <<std::endl;
		viewListOfGeneralClass(curYear);
		std::cout << "\n- Your choice (Ex: 20CLC04): ";
		cin >> curClass;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (!classExisted(curYear, curClass)) {
			inputClassFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				inputClassFail();
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto EDITSCHOOLYEAR;
				}
				if (choice == 1)
					goto INPUTCLASS;
			}
		}
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITGENERALCLASS;
	case 3:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto STAFFMENU;
	case 4:
		goto EDITSCHOOLYEAR;
	default:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto GENERALCLASS;
	}
EDITGENERALCLASS:
	editGeneralClassMenu();
	cin >> choice;
	switch (choice)
	{
	case 0:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
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
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto INPUTCLASS;
	case 5:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto STAFFMENU;
	default:
		break;
	}
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	goto EDITGENERALCLASS;
SEMESTER:
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	semesterMainMenu();
	cin >> choice;
	switch (choice) {
	case 0:
		goto START;
	case 1:
	CREATESEMESTER:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What semester do you want to create: " ;
		cin >> curSemester.semester_num;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (checkSemester(curYear, curSemester.semester_num)) {
			createSemesterFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				createSemesterFail();
				if (choice == 0)
					goto SEMESTER;
				if (choice == 1)
					goto CREATESEMESTER;
			}
		}
		curSemester.createSemester(curYear, curSemester.semester_num);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto SEMESTER;
	case 2:
	INPUTSEMESTER:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What semester do you want to edit: ";
		cin >> curSemester.semester_num;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (!checkSemester(curYear, curSemester.semester_num)) {
			inputSemesterFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
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
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITSCHOOLYEAR;
	case 4:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto STAFFMENU;
	default:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
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
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto START;
	case 1:
	CREATECOURSE:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What course do you want to create (Ex: CS161-23CLC03): ";
		cin >> curCourse.ID;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (curSemester.findCourse(curCourse)) {
			createCourseFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				createCourseFail();
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto EDITSEMESTER;
				}
				if (choice == 1) goto CREATECOURSE;
			}
		}
		curSemester.createCourse(curYear, curCourse);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITSEMESTER;
	case 2:
		curSemester.viewCourseList();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITSEMESTER;
	case 3:
	INPUTCOURSE:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What course do you want to modify (Ex: CS161-23CLC03): ";
		cin >> curCourse.ID;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (!curSemester.findCourse(curCourse)) {
			inputCourseFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				inputCourseFail();
				if (choice == 0) {
					#ifdef _WIN32
						system("cls");
					#else
						system("clear");
					#endif
					goto EDITSEMESTER;
				}
				if (choice == 1)
					goto INPUTCOURSE;
			}
		}
		curCourse.loadData(curYear, curSemester.semester_num);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto MODIFYCOURSE;
	case 4:
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto SEMESTER;
	default:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITSEMESTER;
	}
MODIFYCOURSE:
	modifyCourseMenu();
	cin >> choice;
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	switch (choice)
	{
	case 0:
		curCourse.saveData(curYear, curSemester.semester_num);
		curSemester.saveData(curYear, curSemester.semester_num);
		curSemester.deallocate();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto START;
	case 1:
		curCourse.viewStudent();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto MODIFYCOURSE;
	case 2:
		importStudent();
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
			std::cout << "- Enter the path of your input file: ";
			std::cin.ignore();
			std::getline(std::cin, path);
			curCourse.inputCSV(path);
			curCourse.matchStudentPoint();
			break;
		case 2:
			curCourse.addStudent();
			std::cout << "\nPress enter to continue...";

			std::cin.ignore();
			std::cin.get();
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
			break;
		default:
			break;
		}
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto MODIFYCOURSE;
	case 3:
		curCourse.deleteStudent();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto MODIFYCOURSE;
	case 4:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto COURSEPOINT;
	case 5:
		curSemester.deleteCourse(curYear, curCourse.ID);
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto EDITSEMESTER;
	case 6:
		curSemester.updateCourse();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto MODIFYCOURSE;
	case 7:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		curCourse.saveData(curYear, curSemester.semester_num);
		curCourse.students.deallocate();
		curCourse.points.deallocate();
		goto EDITSEMESTER;
	default:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
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
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto START;
	case 1:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "- Enter the path of your input file: ";
		std::cin.ignore();
		std::getline(std::cin, path);
		curCourse.importScoreboard(path);
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto COURSEPOINT;
	case 2:
		curCourse.viewScoreboard();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto COURSEPOINT;
	case 3:
		curCourse.updateResult();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto COURSEPOINT;
	case 4:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		curCourse.saveData(curYear, curSemester.semester_num);
		goto MODIFYCOURSE;
	default:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto COURSEPOINT;
	}
	goto COURSEPOINT;
STUDENTMENU:
	studentMenu();
	std::cin >> choice;
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	switch (choice) {
	case 0:
		goto START;
	case 1:
		user.viewProfileInfo();
		break;
	case 2:
	STUDENTYEAR:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		studentChooseYear(user.Username);
		listSchoolYear();
		std::cout << "\n- Your choice (Ex: 2023-2024): ";
		cin >> curYear;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (yearExisted(curYear)) {
			inputSchoolYearFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				inputSchoolYearFail();
				if (choice == 0)
					goto START;
				if (choice == 1)
					goto STUDENTYEAR;
			}
		}
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "- Enter your semester you want to check (Ex: 2): ";
	STUDENTSEMESTER:
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		std::cout << "What semester do you want to check: ";
		cin >> curSemester.semester_num;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		if (!checkSemester(curYear, curSemester.semester_num)) {
			inputSemesterFail();
			while (std::cin >> choice) {
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
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
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	goto STUDENTMENU;
STUDENTVIEW:
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	studentView();
	std::cin >> choice;
	#ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
	switch (choice) {
	case 0:
		curSemester.deallocate();
		curStudentControl.stu_courses.deallocate();
		goto START;
	case 1:
		curStudentControl.viewScoreboard();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		break;
	case 2:
		curStudentControl.viewCourses();
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
		break;
	case 3:
		curSemester.deallocate();
		curStudentControl.stu_courses.deallocate();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		goto STUDENTMENU;
	default:
		break;
	}
	goto STUDENTVIEW;
	curSemester.deallocate();
	return 0;
}

