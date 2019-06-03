#include "VulkanDebugReport.h"
#include "VulkanException.h"
#include "VulkanInstance.h"

using namespace cz::mg::vulkan;

cz::mg::vulkan::VulkanDebugReport::VulkanDebugReport(VulkanInstance& instance, PFN_vkDebugReportCallbackEXT callback, void* userData)
{
    this->instance = &instance;
    VkResult result;
    VkDebugReportCallbackCreateInfoEXT createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    createInfo.pfnCallback = callback;
    createInfo.pUserData = userData;
    PFN_vkCreateDebugReportCallbackEXT f = (PFN_vkCreateDebugReportCallbackEXT)instance.loadFunction("vkCreateDebugReportCallbackEXT");
    if((result = f(instance.getVk(), &createInfo, nullptr, &debugReportCallback)) != VK_SUCCESS) throw VulkanException(result, "Could not create debug report.");
}

cz::mg::vulkan::VulkanDebugReport::~VulkanDebugReport()
{
    PFN_vkDestroyDebugReportCallbackEXT f = (PFN_vkDestroyDebugReportCallbackEXT)instance->loadFunction("vkDestroyDebugReportCallbackEXT");
    f(instance->getVk(), debugReportCallback, nullptr);
}
