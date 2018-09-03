
#include "TimeBased.h"

void timeBasedStuff()
{
    myAbj.currentFrameTime = chrono::steady_clock::now();
    myAbj.deltaFrameTime = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.lastFrameTime).count();
    myAbj.lastFrameTime = myAbj.currentFrameTime;

    pollController();
}

//void pollController()
//{
////    for (auto &i : myAbj.autoRepeatVec)
////    {
////        if (i.resetTimer)
////        {
////            i.loopTimeStart = myAbj.currentFrameTime; //
////            i.resetTimer = 0;
////        }
////    }
//
//    for (uint i = 0; i < myAbj.autoRepeatVec.size(); ++i)
//    {
//        if (myAbj.autoRepeatVec[i].resetTimer)
//        {
//            myAbj.autoRepeatVec[i].loopTimeStart = myAbj.currentFrameTime; //
//            myAbj.autoRepeatVec[i].resetTimer = 0;
//        }
//
//    }
//
//    int pollControllerTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.pollController1.loopTimeStart).count();
////    cout << "pollControllerTimeMS = " << pollControllerTimeMS << endl;
//
//    int autoRepeatPrevent0MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent0.loopTimeStart).count();
//    int autoRepeatPrevent1MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent1.loopTimeStart).count();
//    int autoRepeatPrevent2MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent2.loopTimeStart).count();
//    int autoRepeatPrevent3MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent3.loopTimeStart).count();
//    int autoRepeatPrevent4MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent4.loopTimeStart).count();
//    int autoRepeatPrevent5MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent5.loopTimeStart).count();
//    int autoRepeatPrevent6MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent6.loopTimeStart).count();
//    int autoRepeatPrevent7MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent7.loopTimeStart).count();
//    int autoRepeatPrevent8MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent8.loopTimeStart).count();
////    cout << "autoRepeatPrevent5MS = " << autoRepeatPrevent5MS << endl;
//
//    if (pollControllerTimeMS > 50)
//    {
//        myAbj.pollController1.resetTimer = 1;
//        myAbj.pollController1.startTime = chrono::steady_clock::now();
//
//        //polll here
//        int presentController = glfwJoystickPresent(GLFW_JOYSTICK_1);
////        cout << "presentController = " << presentController << endl;
//
//        if (presentController == 1)
//        {
//            int buttonCt; //11
//            const unsigned char *controllerButtons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCt);
////            cout << "buttonCt = " << buttonCt << endl;
//
////            int axesCt; //8
////            const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCt);
//////            cout << "axesCt = " << axesCt << endl;
////
//////            for (int i = 0; i < 8; ++i)
//////            {
//////                cout << "axes " << i << " = " << axes[i] << endl;
////////                if (axes[i] == GLFW_PRESS)
////////                    cout << "pressing button : " << i << endl;
//////            }
////
//
//            if (controllerButtons[4] == GLFW_PRESS && autoRepeatPrevent4MS >= 1000)
//            {
////                cout << "pressed 4 w/o autorepeat" << endl;
////                cout << "autoRepeatPrevent4MS = " << autoRepeatPrevent4MS << endl;
//
//                myAbj.autoRepeatPrevent4.resetTimer = 1;
//                myAbj.autoRepeatPrevent4.startTime = chrono::steady_clock::now();
//
//                system("killall -9 omxplayer omxplayer.bin");
//                speedUpOrSlowDown("decrease");
//            }
//
//            if (controllerButtons[5] == GLFW_PRESS && autoRepeatPrevent5MS >= 1000)
//            {
////                cout << "pressed 5 w/o autorepeat" << endl;
//                cout << "autoRepeatPrevent5MS = " << autoRepeatPrevent5MS << endl;
//
//                myAbj.autoRepeatPrevent5.resetTimer = 1;
//                myAbj.autoRepeatPrevent5.startTime = chrono::steady_clock::now();
//
//                system("killall -9 omxplayer omxplayer.bin");
//                speedUpOrSlowDown("increase");
//            }
//
//            if (controllerButtons[6] == GLFW_PRESS && autoRepeatPrevent6MS >= 1000)
//            {
//                myAbj.autoRepeatPrevent6.resetTimer = 1;
//                myAbj.autoRepeatPrevent6.startTime = chrono::steady_clock::now();
//
//                myAbj.quitTgl = 1;
//                system("killall -9 omxplayer omxplayer.bin");
//            }
//
//            if (controllerButtons[6] == GLFW_PRESS && autoRepeatPrevent6MS >= 1000)
//            {
//                myAbj.autoRepeatPrevent6.resetTimer = 1;
//                myAbj.autoRepeatPrevent6.startTime = chrono::steady_clock::now();
//
//                system("killall -9 omxplayer omxplayer.bin");
//                playPauseVid();
//            }
//
//
//        }
//    }
//
//}


void pollController()
{
    if (myAbj.pollController1.resetTimer)
    {
        myAbj.pollController1.loopTimeStart = myAbj.currentFrameTime; //
        myAbj.pollController1.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent0.resetTimer)
    {
        myAbj.autoRepeatPrevent0.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent0.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent1.resetTimer)
    {
        myAbj.autoRepeatPrevent1.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent1.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent2.resetTimer)
    {
        myAbj.autoRepeatPrevent2.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent2.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent3.resetTimer)
    {
        myAbj.autoRepeatPrevent3.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent3.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent4.resetTimer)
    {
        myAbj.autoRepeatPrevent4.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent4.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent5.resetTimer)
    {
        myAbj.autoRepeatPrevent5.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent5.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent6.resetTimer)
    {
        myAbj.autoRepeatPrevent6.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent6.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent7.resetTimer)
    {
        myAbj.autoRepeatPrevent7.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent7.resetTimer = 0;
    }

    if (myAbj.autoRepeatPrevent8.resetTimer)
    {
        myAbj.autoRepeatPrevent8.loopTimeStart = myAbj.currentFrameTime;
        myAbj.autoRepeatPrevent8.resetTimer = 0;
    }

    int pollControllerTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.pollController1.loopTimeStart).count();
//    cout << "pollControllerTimeMS = " << pollControllerTimeMS << endl;

    int autoRepeatPrevent0MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent0.loopTimeStart).count();
    int autoRepeatPrevent1MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent1.loopTimeStart).count();
    int autoRepeatPrevent2MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent2.loopTimeStart).count();
    int autoRepeatPrevent3MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent3.loopTimeStart).count();
    int autoRepeatPrevent4MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent4.loopTimeStart).count();
    int autoRepeatPrevent5MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent5.loopTimeStart).count();
    int autoRepeatPrevent6MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent6.loopTimeStart).count();
    int autoRepeatPrevent7MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent7.loopTimeStart).count();
    int autoRepeatPrevent8MS = chrono::duration_cast<ms>(myAbj.currentFrameTime - myAbj.autoRepeatPrevent8.loopTimeStart).count();

    if (pollControllerTimeMS > 50)
    {
        myAbj.pollController1.resetTimer = 1;
        myAbj.pollController1.startTime = chrono::steady_clock::now();

        //polll here
        int presentController = glfwJoystickPresent(GLFW_JOYSTICK_1);
//        cout << "presentController = " << presentController << endl;

        if (presentController == 1)
        {
            int buttonCt; //11
            const unsigned char *controllerButtons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCt);
//            cout << "buttonCt = " << buttonCt << endl;

//            int axesCt; //8
//            const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCt);
////            cout << "axesCt = " << axesCt << endl;
//
////            for (int i = 0; i < 8; ++i)
////            {
////                cout << "axes " << i << " = " << axes[i] << endl;
//////                if (axes[i] == GLFW_PRESS)
//////                    cout << "pressing button : " << i << endl;
////            }
//

            if (controllerButtons[2] == GLFW_PRESS && autoRepeatPrevent2MS >= 1000)
            {
//                cout << "pressed 2 w/o autorepeat" << endl;
//                cout << "autoRepeatPrevent2MS = " << autoRepeatPrevent2MS << endl;


                myAbj.autoRepeatPrevent2.resetTimer = 1;
                myAbj.autoRepeatPrevent2.startTime = chrono::steady_clock::now();

                system("killall -9 omxplayer omxplayer.bin");
                goBackOrForwardSec("back");
            }

            if (controllerButtons[3] == GLFW_PRESS && autoRepeatPrevent3MS >= 1000)
            {
//                cout << "pressed 3 w/o autorepeat" << endl;
//                cout << "autoRepeatPrevent3MS = " << autoRepeatPrevent3MS << endl;

                myAbj.autoRepeatPrevent3.resetTimer = 1;
                myAbj.autoRepeatPrevent3.startTime = chrono::steady_clock::now();

                system("killall -9 omxplayer omxplayer.bin");
                goBackOrForwardSec("forward");
            }

            if (controllerButtons[4] == GLFW_PRESS && autoRepeatPrevent4MS >= 1000)
            {
//                cout << "pressed 4 w/o autorepeat" << endl;
//                cout << "autoRepeatPrevent4MS = " << autoRepeatPrevent4MS << endl;

                myAbj.autoRepeatPrevent4.resetTimer = 1;
                myAbj.autoRepeatPrevent4.startTime = chrono::steady_clock::now();

                system("killall -9 omxplayer omxplayer.bin");
                speedUpOrSlowDown("decrease");
            }

            if (controllerButtons[5] == GLFW_PRESS && autoRepeatPrevent5MS >= 1000)
            {
//                cout << "pressed 5 w/o autorepeat" << endl;
                cout << "autoRepeatPrevent5MS = " << autoRepeatPrevent5MS << endl;

                myAbj.autoRepeatPrevent5.resetTimer = 1;
                myAbj.autoRepeatPrevent5.startTime = chrono::steady_clock::now();

//                system("killall -9 omxplayer omxplayer.bin");
                speedUpOrSlowDown("increase");
            }

            if (controllerButtons[6] == GLFW_PRESS && autoRepeatPrevent6MS >= 1000)
            {
                myAbj.autoRepeatPrevent6.resetTimer = 1;
                myAbj.autoRepeatPrevent6.startTime = chrono::steady_clock::now();

                myAbj.quitTgl = 1;
                system("killall -9 omxplayer omxplayer.bin");
            }

            if (controllerButtons[7] == GLFW_PRESS && autoRepeatPrevent7MS >= 1000)
            {
                myAbj.autoRepeatPrevent7.resetTimer = 1;
                myAbj.autoRepeatPrevent7.startTime = chrono::steady_clock::now();

                system("killall -9 omxplayer omxplayer.bin");
                playPauseVid();
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

string getTime(string editModeMatch, int timeToAdd)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if (i.editModeHotkey == editModeMatch)
        {

//            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - i.startTime).count();
            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>((chrono::steady_clock::now() + chrono::seconds(abs(timeToAdd)) ) - i.startTime).count();
            durSinceLastStart = glm::max(0, int(durSinceLastStart - 2)); //
//            int durSinceLastStartRounded = roundNumber(durSinceLastStart) + timeToAdd;
            int durSinceLastStartRounded = roundNumber(durSinceLastStart);
//            durSinceLastStartRounded = glm::max(0, durSinceLastStartRounded); /////
            int HH, MM, SS;

            if (timeToAdd < 0)
                durSinceLastStartRounded *= -1;

//            chrono::duration<int>timeToAddDur(timeToAdd);
//            myAbj.currentFrameTime += timeToAddDur;

//            time_t printTime = std::chrono::system_clock::to_time_t(myAbj.currentFrameTime);
//            cout << "currentFrameTime in getTime = " << printTime << endl;
//
            cout << "dur since last start rounded = " << durSinceLastStartRounded << endl;
            int testNeg = -2;
            int usableTestNeg = abs(testNeg);
            cout << "*********** usableTestNeg = " << usableTestNeg << endl;

//            i.resetPlayTimer = 1;
            i.startTime = chrono::steady_clock::now();

//            if (!in forward or back x seconds)
//            i.secUsableRoundedStored = 0;

//            for (auto &j : i.video DescriptVec)
//            {
//                if (j.pathFull == i.pathCurrent)
//                {
////                    if (durSinceLastStartRounded >= j.secDuration)
//                    if (durSinceLastStartRounded >= j.secDuration || durSinceLastStartRounded <= 0)
//                    {
////                        chrono::duration<int>timeToAddDur(timeToAdd);
////                        myAbj.currentFrameTime += timeToAddDur;
//
//
//                        i.resetPlayTimer = 1;
//                        i.startTime = chrono::steady_clock::now();
//                        i.secUsableRoundedStored = 0;
//
//                        return "00:00:00";
//                    }
//                }
//            }

            cout << "$$$$$$ i.secUsableRoundedStored BEFORE = " << i.secUsableRoundedStored << endl;
            SS = (i.secUsableRoundedStored + (durSinceLastStartRounded)) % 60;
            i.secUsableRoundedStored += durSinceLastStartRounded;
            cout << "i$$$$$ .secUsableRoundedStored AFTER = " << i.secUsableRoundedStored << endl;


            if (i.secUsableRoundedStored <= 0)
            {
                i.resetPlayTimer = 1;
                i.startTime = chrono::steady_clock::now();
                i.secUsableRoundedStored = 0;

                return "00:00:00";
            }


            MM = ((i.secUsableRoundedStored + durSinceLastStartRounded) / 60) % 60;
//            MM = (durSinceLastStartRounded / 60) % 60;
            HH = MM / 60;

            stringstream rr;
            rr << setfill('0') << setw(2) << HH << ":" << setw(2) << MM << ":" << setw(2) << SS;
            cout << "~~~~~~~~ HH:MM:SS getTime() = " << rr.str() << endl;

            return rr.str();
        }
    }

    return "getTime() error";
}

//string getTime(string editModeMatch, int timeToAdd)
//{
//    for (auto &i : myAbj.videoKernelVec)
//    {
//        if (i.editModeHotkey == editModeMatch)
//        {
//
////            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - i.startTime).count();
//            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>((chrono::steady_clock::now() + chrono::seconds(abs(timeToAdd)) ) - i.startTime).count();
//            durSinceLastStart = glm::max(0, int(durSinceLastStart - 2)); //
////            int durSinceLastStartRounded = roundNumber(durSinceLastStart) + timeToAdd;
//            int durSinceLastStartRounded = roundNumber(durSinceLastStart);
////            durSinceLastStartRounded = glm::max(0, durSinceLastStartRounded); /////
//            int HH, MM, SS;
//
//            if (timeToAdd < 0)
//                durSinceLastStartRounded *= -1;
//
////            chrono::duration<int>timeToAddDur(timeToAdd);
////            myAbj.currentFrameTime += timeToAddDur;
//
////            time_t printTime = std::chrono::system_clock::to_time_t(myAbj.currentFrameTime);
////            cout << "currentFrameTime in getTime = " << printTime << endl;
////
//            cout << "dur since last start rounded = " << durSinceLastStartRounded << endl;
//            int testNeg = -2;
//            int usableTestNeg = abs(testNeg);
//            cout << "*********** usableTestNeg = " << usableTestNeg << endl;
//
////            i.resetPlayTimer = 1;
//            i.startTime = chrono::steady_clock::now();
//
////            if (!in forward or back x seconds)
////            i.secUsableRoundedStored = 0;
//
////            for (auto &j : i.video DescriptVec)
////            {
////                if (j.pathFull == i.pathCurrent)
////                {
//////                    if (durSinceLastStartRounded >= j.secDuration)
////                    if (durSinceLastStartRounded >= j.secDuration || durSinceLastStartRounded <= 0)
////                    {
//////                        chrono::duration<int>timeToAddDur(timeToAdd);
//////                        myAbj.currentFrameTime += timeToAddDur;
////
////
////                        i.resetPlayTimer = 1;
////                        i.startTime = chrono::steady_clock::now();
////                        i.secUsableRoundedStored = 0;
////
////                        return "00:00:00";
////                    }
////                }
////            }
//
//            cout << "$$$$$$ i.secUsableRoundedStored BEFORE = " << i.secUsableRoundedStored << endl;
//            SS = (i.secUsableRoundedStored + (durSinceLastStartRounded)) % 60;
//            i.secUsableRoundedStored += durSinceLastStartRounded;
//            cout << "i$$$$$ .secUsableRoundedStored AFTER = " << i.secUsableRoundedStored << endl;
//
//            MM = ((i.secUsableRoundedStored + durSinceLastStartRounded) / 60) % 60;
////            MM = (durSinceLastStartRounded / 60) % 60;
//            HH = MM / 60;
//
//            stringstream rr;
//            rr << setfill('0') << setw(2) << HH << ":" << setw(2) << MM << ":" << setw(2) << SS;
//            cout << "~~~~~~~~ HH:MM:SS getTime() = " << rr.str() << endl;
//
//            return rr.str();
//        }
//    }
//
//    return "getTime() error";
//}


//string getTime(string editModeMatch, int timeToAdd)
//{
//    for (auto &i : myAbj.videoKernelVec)
//    {
//        if (i.editModeHotkey == editModeMatch)
//        {
////            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - i.startTime).count();
//            double durSinceLastStart = chrono::duration_cast<chrono::duration<double>>((chrono::steady_clock::now() + chrono::seconds(10) ) - i.startTime).count();
//            durSinceLastStart = glm::max(0, int(durSinceLastStart - 2)); //
////            int durSinceLastStartRounded = roundNumber(durSinceLastStart) + timeToAdd;
//            int durSinceLastStartRounded = roundNumber(durSinceLastStart);
////            durSinceLastStartRounded = glm::max(0, durSinceLastStartRounded); /////
//            int HH, MM, SS;
//
//            if (timeToAdd < 0)
//                durSinceLastStartRounded *= -1;
//
////            chrono::duration<int>timeToAddDur(timeToAdd);
////            myAbj.currentFrameTime += timeToAddDur;
//
////            time_t printTime = std::chrono::system_clock::to_time_t(myAbj.currentFrameTime);
////            cout << "currentFrameTime in getTime = " << printTime << endl;
////
//            cout << "dur since last start rounded = " << durSinceLastStartRounded << endl;
//
////            i.resetPlayTimer = 1;
//            i.startTime = chrono::steady_clock::now();
//
////            if (!in forward or back x seconds)
////            i.secUsableRoundedStored = 0;
//
////            for (auto &j : i.video DescriptVec)
////            {
////                if (j.pathFull == i.pathCurrent)
////                {
//////                    if (durSinceLastStartRounded >= j.secDuration)
////                    if (durSinceLastStartRounded >= j.secDuration || durSinceLastStartRounded <= 0)
////                    {
//////                        chrono::duration<int>timeToAddDur(timeToAdd);
//////                        myAbj.currentFrameTime += timeToAddDur;
////
////
////                        i.resetPlayTimer = 1;
////                        i.startTime = chrono::steady_clock::now();
////                        i.secUsableRoundedStored = 0;
////
////                        return "00:00:00";
////                    }
////                }
////            }
//
//            cout << "$$$$$$ i.secUsableRoundedStored BEFORE = " << i.secUsableRoundedStored << endl;
//            SS = (i.secUsableRoundedStored + (durSinceLastStartRounded)) % 60;
//            i.secUsableRoundedStored += durSinceLastStartRounded;
//            cout << "i$$$$$ .secUsableRoundedStored AFTER = " << i.secUsableRoundedStored << endl;
//
//            MM = (durSinceLastStartRounded / 60) % 60;
//            HH = MM / 60;
//
//            stringstream rr;
//            rr << setfill('0') << setw(2) << HH << ":" << setw(2) << MM << ":" << setw(2) << SS;
//            cout << "~~~~~~~~ HH:MM:SS getTime() = " << rr.str() << endl;
//
//            return rr.str();
//        }
//    }
//
//    return "getTime() error";
//}
