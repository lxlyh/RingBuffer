//////////////////////////////////////////////////////////////////////////////////////////////////////
// 	File name	:	Typedef.h
// 	Brief 		: 	Define common data types for almost processor architectures, which have one of 
//					8/16/32/64-bit data bus types
//	Author 		: 	AnhNH57
//  Note 		: 	
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
// 	MODIFICATION HISTORY:
//
// 	Ver  	PIC  		Date       	Changes
// 	----- 	-------- 	---------- 	------------------------------------------------------------------
// 	1.00  	AnhNH57  	28-08-2015 	Create Framework
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TYPE_DEF__
#define __TYPE_DEF__

// unsigned 8-bit data types
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned char			BYTE;

// signed 8-bit data types
typedef char					CHAR;
typedef char					INT8;

// unsigned 16-bit types
//typedef unsigned short			UINT16;
typedef unsigned int			UINT16;
typedef unsigned short			WORD;

// signed 16-bit types
//typedef short					INT16;
typedef int					INT16;

// unsigned 32-bit types
typedef unsigned long			ULONG;
typedef unsigned long			UINT32;
typedef unsigned long			DWORD;

// signed 32-bit types
typedef long					LONG;
typedef long					INT32;

// unsigned 64-bit types
typedef unsigned long long		ULONGLONG;
typedef unsigned long long		UINT64;

// signed 64-bit types
typedef long long				LONGLONG;
typedef long long				INT64;

// Boolean types
#ifndef BOOL
	typedef int					BOOL;
	#define TRUE				1
	#define FALSE				0
#endif	

// Pointer types
#ifndef LPVOID
  typedef void*					LPVOID;
  typedef BYTE*					LPBYTE;
  typedef WORD*					LPWORD;
  typedef DWORD*				LPDWORD;
#endif

// NULL type
#ifndef NULL
#define NULL	0
#endif


#endif	// __TYPE_DEF__
