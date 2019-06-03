#include "VulkanException.h"

cz::mg::vulkan::VulkanException::VulkanException(VkResult result, const char *message)
{
    this->result = result;
    this->message = message;
}
