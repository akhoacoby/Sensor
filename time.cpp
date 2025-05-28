/*************************************************************************
                                Time
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Time> realization (file Time.cpp) ------------

#include "time.h"


    bool Time::operator==(const Time& other) const {
        return year == other.year &&
               month == other.month &&
               day == other.day &&
               hour == other.hour &&
               minute == other.minute &&
               second == other.second;
    }

    
    bool Time::operator<(const Time& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }

   
    bool Time::operator<=(const Time& other) const {
        return (*this < other) || (*this == other);
    }


    bool Time::operator>=(const Time& other) const {
        return !(*this < other);
    }

Time::Time()
    : day(1), month(1), year(1970),
      hour(0), minute(0), second(0) {}

Time::Time(const string& time_str) {
    year   = std::stoi(time_str.substr(0, 4));
    month  = std::stoi(time_str.substr(5, 2));
    day    = std::stoi(time_str.substr(8, 2));
    hour   = std::stoi(time_str.substr(11, 2));
    minute = std::stoi(time_str.substr(14, 2));
    second = std::stoi(time_str.substr(17, 2));

    /*
    char sign = time_str[20];  // '+' or '-'
    int zone_hour   = std::stoi(time_str.substr(21, 2));
    int zone_minute = std::stoi(time_str.substr(24, 2));

    zone = zone_hour + (zone_minute / 60.0);
    if (sign == '-') {
        zone *= -1;
    }
    */
}


Time::~Time() {}

// GETTERS
unsigned int Time::getDay() const { return day; }
int Time::getMonth() const { return month; }
int Time::getYear() const { return year; }
unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }
//double Time::getTimeZone() const { return zone; }

// SETTERS
void Time::setDay(unsigned int d) { day = d; }
void Time::setMonth(int m) { month = m; }
void Time::setYear(int y) { year = y; }
void Time::setHour(unsigned int h) { hour = h; }
void Time::setMinute(unsigned int m) { minute = m; }
void Time::setSecond(unsigned int s) { second = s; }
//void Time::setTimeZone(double z) { zone = z; }

// << OPERATOR OVERRIDE
ostream& operator<<(ostream& os, const Time t) {
    os << t.year << "-" << t.month << "-" << t.day << " " << t.hour << ":" << t.minute << ":" << t.second;
    return os;
}
