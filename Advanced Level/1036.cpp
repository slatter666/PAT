#include <iostream>
using namespace std;

int main()
{
    int n, grade, minMaleGrade = 101, maxFemaleGrade = -1;
    string name, gender, id, maleName, maleId, femaleName, femaleId;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> gender >> id >> grade;
        if (gender == "M" && grade < minMaleGrade)
        {
            maleName = name;
            maleId = id;
            minMaleGrade = grade;
        }
        if (gender == "F" && grade > maxFemaleGrade)
        {
            femaleName = name;
            femaleId = id;
            maxFemaleGrade = grade;
        }
    }

    bool flag = 0;
    if (femaleName.size() == 0)
    {
        cout << "Absent" << endl;
        flag = 1;
    }
    else
        cout << femaleName << " " << femaleId << endl;

    if (maleName.size() == 0)
    {
        cout << "Absent" << endl;
        flag = 1;
    }
    else
        cout << maleName << " " << maleId << endl;

    if (flag)
        cout << "NA" << endl;
    else
        cout << maxFemaleGrade - minMaleGrade << endl;
    return 0;
}