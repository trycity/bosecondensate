// BitVect.h

//Bit vector header file

#ifndef _BITVECT_H
#define _BITVECT_H

#include <string>


namespace QMC{
	class BitVector
	{
	public:
		BitVector();
		BitVector(int nbits);
		BitVector(const BitVector&);
		~BitVector();

		void SetBit(int bit, int val=1);
		int GetBit(int bit) const;
		void ToggleBit(int bit);
		void SetLength(int nbits);

		BitVector operator&(const BitVector&) const;
		BitVector& operator &=(const BitVector&);
		BitVector operator|(const BitVector&) const;
		BitVector& operator |=(const BitVector&);
		BitVector operator ^(const BitVector&) const;
		BitVector& operator ^=(const BitVector&);
		friend BitVector operator ~ (const BitVector&);
		BitVector& operator =(const BitVector&);
		int operator[](int bit) const;
	
	protected:
		unsigned char* m_BitVec;
		int m_Len;
	};
};

#endif
