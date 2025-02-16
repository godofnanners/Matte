#pragma once

#define MIN(a,b)\
(((a)<(b)) ? a:b)
	

#define MAX(a,b)\
	(((a)>(b)) ? a:b)
#define SAFE_DELETE(a)\
	delete a,\
	a=nullptr
#define SAFE_DELETE_ARRAY(a)\
delete[] a,\
a=nullptr

#define CLAMP(a,b,c)\
((a)<MIN(b,c)) ? ((a)=MIN(b,c)):((a)>MAX(b,c) ? a=MAX(b,c):a)

constexpr auto PI = (3.1415926535897f);


