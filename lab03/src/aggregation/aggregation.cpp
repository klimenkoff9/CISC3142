#include "aggregation.h"
#include "../io/io.cpp"

void passRateByInstructor()
{
    vector<Enrollment> records;
    int courseNumbers[3] = {1115, 3115, 3130};
    for (int i = 0; i < sizeof(courseNumbers) / sizeof(courseNumbers[0]); i++)
    {
        read("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/data/" + to_string(courseNumbers[i]) + ".csv", records);
    }

    unordered_map<string, int> instructorTotalClassesCount;
    unordered_map<string, int> instructorPassRate;

    for (int i = 0; i < records.size(); i++)
    {
        if (!instructorTotalClassesCount[records[i].getInstructorID()])
        {
            instructorTotalClassesCount[records[i].getInstructorID()] = 0;
        }
        instructorTotalClassesCount[records[i].getInstructorID()]++;
        if (records[i].getGrade() != "W" && records[i].getGrade() != "F" && records[i].getGrade() != "WD")
        {
            if (!instructorPassRate[records[i].getInstructorID()])
            {
                instructorPassRate[records[i].getInstructorID()] = 0;
            }
            instructorPassRate[records[i].getInstructorID()]++;
        }
    }
}