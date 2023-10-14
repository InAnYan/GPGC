#ifndef GPGC_INCLUDE_PTR_HPP
#define GPGC_INCLUDE_PTR_HPP

namespace Gc
{
    template <typename T>
    class Ptr
    {
    public:
        const T* operator->() const;
        T* operator->();
        
        const T& operator*() const;
        T& operator*();
        
        operator bool() const;
    
    private:
        T* ptr;
        
        explicit Ptr(T* obj);
        Ptr();
        
        friend class MemoryManager;
    };
    
    template <typename T>
    Ptr<T>::Ptr(T* obj)
            : ptr(obj)
    {
    
    }
    
    template <typename T>
    Ptr<T>::Ptr()
            : ptr(nullptr)
    {
    
    }
    
    template <typename T>
    const T* Ptr<T>::operator->() const
    {
        return ptr;
    }
    
    template <typename T>
    T* Ptr<T>::operator->()
    {
        return ptr;
    }
    
    template <typename T>
    const T& Ptr<T>::operator*() const
    {
        return *ptr;
    }
    
    template <typename T>
    T& Ptr<T>::operator*()
    {
        return *ptr;
    }
    
    template <typename T>
    Ptr<T>::operator bool() const
    {
        return ptr != nullptr;
    }
} // Gc

#endif // GPGC_INCLUDE_PTR_HPP
