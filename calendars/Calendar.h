#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar {
protected:
    int year = 1;
    int month = 1;
    int day = 1;

    int mark = 0;

public:
    Calendar(int m, int d, int y) : month(m), day(d), year(y) {
    };

    Calendar(int d) {
    };

    Calendar() {
    };

    virtual int getDefYearLen() {
        return 355;
    }

    int getYear() const {
        return year;
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

    void setMark(int mark) {

    }
};

#endif /*CALENDAR_H*/
