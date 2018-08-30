#include "Core.h"
#include "Input.h"

#include <glob.h>
#include "RenderVid.h"

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

//https://www.youtube.com/watch?v=eJ1o3JibPQg
Abj myAbj;

int main(int argc, char *argv[])
{
    myAbjInit();

    srand(static_cast<int>(time(0)));

	glfwInit();

	//try experimental
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_DECORATED, GL_FALSE); //

    /* WIDTH / HEIGHT */
	myAbj.width = 50;
	myAbj.height = 50;

    myAbj.GLFWwin = glfwCreateWindow(myAbj.width, myAbj.height, "Shadows Spider", 0, 0); //windowed
    glfwSetWindowPos(myAbj.GLFWwin, 0, 0);

    glfwMakeContextCurrent(myAbj.GLFWwin);
	glewExperimental = 1;
	glewInit();
	glfwSetInputMode(myAbj.GLFWwin, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(myAbj.GLFWwin, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	glfwSetKeyCallback(myAbj.GLFWwin, keyCallback);

	glfwSwapInterval(0); //vsync off
	glClearColor(0.f, 0.f, 0.f, 0.f);
    glfwFocusWindow(myAbj.GLFWwin);

    playPauseVid();

    do
    {
        timeBasedStuff();
//
//        loopVideo();
//
////        auto time_point = chrono::system_clock::now();
////        time_t ttp = chrono::system_clock::to_time_t(time_point);
////        cout << "~~~ time: " << ctime(&ttp);
//
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, myAbj.width, myAbj.height);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(myAbj.GLFWwin);
        glfwPollEvents();
    }

    while
        (!myAbj.quitTgl && !glfwWindowShouldClose(myAbj.GLFWwin));

    glfwTerminate();

    return 0;
}

//int main(int argc, char *argv[])
//{
//    myAbjInit();
//
//    //SPD - DURATION(HHMMSS)
//    //    025000028_timerCountUp.mp4
//    //    050000028_timerCountUp.mp4
//    //    075000028_timerCountUp.mp4
//    //    100000028_timerCountUp.mp4
//    //    125000028_timerCountUp.mp4
//    //    150000028_timerCountUp.mp4
//
//    myAbj.editModePathHotkeyVec =
//    {
//        { "/home/pi/Desktop/source/repos/ssPi_videos/300/", "A" },
////        { "/home/pi/Desktop/source/repos/ssPi_videos/A/", "A" },
////        { "/home/pi/Desktop/source/repos/ssPi_videos/S/", "S" },
//    };
//
//    for (auto &i : myAbj.editModePathHotkeyVec)
//    {
//        stringstream ss;
//        ss << i.path << "*";
//        string pathWildcard = ss.str();
//
//        glob_t glob_result;
//        glob(pathWildcard.c_str(), GLOB_TILDE, NULL, &glob_result);
//
//        VideoKernel myVideoKernel;
//        myVideoKernel.playTgl = 0;
//        myVideoKernel.speedIdx = 3;
//        myVideoKernel.editModeHotkey = i.hotkey;
//        myVideoKernel.pathCurrent = "test";
//        myVideoKernel.secUsableRoundedStored = 0;
//        myVideoKernel.time = "00:00:00";
//        myVideoKernel.usableStartPos = "00:00:00";
//        myVideoKernel.volumePercentVecIdx = 5;
//        myVideoKernel.vol = myAbj.volumePercentVec[myVideoKernel.volumePercentVecIdx].volume;
//        myVideoKernel.muteTgl = 0;
//        myVideoKernel.volUsable = (myVideoKernel.muteTgl) ? -8000 : myVideoKernel.vol;
//        myVideoKernel.resetPlayTimer = 1;
//
//        for (uint j = 0; j < glob_result.gl_pathc; ++j)
//        {
//            string globFilePath = glob_result.gl_pathv[j]; //pathFull
//            string fileWithExt = stringSplit(globFilePath, i.path)[1];
//
//            /* GET SPEED */
//            string first10 = fileWithExt.substr(0, 10);
//            vector<string> mySplitVec1 = stringSplit(fileWithExt, first10);
//
//            string substrSpeed = fileWithExt.substr(0, 3);
//            string substrSpeedF0 = substrSpeed.substr(0, 1);
//            string substrSpeedF1 = substrSpeed.substr(1, 2);
//
//            stringstream ss;
//            ss << substrSpeedF0 << "." << substrSpeedF1;
//            float speedF = atof(ss.str().c_str());
//
//            if (speedF == 1.f)
//                myVideoKernel.pathCurrent = globFilePath;
//
//            VideoDescript myVideoDescript;
//            myVideoDescript.speed = speedF;
//            myVideoDescript.stringDuration = timeHHMMSS(fileWithExt.substr(3, 6));
//            myVideoDescript.secDuration = timeHHMMSS_toSec(fileWithExt.substr(3, 6), 0);
////            myVideoDescript.secDuration = 10; //2;
//            myVideoDescript.pathFull = globFilePath;
//            myVideoDescript.pathShort = RemoveSuffix(mySplitVec1[1]);
//
//            myVideoKernel.videoDescriptVec.push_back(myVideoDescript);
//
//
////            cout << "myVideoDescript.speed = " << myVideoDescript.speed << endl;
////            cout << "myVideoDescript.stringDuration = " << myVideoDescript.stringDuration << endl;
////            cout << "myVideoDescript.secDuration = " << myVideoDescript.secDuration << endl;
////            cout << "myVideoDescript.pathFull = " << myVideoDescript.pathFull << endl;
////            cout << "myVideoDescript.pathShort = " << myVideoDescript.pathShort << endl;
////            cout << endl;
//        }
//
//        myAbj.videoKernelVec.push_back(myVideoKernel);
//    }
//
//    srand(static_cast<int>(time(0)));
//
//	glfwInit();
//
//	//try experimental
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//
//    int presentController = glfwJoystickPresent(GLFW_JOYSTICK_1);
//    cout << "presentController = " << presentController << endl;
//
//    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
//	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//	glfwWindowHint(GLFW_DECORATED, GL_FALSE); //
//
//    /* WIDTH / HEIGHT */
//	myAbj.width = 50;
//	myAbj.height = 50;
//
////    myAbj.width = 1920;
////	myAbj.height = 1080;
//
//    myAbj.GLFWwin = glfwCreateWindow(myAbj.width, myAbj.height, "Shadows Spider", 0, 0); //windowed
//    glfwSetWindowPos(myAbj.GLFWwin, 0, 0);
//
//    glfwMakeContextCurrent(myAbj.GLFWwin);
//	glewExperimental = 1;
//	glewInit();
//	glfwSetInputMode(myAbj.GLFWwin, GLFW_STICKY_KEYS, GL_TRUE);
//	glfwSetInputMode(myAbj.GLFWwin, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
////	glfwSetInputMode(myAbj.GLFWwin, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//
////	glfwSetCursorPosCallback(myAbj.GLFWwin, cursorPosCallback);
////	glfwSetMouseButtonCallback(myAbj.GLFWwin, mouseButtonCallback);
//	glfwSetKeyCallback(myAbj.GLFWwin, keyCallback);
////	glfwSetScrollCallback(myAbj.GLFWwin, scrollCallback);
//
//	glfwSwapInterval(0); //vsync off
//	glClearColor(0.f, 0.f, 0.f, 0.f);
//    glfwFocusWindow(myAbj.GLFWwin);
//
//    playPauseVid();
//
//    do
//    {
//        timeBasedStuff();
//
//        loopVideo();
//
////        auto time_point = chrono::system_clock::now();
////        time_t ttp = chrono::system_clock::to_time_t(time_point);
////        cout << "~~~ time: " << ctime(&ttp);
//
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//        glViewport(0, 0, myAbj.width, myAbj.height);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glfwSwapBuffers(myAbj.GLFWwin);
//        glfwPollEvents();
//    }
//
//    while
//        (!myAbj.quitTgl && !glfwWindowShouldClose(myAbj.GLFWwin));
//
//    glfwTerminate();
//
//    return 0;
//}

void myAbjInit()
{
    myAbj.quitTgl = 0;

    myAbj.volumePercentVec =
    {
        { -8000, 0 },
        { -2000, .1f },
        { -1204, .25f },
        { -602, .5f },
        { -249, .75f },
        { 0, 1.f },
    };

    myAbj.soundOutput = "local";
    myAbj.speedPercentVec = { .25f, .5f, .75f, 1.f, 1.2f, 1.3f, 1.35f, 1.4f, 1.5f };

    myAbj.pollController1.resetTimer = 1;
    myAbj.autoRepeatPrevent5.resetTimer = 1;
}
