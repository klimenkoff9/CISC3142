#include "aggregation.h"
#include "../io/io.cpp"
#include <iostream>

void passRateByInstructor(vector<Enrollment> &records)
{
    unordered_map<string, int> instructorTotalClassesCount;
    unordered_map<string, int> instructorPassRate;

    for (Enrollment record : records)
    {
        if (!instructorTotalClassesCount[record.getInstructorID()])
        {
            instructorTotalClassesCount[record.getInstructorID()] = 0;
        }
        instructorTotalClassesCount[record.getInstructorID()]++;
        if (record.getGrade() != "W" && record.getGrade() != "F" && record.getGrade() != "WD")
        {
            if (!instructorPassRate[record.getInstructorID()])
            {
                instructorPassRate[record.getInstructorID()] = 0;
            }
            instructorPassRate[record.getInstructorID()]++;
        }
    }

    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/passRateByInstructor.txt", "Instructor", "PassRate", instructorPassRate, instructorTotalClassesCount);
}

void passRateByCourseNumber(vector<Enrollment> &records)
{
    unordered_map<string, int> courseNumberTotalClassesCount;
    unordered_map<string, int> courseNumberPassRate;

    for (Enrollment record : records)
    {
        if (!courseNumberTotalClassesCount[record.getCurseNo()])
        {
            courseNumberTotalClassesCount[record.getCurseNo()] = 0;
        }
        courseNumberTotalClassesCount[record.getCurseNo()]++;
        if (record.getGrade() != "W" && record.getGrade() != "F" && record.getGrade() != "WD")
        {
            if (!courseNumberPassRate[record.getCurseNo()])
            {
                courseNumberPassRate[record.getCurseNo()] = 0;
            }
            courseNumberPassRate[record.getCurseNo()]++;
        }
    }

    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/passRateByCourseNum.txt", "CourseNumber", "PassRate", courseNumberPassRate, courseNumberTotalClassesCount);
}

void withdrawalRateByCourse(vector<Enrollment> &records)
{
    unordered_map<string, int> courseNumberWithdrawalCount;
    unordered_map<string, int> courseNumberTotalClassesCount;

    for (Enrollment record : records)
    {
        if (!courseNumberTotalClassesCount[record.getCurseNo()])
        {
            courseNumberTotalClassesCount[record.getCurseNo()] = 0;
        }
        courseNumberTotalClassesCount[record.getCurseNo()]++;
        if (record.getGrade() == "W" || record.getGrade() == "WD")
        {
            if (!courseNumberWithdrawalCount[record.getCurseNo()])
            {
                courseNumberWithdrawalCount[record.getCurseNo()] = 0;
            }
            courseNumberWithdrawalCount[record.getCurseNo()]++;
        }
    }

    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/wRateByCourse.txt", "Course Number", "Withdrawal Rate", courseNumberWithdrawalCount, courseNumberTotalClassesCount);
}

void withdrawalRateByInstructor(vector<Enrollment> &records)
{
    unordered_map<string, int> instructorWithdrawalCount;
    unordered_map<string, int> instructorTotalClassesCount;

    for (Enrollment record : records)
    {
        if (!instructorTotalClassesCount[record.getInstructorID()])
        {
            instructorTotalClassesCount[record.getInstructorID()] = 0;
        }
        instructorTotalClassesCount[record.getInstructorID()]++;
        if (record.getGrade() == "W" || record.getGrade() == "WD")
        {
            if (!instructorWithdrawalCount[record.getInstructorID()])
            {
                instructorWithdrawalCount[record.getInstructorID()] = 0;
            }
            instructorWithdrawalCount[record.getInstructorID()]++;
        }
    }

    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/wRateByInstructor.txt", "Instructor", "Withdrawal Rate", instructorWithdrawalCount, instructorTotalClassesCount);
}

void fallPassRate(vector<Enrollment> &records)
{
    unordered_map<string, int> courseNumberTotalClassesCount;
    unordered_map<string, int> courseNumberPassRate;
    unordered_set<string> fallCourses = {"T04", "T08", "T12", "T16", "T20", "T23"};

    for (Enrollment record : records)
    {
        if (fallCourses.find(record.getTermID()) != fallCourses.end())
        {
            if (!courseNumberTotalClassesCount[record.getCurseNo()])
            {
                courseNumberTotalClassesCount[record.getCurseNo()] = 0;
            }
            courseNumberTotalClassesCount[record.getCurseNo()]++;
            if (record.getGrade() != "F" && record.getGrade() != "WD" && record.getGrade() != "W")
            {
                if (!courseNumberPassRate[record.getCurseNo()])
                {
                    courseNumberPassRate[record.getCurseNo()] = 0;
                }
                courseNumberPassRate[record.getCurseNo()]++;
            }
        }
    }
    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/fallPassRate.txt", "Course", "Pass Rate", courseNumberPassRate, courseNumberTotalClassesCount);
}

void springPassRate(vector<Enrollment> &records)
{
    unordered_map<string, int> courseNumberTotalClassesCount;
    unordered_map<string, int> courseNumberPassRate;
    unordered_set<string> springCourses = {"T02", "T06", "T10", "T14", "T18", "T21"};

    for (Enrollment record : records)
    {
        if (springCourses.find(record.getTermID()) != springCourses.end())
        {
            if (!courseNumberTotalClassesCount[record.getCurseNo()])
            {
                courseNumberTotalClassesCount[record.getCurseNo()] = 0;
            }
            courseNumberTotalClassesCount[record.getCurseNo()]++;
            if (record.getGrade() != "F" && record.getGrade() != "WD" && record.getGrade() != "W")
            {
                if (!courseNumberPassRate[record.getCurseNo()])
                {
                    courseNumberPassRate[record.getCurseNo()] = 0;
                }
                courseNumberPassRate[record.getCurseNo()]++;
            }
        }
    }
    write("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/out/springPassRate.txt", "Course", "Pass Rate", courseNumberPassRate, courseNumberTotalClassesCount);
}