#pragma once
#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

class StopWatch
{
public:
	StopWatch()	
	{
    #ifdef WIN32
		QueryPerformanceFrequency(&counterFrequency_);
		QueryPerformanceCounter(&start_);
    #else
		gettimeofday(&start_, 0);
    #endif
	}

	void Reset()
	{
    #ifdef WIN32
		QueryPerformanceCounter(&start_);
    #else
		gettimeofday(&start_, 0);
    #endif
	}

	// Get elapsed time in seconds
	float GetElapsedSeconds()
	{
    #ifdef WIN32
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		return float((now.QuadPart - start_.QuadPart) /	double(counterFrequency_.QuadPart));
    #else
		timeval now;
		gettimeofday(&now, 0);
		float fSeconds = (float)(now.tv_sec - start_.tv_sec);
		float fFraction = (float)(now.tv_usec - start_.tv_usec) * 0.000001f;
		return fSeconds + fFraction;
    #endif
	}

private:
#ifdef WIN32
	LARGE_INTEGER counterFrequency_;
	LARGE_INTEGER start_;
#else
	timeval start_;
#endif
};