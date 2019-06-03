#ifndef CZ_MG_VULKAN_VULKANEXCEPTION_H
#define CZ_MG_VULKAN_VULKANEXCEPTION_H

#include "Vulkan.h"

namespace cz::mg::vulkan
{
    class VulkanException
    {
        private:
            VkResult result;
            const char* message;

        public:
            VulkanException(VkResult result, const char* message);

            inline VkResult& getResult()
            {
                return result;
            }

            inline const char* getMessage()
            {
                return message;
            }
    };
}

#endif //CZ_MG_VULKAN_VULKANEXCEPTION_H
