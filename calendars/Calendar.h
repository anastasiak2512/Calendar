#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar {
protected:
    int year = 1;
    int month = 1;
    int day = 1;

    int mark = 0;

public:
    Calendar(int m, int d, int y): month(m), day(d), year(y) {};
    Calendar(int d) {};
    Calendar() {};


    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Calendar::year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Calendar::month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        Calendar::day = day;
    }

    int getMark() const {
        return mark;
    }

    void setMark(int mark) {
        Calendar::mark = mark;
    }

    int getYearLen(int year) {
        return 356;
    }

};
#endif /*CALENDAR_H*/
