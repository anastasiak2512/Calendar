#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar {
protected:
    int year = 1;   // 1...
    int month = 1;  // 1 == January, ..., 12 == December
    int day = 1;

public:
    Calendar(int m, int d, int y): month(m), day(d), year(y) {};
    Calendar(int d) {};
    Calendar() {};

    int GetMonth() { return month; }
    int GetDay() { return day; }
    int GetYear() { return year; }
};

#endif /*CALENDAR_H*/
