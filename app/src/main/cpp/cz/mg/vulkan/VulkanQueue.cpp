#include "VulkanQueue.h"

cz::mg::vulkan::VulkanQueue::VulkanQueue(VkQueue queue)
{
    this->queue = queue;
}

cz::mg::vulkan::VulkanQueue::~VulkanQueue()
{
}
