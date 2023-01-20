#pragma

#include "CType.h"

namespace PetLib{
    
    template< class Elem, size_t N >
    class Alloc{

    public:
        

                    Alloc( const Alloc& ) = delete;
                    Alloc()                                                                     { this->allocate(); }
                    Alloc( Alloc&& RAlloc ) : m_data( RAlloc.m_data ), alloc( RAlloc.alloc )    
    { 
        RAlloc.m_data = nullptr; 
        RAlloc.alloc = false;
    }

                    ~Alloc()                                                                    { this->deallocate(); }

    Alloc&          operator=( const Alloc& ) = delete;
    Alloc&          operator=( Alloc&& RAlloc )
    {
        this->deallocate();

        m_data = RAlloc.m_data;
        alloc = RAlloc.alloc;

        RAlloc.m_data = nullptr;
        RAlloc.alloc = false;

        return *this;
    }
    
    Elem*           adress()                                                                    { return m_data; }
    const Elem*     adress() const                                                              { return m_data; }
        
    size_t          size() const                                                                { return N; }

    //core-function
    void            allocate( size_t size = N )                                         
    { 
        if( !alloc) m_data = new Elem[size];
        alloc = true;
    }
    void            deallocate()                                                        
    { 
        if( alloc ) 
        {
            delete[] m_data;
            alloc = false;
        }        
    }
    void            construct( const Elem& RE)                                          
    { 
        if( !alloc ) this->allocate();
        new( m_data ) Elem( RE );
    }
    void            destroy()                                                           
    { 
        if( alloc ) m_data->~Elem();  
    }

    private:

        bool alloc = false;
        Elem* m_data;
    };    
}; //PetLib