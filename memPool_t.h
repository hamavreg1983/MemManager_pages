#ifndef __MEM_POOL_T__
#define __MEM_POOL_T__

#include <vector>
#include "memManager_t.h"
#include "memPage_t.h"

/** 
 *  @file memPool_t.h
 *  @brief The role of memPool_t is to  control  placement of data in vector of  memory pages and to provide user the following functionality
 * 
 *  @details 
 * 
 *  @author Author Yuval Hamberg (yuval.hamberg@gmail.com) 
 *	@date  May 2017
 * 
 *  @bug No known bugs. 
 */ 
 



/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class MemPool_t : public MemManager_t
{
	public:
		MemPool_t();		/* Default CTOR */
		virtual ~MemPool_t();	/* DTOR */
	
		virtual size_t Read(void* _readOutput, size_t _readSize); 
		virtual size_t Read(void* _readOutput, size_t _readSize, size_t _position)	; 
	
		virtual size_t Write(const void* _writeContent, size_t _writeSize); 
		virtual size_t Write(const void* _writeContent, size_t _writeSize, size_t _position );
		
		size_t GetDefaultSize();
		size_t SetDefaultSize(size_t _newSize);
		
	protected:
	
	private:
		MemPage_t* GetCurrentPage(size_t _position, size_t* _internalPosition);
		MemPage_t* CreateNewPage();
		
		std::vector <MemPage_t*> m_vector_pages;
	
		MemPool_t& operator=(const MemPool_t& _pool) ; // empty
		MemPool_t(const MemPool_t& _pool) ;			/* empty copy CTOR */
};


/* ~~~ API function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */





#endif /* __MEM_POOL_T__ */
