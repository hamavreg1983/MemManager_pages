#include <string.h> //memcpy
#include "memPage_t.h"

/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define DEFAULT_SIZE_PAGE 8

/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~ Internal function forward declartion ~~~~~~~~~~~~~~~~~~~~~~~~ */



/* ~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

size_t MemPage_t::m_defaultPageSize = DEFAULT_SIZE_PAGE;

MemPage_t::MemPage_t() : m_pageSize(m_defaultPageSize)
{
	m_page = new char[m_pageSize];
	if (!m_page)
	{
		// TODO error. allocation failed.
	}
	
	return;
}

MemPage_t::MemPage_t(size_t _pageCapcity) : m_pageSize(_pageCapcity) // empty copy constractor
{
	m_page = new char[m_pageSize];
	if (!m_page)
	{
		// TODO error. allocation failed.
	}
	
	return;
}

MemPage_t::~MemPage_t()
{
	delete[] (char*)m_page;
	return;
}


size_t MemPage_t::GetCapacity() const
{
	return m_pageSize;
}

bool MemPage_t::IsFull() const
{
	return (m_pageSize <= m_actualUsedSize);
}



size_t MemPage_t::Read(void* _readOutput, size_t _readSize)
{
	return Read(_readOutput, _readSize, GetPosition() );
}

size_t MemPage_t::Read(void* _readOutput, size_t _readSize, size_t _position)
{
	if (NULL == _readOutput)
	{
		return 0;
	}
	
	if (_position > m_actualUsedSize) // illegal position
	{
		return 0; 
	}
	
	if (_position + _readSize > m_actualUsedSize) // read size too big
	{
		_readSize = m_actualUsedSize - _position;
	}
	
	memcpy ( _readOutput, (char*)m_page + _position ,_readSize );
	SetPosition(_position + _readSize);
	
	return _readSize;
}

size_t MemPage_t::Write(const void* _writeContent, size_t _writeSize)
{
	return Write(_writeContent, _writeSize, GetPosition() );
}

size_t MemPage_t::Write(const void* _writeContent, size_t _writeSize, size_t _position )
{
	if (NULL == _writeContent)
	{
		return 0;
	}
	
	if (_position > m_actualUsedSize) // illagle position
	{
		return 0;
	}
	
	if (_position + _writeSize > m_pageSize) // write size exced page free space. truncate write size
	{
		_writeSize = m_pageSize - _position;
	}
	
	memcpy ( (char*)m_page + _position, _writeContent ,_writeSize );
	
	if (_position + _writeSize > m_actualUsedSize)
	{ // increase m_actualUsedSize only if wrote new infomration and did not just overire data.
		m_actualUsedSize += _position + _writeSize - m_actualUsedSize;
	}
	SetPosition(_position + _writeSize);
	
	return _writeSize;
}


size_t MemPage_t::GetDefaultSize()
{
	return m_defaultPageSize;
}

size_t MemPage_t::SetDefaultSize(size_t _newSize)
{
	if (0 != _newSize)
	{
		m_defaultPageSize = _newSize;
	}
	
	return m_defaultPageSize;
}










