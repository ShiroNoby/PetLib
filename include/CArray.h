#pragma once

#include "CType.h"
#include "CCompare.h"

namespace PetLib{


    template< class Elem, size_t N >
    class Array{

    public:

    //memory acces    
    Elem& at( size_t index )
    {
        if( index < N ) return m_data[ index ];
        
        Elem tmp{};
        return tmp;
    }

    const Elem& at( size_t index ) const
    {
        if ( index < N ) return m_data[ index ];

        Elem tmp{};
        return tmp;
    }


    Elem& operator[]( size_t index ) { return m_data[ index ]; }

    const Elem& operator[]( size_t index ) const { return m_data[ index ]; }


    Elem& front() { return *m_data; }

    const Elem& front() const { return *m_data; }


    Elem& back() { return m_data[ N - 1 ]; }

    const Elem& back() const { return m_data[ N - 1 ]; }


    Elem* data() { return m_data; }

    const Elem* data() const { return m_data; }


    //info
    bool empty() const { return N; }
    
    size_t size() const { return N; }


    //swap();
    //fill();

    //friend operator
    template< class Elem, size_t N >
    friend bool operator==( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, size_t N >
    friend bool operator!=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, size_t N >
    friend bool operator<( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, size_t N >
    friend bool operator<=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, size_t N >
    friend bool operator>( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, size_t N >
    friend bool operator>=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );
    
    private:

        Elem m_data[N]{};
    };


    template< class Elem, size_t N >
    bool operator==
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >( LM , RM ) == 0 ) ? true : false;
            }

    template< class Elem, size_t N > 
    bool operator!=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >( LM, RM ) != 0 ) ? true : false;
            }

    template< class Elem, size_t N >
    bool operator< 
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >( LM, RM ) == -1 ) ? true : false;
            }

    template< class Elem, size_t N >
    bool operator<=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                int resoult = ARRMinCompare< Array< Elem, N > >( LM, RM );
                return ( resoult == -1 || resoult == 0) ? true : false;
            }

    template< class Elem, size_t N >
    bool operator> 
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return (ARRMinCompare< Array< Elem, N > >( LM, RM ) == 1) ? true : false;
            }

    template< class Elem, size_t N >
    bool operator>=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                int resoult = ARRMinCompare< Array< Elem, N > >( LM, RM );
                return (resoult == 1 || resoult == 0) ? true : false;
            }


}; //PetLib