// BitVector.cpp

#include "BitVector.h"

using namespace QMC;

BitVector::BitVector()
{
	m_Len = 0;
	m_BitVec = NULL;
}

BitVector::BitVector(int nbits)
{
	m_Len = nbits/8 + ((nbits%8)?1:0);
	m_BitVec = new unsigned char[m_Len];
}

BitVector::BitVector(const BitVector& bvec) 
{
	m_Len = bvec.m_Len;
	m_BitVec = new unsigned char[m_Len];
	memcpy(m_BitVec, bvec.m_BitVec, m_Len);
}

BitVector::~BitVector()
{
	if(m_BitVec != NULL)
	{
		delete[] m_BitVec;
	}
	
	m_BitVec = NULL:
}

void BitVector::SetBit(int bit, bool val)
{
	if(bit < 8*m_Len)
	{
		if(val)
		{
			m_BitVec[bit/8] |= _BV_BIT[bit%8];
		}else
		{
			m_BitVec[bit/8] &= ~_BV_BIT[bit%8];
		}
	}
}


int BitVector::GetBit(int bit) const
{
	if(bit < 8*m_Len)
	{
		return ((m_BitVec[bit/8]& _BV_BIT[bit%8])?1:0);
	}

	return -1;
}


void BitVector::ToggleBit(int bit)
{
	if(bit <8*m_Len)
	{
		m_BitVec[bit/8] ^= _BV_BIT[bit%8];
	}
}


void BitVector::SetLength(int nbits)
{
	if(m_BitVec != NULL)
	{
		delete[] m_BitVec;
	}

	m_Len = nbits/8 + ((nbits%8)?1:0);
	m_BitVec = new unsigned char[m_Len];
}


BitVector BitVector::operator&(const BitVector& b) const
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
	BitVector ret(mlen*8);
	
	for(int i=0; i<mlen; i++)
	{
		ret.m_BitVec[i] = m_BitVec[i] & b.m_BitVec[i];
	}

	return ret;
}


BitVector& BitVector::operator &=(const BitVector& b)
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
		
	for(int i=0; i<mlen; i++)
	{
		m_BitVec[i] &= b.m_BitVec[i];
	}

	return *this;
}

BitVector BitVector::operator|(const BitVector& b) const
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
	BitVector ret(mlen*8);
	
	for(int i=0; i<mlen; i++)
	{
		ret.m_BitVec[i] = m_BitVec[i] | b.m_BitVec[i];
	}

	return ret;
}


BitVector& BitVector::operator |=(const BitVector& b)
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
		
	for(int i=0; i<mlen; i++)
	{
		m_BitVec[i] |= b.m_BitVec[i];
	}

	return *this;
}


BitVector BitVector::operator ^(const BitVector& b) const
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
	BitVector ret(mlen*8);
	
	for(int i=0; i<mlen; i++)
	{
		ret.m_BitVec[i] = m_BitVec[i]^b.m_BitVec[i];
	}

	return ret;
}


BitVector& BitVector::operator ^=(const BitVector& b)
{
	int mlen = (m_Len > b.m_Len)?m_Len:b.m_Len;
		
	for(int i=0; i<mlen; i++)
	{
		m_BitVec[i] ^= b.m_BitVec[i];
	}

	return *this;
}
		
BitVector operator ~ (const BitVector& b)
{
	BitVector ret(b.m_Len*8);
	
	for(int i=0; i<m_Len; i++)
	{
		ret.m_BitVec[i] = ~b.m_BitVec[i];
	}

	return ret;
}

BitVector& BitVector::operator =(const BitVector& b)
{
	if(m_BitVec == b.m_BitVec)
	{
		return *this;
	}

	if(m_BitVec != NULL)
	{
		delete[] m_BitVec;
	}

	m_Len = b.m_Len;
	m_BitVec = new unsigned char[m_Len];
	memcpy(m_BitVec, b.m_BitVec, m_Len);

	return *this;
}


int BitVector::operator[](int bit) const
{
	return GetBit(bit);
}
