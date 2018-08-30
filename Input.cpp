#include "Input.h"

vector<string> stringSplit(string data, string token)
{
	vector<string> output;
	auto pos = string::npos;

	do
	{
		pos = data.find(token);
		output.push_back(data.substr(0, pos));

		if (string::npos != pos)
			data = data.substr(pos + token.size());

	} while (string::npos != pos);

	return output;
}

string GetFileName(string &input)
{
	string sep("/");
	size_t pos = input.find_last_of(sep);

	if (pos != string::npos)
	{
		return input.substr(pos + 1);
	}

	else
		return input;
}

string RemoveSuffix(string &input)
{
	string sep(".");
	uint pos = uint(input.find_last_of(sep));

	if (pos != string::npos)
	{
		return input.substr(0, pos);
	}

	else
		return input;
}

int roundNumber(double toRound)
{
    int round = 0;

    if (floor(toRound - .5) == (toRound - .5)) // vapor / vapour
    {
        if (rand() % 2)
            round = toRound - .5f;

        else
            round = toRound - .5f;
    }

    else
    {
        if (toRound - .5 > floor(toRound))
            round = ceil(toRound);

        if (toRound - .5 < floor(toRound))
            round = floor(toRound);
    }

    return round;
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

void playPauseVid(string appliesTo)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if ( (appliesTo == "indy" && i.editModeHotkey == myAbj.editModeVec[myAbj.editModeIdx]) || appliesTo == "all")
        {
            i.playTgl = !i.playTgl;

            if (!i.playTgl) //PAUSE the file at the stored time
            {
                i.time = getTime(i.editModeHotkey);
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
}

void muteVid(string appliesTo)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if ( (appliesTo == "indy" && i.editModeHotkey == myAbj.editModeVec[myAbj.editModeIdx]) || appliesTo == "all")
        {
            i.muteTgl = !i.muteTgl;
            i.volUsable = (i.muteTgl) ? -8000 : myAbj.volumePercentVec[i.volumePercentVecIdx].volume;

            if (i.playTgl)
            {
                i.playTgl = 0;
                i.time = getTime(i.editModeHotkey);

                stringstream ss;
                ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
                system(ss.str().c_str());

                i.startTime = chrono::steady_clock::now();
                i.resetPlayTimer = 1;
                i.playTgl = 1;
            }
        }
    }
}

void speedUpOrSlowDown(string myOperation, string appliesTo)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if ( (appliesTo == "indy" && i.editModeHotkey == myAbj.editModeVec[myAbj.editModeIdx]) || appliesTo == "all")
        {
            float speedOld = myAbj.speedPercentVec[i.speedIdx];
            i.speedIdx = (myOperation == "decrease") ? glm::clamp(i.speedIdx - 1, 0, 8) : glm::clamp(i.speedIdx + 1, 0, 8);
            float speedNew = myAbj.speedPercentVec[i.speedIdx];

            string usableTimeOld = getTime(i.editModeHotkey); /////

            int usableTimeSecOld = timeHHMMSS_toSec(usableTimeOld, 1);
            int timeSec100 = usableTimeSecOld * speedOld;
            int usableTimeSecNew = timeSec100 / speedNew;

            /* convert storedTime for next time */
            float storedSecTo100 = i.secUsableRoundedStored * speedOld;
            float storedSecNewSpeed = storedSecTo100 / speedNew;
            i.secUsableRoundedStored = storedSecNewSpeed;

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
//                    cout << "i.pathCurrent = " << i.pathCurrent << endl;

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
}

void volumeUpDown(string myOperation, string appliesTo)
{
    for (auto &i : myAbj.videoKernelVec)
    {
        if ((appliesTo == "indy" && i.editModeHotkey == myAbj.editModeVec[myAbj.editModeIdx]) || appliesTo == "all")
        {
            i.volumePercentVecIdx = (myOperation == "decrease") ? glm::clamp(i.volumePercentVecIdx - 1, 0, int(myAbj.volumePercentVec.size())) : glm::clamp(i.volumePercentVecIdx + 1, 0, int(myAbj.volumePercentVec.size()));
            i.vol = myAbj.volumePercentVec[i.volumePercentVecIdx].volume;
            i.volUsable = (i.muteTgl) ? -8000 : i.vol;

            bool playTglStored = i.playTgl;
            i.playTgl = 0;
            i.time = getTime(i.editModeHotkey);

            stringstream ss;
            ss << "omxplayer --no-osd --vol " << i.volUsable << " -o " << myAbj.soundOutput << " --pos " << i.time << " " << i.pathCurrent << " &";
            system(ss.str().c_str());

            i.startTime = chrono::steady_clock::now();
            i.resetPlayTimer = 1;
            i.playTgl = playTglStored;
        }
    }
}

void keyCallback(GLFWwindow *myWin, int key, int scancode, int action, int mods)
{
    /* PRESS */
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_Q && mods == GLFW_MOD_CONTROL)
        {
            myAbj.quitTgl = 1;
            system("killall -9 omxplayer omxplayer.bin");

            cout << endl;
            cout << "before quitting remember to store open vid name, position, volume, etc in XML !!" << endl;
        }
    }

    /* RELEASE */
    if (action == GLFW_RELEASE)
    {
        if      (key == GLFW_KEY_A) myAbj.editMode = "A";
        else if (key == GLFW_KEY_S) myAbj.editMode = "S";
        else if (key == GLFW_KEY_D) myAbj.editMode = "D";
        else if (key == GLFW_KEY_F) myAbj.editMode = "F";

        if (key == GLFW_KEY_LEFT_BRACKET)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                speedUpOrSlowDown("decrease", "all");

            else
                speedUpOrSlowDown("decrease", "indy");
        }

        else if (key == GLFW_KEY_RIGHT_BRACKET)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                speedUpOrSlowDown("increase", "all");

            else
                speedUpOrSlowDown("increase", "indy");
        }

        else if (key == GLFW_KEY_DOWN)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                volumeUpDown("decrease", "all");

            else
                volumeUpDown("decrease", "indy");
        }

        else if (key == GLFW_KEY_UP)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                volumeUpDown("increase", "all");

            else
                volumeUpDown("increase", "indy");
        }

        else if (key == GLFW_KEY_LEFT)
        {
//            system("killall -9 omxplayer omxplayer.bin");

            myAbj.editModeIdx = glm::max(0, myAbj.editModeIdx - 1);
            myAbj.editMode = myAbj.editModeVec[myAbj.editModeIdx];

            cout << "myAbj.editModeIdx / editMode = " << myAbj.editModeIdx << " " << myAbj.editMode <<endl;
        }

        else if (key == GLFW_KEY_RIGHT)
        {
//            system("killall -9 omxplayer omxplayer.bin");

            myAbj.editModeIdx = glm::min(3, myAbj.editModeIdx + 1);
            myAbj.editMode = myAbj.editModeVec[myAbj.editModeIdx];

            cout << "myAbj.editModeIdx / editMode = " << myAbj.editModeIdx << " " << myAbj.editMode <<endl;
        }

        else if (key == GLFW_KEY_SPACE)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                playPauseVid("all");

            else
                playPauseVid("indy");
        }

        else if (key == GLFW_KEY_M)
        {
            system("killall -9 omxplayer omxplayer.bin");

            if (myAbj.editMode == "F")
                muteVid("all");

            else
                muteVid("indy");
        }
    }
}
