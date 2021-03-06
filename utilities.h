#include <chrono>

#define TIMER std::chrono::time_point<std::chrono::steady_clock>
#define TIC chrono::steady_clock::now()
#define TOC chrono::steady_clock::now()

double get_time_us( std::chrono::time_point<std::chrono::steady_clock> & start, 
					std::chrono::time_point<std::chrono::steady_clock> & end, 
					uint32_t N=1);