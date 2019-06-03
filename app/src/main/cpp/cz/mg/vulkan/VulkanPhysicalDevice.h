#ifndef CZ_MG_VULKAN_VULKANPHYSICALDEVICE_H
#define CZ_MG_VULKAN_VULKANPHYSICALDEVICE_H

#include "Vulkan.h"
#include <vector>
#include "VulkanQueueFamily.h"

namespace cz::mg::vulkan
{
    class VulkanPhysicalDevice
    {
        private:
            VkPhysicalDevice physicalDevice;

        public:
            VulkanPhysicalDevice(VkPhysicalDevice physicalDevice);
            ~VulkanPhysicalDevice();

            inline VkPhysicalDevice& getVk()
            {
                return physicalDevice;
            }

            VkPhysicalDeviceProperties getProperties();
            std::vector<VulkanQueueFamily> getQueueFamilies();
            VkPhysicalDeviceMemoryProperties getMemoryProperties();
            VkPhysicalDeviceFeatures getFeatures();
    };
}

#endif //CZ_MG_VULKAN_VULKANPHYSICALDEVICE_H
