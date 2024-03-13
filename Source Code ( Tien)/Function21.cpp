#include "header.h"

void view_of_list_of_course ( Semesters * temp )
{
    Courses * cur = temp->courses;
    while ( cur != NULL )
    {
        std::cout << cur->course_id << " -- " << cur->course_name << " -- " << cur->num_credits << std::endl;
        cur = cur->pNext;
    }
}

