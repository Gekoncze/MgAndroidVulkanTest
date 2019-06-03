#ifndef CZ_MG_VULKAN_VULKANQUEUEFAMILY_H
#define CZ_MG_VULKAN_VULKANQUEUEFAMILY_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanSurface;
}

namespace cz::mg::vulkan
{
    class VulkanQueueFamily
    {
        private:
            uint32_t index;
            VkQueueFamilyProperties properties;
            VkPhysicalDevice physicalDevice;

        public:
            VulkanQueueFamily(VkPhysicalDevice physicalDevice, uint32_t index, VkQueueFamilyProperties properties);
            ~VulkanQueueFamily();

            inline uint32_t& getIndex()
            {
                return index;
            }

            inline VkQueueFamilyProperties& getProperties()
            {
                return properties;
            }

            inline VkPhysicalDevice getPhysicalDevice()
            {
                return physicalDevice;
            }

            VkBool32 canPresentOnSurface(VulkanSurface& surface);
    };
}

#endif //CZ_MG_VULKAN_VULKANQUEUEFAMILY_H
