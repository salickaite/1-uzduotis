#pragma once
#include <chrono>
class laikmatis {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	laikmatis() : start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}

};