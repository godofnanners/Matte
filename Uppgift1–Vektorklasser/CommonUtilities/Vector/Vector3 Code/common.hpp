
#ifndef ALIB_META
#define ALIB_META

#ifdef _WIN32
	#define ALIB_WINDOWS

	#undef UNICODE
	#define UNICODE
#endif


#ifdef _MSC_VER
	
	#define strong_inline __forceinline

#endif

#endif
