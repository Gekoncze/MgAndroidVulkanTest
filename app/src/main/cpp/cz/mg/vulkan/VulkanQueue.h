#ifndef CZ_MG_VULKAN_VULKANQUEUE_H
#define CZ_MG_VULKAN_VULKANQUEUE_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanQueue
    {
        private:
            VkQueue queue;

        public:
            VulkanQueue(VkQueue queue);
            ~VulkanQueue();

            inline VkQueue& getVk()
            {
                return queue;
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANQUEUE_H
