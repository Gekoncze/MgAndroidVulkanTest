#include "VulkanSurface.h"
#include "VulkanInstance.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanSurface::VulkanSurface(VulkanInstance& instance)
{
    this->instance = &instance;
}

cz::mg::vulkan::VulkanSurface::~VulkanSurface()
{
    PFN_vkDestroySurfaceKHR f = (PFN_vkDestroySurfaceKHR)instance->loadFunction("vkDestroySurfaceKHR");
    f(instance->getVk(), surface, nullptr);
}
