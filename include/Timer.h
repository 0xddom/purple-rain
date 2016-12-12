#ifndef _TIMER_H
#define _TIMER_H

class Timer {
 private:
  int startTicks;
  int pausedTicks;
  bool paused;
  bool started;

  void setState(bool, bool, int, int);

 public:
  Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  int getTicks();

  bool isStarted();
  bool isPaused();
};

#endif
