#ifndef __MEM_MANAGER_T__
#define __MEM_MANAGER_T__

#include <cstddef> /* size_t */
/** 
 *  @file mem_manager_t.h
 *  @brief 
 * 
 *  @details memManager_t  can 't be constructed. We want to create our own memory management system, which actually is some kind of container of memory pages. Each page is just a chunk of bytes in memory. 
 * 
 *  @author Author Yuval Hamberg (yuval.hamberg@gmail.com) 
 *	@date May 2017
 * 
 *  @bug No known bugs. 
 */ 
 


/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
typedef unsigned int Uint;


/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class MemManager_t
{
	public:
		MemManager_t();		/* Default CTOR */
		virtual ~MemManager_t() {};	/* DTOR */
	
		size_t GetPosition() const;
		size_t SetPosition(size_t _newPosition);
	
		bool IsEmpty() const;
		size_t GetSize() const;
	
		virtual size_t Read(void* _readOutput, size_t _readSize) = 0; 
		virtual size_t Read(void* _readOutput, size_t _readSize, size_t _position) = 0; 
	
		virtual size_t Write(const void* _writeData, size_t _writeSize) = 0; 
		virtual size_t Write(const void* _writeData, size_t _writeSize, size_t _position ) = 0;
	
	protected:
		size_t m_actualUsedSize;
	
	private:
	
		size_t m_currentPos;
	
		MemManager_t& operator=(const MemManager_t& _manager); // empty
		MemManager_t(const MemManager_t& _manager);		/* empty copy CTOR */
};


/* ~~~ API function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */





#endif /* __MEM_MANAGER_T__ */
