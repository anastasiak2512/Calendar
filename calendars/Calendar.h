#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar {
protected:
    int year = 1;
    int month = 1;
    int day = 1;

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



    void resetDate(int day)
    {
    }
    int getDay() const;
    void setDay(int value);
};

#endif /*CALENDAR_H*/
