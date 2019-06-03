#include "Vulkan.h"
#include "VulkanException.h"

cz::mg::vulkan::Vulkan::Vulkan()
{
    int result = InitVulkan();
    if(result == 0) throw VulkanException(static_cast<VkResult>(0x7FFFFFFF), "Could not init vulkan.");
}

cz::mg::vulkan::Vulkan::~Vulkan()
{
}

std::vector<VkLayerProperties> cz::mg::vulkan::Vulkan::getAvailableLayers()
{
    VkResult result;
    uint32_t count = 0;
    if((result = vkEnumerateInstanceLayerProperties(&count, nullptr)) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate instance layer properties.");
    std::vector<VkLayerProperties> properties(count);
    if((result = vkEnumerateInstanceLayerProperties(&count, properties.data())) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate instance layer properties.");
    return properties;
}

std::vector<VkExtensionProperties> cz::mg::vulkan::Vulkan::getAvailableExtensions()
{
    VkResult result;
    uint32_t count = 0;
    if((result = vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr)) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate instance extension properties.");
    std::vector<VkExtensionProperties> properties(count);
    if((result = vkEnumerateInstanceExtensionProperties(nullptr, &count, properties.data())) != VK_SUCCESS) throw VulkanException(result, "Could not enumerate instance extension properties.");
    return properties;
}

std::string cz::mg::vulkan::vulkanBoolToString(VkBool32 b)
{
    switch(b)
    {
        case VK_FALSE: return "VK_FALSE";
        case VK_TRUE: return "VK_TRUE";
        default: "OTHER";
    }
}

std::string cz::mg::vulkan::vulkanResultToString(VkResult result)
{
    switch(result)
    {
        case VK_SUCCESS: return "VK_SUCCESS";
        case VK_NOT_READY: return "VK_NOT_READY";
        case VK_TIMEOUT: return "VK_TIMEOUT";
        case VK_EVENT_SET: return "VK_EVENT_SET";
        case VK_EVENT_RESET: return "VK_EVENT_RESET";
        case VK_INCOMPLETE: return "VK_INCOMPLETE";
        case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
        case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
        case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
        case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
        case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
        case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
        case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
        case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
        case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
        case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
        case VK_ERROR_FRAGMENTED_POOL: return "VK_ERROR_FRAGMENTED_POOL";
        case VK_ERROR_OUT_OF_POOL_MEMORY: return "VK_ERROR_OUT_OF_POOL_MEMORY";
        case VK_ERROR_INVALID_EXTERNAL_HANDLE: return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
        case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
        case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case VK_ERROR_VALIDATION_FAILED_EXT: return "VK_ERROR_VALIDATION_FAILED_EXT";
        case VK_ERROR_INVALID_SHADER_NV: return "VK_ERROR_INVALID_SHADER_NV";
        case VK_ERROR_FRAGMENTATION_EXT: return "VK_ERROR_FRAGMENTATION_EXT";
        case VK_ERROR_NOT_PERMITTED_EXT: return "VK_ERROR_NOT_PERMITTED_EXT";
        default: return "OTHER_ERROR";
    }
}

std::string cz::mg::vulkan::vulkanDebugReportFlagsToString(VkDebugReportFlagsEXT flags)
{
    std::string result;
    if(flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT) result.append("VK_DEBUG_REPORT_INFORMATION_BIT_EXT ");
    if(flags & VK_DEBUG_REPORT_WARNING_BIT_EXT) result.append("VK_DEBUG_REPORT_WARNING_BIT_EXT ");
    if(flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) result.append("VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT ");
    if(flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) result.append("VK_DEBUG_REPORT_ERROR_BIT_EXT ");
    if(flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT) result.append("VK_DEBUG_REPORT_DEBUG_BIT_EXT ");
    return result;
}

std::string cz::mg::vulkan::vulkanQueueFlagsToString(VkQueueFlags flags)
{
    std::string result;
    if(flags & VK_QUEUE_GRAPHICS_BIT) result.append("VK_QUEUE_GRAPHICS_BIT ");
    if(flags & VK_QUEUE_COMPUTE_BIT) result.append("VK_QUEUE_COMPUTE_BIT ");
    if(flags & VK_QUEUE_TRANSFER_BIT) result.append("VK_QUEUE_TRANSFER_BIT ");
    if(flags & VK_QUEUE_SPARSE_BINDING_BIT) result.append("VK_QUEUE_SPARSE_BINDING_BIT ");
    if(flags & VK_QUEUE_PROTECTED_BIT) result.append("VK_QUEUE_PROTECTED_BIT ");
    return result;
}
