#ifndef CZ_MG_VULKANTEST_EXECUTIONMANAGER_H
#define CZ_MG_VULKANTEST_EXECUTIONMANAGER_H

#include "../vulkan/Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanQueue;
    class VulkanPhysicalDevice;
    class VulkanSurface;
    class VulkanDevice;
}

namespace cz::mg::vulkantest
{
    class ExecutionManager
    {
        NOCOPY(ExecutionManager)

        private:
            cz::mg::vulkan::VulkanQueue* drawQueue = nullptr;
            cz::mg::vulkan::VulkanQueue* presentationQueue = nullptr;
            cz::mg::vulkan::VulkanDevice* device = nullptr;

        public:
            ExecutionManager(cz::mg::vulkan::VulkanPhysicalDevice& physicalDevice, cz::mg::vulkan::VulkanSurface& surface);
            ~ExecutionManager();

            inline cz::mg::vulkan::VulkanQueue& getDrawQueue()
            {
                return *drawQueue;
            }

            inline cz::mg::vulkan::VulkanQueue& getPresentationQueue()
            {
                return *presentationQueue;
            }

            inline cz::mg::vulkan::VulkanDevice& getDevice()
            {
                return *device;
            }
    };
}

#endif //CZ_MG_VULKANTEST_EXECUTIONMANAGER_H
