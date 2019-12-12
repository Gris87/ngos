#ifndef NGOS_FLAGS_H
#define NGOS_FLAGS_H



#define DEFINE_FLAGS(flagType, numberType) \
    struct flagType \
    { \
        flagType() \
        { \
            flags = 0; \
        } \
        \
        flagType(const flagType &another) \
        { \
            flags = another.flags; \
        } \
        \
        flagType(numberType another) \
        { \
            flags = another; \
        } \
        \
        inline flagType& operator=(const flagType &another) \
        { \
            flags = another.flags; \
        \
            return *this; \
        } \
        \
        inline flagType& operator=(numberType another) \
        { \
            flags = another; \
        \
            return *this; \
        } \
        \
        inline flagType& operator&=(const flagType &another) \
        { \
            flags &= another.flags; \
        \
            return *this; \
        } \
        \
        inline flagType& operator&=(numberType another) \
        { \
            flags &= another; \
        \
            return *this; \
        } \
        \
        inline flagType& operator|=(const flagType &another) \
        { \
            flags |= another.flags; \
        \
            return *this; \
        } \
        \
        inline flagType& operator|=(numberType another) \
        { \
            flags |= another; \
        \
            return *this; \
        } \
        \
        inline bool operator==(const flagType &another) const \
        { \
            return flags == another.flags; \
        } \
        \
        inline bool operator==(numberType another) const \
        { \
            return flags == another; \
        } \
        \
        inline bool operator!=(const flagType &another) const \
        { \
            return flags != another.flags; \
        } \
        \
        inline bool operator!=(numberType another) const \
        { \
            return flags != another; \
        } \
        \
        inline numberType operator&(const flagType &another) const \
        { \
            return flags & another.flags; \
        } \
        \
        inline numberType operator&(numberType another) const \
        { \
            return flags & another; \
        } \
        \
        inline numberType operator|(const flagType &another) const \
        { \
            return flags | another.flags; \
        } \
        \
        inline numberType operator|(numberType another) const \
        { \
            return flags | another; \
        } \
        \
        numberType flags; \
    } __attribute__((packed));



#endif // NGOS_FLAGS_H
