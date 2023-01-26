#pragma once

#include "CType.h"

namespace PetLib{
    

    template< class Elem >
    class Alloc{

    public:
        
    Alloc() {}

    Alloc( const Alloc& ) = delete;

    explicit Alloc( size_t size ) { this->allocate( size ); }

    Alloc( Alloc&& RAlloc ) : m_data( RAlloc.m_data ), m_size( RAlloc.m_size )
    { 
        RAlloc.m_data = nullptr;
        RAlloc.m_size = 0;
    }

    ~Alloc() { this->deallocate(); }


    Alloc& operator=( const Alloc& ) = delete;

    Alloc& operator=( Alloc&& RAlloc )
    {
        this->deallocate();

        m_data = RAlloc.m_data;
        m_size = RAlloc.m_size;

        RAlloc.m_data = nullptr;
        RAlloc.m_size = 0;

        return *this;
    }

    
    Elem* adress() { return m_data; }

    const Elem* adress() const { return m_data; }          
          
    size_t size() const { return m_size; }


    //core-function
    void allocate( size_t size = MinMemBlock )                                         
    { 
        deallocate();

        if( !m_size )
        {
            m_data = new Elem[size];
            m_size = size;
        }
    }

    void deallocate()                                                        
    { 
        if( m_size )
        {
            delete[] m_data;
            m_size = 0;
        }        
    }

    void construct( const Elem& RE)                                          
    { 
        if( !m_size ) this->allocate();
        new( m_data ) Elem( RE );
    }

    void destroy()                                                           
    { 
        if( m_size ) m_data->~Elem();
    }


    private:

        size_t m_size = 0;
        Elem* m_data = nullptr;
    };  
    

}; //PetLib