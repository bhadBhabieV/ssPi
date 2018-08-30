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
