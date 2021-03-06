#ifndef CLOCK_LOOP_H
#define CLOCK_LOOP_H

#include <chrono>
#include <thread>

template<int LOOP_PER_SECOND>
class ClockLoop {
public:
    typedef std::chrono::duration<long,std::ratio<1, LOOP_PER_SECOND>> duration_t;
    typedef std::chrono::time_point<std::chrono::system_clock, duration_t> time_point_t;

    ClockLoop() = default;

    void waitNextLoop() {
		loopEnd = loopStart + loopDuration;
		std::this_thread::sleep_until(loopEnd);
		loopStart = loopEnd;
	}
private:
	const duration_t loopDuration = duration_t(1);

	time_point_t loopStart = std::chrono::time_point_cast<duration_t>(std::chrono::system_clock::now());
	time_point_t loopEnd;
};

#endif  // CLOCK_LOOP_H
