#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include <iomanip>
#include "clsString.h"
using namespace std;

class clsDate{
	short _day;
	short _month;
	short _year;

	public:
	    clsDate(){
            time_t t = time(0);
            tm* now = localtime(&t);
            _day = now->tm_mday;
            _month = now->tm_mon + 1;
            _year = now->tm_year + 1900;
	    }

		clsDate(string dateString){
			vector <string> dateVector = clsString::splitString(dateString, "/");
			_day = stoi(dateVector[0]);
			_month = stoi(dateVector[1]);
			_year = stoi(dateVector[2]);
		}

		clsDate(short day, short month, short year){
			_day = day;
			_month = month;
			_year = year;
		}

		short getDay(){return _day;}

		short getMonth(){return _month;}

		short getYear(){return _year;}

		static clsDate convertDaysToDate(short daysNb, short year){
			short month = 1, monthDays, day;
			monthDays = getDaysOfMonth(month, year);
			while(daysNb > monthDays){
				daysNb -= monthDays;
				monthDays = getDaysOfMonth(++month, year);
			}
			if(daysNb == 0)
				day = getDaysOfMonth(month, year);
			else{
				day = daysNb;
			}
			return clsDate(day, month, year);
		}

		clsDate(short daysNb, short year){
			*this = convertDaysToDate(daysNb, year);
		}

		static bool isLeapYear(short year){
			return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? true : false;
		}

		bool isLeapYear(){
			return isLeapYear(_year);
		}

		static int getDaysOfMonth(short month, short year){
			return (month < 1 || month > 12) ? 0 : (month == 2 ? (isLeapYear(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);
		}

		int getDaysOfMonth(){
			return getDaysOfMonth(_month, _year);
		}

		static short getDaysOfYear(short year){
			return isLeapYear(year) ? 366 : 365;
		}

		short getDaysOfYear(){
			return getDaysOfYear(_year);
		}

		static short getDaysNumberFromYearBeginning(short day, short month, short year){
			short daysNb = day;
			for(short i = 1; i < month; i++)
				daysNb += getDaysOfMonth(i, year);
			return daysNb;
		}

		short getDaysNumberFromYearBeginning(){
			return getDaysNumberFromYearBeginning(_day, _month, _year);
		}

		static bool isDate1AfterDate2(short day1, short month1, short year1, short day2, short month2, short year2){
            if(year1 > year2)
                return true;
            else if(year1 < year2)
                return false;
            else if(month1 > month2)
                return true;
            else if(month1 < month2)
                return false;
            else if(day1 > day2)
                return true;
            else
                return false;
        }

        bool isAfterDate(clsDate date){
            return isDate1AfterDate2(_day, _month, _year, date.getDay(), date.getMonth(), date.getYear());
        }

		void print(){
            cout << _day << "/" << _month << "/" << _year;
		}

		static short getDayOrder(short year, short month, short day){
            short a = (14 - month) / 12;
            short y = year - a;
            short m = month + 12 * a - 2;
            return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        }

        short getDayOrder(){
            return getDayOrder(_year, _month, _day);
        }

        static string getDayName(short day, short month, short year){
            short dayNumber = getDayOrder(year, month, day);
            string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
            return days[dayNumber];
        }

        string getDayName(){
            return getDayName(_day, _month, _year);
        }

        static string getMonthName(short month){
            string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
            return months[month - 1];
        }

        string getMonthName(){
            return getMonthName(_month);
        }

		static void printMonthCalendar(short month, short year){
            cout << "\n\t_______________" << getMonthName(month) << "_______________\n\n";
            cout << "\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n\t";
            short firstDayOrder = getDayOrder(year, month, 1);
            short i = 0;
            while(i < firstDayOrder){
                cout << setw(3) << " " << "  ";
                i++;
            }
            for(short j = 1; j <= getDaysOfMonth(month, year); j++){
                cout << setw(3) << j << "  ";
                if(++i == 7){
                    cout << "\n\t";
                    i = 0;
                }
            }
            cout << "\n\t_________________________________\n\n";
        }

        void printMonthCalendar(){
            printMonthCalendar(_month, _year);
        }

        static void printYearCalendar(short year){
            cout << "\t_________________________________\n\n\t";
            cout << "         Calendar - " << year << "         \n";
            cout << "\t_________________________________\n\n";
            for(short month = 1; month <= 12; month++)
                printMonthCalendar(month, year);
        }

        void printYearCalendar(){
            printYearCalendar(_year);
        }

        static short getDaysDifferenceBetweenTwoDates(short day1, short month1, short year1, short day2, short month2, short year2, bool includeEndDay = false){
            short swapFlagValue = 1;
            if(isDate1AfterDate2(day1, month1, year1, day2, month2, year2)){
                swap(day1, day2);
                swap(month1, month2);
                swap(year1, year2);
                swapFlagValue = -1;
            }
            if(year1 == year2){
                if(month1 == month2){
                    return (includeEndDay) ? (day2 - day1 + 1) * swapFlagValue : (day2 - day1) * swapFlagValue;
                }
                else{
                    short daysDifference = getDaysOfMonth(month1, year1) - day1;
                    short month = month1 + 1;
                    while(month < month2){
                        daysDifference += getDaysOfMonth(month, year1);
                        month++;
                    }
                    daysDifference += day2;
                    return (includeEndDay) ? (daysDifference + 1) * swapFlagValue : daysDifference * swapFlagValue;
                }
            }
            else{
                short daysDifference = getDaysNumberFromYearBeginning(day2, month2, year2);
                daysDifference += getDaysOfYear(year1) - getDaysNumberFromYearBeginning(day1, month1, year1);
                short year = year1 + 1;
                while(year < year2){
                    daysDifference += getDaysOfYear(year);
                    year++;
                }
                return (includeEndDay) ? (daysDifference + 1) * swapFlagValue : daysDifference * swapFlagValue;
            }
        }

        static short getDaysDifferenceBetweenTwoDates(clsDate date1, clsDate date2, bool includeEndDay = false){
            return getDaysDifferenceBetweenTwoDates(date1.getDay(), date1.getMonth(), date1.getYear(), date2.getDay(), date2.getMonth(), date2.getYear(), includeEndDay);
        }

        static bool isLastDayInMonth(short day, short month, short year){
            return (day == getDaysOfMonth(month, year));
        }

        bool isLastDayInMonth(){
            return isLastDayInMonth(_day, _month, _year);
        }

        static bool isLastMonthInYear(short month){
            return (month == 12);
        }

        bool isLastMonthInYear(){
            return isLastMonthInYear(_month);
        }

        static bool isValidDate(short day, short month, short year){
            if(month < 1 || month > 12 || year < 1)
                return false;
            return day <= getDaysOfMonth(month, year);
        }

        bool isValid(){
            return isValidDate(_day, _month, _year);
        }

        void increaseDateByOneDay(){
            if(!this->isLastDayInMonth()){
                _day++;
                return;
            }
            else{
                _day = 1;
                if(!this->isLastMonthInYear()){
                    _month++;
                    return;
                }
                else{
                    _month = 1;
                    _year++;
                    return;
                }
            }
        }

        void increaseDateByXDays(short daysNb){
            for(short i = 1; i <= daysNb; i++)
                this->increaseDateByOneDay();
        }

        void increaseDateByOneWeek(){
            this->increaseDateByXDays(7);
        }

        void increaseDateByXWeeks(short weeksNb){
            for(short i = 1; i <= weeksNb; i++)
                this->increaseDateByOneWeek();
        }

        void increaseDateByOneMonth(){
            if(_month == 12){
                _year++;
                _month = 1;
            }
            else
                _month++;
            if(_day > getDaysOfMonth(_month, _year))
                _day = getDaysOfMonth(_month, _year);
        }

        void increaseDateByXMonths(short monthsNb){
            for(short i = 1; i <= monthsNb; i++)
                this->increaseDateByOneMonth();
        }

        void increaseDateByOneYear(){
            _year++;
            if(_month == 2 && _day == 29)
                _day = 	getDaysOfMonth(_month, _year);
        }

        void increaseDateByXYears(short yearsNb){
            _year += yearsNb;
            if(_month == 2 && _day == 29)
                _day = getDaysOfMonth(_month, _year);
        }

        void increaseDateByOneDecade(){
            this->increaseDateByXYears(10);
        }

        void increaseDateByXDecades(short decadesNb){
            this->increaseDateByXYears(10 * decadesNb);
        }

        void increaseDateByOneCentury(){
            this->increaseDateByXYears(100);
        }

        void increaseDateByMillenium(){
            this->increaseDateByXYears(1000);
        }

        void decreaseDateByOneDay(){
            if(_day == 1){
                if(_month == 1){
                    _month = 12;
                    _year--;
                }
                else
                    _month--;
                _day = getDaysOfMonth(_month, _year);
            }
            else
                _day--;
        }

        void decreaseDateByXDays(short daysNb){
            for(short i = 1; i <= daysNb; i++)
                this->decreaseDateByOneDay();
        }

        void decreaseDateByOneWeek(){
            this->decreaseDateByXDays(7);
        }

        void decreaseDateByXWeeks(short weeksNb){
            for(short i = 1; i <= weeksNb; i++)
                this->decreaseDateByOneWeek();
        }

        void decreaseDateByOneMonth(){
            if(_month == 1){
                _year--;
                _month = 12;
            }
            else
                _month--;
            if(_day > getDaysOfMonth(_month, _year))
                _day = getDaysOfMonth(_month, _year);
        }

        void decreaseDateByXMonths(short monthsNb){
            for(short i = 1; i <= monthsNb; i++)
                this->decreaseDateByOneMonth();
        }

        void decreaseDateByOneYear(){
            _year--;
            if(_month == 2 && _day == 29)
                _day = 	getDaysOfMonth(_month, _year);
        }

        void decreaseDateByXYears(short yearsNb){
            _year -= yearsNb;
            if(_month == 2 && _day == 29)
                _day = getDaysOfMonth(_month, _year);
        }

        void decreaseDateByOneDecade(){
            this->decreaseDateByXYears(10);
        }

        void decreaseDateByXDecades(short decadesNb){
            this->decreaseDateByXYears(10 * decadesNb);
        }

        void decreaseDateByOneCentury(){
            this->decreaseDateByXYears(100);
        }

        void decreaseDateByMillenium(){
            this->decreaseDateByXYears(1000);
        }

        static bool isEndOfWeek(short day, short month, short year){
            return getDayOrder(day, month, year) == 6;
        }

        bool isEndOfWeek(){
            return this->getDayOrder() == 6;
        }

        static bool isWeekEnd(short day, short month, short year){
            return getDayName(day, month, year) == "Sat" || getDayName(day, month, year) == "Sun";
        }

        bool isWeekEnd(){
            return this->getDayName() == "Sat" || this->getDayName() == "Sun";
        }

        static bool isBusinessDay(short day, short month, short year){
            return !isWeekEnd(day, month, year);
        }

        bool isBusinessDay(){
            return !this->isWeekEnd();
        }

        static short daysUntillEndOfWeek(short day, short month, short year){
            return 6 - getDayOrder(year, month, day);
        }

        short daysUntillEndOfWeek(){
            return 6 - this->getDayOrder();
        }

        static short daysUntillEndOfMonth(short day, short month, short year){
            return getDaysOfMonth(month, year) - day;
        }

        short daysUntillEndOfMonth(){
            return this->getDaysOfMonth() - _day;
        }

        static short daysUntillEndOfYear(short day, short month, short year){
            return getDaysOfYear(year) - getDaysNumberFromYearBeginning(day, month, year);
        }

        short daysUntillEndOfYear(){
            return this->getDaysOfYear() - this->getDaysNumberFromYearBeginning();
        }

        static string dateToString(short day, short month, short year){
            return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        }

        string toString(){
            return dateToString(_day, _month, _year);
        }

        static string getSystemDateTime(){
            time_t t = time(0);
            tm* now = localtime(&t);
            short day = now->tm_mday;
            short month = now->tm_mon + 1;
            short year = now->tm_year + 1900;
            short hours = now->tm_hour;
            short minutes = now->tm_min;
            short seconds = now->tm_sec;
            return dateToString(day, month, year) + " - " + to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
        }
};

