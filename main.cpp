#include <iostream>
#include <vector>
#include <fstream>
#include "src/header.h"
using namespace std;
using namespace DOY;
int main()
{

    /*Driver test code!*/
    vector<DayOfYearSet::DayOfYear> doyVec(5);

    DayOfYearSet::DayOfYear doy0(26, 12);
    DayOfYearSet::DayOfYear doy1(4, 6);
    DayOfYearSet::DayOfYear doy2(8, 1);
    DayOfYearSet::DayOfYear doy3(5, 2);
    DayOfYearSet::DayOfYear doy4(30, 8);
    
    doyVec[0] = doy0;
    doyVec[1] = doy1;
    doyVec[2] = doy2;
    doyVec[3] = doy3;
    doyVec[4] = doy4;
    
    
    DayOfYearSet set1(doyVec);

    
    DayOfYearSet::DayOfYear doy5(14, 3);
    DayOfYearSet::DayOfYear doy6(8, 1);
    DayOfYearSet::DayOfYear doy7(27, 9);
    DayOfYearSet::DayOfYear doy8(12, 4);
    DayOfYearSet::DayOfYear doy9(5, 2);
    
    DayOfYearSet set2(5);
    set2.add(doy5);
    set2.add(doy6);
    set2.add(doy7);
    set2.add(doy8);
    set2.add(doy9);
    
    cout << "\nSet1 size: " << set1.size() << endl;

    cout << "\nSet2 size: " << set2.size() << endl;

    cout << "Operator+ = Union of two sets :" << endl;
    cout << (set1 + set2) << endl;

    cout << "Operator- = Difference of two sets :" << endl;
    cout << (set1 - set2) << endl;

    cout << "Operator^ = Intersection of two sets :" << endl;
    cout << (set1 ^ set2) << endl;

    cout << "Operator[] = Index operator of DayOfYearSet (e.g set1[0]) :" << endl;
    cout << "Day:" << set1[0].getDay() << " Month:" << set1[0].getMonth() << endl;

    cout << "\nOperator== -> Compares the set1 and set2:" << endl;
    if(set1 == set2)
        cout << "Sets are equal!" << endl;
    else
        cout << "Sets are not equal!" << endl;    

    cout << "\nOperator!= -> Compares the set1 and set2:" << endl;
    if(set1 != set2)
        cout << "Sets are not equal!" << endl;
    else
        cout << "Sets are equal!" << endl;

    cout << "\nAdd element doy1(4, 6) in set2:" << endl;
    set2.add(doy1);
    cout << "\nThe final state of the set2 is:" << endl;
    cout << set2 << endl;

    cout << "Remove first element( [0] ) in set1:" << endl;
    set1.remove(0);
    cout << "\nThe final state of the set1 is:" << endl;
    cout << set1 << endl;

    cout << "Operator ! = Complement of set1:" << endl;
    cout << !set1;

    set1.saveFile("set1.txt");
    set2.saveFile("set2.txt");
    
    cout << "\nDe Morgan Rule is: !(s1 + s2) == !s1 ^ !s2" << endl;
    if( !( (set1) + (set2) ) == ( !(set1) ^ !(set2) ) )
        cout << "The rule has been successfully executed!!" << endl;

    cout << "\nALL OPERATIONS ARE DONE, PLEASE CHECK THE TERMINAL !" << endl;
    cout << "MADE OPERATIONS WITH SET1 AND SET2 !" << endl;
    cout << "SET1 AND SET2 ARE SAVED TO THE FILE !" << endl;
    
   return 0;
}