#ifndef CZ_MG_VULKAN_VULKANDEVICE_H
#define CZ_MG_VULKAN_VULKANDEVICE_H

#include "Vulkan.h"
#include "VulkanQueue.h"
#include "VulkanQueueAllocation.h"
#include <vector>

namespace cz::mg::vulkan
{
    class VulkanPhysicalDevice;
    class VulkanQueueFamily;
}

namespace cz::mg::vulkan
{
    class VulkanDevice
    {
        NOCOPY(VulkanDevice)

        private:
            VkDevice device;

        public:
            VulkanDevice(VulkanPhysicalDevice& physicalDevice, std::vector<VulkanQueueAllocation> queueAllocations);
            ~VulkanDevice();

            inline VkDevice& getVk()
            {
                return device;
            }

            VulkanQueue getQueue(VulkanQueueFamily& queueFamily, int i);
    };
}

#endif //CZ_MG_VULKAN_VULKANDEVICE_H
