#ifndef CLOCK_LOOP_HPP
#define CLOCK_LOOP_HPP

#include <chrono>
#include <thread>

template <int LOOP_PER_SECOND> class ClockLoop {

typedef std::chrono::duration<long,std::ratio<1, LOOP_PER_SECOND>> 
duration_t;
typedef std::chrono::time_point<std::chrono::system_clock, duration_t> time_point_t;

public:
    ClockLoop() {}

    void waitNextLoop() {
		this->loopEnd = this->loopStart + loopDuration;

		std::this_thread::sleep_until(this->loopEnd);
		this->loopStart = loopEnd;
	}
private:
	const duration_t loopDuration = duration_t(1);

	time_point_t loopStart = 
		std::chrono::time_point_cast<duration_t>(std::chrono::system_clock::now());
	// Variable in the class to avoid creating one at each loop.
	// Performance gain?
	time_point_t loopEnd;
};

#endif  // SERVER_SCENE_HPP