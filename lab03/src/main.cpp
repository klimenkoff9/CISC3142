
#include "aggregation/aggregation.cpp"

int main()
{
    vector<Enrollment> records;
    int courseNumbers[3] = {1115, 3115, 3130};
    for (int i = 0; i < sizeof(courseNumbers) / sizeof(courseNumbers[0]); i++)
    {
        read("/Users/kilmenkovd/Desktop/Classes/CISC3142/lab03/data/" + to_string(courseNumbers[i]) + ".csv", records);
    }
    passRateByInstructor(records);
    passRateByCourseNumber(records);
    withdrawalRateByCourse(records);
    withdrawalRateByInstructor(records);
    fallPassRate(records);
    springPassRate(records);
}
