#pragma

#include "CType.h"

namespace PetLib {

    template< class type >
    int ARRMinCompare( const type& LT, const type& RT)
    {
        uint Lsize = LT.size();
        uint Rsize = RT.size();
        uint smoll = ( Lsize < Rsize ) ? Lsize : Rsize;

        for(uint index = 0; index < smoll; ++index) 
        {
            if( LT[index] < RT[index] ) return -1; // left < right | -1
            if( LT[index] > RT[index] ) return 1; // left > right | 1
        }

        if( Lsize < Rsize ) return -1; // left < right | -1
        if( Lsize > Rsize ) return 1; // left > right | 1

        return 0; // left == right | 0
    }

}; //PetLib