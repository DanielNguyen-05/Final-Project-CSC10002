QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GeneralClass.cpp \
    User.cpp \
    course.cpp \
    createAccount.cpp \
    main.cpp \
    mainwindow.cpp \
    schoolyear.cpp \
    score.cpp \
    semester.cpp \
    student.cpp \
    student_control.cpp \
    subFunction.cpp

HEADERS += \
    GeneralClass.hpp \
    LinkedList.hpp \
    User.hpp \
    course.hpp \
    createAccount.hpp \
    mainwindow.h \
    schoolyear.hpp \
    score.hpp \
    semester.hpp \
    student.hpp \
    student_control.hpp \
    student_courses.hpp \
    subFunction.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    Data/2017-2018/Semester 1/2/2.csv \
    Data/2017-2018/Semester 1/2/2.csv \
    Data/2017-2018/Semester 1/2/Point.csv \
    Data/2017-2018/Semester 1/2/Point.csv \
    Data/2017-2018/Semester 1/2/StudentList.csv \
    Data/2017-2018/Semester 1/2/StudentList.csv \
    Data/2017-2018/Semester 1/CSC161/CSC161.csv \
    Data/2017-2018/Semester 1/CSC161/CSC161.csv \
    Data/2017-2018/Semester 1/CSC161/Point.csv \
    Data/2017-2018/Semester 1/CSC161/Point.csv \
    Data/2017-2018/Semester 1/CSC161/StudentList.csv \
    Data/2017-2018/Semester 1/CSC161/StudentList.csv \
    Data/2017-2018/Semester 1/CourseList.txt \
    Data/2017-2018/Semester 1/CourseList.txt \
    Data/2017-2018/semester.txt \
    Data/Account/AcademicStaff/23127157.csv \
    Data/Account/AcademicStaff/23127157.txt \
    Data/Account/AcademicStaff/miTomThanhLong.txt \
    Data/Account/Student/23127158.txt \
    Data/GeneralClasses/2017-2018/GeneralClass.txt \
    Data/GeneralClasses/2018-2019/GeneralClass.txt \
    Data/GeneralClasses/2020-2021/20APCS1.csv \
    Data/GeneralClasses/2020-2021/20APCS2.csv \
    Data/GeneralClasses/2020-2021/20CLC01.csv \
    Data/GeneralClasses/2020-2021/20CLC02.csv \
    Data/GeneralClasses/2020-2021/20CLC03.csv \
    Data/GeneralClasses/2020-2021/20CTT1.csv \
    Data/GeneralClasses/2021-2022/21APCS1.csv \
    Data/GeneralClasses/2021-2022/21APCS2.csv \
    Data/GeneralClasses/2021-2022/21CLC01.csv \
    Data/GeneralClasses/2021-2022/21CLC02.csv \
    Data/GeneralClasses/2021-2022/21CTT1.csv \
    Data/GeneralClasses/2021-2022/GeneralClass.txt \
    Data/GeneralClasses/2022-2023/22APCS1.csv \
    Data/GeneralClasses/2022-2023/22CLC01.csv \
    Data/GeneralClasses/2022-2023/22CLC02.csv \
    Data/GeneralClasses/2022-2023/22CLC03.csv \
    Data/GeneralClasses/2023--2024/23clc03.csv \
    Data/GeneralClasses/2025-2026/GeneralClass.txt \
    Data/GeneralClasses/2027-2028/21CLC01.csv \
    Data/GeneralClasses/2027-2028/GeneralClass.txt \
    Data/SchoolYear.txt
