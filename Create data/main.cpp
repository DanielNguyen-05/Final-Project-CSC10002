#include "createAccount.hpp"
#include <iostream>

int main()
{
    std::cout << "Start create account :))))\n";

    int choice;
    std::string classname;
    do{
        std::cout   << "1. Create staff account\n"
                    << "2. Create student account from class file\n"
                    << "0. End\n\n"
                    << "Choice: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                createStaffAccount();
                break;
            
            case 2:
                std::cout << "Input classname: ";
                std::cin >> classname;
                createClassAccountFromfile(classname);
                break;

            case 0:
                std::cout << "Pai pai!!";
                return 0;

            default:
                break;
        }
    }while(choice != 0);

    return 0;
}