#ifndef CZ_MG_VULKAN_VULKANCOMMANDPOOL_H
#define CZ_MG_VULKAN_VULKANCOMMANDPOOL_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanDevice;
    class VulkanQueueFamily;
}

namespace cz::mg::vulkan
{
    class VulkanCommandPool
    {
        NOCOPY(VulkanCommandPool)

        private:
            VkCommandPool commandPool;
            VulkanDevice* device;

        public:
            VulkanCommandPool(VulkanDevice& device, VulkanQueueFamily& queueFamily);
            ~VulkanCommandPool();

            inline VkCommandPool& getVk()
            {
                return commandPool;
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANCOMMANDPOOL_H
