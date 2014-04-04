class General {
public:
    /*
      XdayOnOrBefore returns the date of the weekday before the given date.

      Parameters:

        Input, int D, the absolute date.

        Input, int X, the weekday (0 through 6, with 0 meaning Sunday).

        Output, int XdayOnOrBefore, the date of the last weekday of
        type X on or before date D.
    */
    static int XdayOnOrBefore(int d, int x);


};
