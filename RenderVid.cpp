#include "RenderVid.h"


void goBackOrForwardSec(string forwardOrBack)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if (i.playTgl)
        {
//            i.time = getTime(i.editModeHotkey, 30);
//            i.time = getTime(i.editModeHotkey, 0);

            for (auto &j : i.videoDescriptVec)
            {
                if (j.pathFull == i.pathCurrent)
                {
//                    int loopVideoTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - i.loopTimeStart).count() + (i.secUsableRoundedStored * 1000);

                    if (forwardOrBack == "back")
                    {
//                        loopVideoTimeMS -= 10000;
//9739436077
//                        if (loopVideoTimeMS < 0)
//                        {
//                            system("killall -9 omxplayer omxplayer.bin");
//                            i.resetPlayTimer = 1;
//                            i.startTime = chrono::steady_clock::now();
//                            i.secUsableRoundedStored = 0;
//
//                            i.loopTimeStart = myAbj.currentFrameTime; //
//                            i.resetPlayTimer = 0;
//
                            stringstream ss;
//                            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << "00:00:00" << " " << i.pathCurrent << " &";
                            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " " << i.pathCurrent << " &";
                            system(ss.str().c_str());
//
////                            loopVideo();
//                        }
//
//                        else
//                        {
//
//                        }
                    }
//
                    if (forwardOrBack == "forward")
                    {
                        if (i.playTgl)
                        {
                            i.time = getTime(i.editModeHotkey, 30);

                            stringstream ss;
                            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
                            system(ss.str().c_str());

//                            i.startTime = chrono::steady_clock::now();
//                            i.resetPlayTimer = 1;
                        }
                    }

                }
            }
        }
    }
}

void loopVideo()
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if (i.playTgl)
        {
            if (i.resetPlayTimer)
            {
                i.loopTimeStart = myAbj.currentFrameTime; //
                i.resetPlayTimer = 0;
            }

            for (auto &j : i.videoDescriptVec)
            {
                if (j.pathFull == i.pathCurrent)
                {
                    int loopVideoTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - i.loopTimeStart).count() + (i.secUsableRoundedStored * 1000);

                    cout << "loopVideoTimeMS = " << loopVideoTimeMS << endl;
//                    cout << "j.secDuration MS = " << j.secDuration * 1000 << endl;
//                    cout << "j.secDuration MS + 5000= " << (j.secDuration * 1000) + 5000 << endl;
    //
//                    if (loopVideoTimeMS >= (j.secDuration * 1000) + 2000)
                    if (loopVideoTimeMS >= (j.secDuration * 1000) + 5000)
                    {
                        cout << endl;
                        cout << "video has ended, begin new loop" << endl;
                        cout << endl;

                        system("killall -9 omxplayer omxplayer.bin");

                        stringstream ss;
                        ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.usableStartPos << " " << i.pathCurrent << " &";
                        system(ss.str().c_str());

                        i.resetPlayTimer = 1;
                        i.startTime = chrono::steady_clock::now();
                        i.secUsableRoundedStored = 0;
                    }
                }
            }
        }
    }

}

//void loopVideo()
//{
//    for (auto &i : myAbj.videoKernelVec)
//    {
//        if (i.playTgl)
//        {
//            if (i.resetPlayTimer)
//            {
//                i.loopTimeStart = myAbj.currentFrameTime; //
//                i.resetPlayTimer = 0;
//            }
//
//            for (auto &j : i.videoDescriptVec)
//            {
//                if (j.pathFull == i.pathCurrent)
//                {
//                    int loopVideoTimeMS = chrono::duration_cast<ms>(myAbj.currentFrameTime - i.loopTimeStart).count() + (i.secUsableRoundedStored * 1000);
//
//                    cout << "loopVideoTimeMS = " << loopVideoTimeMS << endl;
//                    cout << "j.secDuration MS = " << j.secDuration * 1000 << endl;
//                    cout << "j.secDuration MS + 5000= " << (j.secDuration * 1000) + 5000 << endl;
//    //
////                    if (loopVideoTimeMS >= (j.secDuration * 1000) + 2000)
//                    if (loopVideoTimeMS >= (j.secDuration * 1000) + 5000)
//                    {
//                        cout << endl;
//                        cout << "video has ended, begin new loop" << endl;
//                        cout << endl;
//
//                        system("killall -9 omxplayer omxplayer.bin");
//
//                        stringstream ss;
//                        ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.usableStartPos << " " << i.pathCurrent << " &";
//                        system(ss.str().c_str());
//
//                        i.resetPlayTimer = 1;
//                        i.startTime = chrono::steady_clock::now();
//                        i.secUsableRoundedStored = 0;
//                    }
//                }
//            }
//        }
//    }
//
//}

void playPauseVid()
{
    for (auto &i : myAbj.videoKernelVec)
    {
        i.playTgl = !i.playTgl;

        if (!i.playTgl) //PAUSE the file at the stored time
        {
            i.time = getTime(i.editModeHotkey, 0);
            i.resetPlayTimer = 1;
        }

        else //PLAY the file at the stored time
        {
            stringstream ss;
            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
            system(ss.str().c_str());

            i.startTime = chrono::steady_clock::now(); //
            i.resetPlayTimer = 1;
        }

//            cout << "time playPauseVid() = " << i.time << endl;
    }
}

void muteVid()
{
    for (auto &i : myAbj.videoKernelVec)
    {
        i.muteTgl = !i.muteTgl;
        i.volUsable = (i.muteTgl) ? -8000 : myAbj.volumePercentVec[i.volumePercentVecIdx].volume;

        if (i.playTgl)
        {
            i.time = getTime(i.editModeHotkey, 0);

            stringstream ss;
            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
            system(ss.str().c_str());

            i.startTime = chrono::steady_clock::now();
            i.resetPlayTimer = 1;
        }
    }
}

void speedUpOrSlowDown(string myOperation)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        float speedOld = myAbj.speedPercentVec[i.speedIdx];
        i.speedIdx = (myOperation == "decrease") ? glm::clamp(i.speedIdx - 1, 0, 8) : glm::clamp(i.speedIdx + 1, 0, 8);
        float speedNew = myAbj.speedPercentVec[i.speedIdx];

        string usableTimeOld = getTime(i.editModeHotkey, 0); /////

        int usableTimeSecOld = timeHHMMSS_toSec(usableTimeOld, 1);
        int timeSec100 = usableTimeSecOld * speedOld;
        int usableTimeSecNew = timeSec100 / speedNew;

        /* convert storedTime for next time */
        float storedSecTo100 = i.secUsableRoundedStored * speedOld;
        i.secUsableRoundedStored = storedSecTo100 / speedNew;

        for (auto &j : i.videoDescriptVec)
        {
            if (j.speed == myAbj.speedPercentVec[i.speedIdx])
            {
                i.pathCurrent = j.pathFull;
                i.time = secToHHMMSS(glm::clamp(usableTimeSecNew, 0, j.secDuration - 1));
//                    i.time = secToHHMMSS(usableTimeSecNew);

                cout << endl;
//                    cout << "j.secDuration = " << j.secDuration << endl;
//                    cout << "usableTimeSecOld = " << usableTimeSecOld << endl;
//                    cout << "usableTimeOld in HHMMSS = " << usableTimeOld << endl;
//                    cout << "speedOld = " << speedOld << endl;
//                    cout << "timeSec100 = " << timeSec100 << endl;
//                    cout << "speedNew = " << speedNew << endl;
//                    cout << "usableTimeSecNew = " << usableTimeSecNew << endl;
//                    cout << "i.time = " << i.time << endl;
                cout << "i.pathCurrent = " << i.pathCurrent << endl;

                cout << "speedNew = " << speedNew << endl;
                cout << endl;
            }
        }

        bool playTglStored = i.playTgl;
        i.playTgl = 0;

        stringstream ss;
        ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
        system(ss.str().c_str());

        i.startTime = chrono::steady_clock::now();
        i.playTgl = playTglStored;
        i.resetPlayTimer = 1;
    }
}

void volumeUpDown(string myOperation)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        i.volumePercentVecIdx = (myOperation == "decrease") ? glm::clamp(i.volumePercentVecIdx - 1, 0, int(myAbj.volumePercentVec.size())) : glm::clamp(i.volumePercentVecIdx + 1, 0, int(myAbj.volumePercentVec.size()));
        i.vol = myAbj.volumePercentVec[i.volumePercentVecIdx].volume;
        i.volUsable = (i.muteTgl) ? -8000 : i.vol;

        bool playTglStored = i.playTgl;
        i.playTgl = 0;
        i.time = getTime(i.editModeHotkey, 0);

        stringstream ss;
        ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
        system(ss.str().c_str());

        i.startTime = chrono::steady_clock::now();
        i.resetPlayTimer = 1;
        i.playTgl = playTglStored;
    }
}
