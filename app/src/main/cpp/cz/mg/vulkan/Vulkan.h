#ifndef CZ_MG_VULKAN_VULKAN_H
#define CZ_MG_VULKAN_VULKAN_H

#include "../utilities/Utilities.h"
#include "NativeVulkanHeader.h"
#include <vector>
#include <string>

namespace cz::mg::vulkan
{
    class Vulkan
    {
        NOCOPY(Vulkan)

        public:
            Vulkan();
            ~Vulkan();

            std::vector<VkLayerProperties> getAvailableLayers();
            std::vector<VkExtensionProperties> getAvailableExtensions();
    };

    std::string vulkanBoolToString(VkBool32 b);
    std::string vulkanResultToString(VkResult result);
    std::string vulkanDebugReportFlagsToString(VkDebugReportFlagsEXT flags);
    std::string vulkanQueueFlagsToString(VkQueueFlags flags);
}

#endif //CZ_MG_VULKAN_VULKAN_H
