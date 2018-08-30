
#include "TimeBased.h"

void timeBasedStuff()
{
    myAbj.currentFrameTime = chrono::steady_clock::now();
    myAbj.deltaFrameTime = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.lastFrameTime).count();
    myAbj.lastFrameTime = myAbj.currentFrameTime;

    pollController();
}

void pollController()
{
    if (myAbj.pollController1.resetTimer)
    {
        myAbj.pollController1.loopTimeStart = myAbj.currentFrameTime; //
        myAbj.pollController1.resetTimer = 0;
    }

    int pollControllerTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.pollController1.loopTimeStart).count();
//    cout << "pollControllerTimeMS = " << pollControllerTimeMS << endl;


    if (pollControllerTimeMS > 50)
    {
        myAbj.pollController1.resetTimer = 1;
        myAbj.pollController1.startTime = chrono::steady_clock::now();

        //polll here
        int presentController = glfwJoystickPresent(GLFW_JOYSTICK_1);
        cout << "presentController = " << presentController << endl;

        if (presentController == 1)
        {
            int buttonCt; //11
            const unsigned char *controllerButtons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCt);
            cout << "buttonCt = " << buttonCt << endl;

            int axesCt; //8
            const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCt);
            cout << "axesCt = " << axesCt << endl;

            for (int i = 0; i < 11; ++i)
            {
                if (controllerButtons[i] == GLFW_PRESS)
                    cout << "pressing button : " << i << endl;
            }

            for (int i = 0; i < 8; ++i)
            {
                cout << "axes " << i << " = " << axes[i] << endl;
//                if (axes[i] == GLFW_PRESS)
//                    cout << "pressing button : " << i << endl;
            }

        }
    }

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