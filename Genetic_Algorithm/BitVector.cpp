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


