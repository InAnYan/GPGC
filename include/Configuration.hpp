#ifndef GPGC_INCLUDE_CONFIGURATION_HPP
#define GPGC_INCLUDE_CONFIGURATION_HPP

#include <cstddef>

namespace Gc
{
    class Configuration
    {
    public:
        Configuration(std::size_t initialNextGC, std::size_t growthFactor);
    
        std::size_t GetInitialNextGC() const;
        std::size_t GetGrowthFactor() const;
        
    private:
        std::size_t initialNextGC;
        std::size_t growthFactor;
    };
} // Gc

#endif // GPGC_INCLUDE_CONFIGURATION_HPP
