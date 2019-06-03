#ifndef CZ_MG_UTILITIES_NOCOPY_H
#define CZ_MG_UTILITIES_NOCOPY_H

#define NOCOPY(x) \
    x(const x&) = delete; \
    x(x&) = delete; \
    x& operator=(const x&) = delete; \
    x& operator=(x&) = delete;

#endif //CZ_MG_UTILITIES_NOCOPY_H
