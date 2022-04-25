#ifndef _HEADER_H
#define _HEADER_H
#include <vector>
using namespace std;
namespace DOY
{
    class DayOfYearSet
    {
    public:
        class DayOfYear
        {
        public:
            /*Constructors should increment the numOfObj by 1 when a new object is created.*/
            DayOfYear();
            DayOfYear(int);
            DayOfYear(int, int);
            /*Destructor should decrease the numOfObj by 1 when the object dies.*/
            //~DayOfYear();
            void setDay(int);
            void setMonth(int);
            int getDay() {return day;}
            int getMonth() {return month;}
            bool check(int, int) const;
        private:
            int day;
            int month;
            static int numOfObj;
            static int getNumOfObj();
        };
        DayOfYearSet(vector<DayOfYear>&);
        DayOfYearSet(const DayOfYearSet&);
        DayOfYearSet(int);
        /*Destructor should delete the DayOfYear*.*/
        ~DayOfYearSet();
        void setSize(int);
        void setCapacity(int);
        DayOfYear* getArr() const {return arr;}
        int getCapacity() const {return arrCapacity;}
        bool add(DayOfYear newDoy);
        void remove(int index);
        int size()const {return arrSize;}
        DayOfYear& operator[](int);
        const DayOfYear& operator[](int)const;
        DayOfYearSet& operator=(const DayOfYearSet& rightSide);
        friend bool operator==(const DayOfYearSet&, const DayOfYearSet&);
        friend bool operator!=(const DayOfYearSet&, const DayOfYearSet&);
        friend DayOfYearSet operator +(const DayOfYearSet&, const DayOfYearSet&);
        friend DayOfYearSet operator -(const DayOfYearSet&, const DayOfYearSet&);
        friend DayOfYearSet operator ^(const DayOfYearSet&, const DayOfYearSet&);
        DayOfYearSet operator !();
        friend ostream& operator <<(ostream&, const DayOfYearSet&);
        //friend ofstream& operator <<(ofstream&, const DayOfYearSet&);
        void saveFile(const string fileName);
        
    private:
        int arrSize;
        int arrCapacity;
        DayOfYear* arr;
    };
}
#endif