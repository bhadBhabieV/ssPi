
#include "TimeBased.h"

void timeBasedStuff()
{
    myAbj.currentFrameTime = chrono::steady_clock::now();
    myAbj.deltaFrameTime = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.lastFrameTime).count();
    myAbj.lastFrameTime = myAbj.currentFrameTime;

    pollController();
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

string getTime(string editModeMatch)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if (i.editModeHotkey == editModeMatch)
        {
            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - i.startTime).count();
            durSinceLastStart = glm::max(0, int(durSinceLastStart - 2)); //

            int durSinceLastStartRounded = roundNumber(durSinceLastStart);

            int HH, MM, SS;

//            cout << "i.secUsableRoundedStored BEFORE = " << i.secUsableRoundedStored << endl;
            SS = (i.secUsableRoundedStored + (durSinceLastStartRounded)) % 60;
            i.secUsableRoundedStored += durSinceLastStartRounded;
//            cout << "i.secUsableRoundedStored AFTER = " << i.secUsableRoundedStored << endl;

            MM = (durSinceLastStartRounded / 60) % 60;
            HH = MM / 60;

            stringstream rr;
            rr << setfill('0') << setw(2) << HH << ":" << setw(2) << MM << ":" << setw(2) << SS;
//            cout << "HH:MM:SS getTime() = " << rr.str() << endl;

            return rr.str();
        }
    }

    return "getTime() error";
}
