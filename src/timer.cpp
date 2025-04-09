#include "timer.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using timer_clock = std::chrono::high_resolution_clock;
using timer_time_point = std::chrono::time_point<timer_clock>;

static timer_time_point lastFrameTime = timer_clock::now();

std::string Timer::currentDateTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&timeNow);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Timer::init(double upsRate)
{
    ups = upsRate;
    lastTime = std::chrono::duration<double>(timer_clock::now().time_since_epoch()).count();
    accumulator = 0.0;
    frameCount = 0;
    updateCount = 0;
    timer = 0.0;
}

void Timer::frame()
{
    auto current = timer_clock::now();
    double currentTime = std::chrono::duration<double>(current.time_since_epoch()).count();
    delta = currentTime - lastTime;
    lastTime = currentTime;

    accumulator += delta;
    timer += delta;
    frameCount++;

    if (timer >= 1.0)
    {
        fps = frameCount / timer;
        updateCount = 0;
        frameCount = 0;
        timer = 0.0;
    }
}

bool Timer::shouldUpdate()
{
    double updateInterval = 1.0 / ups;
    if (accumulator >= updateInterval)
    {
        accumulator -= updateInterval;
        updateCount++;
        return true;
    }
    return false;
}

double Timer::getDelta()
{
    return delta;
}

double Timer::getAlpha()
{
    return accumulator / (1.0 / ups);
}
float Timer::getFPS()
{
    return fps;
}

float Timer::getUPS()
{
    return ups;
}
