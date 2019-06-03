#include "ExecutionManager.h"
#include "../vulkan/VulkanQueueFamily.h"
#include "../vulkan/VulkanPhysicalDevice.h"
#include "../vulkan/VulkanQueue.h"
#include "../vulkan/VulkanException.h"
#include "../vulkan/VulkanDevice.h"
#include "../vulkan/VulkanQueueAllocation.h"
#include "../utilities/Utilities.h"
#include <vector>

using namespace cz::mg::vulkan;
using namespace cz::mg::vulkantest;

cz::mg::vulkantest::ExecutionManager::ExecutionManager(VulkanPhysicalDevice& physicalDevice, VulkanSurface& surface)
{
    VulkanQueueFamily* dqf = nullptr;
    VulkanQueueFamily* pqf = nullptr;
    VulkanQueueFamily* dpqf = nullptr;

    for(VulkanQueueFamily& queueFamily : physicalDevice.getQueueFamilies())
    {
        if(dqf == nullptr && queueFamily.getProperties().queueFlags & VK_QUEUE_GRAPHICS_BIT) dqf = &queueFamily;
        if(pqf == nullptr && queueFamily.canPresentOnSurface(surface)) pqf = &queueFamily;
        if(dpqf == nullptr && queueFamily.getProperties().queueFlags & VK_QUEUE_GRAPHICS_BIT && queueFamily.canPresentOnSurface(surface)) dpqf = &queueFamily;
    }

    try
    {
        if(dpqf != nullptr)
        {
            std::vector<VulkanQueueAllocation> a;
            a.push_back(VulkanQueueAllocation(*dpqf, 1));

            device = new VulkanDevice(physicalDevice, a);
            drawQueue = new VulkanQueue(device->getQueue(*dpqf, 0));
            presentationQueue = new VulkanQueue(device->getQueue(*dpqf, 0));
            return;
        }
        else if(dqf != nullptr && pqf != nullptr)
        {
            std::vector<VulkanQueueAllocation> a;
            a.push_back(VulkanQueueAllocation(*dqf, 1));
            a.push_back(VulkanQueueAllocation(*pqf, 1));

            device = new VulkanDevice(physicalDevice, a);
            drawQueue = new VulkanQueue(device->getQueue(*dqf, 0));
            presentationQueue = new VulkanQueue(device->getQueue(*pqf, 0));
            return;
        }
    }
    catch(...)
    {
        SAFE_DELETE(presentationQueue);
        SAFE_DELETE(drawQueue);
        SAFE_DELETE(device);
        throw;
    }

    throw VulkanException(VK_RESULT_MAX_ENUM, "Could not find required queue families.");
}

cz::mg::vulkantest::ExecutionManager::~ExecutionManager()
{

    SAFE_DELETE(presentationQueue);
    SAFE_DELETE(drawQueue);
    SAFE_DELETE(device);
}
