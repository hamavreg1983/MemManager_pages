#include <vector>
#include <cstddef>

#include <iostream> /* cout */
#include "memPool_t.h"


/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~ Internal function forward declartion ~~~~~~~~~~~~~~~~~~~~~~~~ */



/* ~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


MemPool_t::MemPool_t()
{
	CreateNewPage();
}

MemPool_t::~MemPool_t()
{
	// delete page inside vector
	
	for(std::vector<MemPage_t*>::iterator it = m_vector_pages.begin(); it != m_vector_pages.end(); ++it)
	{
		delete *it;
	}
}

size_t MemPool_t::Read(void* _readOutput, size_t _readSize)
{
	return Read(_readOutput, _readSize, GetPosition() );
}

size_t MemPool_t::Read(void* _readOutput, size_t _readSize, size_t _position)
{
	size_t interanlPosition;
	int resultRead = 0;
	MemPage_t* currentPage;
	
	if (!SetPosition(_position)) // test if moved succsusfly.
	{
		return 0;
	}
	
	while (resultRead != _readSize )
	{
		currentPage = GetCurrentPage(GetPosition(), &interanlPosition);
		if (NULL == currentPage)
		{
			break;
		}
		if (GetPosition() >= m_actualUsedSize)
		{
			break;
		}
		
		_readSize -= resultRead;
		
		resultRead = currentPage->Read((char*)_readOutput + resultRead, _readSize, interanlPosition );
		
		SetPosition(GetPosition() + resultRead);
	}
	
	return GetPosition() - _position;
}


size_t MemPool_t::Write(const void* _writeContent, size_t _writeSize)
{
	return Write(_writeContent, _writeSize, GetPosition() );
}

size_t MemPool_t::Write(const void* _writeContent, size_t _writeSize, size_t _position )
{
	size_t interanlPosition;
	MemPage_t* currentPage = GetCurrentPage(_position, &interanlPosition);
	if (NULL == currentPage)
	{
		return 0;
	}
	
	if (!SetPosition(_position)) // test if moved succsusfly.
	{
		return 0;
	}
	
	int resultWrite = currentPage->Write(_writeContent, _writeSize, interanlPosition );
	
	while (resultWrite != _writeSize)
	{
		if (m_actualUsedSize == GetPosition())
		// check if need to create a new page, or just continue to overritte.
		{
			CreateNewPage(); 
		}
		
		_writeSize -= resultWrite;
		m_actualUsedSize += resultWrite;
		SetPosition(GetPosition() + resultWrite);
		
		currentPage = GetCurrentPage(GetPosition(), &interanlPosition);
		if (NULL == currentPage)
		{
			break;
		}
		
		resultWrite = currentPage->Write((char*)_writeContent + resultWrite, _writeSize, interanlPosition ); 
		
		// can't write a signal item which is larger than a page
	}
	
	m_actualUsedSize += resultWrite;
	SetPosition(GetPosition() + resultWrite);
	
	return GetPosition() - _position;
}

size_t MemPool_t::GetDefaultSize()
{
	return MemPage_t::GetDefaultSize();
}

size_t MemPool_t::SetDefaultSize(size_t _newSize)
{
	return MemPage_t::SetDefaultSize(_newSize);
}


MemPage_t* MemPool_t::GetCurrentPage(size_t _position, size_t* _internalPosition)
{
	if (_position > m_actualUsedSize || NULL == _internalPosition)
	{
		return NULL;
	}
	
	size_t nextPagePosition = 0;
	size_t currentPagePosition = 0;
	int it = 0;
	size_t interalPos;
	
	while (nextPagePosition <= m_actualUsedSize)
	{
		nextPagePosition += m_vector_pages[it]->GetCapacity();
		
		if (nextPagePosition > _position)
		{
			interalPos = _position - currentPagePosition;
			break;
		}
		++it;
		currentPagePosition = nextPagePosition;
	}
	
	*_internalPosition = interalPos;
	return m_vector_pages[it];
}

MemPage_t* MemPool_t::CreateNewPage()
{
	MemPage_t* page;
	page = new MemPage_t; // delete it at destractor
	m_vector_pages.push_back (page);
	return page;
}





