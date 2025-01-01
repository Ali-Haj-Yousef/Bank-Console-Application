#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std;

class clsPeriod{
        clsDate _startDate;
        clsDate _endDate;

    public:
        clsPeriod(clsDate startDate, clsDate endDate){
            _startDate = startDate;
            _endDate = endDate;
        }

        clsDate getStartDate(){return _startDate;}

        clsDate getEndDate(){return  _endDate;}

        bool doesIncludeDate(clsDate date){
            return date.isAfterDate(_startDate) && _endDate.isAfterDate(date);
        }

        bool doesIntersectWithPeriod(clsPeriod period){
            return (!period.getStartDate().isAfterDate(_endDate) || !_startDate.isAfterDate(period.getEndDate()) );
        }

        short countIntersectingDaysWithPeriod(clsPeriod period){
            if(!this->doesIntersectWithPeriod(period))
                return 0;
            if(this->doesIncludeDate(period.getStartDate())){
                if(this->doesIncludeDate(period.getEndDate()))
                    return period.getDaysDifference();
                else
                    return clsDate::getDaysDifferenceBetweenTwoDates(period.getStartDate(), _endDate);
            }
            else if(this->doesIncludeDate(period.getEndDate()))
                return clsDate::getDaysDifferenceBetweenTwoDates(period.getEndDate(), _startDate);
            else
                return this->getDaysDifference();
        }

        short Length(bool includeEndDay = false){
            return this->getDaysDifference(includeEndDay);
        }

        short getDaysDifference(bool includeEndDay = false){
            return clsDate::getDaysDifferenceBetweenTwoDates(_startDate, _endDate, includeEndDay);
        }

        short getVacationDays(){
            short vacationDaysNb = 0;
            while(_endDate.isAfterDate(_startDate)){
                if(!(_startDate.isWeekEnd()))
                    vacationDaysNb++;
                _startDate.increaseDateByOneDay();
            }
            return vacationDaysNb;
        }
};

