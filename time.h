/*************************************************************************
                           Time  -  description
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Time> interface (file Time.h) ------------
#ifndef TIME_H
#define TIME_H

// SYSTEM INCLUDES 
#include <string>
#include <ostream>
#include <cstdio>
using namespace std;

// USED TYPES

class Time {
    friend ostream& operator<<(ostream& os, const Time t);
    public:
        // Overload operator==
        bool operator==(const Time& other) const;

        // Overload operator<
        bool operator<(const Time& other) const;

        // Overload operator<= using operator< and operator==
        bool operator<=(const Time& other) const;

        bool operator>(const Time& other) const;
        bool operator>=(const Time& other) const;

        // METHODS 
        unsigned long long toSeconds() const;
        Time addHours(int hours) const;


        // CONSTRUCTORS
        Time(); 
        Time(const string& time_str);
        virtual ~Time();

        // GETTERS 
        unsigned int getDay() const;
        int getMonth() const;
        int getYear() const;
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;
        //double getTimeZone() const;

        // SETTERS
        void setDay(unsigned int day);
        void setMonth(int month);
        void setYear(int year);
        void setHour(unsigned int hour);
        void setMinute(unsigned int minute);
        void setSecond(unsigned int second);
        //void setTimeZone(double zone);
        
    private:
        // PRIVATE ATTRIBUTES
        unsigned int day;
        int month;
        int year;
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
        //double zone;
};

#endif // TIME_H
