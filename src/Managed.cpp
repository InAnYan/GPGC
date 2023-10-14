#include "../include/Managed.hpp"

namespace Gc
{
    Managed::Managed(Ptr<Managed> next)
            : isMarked(false), next(next)
    {
    
    }
} // Gc