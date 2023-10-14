#include "../include/Configuration.hpp"

namespace Gc
{
    Configuration::Configuration(std::size_t initialNextGC, std::size_t growthFactor)
            : initialNextGC(initialNextGC), growthFactor(growthFactor)
    {
    
    }
    
    std::size_t Configuration::GetInitialNextGC() const
    {
        return initialNextGC;
    }
    
    std::size_t Configuration::GetGrowthFactor() const
    {
        return growthFactor;
    }
} // Gc