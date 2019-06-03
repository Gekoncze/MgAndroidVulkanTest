#include "VulkanAndroidSurface.h"
#include "VulkanException.h"
#include "VulkanInstance.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanAndroidSurface::VulkanAndroidSurface(VulkanInstance& instance, ANativeWindow* window) : cz::mg::vulkan::VulkanSurface(instance)
{
    VkResult result;

    VkAndroidSurfaceCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    createInfo.window = window;

    PFN_vkCreateAndroidSurfaceKHR f = (PFN_vkCreateAndroidSurfaceKHR)instance.loadFunction("vkCreateAndroidSurfaceKHR");
    if((result = f(instance.getVk(), &createInfo, nullptr, &surface)) != VK_SUCCESS) throw VulkanException(result, "Could not create android surface.");
}
