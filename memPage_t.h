#ifndef __MEM_PAGE_T__
#define __MEM_PAGE_T__

#include "memManager_t.h"


/** 
 *  @file MemPage_t.h
 *  @brief memPage_t has to hold any data as a stream of bytes 
 * 
 *  @details 
 * 
 *  @author Author Yuval Hamberg (yuval.hamberg@gmail.com) 
 *	@date  May 2017
 * 
 *  @bug No known bugs. 
 */ 
 



/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~ Class  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class MemPage_t : public MemManager_t
{
	public:
	
		MemPage_t();		/* Default CTOR */
		MemPage_t(size_t _pageCapcity);
		virtual ~MemPage_t();	/* DTOR */
	
		bool IsFull() const;
		size_t GetCapacity() const;
	
		virtual size_t Read(void* _readOutput, size_t _readSize); 
		virtual size_t Read(void* _readOutput, size_t _readSize, size_t _position); 
	
		virtual size_t Write(const void* _writeContent, size_t _writeSize); 
		virtual size_t Write(const void* _writeContent, size_t _writeSize, size_t _position );
		
		static size_t GetDefaultSize();
		static size_t SetDefaultSize(size_t _newSize);
		
	protected:
	
	private:
	
		void* m_page;
		const size_t m_pageSize;
		static size_t m_defaultPageSize; 
		
		MemPage_t& operator=(const MemPage_t& _page); // empty
		MemPage_t(const MemPage_t& _page);		/* empty copy CTOR */
};






#endif /* __MEM_PAGE_T__ */
