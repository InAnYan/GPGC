#include "../include/MemoryManager.hpp"

namespace Gc
{
    MemoryManager::MemoryManager(RootsSource&& roots, Configuration&& conf)
            : conf(conf), roots(std::move(roots)), allowGC(false),
              objects(nullptr), objectsCount(0), nextGC(conf.GetInitialNextGC())
    {
    
    }
    
    MemoryManager::~MemoryManager()
    {
        Ptr<Managed> obj = objects;
        while (obj)
        {
            Ptr<Managed> next = obj->next;
            delete obj.ptr;
            obj = next;
        }
    }
    
    void MemoryManager::MarkObject(Ptr<Managed> obj)
    {
        if (obj && !obj->isMarked)
        {
            obj->isMarked = true;
            obj->MarkChildren();
        }
    }
    
    void MemoryManager::On()
    {
        allowGC = true;
    }
    
    void MemoryManager::Off()
    {
        allowGC = false;
    }
    
    bool MemoryManager::IsOn() const
    {
        return allowGC;
    }
    
    void MemoryManager::CollectGarbageIfNeeded()
    {
        if (allowGC && objectsCount > nextGC)
        {
            CollectGarbage();
        }
    }
    
    void MemoryManager::CollectGarbage()
    {
        MarkStage();
        SweepStage();
        
        UpdateNextGC();
    }
    
    void MemoryManager::MarkStage()
    {
        roots();
    }
    
    void MemoryManager::SweepStage()
    {
        Ptr<Managed> prev;
        Ptr<Managed> obj = objects;
        
        while (obj)
        {
            Ptr<Managed> next = obj->next;
            
            if (obj->isMarked)
            {
                obj->isMarked = false;
                prev = obj;
                obj = next;
            }
            else
            {
                if (!prev)
                {
                    objects = next;
                }
                else
                {
                    prev->next = next;
                }
                
                delete obj.ptr;
                --objectsCount;
                
                obj = next;
            }
        }
    }
    
    void MemoryManager::UpdateNextGC()
    {
        nextGC = objectsCount * conf.GetGrowthFactor();
    }
} // Gc