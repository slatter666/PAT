#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct student
{
    string name;
    string id;
    int grade;
};

int main()
{
    int n;
    cin>>n;
    student s[n+2];
    int mingrade = 100;
    int maxgrade = 0;
    int minindex,maxindex;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].id>>s[i].grade;
        if(s[i].grade>maxgrade)
        {
            maxgrade = s[i].grade;
            maxindex = i;
        }
        if(s[i].grade<mingrade)
        {
            mingrade = s[i].grade;
            minindex = i;
        }
    }

    cout<<s[maxindex].name<<" "<<s[maxindex].id<<endl;
    cout<<s[minindex].name<<" "<<s[minindex].id<<endl;
    return 0;
}