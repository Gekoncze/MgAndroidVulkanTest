#include "VulkanCommandPool.h"
#include "VulkanException.h"
#include "VulkanQueueFamily.h"
#include "VulkanDevice.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanCommandPool::VulkanCommandPool(VulkanDevice& device, VulkanQueueFamily& queueFamily)
{
    this->device = &device;
    VkResult result;

    VkCommandPoolCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    createInfo.queueFamilyIndex = queueFamily.getIndex();

    if((result = vkCreateCommandPool(device.getVk(), &createInfo, nullptr, &commandPool)) != VK_SUCCESS) throw VulkanException(result, "Could not create command pool.");
}

cz::mg::vulkan::VulkanCommandPool::~VulkanCommandPool()
{
    vkDestroyCommandPool(device->getVk(), commandPool, nullptr);
}
