#ifndef CZ_MG_VULKAN_VULKANQUEUEALLOCATION_H
#define CZ_MG_VULKAN_VULKANQUEUEALLOCATION_H

#include "Vulkan.h"
#include "VulkanQueueFamily.h"
#include <vector>

namespace cz::mg::vulkan
{
    class VulkanQueueAllocation
    {
        private:
            uint32_t queueFamilyIndex;
            uint32_t queueCount;
            std::vector<float> priorities;

        public:
            VulkanQueueAllocation(VulkanQueueFamily& queueFamily, uint32_t queueCount);
            ~VulkanQueueAllocation();

            inline uint32_t getQueueFamilyIndex()
            {
                return queueFamilyIndex;
            }

            inline uint32_t getQueueCount()
            {
                return queueCount;
            }

            inline float* getQueuePriorities()
            {
                return priorities.data();
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANQUEUEALLOCATION_H
