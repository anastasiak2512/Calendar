
class General {
public:
    /// \brief XdayOnOrBefore returns the date of the weekday before the given date.
    /// \param d Absolute date.
    /// \param x The weekday (0 through 6, with 0 meaning Sunday).
    /// \return The date of the last weekday of type X on or before date D.
    static int XdayOnOrBefore(int d, int x);


};
