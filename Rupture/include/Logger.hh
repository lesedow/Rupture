#pragma once

#ifdef RUPTURE_DEBUG
	#ifndef RUPTUREINFO
		#define RUPTUREINFO 1
	#endif // !RUPTUREINFO

	#ifndef RUPTUREWARNING
		#define RUPTUREWARNING 2
	#endif // !RUPTUREWARNING

	#ifndef RUPTUREERROR
		#define RUPTUREERROR 3
	#endif // !RUPTUREERROR

	#ifndef RUPTURELOGLEVEL
		#define RUPTURELOGLEVEL RUPTUREERROR
	#endif // !RUPTURELOGLEVEL

	#if RUPTURELOGLEVEL == RUPTUREINFO
		#define RUPTURELOG 1
	#elif RUPTURELOGLEVEL == RUPTUREWARNING
		#define RUPTURELOG 2
	#elif RUPTURELOGLEVEL == RUPTUREERROR
		#define RUPTURELOG 3 
	#endif

	#ifndef RUPTUREASSERT 
	#define RUPTUREASSERT(condition, message)\
		do {\
			if (!(condition)){\
				std::cout << std::format(\
					"[ASSERT]: {} {}\nFile: {}\nLine: {}\n",\
					#condition, message, __FILE__, __LINE__);\
				__debugbreak();\
			}\
		} while (0)
	#endif
#endif