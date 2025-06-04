/*************************************************************************
                                Time
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Time> realization (file Time.cpp) ------------

#include "Time.h"


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
        return !(*this < other) || (*this == other);
    }

    bool Time::operator>(const Time& other) const {
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

unsigned long long Time::toSeconds() const {
    unsigned long long totalSeconds = 0;
    totalSeconds += static_cast<unsigned long long>(year) * 365 * 86400ULL;
    totalSeconds += static_cast<unsigned long long>(month) * 30 * 86400ULL;
    totalSeconds += static_cast<unsigned long long>(day) * 86400ULL;
    totalSeconds += static_cast<unsigned long long>(hour) * 3600ULL;
    totalSeconds += static_cast<unsigned long long>(minute) * 60ULL;
    totalSeconds += second;

    return totalSeconds;
}

#include <ctime>     // for std::tm, std::mktime
#include <iomanip>   // for std::setfill, std::setw

Time Time::addHours(int hours) const
{
    std::tm t = {};
    t.tm_year = year - 1900;  // tm_year is years since 1900
    t.tm_mon  = month - 1;    // tm_mon is 0-based
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min  = minute;
    t.tm_sec  = second;

    std::time_t time_epoch = std::mktime(&t); // normalize
    if (time_epoch == -1)
    {
        return *this;
    }

    time_epoch += hours * 3600;  // Add hours

    std::tm* new_tm = std::localtime(&time_epoch);

    Time result;
    result.setYear(new_tm->tm_year + 1900);
    result.setMonth(new_tm->tm_mon + 1);
    result.setDay(new_tm->tm_mday);
    result.setHour(new_tm->tm_hour);
    result.setMinute(new_tm->tm_min);
    result.setSecond(new_tm->tm_sec);

    return result;
}


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
