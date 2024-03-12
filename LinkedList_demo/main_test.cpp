#include"LinkedList.h"
#include"student.h"

int main() {
	Students stu1 = {3, 23127, "Nguyen Hoang Gia", "Bao", "Male", "19/03/2005", 89495};
	Students stu2 = { 4, 2317, "Nguyen Gia", "Bao", "Male", "19/03/2005", 18495 };
	Students stu3 = { 3, 2927, "Hoang Gia", "Bao", "Male", "19/03/2005", 37795 };
	Students stu4 = { 3, 73127, "Nguyen", "Bao", "Male", "19/03/2005", 6495 };
	LinkedList<Students> class1;
	class1.insertNode(stu1);
	class1.insertNode(stu2);
	class1.insertNode(stu3);
	class1.insertNode(stu4);
	class1.printList();
	class1.deallocate();
	return 0;
}