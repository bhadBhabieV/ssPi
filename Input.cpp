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
        if (key == GLFW_KEY_LEFT_BRACKET)
        {
            system("killall -9 omxplayer omxplayer.bin");
            speedUpOrSlowDown("decrease");
        }

        else if (key == GLFW_KEY_RIGHT_BRACKET)
        {
            system("killall -9 omxplayer omxplayer.bin");
            speedUpOrSlowDown("increase");
        }

        else if (key == GLFW_KEY_DOWN)
        {
            system("killall -9 omxplayer omxplayer.bin");
            volumeUpDown("decrease");
        }

        else if (key == GLFW_KEY_UP)
        {
            system("killall -9 omxplayer omxplayer.bin");
            volumeUpDown("increase");
        }

        else if (key == GLFW_KEY_SPACE)
        {
            system("killall -9 omxplayer omxplayer.bin");
            playPauseVid();
        }

        else if (key == GLFW_KEY_M)
        {
            system("killall -9 omxplayer omxplayer.bin");
            muteVid();
        }
    }
}
