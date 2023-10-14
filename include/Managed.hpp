#ifndef GPGC_INCLUDE_MANAGED_HPP
#define GPGC_INCLUDE_MANAGED_HPP

#include "Ptr.hpp"

namespace Gc
{
    class Managed
    {
    public:
        explicit Managed(Ptr<Managed> next);
        virtual ~Managed() = default;
    
    private:
        bool isMarked;
        Ptr<Managed> next;
        
        virtual void MarkChildren() = 0;
        
        friend class MemoryManager;
    };
} // Gc

#endif // GPGC_INCLUDE_MANAGED_HPP
