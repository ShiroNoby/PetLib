#pragma once

#include "CType.h"
#include "CArray.h"
#include "CAlloc.h"
#include "CUtility.h"

namespace PetLib {


    size_t calc_size( size_t index )
    {
        if ( index != MinMemBlock )
        {
            size_t tmp = index / MinMemBlock;
            index = (tmp + 1) * MinMemBlock;
        }

        return index;
    }


    template< class Elem >
    struct VecBuff{  

        VecBuff() = delete;
        VecBuff( const VecBuff& ) = delete;

        VecBuff( size_t size ) 
        {
            m_data.allocate( calc_size( size ) );
        }

        VecBuff( VecBuff&& RVec ) : m_size( RVec.m_size ), m_data( move( RVec.m_data ) ) 
        {
            RVec.m_size = 0;
        }


        VecBuff& operator=( const VecBuff& ) = delete;

        VecBuff& operator=( VecBuff&& RVec ) 
        {
            m_size = RVec.m_size;
            m_data = Move( RVec.m_data );

            RVec.m_size = 0;

            return *this;
        }


        size_t size() const { return m_size; }

        size_t max_size() const { return m_data.size(); }


        Elem& at( size_t index ) 
        {
            if( size() < max_size() ) return ( m_data.adress() + index );

            Elem tmp{};
            return tmp;
        }

        const Elem& at(size_t index) const 
        {
            if ( size() < max_size() ) return ( m_data.adress() + index );

            Elem tmp{};
            return tmp;
        }


        Elem& operator[]( size_t index )
        {
            return ( m_data.adress() + index );
        }

        const Elem& operator[]( size_t index ) const
        {
            return ( m_data.adress() + index );
        }


        void resize( size_t size ) 
        {
            VecBuff< Elem > tmp( size );
            tmp.assign( *this );

            *this = Move( tmp );
        }

        void add( const Elem& RElem )
        {
            size_t LCup = m_data.size();
            size_t LSize = m_size;

            if( !LCup ) { m_data.allocate(); }
            if( LSize >= LCup; ) resize( LSize + 2 );

            m_data[ m_size ] = RElem;
            ++m_size;
        }

        VecBuff& assign( const VecBuff& RBuff )
        {
            size_t RSize = RBuff.m_size;
            size_t LCup = m_data.size();
            size_t RCup = RBuff.m_data.size();
            
            if( m_size || LCup < RCup ) 
            {
                m_data.allocate( RCup );
                m_size = 0;
            }

            for ( ; m_size != RSize; ++m_size )
            {
                m_data[ m_size ] = RBuff[ m_size ];
            }

            return *this;
        }


        size_t m_size = 0;
        Alloc< Elem > m_data;

    };
    
    
    template< class Elem >
    class Vector
    {

        Vector& operator=( const Vector& RVec ) { return array.assign( RVec.array ); }

        Vector& operator=( Vector&& RVec ) { return array = RVec; }


        size_t max_size() const { return array.max_size(); }

      
        /* Element access
        clear
    insert
    emplace
        erase
        push_back
    emplace_back
    pop_back
        resize
    swap


    Non-member functions
        operator==
        operator!=
        operator<
        operator<=
        operator>
        operator>=
    */
      
    public:

        Vector() : array( MinMemBlock ) {}

        Vector( size_t size ) : array( size ) {}

        Vector( const Vector& RVec ) : array( RVec.max_size() ) 
        {
            array.assign( RVec.array );
        }

        Vector( Vector&& RVec ) : array( Move( RVec.array ) ) 
        {
            RVec.array.m_size = 0;
        }


        Elem& at( size_t index ) { return array.at( index ); }

        const Elem& at( size_t index ) const { return array.at(index); }
        

        Elem& operator[]( size_t index ) { return array[ index ]; }

        const Elem& operator[]( size_t index ) const { return array[index]; }


        Elem& front() { return array.at( 0 ); }

        const Elem& front() const { return array.at(0); }


        Elem& back() { return array.at( array.max_size() - 1 ); }

        const Elem& back() const { return array.at(array.max_size() - 1); }


        Elem* data() { return array.m_data.adress(); }
        const Elem* data() const { return array.m_data.adress(); }


        bool empty() const { return (bool)array.size(); }

        size_t size() const { return array.size(); }


    private: 

        VecBuff< Elem > array;
    };


}; //PetLib