#ifndef CORE_H
#define CORE_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>
//#include <glm/glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/norm.hpp>
#include <gtx/transform.hpp>
#include <gtx/string_cast.hpp>
#include <gtx/compatibility.hpp>
#include <gtx/color_space.hpp>
#include <gtx/component_wise.hpp>
#include <gtx/vector_angle.hpp>
#include <gtx/matrix_decompose.hpp>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <chrono>
#include <random>
#include <algorithm>
#include <assert.h>
#include <string>
#include <vector>
#include <cstddef>
#include <map>
#include <fstream>
#include <cfenv>
#include <ctime>

using namespace std;
using ms = chrono::duration<float, std::milli>;

typedef struct
{
    int volume;
    float percent;
} volumePercent;

typedef struct
{
    float speed;
    string stringDuration;
    int secDuration;
    string pathFull, pathShort;
} VideoDescript;

typedef struct
{
    bool resetTimer;
    chrono::steady_clock::time_point startTime, loopTimeStart;
    float deltaTime;

} PollController;

typedef struct
{
    vector<VideoDescript> videoDescriptVec;

    bool playTgl;
    int speedIdx;
    string time; //HH:MM:SS
    string editModeHotkey;
    string pathCurrent;

    int storedPauseTime;
    bool resetPlayTimer;
    int secUsableRoundedStored;
    string usableStartPos;

    chrono::steady_clock::time_point startTime, loopTimeStart;
    float deltaTime;

    bool muteTgl;
    int volumePercentVecIdx;
    int vol, volUsable;

} VideoKernel;

typedef struct
{
//    string path;
    const char *path;
    string hotkey;
} pathHotkey;

typedef struct
{
    vector<VideoKernel> videoKernelVec;
    vector<pathHotkey> editModePathHotkeyVec;
    vector<PollController> autoRepeatVec;

    GLFWwindow *GLFWwin;
    int width, height;
    glm::vec2 winPosGlobal;

    vector<volumePercent> volumePercentVec;
    vector<float> speedPercentVec;

    string soundOutput;
    bool quitTgl;
    int seekTime;

    float deltaFrameTime;
    chrono::steady_clock::time_point currentFrameTime, lastFrameTime, loopTimeStart;

    PollController pollController1, autoRepeatPrevent0, autoRepeatPrevent1, autoRepeatPrevent2, autoRepeatPrevent3, autoRepeatPrevent4, autoRepeatPrevent5, autoRepeatPrevent6, autoRepeatPrevent7, autoRepeatPrevent8;
} Abj;


int roundNumber(double);
vector<string> stringSplit(string, string);
string GetFileName(string &);
string RemoveSuffix(string &);

void myAbjInit();


extern Abj myAbj;

#endif // CORE_H_INCLUDED
