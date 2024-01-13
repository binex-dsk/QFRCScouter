#ifndef MATCHDATA_H
#define MATCHDATA_H

#include "Schedule.h"

class MatchData
{
private:
    Schedule m_schedule;
public:
    MatchData();

    Schedule schedule();
};

#endif // MATCHDATA_H
