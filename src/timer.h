#ifndef TIMER_H
#define TIMER_H

#include <iostream>

class Timer
{
   public:
    static std::string currentDateTime();
    void init(double ups);
    void frame();
    bool shouldUpdate();
    double getDelta();
    double getAlpha();
    float getFPS();
    float getUPS();

   private:
    double delta = 0;
    float fps = 0;
    float ups = 0;
    double lastTime = 0;
    double accumulator = 0;
    double timer = 0;
    int frameCount = 0;
    int updateCount = 0;
};

#endif