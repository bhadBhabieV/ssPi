#include "RenderVid.h"


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
//                    cout << "loopVideoTimeMS = " << loopVideoTimeMS << endl;
//                    cout << "j.secDuration MS = " << j.secDuration * 1000 << endl;
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
