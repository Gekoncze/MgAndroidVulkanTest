#include "VulkanQueueFamily.h"
#include "VulkanSurface.h"

cz::mg::vulkan::VulkanQueueFamily::VulkanQueueFamily(VkPhysicalDevice physicalDevice, uint32_t index, VkQueueFamilyProperties properties)
{
    this->index = index;
    this->properties = properties;
    this->physicalDevice = physicalDevice;
}

cz::mg::vulkan::VulkanQueueFamily::~VulkanQueueFamily()
{
}

VkBool32 cz::mg::vulkan::VulkanQueueFamily::canPresentOnSurface(cz::mg::vulkan::VulkanSurface& surface)
{
    VkBool32 canPresent;
    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, index, surface.getVk(), &canPresent);
    return canPresent;
}
