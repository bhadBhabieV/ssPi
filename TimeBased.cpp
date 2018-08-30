
#include "TimeBased.h"

void timeBasedStuff()
{
    myAbj.currentFrameTime = chrono::steady_clock::now();
    myAbj.deltaFrameTime = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.lastFrameTime).count();
    myAbj.lastFrameTime = myAbj.currentFrameTime;
}

int timeHHMMSS_toSec(string inTimeHHMMSS, bool colon)
{
    int MMpos, SSpos;

    if (colon)
    {
        MMpos = 3;
        SSpos = 6;
    }

    else
    {
        MMpos = 2;
        SSpos = 4;
    }

    //HH:MM:SS vs HHMMSS
    string substrHH = inTimeHHMMSS.substr(0, 2);
    string substrMM = inTimeHHMMSS.substr(MMpos, 2);
    string substrSS = inTimeHHMMSS.substr(SSpos, 2);

//    cout << "substrHH = " << substrHH << endl;
//    cout << "substrMM = " << substrMM << endl;
//    cout << "substrSS = " << substrSS << endl;

    int secDur = (stoi(substrHH) * 60 * 60) + (stoi(substrMM) * 60) + (stoi(substrSS));
    return secDur;
}

string timeHHMMSS(string inTimeHHMMSS)
{
    string substrHH = inTimeHHMMSS.substr(0, 2);
    string substrMM = inTimeHHMMSS.substr(2, 2);
    string substrSS = inTimeHHMMSS.substr(4, 2);

    stringstream ss;
    ss << substrHH << ":" << substrMM << ":" << substrSS << endl;

    return ss.str();
}

string secToHHMMSS(int inSec)
{
    int SS = (inSec) % 60;
    int MM = (inSec / 60) % 60;
    int HH = MM / 60;

    stringstream ss;
    ss << setfill('0') << setw(2) << HH << ":" << setw(2) << MM << ":" << setw(2) << SS;

    return ss.str();
}
