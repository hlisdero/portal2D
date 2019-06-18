#ifndef SCREEN_RECORDER_H
#define SCREEN_RECORDER_H

#include <cstdio>
#include <stdexcept>
#include <cstdlib>
#include "common/protocol/abstract_thread.h"

class ScreenRecorder : public AbstractThread {
public:
    explicit ScreenRecorder() = default;
    ~ScreenRecorder();

    virtual void run() override;

private:
    // FILE *process;
};

#endif  // SCREEN_RECORDER_H
