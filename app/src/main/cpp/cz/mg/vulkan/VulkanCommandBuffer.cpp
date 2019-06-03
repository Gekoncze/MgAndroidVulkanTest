#include "VulkanCommandBuffer.h"
#include "VulkanException.h"
#include "VulkanDevice.h"
#include "VulkanCommandPool.h"

cz::mg::vulkan::VulkanCommandBuffer::VulkanCommandBuffer(VulkanDevice& device, VulkanCommandPool& commandPool, VkCommandBufferLevel level)
{
    this->device = &device;
    this->commandPool = &commandPool;
    VkResult result;

    VkCommandBufferAllocateInfo allocateInfo = {};
    allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocateInfo.commandPool = commandPool.getVk();
    allocateInfo.commandBufferCount = 1;
    allocateInfo.level = level;

    if((result = vkAllocateCommandBuffers(device.getVk(), &allocateInfo, &commandBuffer)) != VK_SUCCESS) throw VulkanException(result, "Could not create command buffer.");
}

cz::mg::vulkan::VulkanCommandBuffer::~VulkanCommandBuffer()
{
    vkFreeCommandBuffers(device->getVk(), commandPool->getVk(), (uint32_t)1, &commandBuffer);
}
