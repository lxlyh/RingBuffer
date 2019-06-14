//////////////////////////////////////////////////////////////////////////////////////////////////////
// 	File name	:	RingBuffer.h
// 	Brief 		: 	A ring buffer of data stream. This ring buffer library can be used for all data
//					type: 8-bit, 16, 32,64-bit, structure data types....
//	Author 		: 	AnhNH57
//  Note 		: 	
//////////////////////////////////////////////////////////////////////////////////////////////////////
// 	MODIFICATION HISTORY:
//
// 	Ver  	PIC  		Date       	Changes
// 	----- 	-------- 	---------- 	------------------------------------------------------------------
// 	1.00  	AnhNH57  	02-07-2013 	Create Framework
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////// Include Files /////////////////////////////////////////////
#include "pic24h_generic.h"
#include "RTOSHelper.h"

///////////////////////////////////// Constant Definitions ///////////////////////////////////////////

/////////////////////////////////////// Type Definitions /////////////////////////////////////////////
// Generic Ring buffer structure
typedef struct S_RING_BUFFER
{
	void*					pvBuffer;					// Data buffer
	UINT16					uiBufferSize;				// Size of buffer or the total of elements
	UINT16					uiElementCount;				// The element count of buffer
	UINT16					uiBufferPopPtr;				// The pointer to start reading
	UINT16					uiBufferPushPtr;			// The pointer to start writing

	UINT16					uiBKElementCount;			// Backup value of the element count of buffer
	UINT16					uiBKBufferPopPtr;			// Backup value of the pointer to start reading
	UINT16					uiBKBufferPushPtr;			// Backup value of the pointer to start writing	
	
	UINT16					uiElementSize;				// Size of each element of the buffer in byte
	BOOL					bBufferPopEnable;			// Data popping enabling flag
	BOOL					bBufferPushEnable;			// Data pushing enabling flag
	
	CallbackFunction1I0O	callbackLock;				// Call-back function for locking multi-access
	CallbackFunction1I0O	callbackUnlock;				// Call-back function for unlocking multi-access
	void*					pvCallbackParam;			// Parameter of the call-back function
	
} SRingBuffer;

///////////////////////////// Macros (Inline Functions) Definitions //////////////////////////////////

///////////////////////////////////// Function Prototypes ////////////////////////////////////////////
void			BufferInit(SRingBuffer* psRingBuffer, 
						   void* pvBuffer, 
						   UINT16 uiBufferSize, 
						   UINT16 uiElementSize, 
						   CallbackFunction1I0O callbackLock, 
						   CallbackFunction1I0O callbackUnlock, 
						   void* pvCallbackParam);

BOOL 			BufferPushStream(SRingBuffer* psRingBuffer, void* pvStream, UINT16 uiLength);
UINT16 			BufferPopStream(SRingBuffer* psRingBuffer, void* pvStream, UINT16 uiLength);
BOOL 			BufferPush(SRingBuffer* psRingBuffer, void* pvData);
UINT16			BufferPop(SRingBuffer* psRingBuffer, void* pvData);
BOOL			BufferPushBack(SRingBuffer* psRingBuffer, UINT16 uiPushBackNumber);
BOOL 			BufferIsPushEnable(SRingBuffer* psRingBuffer);
BOOL 			BufferIsPopEnable(SRingBuffer* psRingBuffer);
void			BufferEnablePop(SRingBuffer* psRingBuffer);
void			BufferDisablePop(SRingBuffer* psRingBuffer);
void			BufferEnablePush(SRingBuffer* psRingBuffer);
void			BufferDisablePush(SRingBuffer* psRingBuffer);
UINT16			BufferGetCount(SRingBuffer* psRingBuffer);
UINT16			BufferGetAvailableCount(SRingBuffer* psRingBuffer);
void			BufferSaveState(SRingBuffer* psRingBuffer);
void			BufferRestoreState(SRingBuffer* psRingBuffer);
void 			BufferFlush(SRingBuffer* psRingBuffer);

///////////////////////////////////// Variable Definitions ///////////////////////////////////////////


#ifdef __cplusplus
}
#endif

#endif	// _RING_BUFFER_H_
