#ifndef CZ_MG_VULKAN_VULKANCOMMANDBUFFER_H
#define CZ_MG_VULKAN_VULKANCOMMANDBUFFER_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanDevice;
    class VulkanCommandPool;
}

namespace cz::mg::vulkan
{
    class VulkanCommandBuffer
    {
        NOCOPY(VulkanCommandBuffer)

        private:
            VkCommandBuffer commandBuffer;
            VulkanDevice* device;
            VulkanCommandPool* commandPool;

        public:
            VulkanCommandBuffer(VulkanDevice& device, VulkanCommandPool& commandPool, VkCommandBufferLevel level);
            ~VulkanCommandBuffer();

            inline VkCommandBuffer& getVk()
            {
                return commandBuffer;
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANCOMMANDBUFFER_H
