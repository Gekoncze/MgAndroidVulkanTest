#ifndef CZ_MG_VULKAN_VULKANDEBUGREPORT_H
#define CZ_MG_VULKAN_VULKANDEBUGREPORT_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanInstance;
}

namespace cz::mg::vulkan
{
    class VulkanDebugReport
    {
        NOCOPY(VulkanDebugReport)

        private:
            VulkanInstance* instance;
            VkDebugReportCallbackEXT debugReportCallback;

        public:
            VulkanDebugReport(VulkanInstance& instance, PFN_vkDebugReportCallbackEXT callback, void* userData);
            ~VulkanDebugReport();
    };
}

#endif //CZ_MG_VULKAN_VULKANDEBUGREPORT_H
