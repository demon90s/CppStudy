#ifdef __unix
#include <unistd.h>
#include <sys/time.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

inline unsigned long PITime()
{
#ifdef __unix
	struct timezone tz = { 0, 0 };
	timeval time;
	gettimeofday(&time, &tz);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
#elif defined(_WIN32)
	return GetTickCount();
#endif
}