#ifndef CZ_MG_VULKAN_VULKANINSTANCE_H
#define CZ_MG_VULKAN_VULKANINSTANCE_H

#include "Vulkan.h"
#include "VulkanPhysicalDevice.h"
#include <vector>

namespace cz::mg::vulkan
{
    class VulkanInstance
    {
        NOCOPY(VulkanInstance)

        private:
            VkInstance instance;

        public:
            VulkanInstance(Vulkan& vulkan, uint32_t apiVersion, const char* applicationName, uint32_t applicationVersion, const char* engineName, uint32_t engineVersion, uint32_t layerCount, const char* const* layers, uint32_t extensionCount, const char* const* extensions);
            ~VulkanInstance();

            inline VkInstance& getVk()
            {
                return instance;
            }

            std::vector<VulkanPhysicalDevice> getPhysicalDevices();
            PFN_vkVoidFunction loadFunction(const char* fname);
    };
}

#endif //CZ_MG_VULKAN_VULKANINSTANCE_H
