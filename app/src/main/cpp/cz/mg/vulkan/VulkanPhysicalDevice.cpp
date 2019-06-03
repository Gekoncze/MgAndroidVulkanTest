#include "VulkanPhysicalDevice.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanPhysicalDevice::VulkanPhysicalDevice(VkPhysicalDevice physicalDevice)
{
    this->physicalDevice = physicalDevice;
}

cz::mg::vulkan::VulkanPhysicalDevice::~VulkanPhysicalDevice()
{
}

VkPhysicalDeviceProperties cz::mg::vulkan::VulkanPhysicalDevice::getProperties()
{
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);
    return properties;
}

std::vector<VulkanQueueFamily> cz::mg::vulkan::VulkanPhysicalDevice::getQueueFamilies()
{
    uint32_t count;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);
    std::vector<VkQueueFamilyProperties> properties(count);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, properties.data());
    std::vector<VulkanQueueFamily> families;
    for(int i = 0; i < properties.size(); i++) families.push_back(VulkanQueueFamily(physicalDevice, i, properties[i]));
    return families;
}

VkPhysicalDeviceMemoryProperties cz::mg::vulkan::VulkanPhysicalDevice::getMemoryProperties()
{
    VkPhysicalDeviceMemoryProperties properties;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &properties);
    return properties;
}

VkPhysicalDeviceFeatures cz::mg::vulkan::VulkanPhysicalDevice::getFeatures()
{
    VkPhysicalDeviceFeatures features;
    vkGetPhysicalDeviceFeatures(physicalDevice, &features);
    return features;
}
