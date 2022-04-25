#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
using namespace std;
namespace DOY
{
    /*This constructor gets day and month, checks the parameter and initializes the object.*/
    DayOfYearSet::DayOfYear::DayOfYear(int newDay, int newMonth)
    {
        if(!check(newDay, newMonth))
        {
            cerr << "Illegal Day and Month!!!" << endl;
            exit(1);
        }
        day = newDay;
        month = newMonth;
    }
    /*This constructor gets month, checks the parameter and initializes the object.*/
    DayOfYearSet::DayOfYear::DayOfYear(int newMonth)
    {
        if(newMonth < 1 || newMonth > 12)
        {
            cerr << "Illegal Month!!!" << endl;
            exit(1);
        }
        day = 1;
        month = newMonth;
    }
    /*This constructor initializes the object.*/
    DayOfYearSet::DayOfYear::DayOfYear()
    {
        day = 1;
        month = 1;
    }
    /*Setters.*/
    void DayOfYearSet::DayOfYear::setDay(int newDay) {day = newDay;}
    void DayOfYearSet::DayOfYear::setMonth(int newMonth) {month = newMonth;}
    
    /*This constructor gets capacity, checks the parameter and initialize the object.*/
    DayOfYearSet::DayOfYearSet(int newCapacity) : arrCapacity(newCapacity), arrSize(0)
    {
        if(newCapacity < 1)
        {
            cerr << "Illegal Capacity!!! Capacity is greater than 0 !!!" << endl;
            exit(1);
        }
        arr = new DayOfYear[arrCapacity];
        for(int i = 0; i < arrCapacity; ++i)
        {   
            arr[i].setDay(-1);
            arr[i].setMonth(-1);
        }
            
    }
    /*This constructor gets vector of DayOfYear, checks the parameter and initialize the object.*/
    DayOfYearSet::DayOfYearSet(vector <DayOfYearSet::DayOfYear>& doyVec)
    {
        if(doyVec.size() == 0)
        {
            cerr << "ERROR! Day of Year vector is empty!" << endl;
            exit(1);
        }     
        arr = new DayOfYear[doyVec.size()];
        for(auto i = 0; i < doyVec.size(); ++i)
            arr[i] = doyVec[i];
        arrSize = doyVec.size();
        arrCapacity = doyVec.size();        
    }
    /*Copy constructor.*/
    DayOfYearSet::DayOfYearSet(const DayOfYearSet& doyObject)
    {
        arrCapacity = doyObject.getCapacity();
        arrSize = doyObject.size();
        arr = new DayOfYear[arrCapacity];
        for(int i = 0; i < arrSize; ++i)
            arr[i] = doyObject.arr[i];
    }
    /*Destructor.*/
    DayOfYearSet::~DayOfYearSet()
    {
        delete [] arr;
    }
    /*This function gets a DayOfYear object and adds in the DayOfYearSet set.*/
    bool DayOfYearSet::add(DayOfYear newDoy)
    {
        if(arrSize < arrCapacity)
        {
            arr[arrSize].setDay(newDoy.getDay());
            arr[arrSize].setMonth(newDoy.getMonth());
            arrSize++;
            return true; 
        }
        DayOfYear* temp = new DayOfYear[arrCapacity * 2];
        if(!temp) return false;
        for(int i = 0; i < arrSize; ++i)
        {
            temp[i].setDay(arr[i].getDay());
            temp[i].setMonth(arr[i].getMonth());
        }
        delete [] arr;
        arr = temp;
        arrCapacity *= 2;
        arr[arrSize].setDay(newDoy.getDay());
        arr[arrSize].setMonth(newDoy.getMonth());
        arrSize++;
        return true;
    }
    /*This function gets the index and removes the given position.*/
    void DayOfYearSet::remove(int index)
    {
        for(int i = index; i < arrSize; ++i)
        {
            arr[i].setDay(arr[i + 1].getDay());
            arr[i].setMonth(arr[i + 1].getMonth());
        }
        arr[arrSize - 1].setDay(-1);
        arr[arrSize - 1].setMonth(-1);
        arrSize--;
    }
    /*This function compares the sets. If they are equal return true, otherwise return false.*/
    bool operator ==(const DayOfYearSet& set1, const DayOfYearSet& set2)
    {
        int i, j, counter = 0;
        if(set1.size() != set2.size())
            return false;
        for(i = 0; i < set1.size(); ++i)
        {
            for(j = 0; j < set2.size(); ++j)
            {
                if( ( set1.getArr()[i].getDay() ) == (set2.getArr()[j].getDay() ) 
                    && ( set1.getArr()[i].getMonth() ) == (set2.getArr()[j].getMonth() ) )
                {
                    counter++;
                    break;
                }    
            }
        }
        if(counter == set1.size())
            return true;
        else
            return false;        
    }
    /*This function compares the sets. If they are not equal return true, otherwise return false.*/
    bool operator !=(const DayOfYearSet& set1, const DayOfYearSet& set2)
    {
        return !(set1 == set2);
    }
    /*This function unions the sets.*/
    DayOfYearSet operator +(const DayOfYearSet& set1, const DayOfYearSet& set2)
    {
        int counter;
        int i, j;
        DayOfYearSet newSet(set1.size() + set2.size());
        for(int k = 0; k < set1.size(); ++k)  
            newSet.add(set1.getArr()[k]);
        for(i = 0; i < set2.size(); ++i)
        {
            counter = 0;
            for(j = 0; j < set1.size(); ++j)
            {
                if( ( set1.getArr()[j].getDay() ) == (set2.getArr()[i].getDay() ) 
                    && ( set1.getArr()[j].getMonth() ) == (set2.getArr()[i].getMonth() ) )
                {
                    counter++;
                }    
            }
            if(counter == 0)
                newSet.add(set2.getArr()[i]);
        }
        return newSet;    
    }
    /*This function finds the differences the given sets.*/   
    DayOfYearSet operator -(const DayOfYearSet& set1, const DayOfYearSet& set2)
    {
        int counter;
        int i, j;
        DayOfYearSet newSet(set1.size() + set2.size());
        for(i = 0; i < set1.size(); ++i)
        {
            counter = 0;
            for(j = 0; j < set2.size(); ++j)
                if( ( ( set1.getArr()[i].getDay() ) == (set2.getArr()[j].getDay() ) 
                    && ( set1.getArr()[i].getMonth() ) == (set2.getArr()[j].getMonth() ) ) )
                    counter++;        
            if(counter == 0)
                newSet.add(set1.getArr()[i]);
        }
        for(i = 0; i < set2.size(); ++i)
        {
            counter = 0;
            for(j = 0; j < set1.size(); ++j)
                if( ( ( set1.getArr()[j].getDay() ) == (set2.getArr()[i].getDay() ) 
                    && ( set1.getArr()[j].getMonth() ) == (set2.getArr()[i].getMonth() ) ) )
                    counter++;        
            if(counter == 0)
                newSet.add(set2.getArr()[i]);
        }
        return newSet;            
    }
    /*This function finds the common elements in the given sets.*/
    DayOfYearSet operator ^(const DayOfYearSet& set1, const DayOfYearSet& set2)
    {
        DayOfYearSet::DayOfYear newDoy;
        DayOfYearSet newSet(set1.size());
        for(int i = 0; i < set1.size(); ++i)
            for(int j = 0; j < set2.size(); ++j)
                if( ( set1.getArr()[i].getDay() ) == (set2.getArr()[j].getDay() ) 
                    && ( set1.getArr()[i].getMonth() ) == (set2.getArr()[j].getMonth() ) )
                {
                    newDoy.setDay(set1.getArr()[i].getDay());
                    newDoy.setMonth(set1.getArr()[i].getMonth());
                    newSet.add(newDoy);
                }
        return newSet;
    }
    /*Complement operator.*/
    DayOfYearSet DayOfYearSet::operator !()
    {
        DayOfYearSet newSet(365);
        DayOfYearSet::DayOfYear newDoy;
        for(int i = 1; i <= 12; ++i)
        {
            for(int j = 1; j <= 31; ++j)
            {
                if( (i == 4 || i == 6 || i == 9 || i == 11) && j > 30 || (i == 2 && j > 28))
                    break;
                else
                {
                    if(arr[i].getDay() != i || arr[j].getMonth() != j)
                    {
                        newDoy.setDay(j);
                        newDoy.setMonth(i);    
                        newSet.add(newDoy);
                    }
                }         
            }
        }
        return newSet;
    }
    /*This function returns the given position of DayOfYearSet.*/
    DayOfYearSet::DayOfYear& DayOfYearSet::operator[](int index)
    {
        if(index >= arrSize)
        {
            cerr << "Out Of Size! Illegal index in DayOfYear!" << endl;
            exit(1);
        }
        return arr[index];
    }
    /*This function returns the given position of DayOfYearSet.*/
    const DayOfYearSet::DayOfYear& DayOfYearSet::operator[](int index) const
    {
        if(index >= arrSize)
        {
            cerr << "Out Of Size! Illegal index in DayOfYear!" << endl;
            exit(1);
        }
        return arr[index];
    }
    ostream& operator <<(ostream& os, const DayOfYearSet& doySet)
    {
        for(int i = 0; i < doySet.size(); ++i)
        {
            os << "Day:" << doySet.getArr()[i].getDay() << " " << "Month:";
            os <<  doySet.getArr()[i].getMonth() << endl;
        }
        return os;    
    }
    /*Assignment operator.*/
    DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& rightSide)
    {
        if(arrCapacity != rightSide.arrCapacity)
        {
            delete [] arr;
            arr = new DayOfYear[rightSide.arrCapacity];
        }
        arrCapacity = rightSide.arrCapacity;
        arrSize = rightSide.arrSize;
        for(int i = 0; i < arrSize; ++i)
            arr[i] = rightSide.arr[i];

        return *this;    
    }
    bool DayOfYearSet::DayOfYear::check(int newDay, int newMonth) const
    {
        if(newMonth < 1 || newMonth > 12)
            return false;
        if( (newMonth == 1) && (newDay < 1 || newDay > 31) )
            return false;
        else if( (newMonth == 2) && (newDay < 1 || newDay > 28) )
            return false;
        else if( (newMonth == 3) && (newDay < 1 || newDay > 31) )
            return false;        
        else if( (newMonth == 4) && (newDay < 1 || newDay > 30) )
            return false;
        else if( (newMonth == 5) && (newDay < 1 || newDay > 31) )
            return false;
        else if( (newMonth == 6) && (newDay < 1 || newDay > 30) )
            return false;
        else if( (newMonth == 7) && (newDay < 1 || newDay > 31) )
            return false;
        else if( (newMonth == 8) && (newDay < 1 || newDay > 31) )
            return false;
        else if( (newMonth == 9) && (newDay < 1 || newDay > 30) )
            return false;
        else if( (newMonth == 10) && (newDay < 1 || newDay > 31) )
            return false;
        else if( (newMonth == 11) && (newDay < 1 || newDay > 30) )
            return false;
        else if( (newMonth == 12) && (newDay < 1 || newDay > 31) )
            return false;   
        return true;                                 
    }
    void DayOfYearSet::saveFile(const string fileName)
    {
        ofstream file;
        file.open(fileName);
        for(int i = 0; i < size(); ++i)
        {
            file << "Day:" << arr[i].getDay() << " Month:" << arr[i].getMonth() << endl;
        }
        file.close();
    }
    
}
