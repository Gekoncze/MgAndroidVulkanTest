#include "VulkanQueueAllocation.h"

cz::mg::vulkan::VulkanQueueAllocation::VulkanQueueAllocation(VulkanQueueFamily& queueFamily, uint32_t queueCount)
{
    this->queueFamilyIndex = queueFamily.getIndex();
    this->queueCount = queueCount;
    this->priorities.resize(queueCount);
    for(int i = 0; i < priorities.size(); i++) priorities[i] = 1.0f;
}

cz::mg::vulkan::VulkanQueueAllocation::~VulkanQueueAllocation()
{
}
