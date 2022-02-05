#include <bits/stdc++.h>

using namespace std;

/*
    STL sort, Structure Sort, Vector sort, String sort

*/

struct Student {
    string name;
    int roll;
    double cgpa;
};

void gradefillup(Student student[])
{
    student[0].name = "Chumma";
    student[0].roll = 129;
    student[0].cgpa = 3.55;

    student[1].name = "dede";
    student[1].roll = 123;
    student[1].cgpa = 3.55;

    student[2].name = "gandu";
    student[2].roll = 134;
    student[2].cgpa = 3.56;

    student[3].name = "marunga";
    student[3].roll = 145;
    student[3].cgpa = 3.56;

    student[4].name = "sala";
    student[4].roll = 154;
    student[4].cgpa = 3.88;


    student[5].name = "Jhukunga";
    student[5].roll = 143;
    student[5].cgpa = 3.88;

    student[6].name = "nehi";
    student[6].roll = 132;
    student[6].cgpa = 3.76;

    student[7].name = "sala";
    student[7].roll = 211;
    student[7].cgpa = 3.76;
}

bool cmp(Student A, Student B)
{
    if(A.cgpa != B.cgpa) return A.cgpa <  B.cgpa;
    return A.roll < B.roll;
}

int main()
{
    int ar[20+3];
    vector <int> ar2;
    for(int i = 0; i<20; i++)
        ar2.push_back(ar[i] = rand());
    cout<<"Unsorted: ";

    for(int i = 0; i<20; i++)
        printf("%d ", ar[i]);
    cout<<endl;

    /*
        to sort using STL function set limit from beginning to end + 1
    */

    sort(ar, ar+20);




    cout<<"Sorted  : ";
    for(int i = 0; i<20; i++)
        printf("%d ", ar[i]);
    cout<<endl<<endl;

    /*
        Structure sort.
        a sort technique that allows multiple restrictions
    */

    Student student[8];
    gradefillup(student);
    sort(student, student+8, cmp);

    for(int i = 0; i<8; i++)
    {
        cout<<student[i].name<<" "<<student[i].roll<<" "<<student[i].cgpa<<endl<<endl;

    }


    /* vector sort*/
    cout<<endl<<endl<<"Unsorted Vector: "<<endl;;

    for (auto i = ar2.begin(); i< ar2.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    cout<<"Sorted Vector: "<<endl;;
    sort(ar2.begin(), ar2.end());
    for (auto i = ar2.begin(); i< ar2.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    /* String sort*/

    vector <string> vstr;
    int n;
    char s[100];
    scanf("%d", &n);

    for(int i = 0; i<n; i++)
    {
        scanf("%s", s);
        vstr.push_back(s);
    }

    sort(vstr.begin(), vstr.end());
    for (auto i = vstr.begin(); i< vstr.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;









    return 0;
}
