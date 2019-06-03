#include "VulkanDevice.h"
#include "VulkanException.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueueFamily.h"

cz::mg::vulkan::VulkanDevice::VulkanDevice(VulkanPhysicalDevice& physicalDevice, std::vector<VulkanQueueAllocation> queueAllocations)
{
    VkResult result;

    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos(queueAllocations.size());
    for(int i = 0; i < queueAllocations.size(); i++){
        queueCreateInfos[i].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfos[i].queueFamilyIndex = queueAllocations[i].getQueueFamilyIndex();
        queueCreateInfos[i].queueCount = queueAllocations[i].getQueueCount();
        queueCreateInfos[i].pQueuePriorities = queueAllocations[i].getQueuePriorities();
    }

    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.queueCreateInfoCount = queueCreateInfos.size();
    createInfo.pQueueCreateInfos = queueCreateInfos.data();

    if((result = vkCreateDevice(physicalDevice.getVk(), &createInfo, nullptr, &device)) != VK_SUCCESS) throw VulkanException(result, "Could not create device.");
}

cz::mg::vulkan::VulkanDevice::~VulkanDevice()
{
    vkDestroyDevice(device, nullptr);
}

cz::mg::vulkan::VulkanQueue cz::mg::vulkan::VulkanDevice::getQueue(cz::mg::vulkan::VulkanQueueFamily &queueFamily, int i)
{
    VkQueue queue;
    vkGetDeviceQueue(device, queueFamily.getIndex(), i, &queue);
    return cz::mg::vulkan::VulkanQueue(queue);
}
