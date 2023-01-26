#pragma once 

namespace PetLib{


    template< class Elem >
    Elem&& Move( Elem& RElem) 
    {
       return static_cast< Elem&& > ( RElem );
    }


}; //PetLib