
#include "aggregation/aggregation.cpp"

int main()
{
    vector<Enrollment> records;
    int courseNumbers[3] = {1115, 3115, 3130};
    for (int i = 0; i < sizeof(courseNumbers) / sizeof(courseNumbers[0]); i++)
    {
        read("../data/d279545d975c1652689e8195e2426adf/" + to_string(courseNumbers[i]) + ".csv", records);
    }
    passRateByInstructor(records);
    passRateByCourseNumber(records);
    withdrawalRateByCourse(records);
    withdrawalRateByInstructor(records);
    fallPassRate(records);
    springPassRate(records);
}
