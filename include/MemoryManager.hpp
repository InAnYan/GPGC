#ifndef GPGC_INCLUDE_MEMORYMANAGER_HPP
#define GPGC_INCLUDE_MEMORYMANAGER_HPP

#include <functional>
#include <utility>

#include "Ptr.hpp"
#include "Managed.hpp"
#include "Configuration.hpp"

namespace Gc
{
    using RootsSource = std::function<void()>;
    
    class MemoryManager
    {
    public:
        MemoryManager(RootsSource&& roots, Configuration&& conf);
        ~MemoryManager();
        
        void On();
        void Off();
        bool IsOn() const;
        
        void CollectGarbageIfNeeded();
        void CollectGarbage();
        
        template <typename T, typename... Args>
        Ptr<T> Allocate(Args&&... args)
        {
            ++objectsCount;
            CollectGarbageIfNeeded();
            
            T* rawPtr = new T(objects, std::forward<Args&&>(args)...);
            objects = rawPtr;
            
            return Ptr<T>(rawPtr);
        }
        
        static void MarkObject(Ptr<Managed> obj);
        
    private:
        Configuration conf;
        RootsSource roots;
        bool allowGC;
        
        Ptr<Managed> objects;
        std::size_t objectsCount;
        std::size_t nextGC;
        
        void MarkStage();
        void SweepStage();
        void UpdateNextGC();
    };
} // Gc

#endif // GPGC_INCLUDE_MEMORYMANAGER_HPP
