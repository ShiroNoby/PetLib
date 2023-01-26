#pragma once

#include "CType.h"

namespace PetLib {


    //////////////////////////////////////////
    // LT < RT          return -1
    // LT > RT          return  1
    // LT == RT       return  0
    //////////////////////////////////////////
    template< class type >
    int ARRMinCompare( const type& LT, const type& RT)
    {
        size_t Lsize = LT.size();
        size_t Rsize = RT.size();
        size_t smoll = ( Lsize < Rsize ) ? Lsize : Rsize;

        for( size_t index = 0; index < smoll; ++index ) 
        {
            if( LT[index] < RT[index] ) return -1;  // left < right | -1
            if( LT[index] > RT[index] ) return 1;   // left > right |  1
        }

        if( Lsize < Rsize ) return -1;  // left < right | -1
        if( Lsize > Rsize ) return 1;   // left > right |  1

        return 0;                       // left == right | 0
    }


}; //PetLib