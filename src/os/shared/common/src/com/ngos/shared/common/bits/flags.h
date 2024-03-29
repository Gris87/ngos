#ifndef COM_NGOS_SHARED_COMMON_BITS_FLAGS_H                                                                                                                                                              // Colorize: green
#define COM_NGOS_SHARED_COMMON_BITS_FLAGS_H                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/macro/utils.h>                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
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
        inline flagType& operator^=(const flagType &another) \
        { \
            flags ^= another.flags; \
        \
            return *this; \
        } \
        \
        inline flagType& operator^=(numberType another) \
        { \
            flags ^= another; \
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
        inline numberType operator^(const flagType &another) const \
        { \
            return flags ^ another.flags; \
        } \
        \
        inline numberType operator^(numberType another) const \
        { \
            return flags ^ another; \
        } \
        \
        \
        \
        numberType flags; \
    } __attribute__((packed));                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define FLAGS(...) (PP_JOIN(__FLAGS_, PP_NARG(__VA_ARGS__))((__VA_ARGS__)))                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAG(name) static_cast<enum_t>(name) // TEST: NO                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_1(a)   __FLAG(PP_0 a)                      // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_2(a)   __FLAG(PP_0 a) | __FLAGS_1(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_3(a)   __FLAG(PP_0 a) | __FLAGS_2(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_4(a)   __FLAG(PP_0 a) | __FLAGS_3(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_5(a)   __FLAG(PP_0 a) | __FLAGS_4(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_6(a)   __FLAG(PP_0 a) | __FLAGS_5(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_7(a)   __FLAG(PP_0 a) | __FLAGS_6(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_8(a)   __FLAG(PP_0 a) | __FLAGS_7(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_9(a)   __FLAG(PP_0 a) | __FLAGS_8(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_10(a)  __FLAG(PP_0 a) | __FLAGS_9(PP_X a)  // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_11(a)  __FLAG(PP_0 a) | __FLAGS_10(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_12(a)  __FLAG(PP_0 a) | __FLAGS_11(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_13(a)  __FLAG(PP_0 a) | __FLAGS_12(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_14(a)  __FLAG(PP_0 a) | __FLAGS_13(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_15(a)  __FLAG(PP_0 a) | __FLAGS_14(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_16(a)  __FLAG(PP_0 a) | __FLAGS_15(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_17(a)  __FLAG(PP_0 a) | __FLAGS_16(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_18(a)  __FLAG(PP_0 a) | __FLAGS_17(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_19(a)  __FLAG(PP_0 a) | __FLAGS_18(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_20(a)  __FLAG(PP_0 a) | __FLAGS_19(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_21(a)  __FLAG(PP_0 a) | __FLAGS_20(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_22(a)  __FLAG(PP_0 a) | __FLAGS_21(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_23(a)  __FLAG(PP_0 a) | __FLAGS_22(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_24(a)  __FLAG(PP_0 a) | __FLAGS_23(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_25(a)  __FLAG(PP_0 a) | __FLAGS_24(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_26(a)  __FLAG(PP_0 a) | __FLAGS_25(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_27(a)  __FLAG(PP_0 a) | __FLAGS_26(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_28(a)  __FLAG(PP_0 a) | __FLAGS_27(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_29(a)  __FLAG(PP_0 a) | __FLAGS_28(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_30(a)  __FLAG(PP_0 a) | __FLAGS_29(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_31(a)  __FLAG(PP_0 a) | __FLAGS_30(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_32(a)  __FLAG(PP_0 a) | __FLAGS_31(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_33(a)  __FLAG(PP_0 a) | __FLAGS_32(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_34(a)  __FLAG(PP_0 a) | __FLAGS_33(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_35(a)  __FLAG(PP_0 a) | __FLAGS_34(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_36(a)  __FLAG(PP_0 a) | __FLAGS_35(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_37(a)  __FLAG(PP_0 a) | __FLAGS_36(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_38(a)  __FLAG(PP_0 a) | __FLAGS_37(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_39(a)  __FLAG(PP_0 a) | __FLAGS_38(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_40(a)  __FLAG(PP_0 a) | __FLAGS_39(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_41(a)  __FLAG(PP_0 a) | __FLAGS_40(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_42(a)  __FLAG(PP_0 a) | __FLAGS_41(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_43(a)  __FLAG(PP_0 a) | __FLAGS_42(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_44(a)  __FLAG(PP_0 a) | __FLAGS_43(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_45(a)  __FLAG(PP_0 a) | __FLAGS_44(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_46(a)  __FLAG(PP_0 a) | __FLAGS_45(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_47(a)  __FLAG(PP_0 a) | __FLAGS_46(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_48(a)  __FLAG(PP_0 a) | __FLAGS_47(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_49(a)  __FLAG(PP_0 a) | __FLAGS_48(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_50(a)  __FLAG(PP_0 a) | __FLAGS_49(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_51(a)  __FLAG(PP_0 a) | __FLAGS_50(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_52(a)  __FLAG(PP_0 a) | __FLAGS_51(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_53(a)  __FLAG(PP_0 a) | __FLAGS_52(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_54(a)  __FLAG(PP_0 a) | __FLAGS_53(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_55(a)  __FLAG(PP_0 a) | __FLAGS_54(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_56(a)  __FLAG(PP_0 a) | __FLAGS_55(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_57(a)  __FLAG(PP_0 a) | __FLAGS_56(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_58(a)  __FLAG(PP_0 a) | __FLAGS_57(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_59(a)  __FLAG(PP_0 a) | __FLAGS_58(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_60(a)  __FLAG(PP_0 a) | __FLAGS_59(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_61(a)  __FLAG(PP_0 a) | __FLAGS_60(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_62(a)  __FLAG(PP_0 a) | __FLAGS_61(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_63(a)  __FLAG(PP_0 a) | __FLAGS_62(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
#define __FLAGS_64(a)  __FLAG(PP_0 a) | __FLAGS_63(PP_X a) // TEST: NO                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_TO_STRING_START_PART(flags, res, cur) \
    { \
        if (flags == 0) \
        { \
            return "NONE"; \
        } \
        \
        cur  = res; \
        *cur = 0; \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_TO_FULL_STRING_START_PART(flags, res, cur, typeFormat) \
    { \
        cur = res + sprintf(res, typeFormat " (", flags); \
        \
        if (flags == 0) \
        { \
            strapp(cur, "NONE)"); \
            \
            return res; \
        } \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_TO_STRING_COMMON_PART(start, cur, unknownCount, flags, type) \
    { \
        start        = cur; \
        unknownCount = 0; \
        \
        for (good_I64 i = 0; i < static_cast<good_I64>(sizeof(flags) * 8); ++i) \
        { \
            enum_t flag = BIT(i); \
            \
            if ((flags & flag) != 0) \
            { \
                const good_Char8 *flagString = flagToString(static_cast<type>(flag)); \
                \
                if (strcmp(flagString, "UNKNOWN") == 0) \
                { \
                    ++unknownCount; \
                } \
                else \
                { \
                    if (cur != start) \
                    { \
                        cur = strapp(cur, " | "); \
                    } \
                    \
                    \
                    \
                    cur = strapp(cur, flagString); \
                } \
            } \
        } \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_TO_STRING_END_PART(start, cur, unknownCount) \
    { \
        if (unknownCount != 0) \
        { \
            if (cur != start) \
            { \
                cur = strapp(cur, " | "); \
            } \
            \
            \
            \
            if (unknownCount == 1) \
            { \
                strapp(cur, "UNKNOWN"); \
            } \
            else \
            { \
                sprintf(cur, "UNKNOWN x %u", unknownCount); \
            } \
        } \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define __FLAGS_TO_FULL_STRING_END_PART(start, cur, unknownCount) \
    { \
        if (unknownCount != 0) \
        { \
            if (cur != start) \
            { \
                cur = strapp(cur, " | "); \
            } \
            \
            \
            \
            if (unknownCount == 1) \
            { \
                strapp(cur, "UNKNOWN)"); \
            } \
            else \
            { \
                sprintf(cur, "UNKNOWN x %u)", unknownCount); \
            } \
        } \
        else \
        { \
            cur[0] = ')'; \
            cur[1] = 0; \
        } \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define FLAGS_TO_STRING(res, flags, type) \
    { \
        good_Char8 *start; \
        good_Char8 *cur; \
        good_U8     unknownCount; \
        \
        __FLAGS_TO_STRING_START_PART(flags, res, cur); \
        __FLAGS_TO_STRING_COMMON_PART(start, cur, unknownCount, flags, type); \
        __FLAGS_TO_STRING_END_PART(start, cur, unknownCount); \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define FLAGS_TO_FULL_STRING(res, flags, type, typeFormat) \
    { \
        good_Char8 *start; \
        good_Char8 *cur; \
        good_U8     unknownCount; \
        \
        __FLAGS_TO_FULL_STRING_START_PART(flags, res, cur, typeFormat); \
        __FLAGS_TO_STRING_COMMON_PART(start, cur, unknownCount, flags, type); \
        __FLAGS_TO_FULL_STRING_END_PART(start, cur, unknownCount); \
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_BITS_FLAGS_H                                                                                                                                                            // Colorize: green
