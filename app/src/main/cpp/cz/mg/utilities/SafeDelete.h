#ifndef CZ_MG_UTILITIES_SAFEDELETE_H
#define CZ_MG_UTILITIES_SAFEDELETE_H

#define SAFE_DELETE(x) { if(x != nullptr) delete x; x = nullptr; }

#endif //CZ_MG_UTILITIES_SAFEDELETE_H
