/*************************************************************************
                                Time
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Time> realization (file Time.cpp) ------------

#include "time.h"

Time::Time()
    : day(1), month(1), year(1970),
      hour(0), minute(0), second(0), zone(0) {}

Time::Time(unsigned int day, int month, int year,
           unsigned int hour, unsigned int minute, unsigned int second,
           int zone)
    : day(day), month(month), year(year),
      hour(hour), minute(minute), second(second), zone(zone) {}

Time::~Time() {}

// GETTERS
unsigned int Time::getDay() const { return day; }
int Time::getMonth() const { return month; }
int Time::getYear() const { return year; }
unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }
int Time::getTimeZone() const { return zone; }

// SETTERS
void Time::setDay(unsigned int d) { day = d; }
void Time::setMonth(int m) { month = m; }
void Time::setYear(int y) { year = y; }
void Time::setHour(unsigned int h) { hour = h; }
void Time::setMinute(unsigned int m) { minute = m; }
void Time::setSecond(unsigned int s) { second = s; }
void Time::setTimeZone(int z) { zone = z; }

// << OPERATOR OVERRIDE
ostream& operator<<(ostream& os, const Time t) {
    os << t.year << "-" << t.month << "-" << t.day << " " << t.hour << ":" << t.minute << ":" << t.second << endl;
    return os;
}
