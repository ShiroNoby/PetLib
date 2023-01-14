#pragma

#include "CType.h"
#include "CCompare.h"

namespace PetLib{

    template< class Elem, uint N >
    class Array{

    public:

    //memory acces
    
    Elem& at( uint index )
    {
        if( index < N ) return m_data[index];
        
        Elem tmp{};
        return tmp;
    }


    const Elem& at( uint index ) const
    {
        if (index < N) return m_data[index];

        Elem tmp{};
        return tmp;
    }


    Elem& operator[]( uint index ) 
    {
        return m_data[ index ];
    }


    const Elem& operator[]( uint index ) const
    {
        return m_data[ index ];
    }


    Elem& front() 
    {
        return *m_data;
    }


    const Elem& front() const
    {
        return *m_data;
    }


    Elem& back()
    {
        return m_data[ N - 1 ];
    }


    const Elem& back() const
    {
        return m_data[N - 1];
    }


    Elem* data()
    {
        return m_data;
    }


    const Elem* data() const
    {
        return m_data;
    }


    //info
    bool empty() const
    {
        return N;
    }


    uint size() const
    {
        return N;
    }


    //swap();
    //fill();

    //friend operator
    template< class Elem, uint N >
    friend bool operator==( const Array< Elem, N >& LM, const Array< Elem, N >& RM );


    template< class Elem, uint N >
    friend bool operator!=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, uint N >
    friend bool operator<( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, uint N >
    friend bool operator<=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, uint N >
    friend bool operator>( const Array< Elem, N >& LM, const Array< Elem, N >& RM );

    template< class Elem, uint N >
    friend bool operator>=( const Array< Elem, N >& LM, const Array< Elem, N >& RM );
    
    private:

        Elem m_data[N]{};
    };


    template< class Elem, uint N >
    bool operator==
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >( LM , RM ) == 0 ) ? true : false;
            }

    template< class Elem, uint N > 
    bool operator!=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >(LM, RM) != 0 ) ? true : false;
            }

    template< class Elem, uint N >
    bool operator< 
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return ( ARRMinCompare< Array< Elem, N > >(LM, RM) == -1 ) ? true : false;
            }

    template< class Elem, uint N >
    bool operator<=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                int resoult = ARRMinCompare< Array< Elem, N > >(LM, RM);
                return ( resoult == -1 || resoult == 0) ? true : false;
            }

    template< class Elem, uint N >
    bool operator> 
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                return (ARRMinCompare< Array< Elem, N > >(LM, RM) == 1) ? true : false;
            }

    template< class Elem, uint N >
    bool operator>=
        ( const Array< Elem, N >& LM, const Array< Elem, N >& RM )
            {
                int resoult = ARRMinCompare< Array< Elem, N > >(LM, RM);
                return (resoult == 1 || resoult == 0) ? true : false;
            }

}; //PetLib