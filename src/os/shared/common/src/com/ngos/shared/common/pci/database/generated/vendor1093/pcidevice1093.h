// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCIDEVICE1093_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCIDEVICE1093_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1093: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0160 = 0x0160,
    DEVICE_0162 = 0x0162,
    DEVICE_0FE1 = 0x0FE1,
    DEVICE_1150 = 0x1150,
    DEVICE_1170 = 0x1170,
    DEVICE_1180 = 0x1180,
    DEVICE_1190 = 0x1190,
    DEVICE_11B0 = 0x11B0,
    DEVICE_11C0 = 0x11C0,
    DEVICE_11D0 = 0x11D0,
    DEVICE_1270 = 0x1270,
    DEVICE_1290 = 0x1290,
    DEVICE_12B0 = 0x12B0,
    DEVICE_1310 = 0x1310,
    DEVICE_1320 = 0x1320,
    DEVICE_1330 = 0x1330,
    DEVICE_1340 = 0x1340,
    DEVICE_1350 = 0x1350,
    DEVICE_1360 = 0x1360,
    DEVICE_13C0 = 0x13C0,
    DEVICE_1490 = 0x1490,
    DEVICE_14E0 = 0x14E0,
    DEVICE_14F0 = 0x14F0,
    DEVICE_1580 = 0x1580,
    DEVICE_15B0 = 0x15B0,
    DEVICE_1710 = 0x1710,
    DEVICE_17C0 = 0x17C0,
    DEVICE_17D0 = 0x17D0,
    DEVICE_1870 = 0x1870,
    DEVICE_1880 = 0x1880,
    DEVICE_18B0 = 0x18B0,
    DEVICE_18C0 = 0x18C0,
    DEVICE_1920 = 0x1920,
    DEVICE_1930 = 0x1930,
    DEVICE_19C0 = 0x19C0,
    DEVICE_1AA0 = 0x1AA0,
    DEVICE_1AD0 = 0x1AD0,
    DEVICE_1AE0 = 0x1AE0,
    DEVICE_1E30 = 0x1E30,
    DEVICE_1E40 = 0x1E40,
    DEVICE_1E50 = 0x1E50,
    DEVICE_2410 = 0x2410,
    DEVICE_2420 = 0x2420,
    DEVICE_2430 = 0x2430,
    DEVICE_2470 = 0x2470,
    DEVICE_24A0 = 0x24A0,
    DEVICE_24B0 = 0x24B0,
    DEVICE_24F0 = 0x24F0,
    DEVICE_2510 = 0x2510,
    DEVICE_2520 = 0x2520,
    DEVICE_27A0 = 0x27A0,
    DEVICE_27B0 = 0x27B0,
    DEVICE_2880 = 0x2880,
    DEVICE_2890 = 0x2890,
    DEVICE_28A0 = 0x28A0,
    DEVICE_28B0 = 0x28B0,
    DEVICE_28C0 = 0x28C0,
    DEVICE_28D0 = 0x28D0,
    DEVICE_28E0 = 0x28E0,
    DEVICE_29F0 = 0x29F0,
    DEVICE_2A00 = 0x2A00,
    DEVICE_2A60 = 0x2A60,
    DEVICE_2A70 = 0x2A70,
    DEVICE_2A80 = 0x2A80,
    DEVICE_2AB0 = 0x2AB0,
    DEVICE_2B10 = 0x2B10,
    DEVICE_2B20 = 0x2B20,
    DEVICE_2B80 = 0x2B80,
    DEVICE_2B90 = 0x2B90,
    DEVICE_2C60 = 0x2C60,
    DEVICE_2C70 = 0x2C70,
    DEVICE_2C80 = 0x2C80,
    DEVICE_2C90 = 0x2C90,
    DEVICE_2CA0 = 0x2CA0,
    DEVICE_2CB0 = 0x2CB0,
    DEVICE_2CC0 = 0x2CC0,
    DEVICE_2D20 = 0x2D20,
    DEVICE_2DB0 = 0x2DB0,
    DEVICE_2DC0 = 0x2DC0,
    DEVICE_2DD0 = 0x2DD0,
    DEVICE_2EB0 = 0x2EB0,
    DEVICE_2EC0 = 0x2EC0,
    DEVICE_2ED0 = 0x2ED0,
    DEVICE_2EE0 = 0x2EE0,
    DEVICE_2EF0 = 0x2EF0,
    DEVICE_2FD1 = 0x2FD1,
    DEVICE_2FD2 = 0x2FD2,
    DEVICE_2FD3 = 0x2FD3,
    DEVICE_2FD5 = 0x2FD5,
    DEVICE_2FD6 = 0x2FD6,
    DEVICE_7003 = 0x7003,
    DEVICE_7004 = 0x7004,
    DEVICE_700B = 0x700B,
    DEVICE_700C = 0x700C,
    DEVICE_701A = 0x701A,
    DEVICE_701B = 0x701B,
    DEVICE_7023 = 0x7023,
    DEVICE_7027 = 0x7027,
    DEVICE_702C = 0x702C,
    DEVICE_702D = 0x702D,
    DEVICE_702E = 0x702E,
    DEVICE_702F = 0x702F,
    DEVICE_7030 = 0x7030,
    DEVICE_7031 = 0x7031,
    DEVICE_7032 = 0x7032,
    DEVICE_7033 = 0x7033,
    DEVICE_7034 = 0x7034,
    DEVICE_7035 = 0x7035,
    DEVICE_7036 = 0x7036,
    DEVICE_7037 = 0x7037,
    DEVICE_7038 = 0x7038,
    DEVICE_7039 = 0x7039,
    DEVICE_703F = 0x703F,
    DEVICE_7040 = 0x7040,
    DEVICE_7044 = 0x7044,
    DEVICE_7047 = 0x7047,
    DEVICE_704C = 0x704C,
    DEVICE_704F = 0x704F,
    DEVICE_7050 = 0x7050,
    DEVICE_7055 = 0x7055,
    DEVICE_7056 = 0x7056,
    DEVICE_705A = 0x705A,
    DEVICE_705B = 0x705B,
    DEVICE_705C = 0x705C,
    DEVICE_705D = 0x705D,
    DEVICE_705E = 0x705E,
    DEVICE_7060 = 0x7060,
    DEVICE_7064 = 0x7064,
    DEVICE_7065 = 0x7065,
    DEVICE_7066 = 0x7066,
    DEVICE_7067 = 0x7067,
    DEVICE_7068 = 0x7068,
    DEVICE_7069 = 0x7069,
    DEVICE_706A = 0x706A,
    DEVICE_706B = 0x706B,
    DEVICE_7073 = 0x7073,
    DEVICE_7074 = 0x7074,
    DEVICE_7075 = 0x7075,
    DEVICE_7076 = 0x7076,
    DEVICE_707C = 0x707C,
    DEVICE_707E = 0x707E,
    DEVICE_7080 = 0x7080,
    DEVICE_7081 = 0x7081,
    DEVICE_7083 = 0x7083,
    DEVICE_7085 = 0x7085,
    DEVICE_7086 = 0x7086,
    DEVICE_7087 = 0x7087,
    DEVICE_7088 = 0x7088,
    DEVICE_708C = 0x708C,
    DEVICE_708D = 0x708D,
    DEVICE_70A9 = 0x70A9,
    DEVICE_70AA = 0x70AA,
    DEVICE_70AB = 0x70AB,
    DEVICE_70AC = 0x70AC,
    DEVICE_70AD = 0x70AD,
    DEVICE_70AE = 0x70AE,
    DEVICE_70AF = 0x70AF,
    DEVICE_70B0 = 0x70B0,
    DEVICE_70B1 = 0x70B1,
    DEVICE_70B2 = 0x70B2,
    DEVICE_70B3 = 0x70B3,
    DEVICE_70B4 = 0x70B4,
    DEVICE_70B5 = 0x70B5,
    DEVICE_70B6 = 0x70B6,
    DEVICE_70B7 = 0x70B7,
    DEVICE_70B8 = 0x70B8,
    DEVICE_70B9 = 0x70B9,
    DEVICE_70BA = 0x70BA,
    DEVICE_70BB = 0x70BB,
    DEVICE_70BC = 0x70BC,
    DEVICE_70BD = 0x70BD,
    DEVICE_70BE = 0x70BE,
    DEVICE_70BF = 0x70BF,
    DEVICE_70C0 = 0x70C0,
    DEVICE_70C3 = 0x70C3,
    DEVICE_70C4 = 0x70C4,
    DEVICE_70C5 = 0x70C5,
    DEVICE_70C6 = 0x70C6,
    DEVICE_70C7 = 0x70C7,
    DEVICE_70C8 = 0x70C8,
    DEVICE_70C9 = 0x70C9,
    DEVICE_70CA = 0x70CA,
    DEVICE_70CC = 0x70CC,
    DEVICE_70CD = 0x70CD,
    DEVICE_70CE = 0x70CE,
    DEVICE_70CF = 0x70CF,
    DEVICE_70D0 = 0x70D0,
    DEVICE_70D1 = 0x70D1,
    DEVICE_70D2 = 0x70D2,
    DEVICE_70D3 = 0x70D3,
    DEVICE_70D4 = 0x70D4,
    DEVICE_70D6 = 0x70D6,
    DEVICE_70D7 = 0x70D7,
    DEVICE_70D8 = 0x70D8,
    DEVICE_70D9 = 0x70D9,
    DEVICE_70DA = 0x70DA,
    DEVICE_70DB = 0x70DB,
    DEVICE_70DC = 0x70DC,
    DEVICE_70DD = 0x70DD,
    DEVICE_70DE = 0x70DE,
    DEVICE_70DF = 0x70DF,
    DEVICE_70E0 = 0x70E0,
    DEVICE_70E1 = 0x70E1,
    DEVICE_70E2 = 0x70E2,
    DEVICE_70E3 = 0x70E3,
    DEVICE_70E4 = 0x70E4,
    DEVICE_70E5 = 0x70E5,
    DEVICE_70E6 = 0x70E6,
    DEVICE_70E7 = 0x70E7,
    DEVICE_70E8 = 0x70E8,
    DEVICE_70E9 = 0x70E9,
    DEVICE_70EA = 0x70EA,
    DEVICE_70EB = 0x70EB,
    DEVICE_70EC = 0x70EC,
    DEVICE_70ED = 0x70ED,
    DEVICE_70EE = 0x70EE,
    DEVICE_70EF = 0x70EF,
    DEVICE_70F0 = 0x70F0,
    DEVICE_70F1 = 0x70F1,
    DEVICE_70F2 = 0x70F2,
    DEVICE_70F3 = 0x70F3,
    DEVICE_70F6 = 0x70F6,
    DEVICE_70F7 = 0x70F7,
    DEVICE_70F8 = 0x70F8,
    DEVICE_70FF = 0x70FF,
    DEVICE_7100 = 0x7100,
    DEVICE_7104 = 0x7104,
    DEVICE_7105 = 0x7105,
    DEVICE_710A = 0x710A,
    DEVICE_710D = 0x710D,
    DEVICE_710E = 0x710E,
    DEVICE_710F = 0x710F,
    DEVICE_7110 = 0x7110,
    DEVICE_7111 = 0x7111,
    DEVICE_7119 = 0x7119,
    DEVICE_711A = 0x711A,
    DEVICE_711B = 0x711B,
    DEVICE_711C = 0x711C,
    DEVICE_7120 = 0x7120,
    DEVICE_7121 = 0x7121,
    DEVICE_7122 = 0x7122,
    DEVICE_7123 = 0x7123,
    DEVICE_7124 = 0x7124,
    DEVICE_7125 = 0x7125,
    DEVICE_7126 = 0x7126,
    DEVICE_7127 = 0x7127,
    DEVICE_7128 = 0x7128,
    DEVICE_7137 = 0x7137,
    DEVICE_713C = 0x713C,
    DEVICE_713D = 0x713D,
    DEVICE_7142 = 0x7142,
    DEVICE_7144 = 0x7144,
    DEVICE_7145 = 0x7145,
    DEVICE_7146 = 0x7146,
    DEVICE_7147 = 0x7147,
    DEVICE_7148 = 0x7148,
    DEVICE_7149 = 0x7149,
    DEVICE_714C = 0x714C,
    DEVICE_714D = 0x714D,
    DEVICE_7150 = 0x7150,
    DEVICE_7152 = 0x7152,
    DEVICE_7156 = 0x7156,
    DEVICE_715D = 0x715D,
    DEVICE_7167 = 0x7167,
    DEVICE_7168 = 0x7168,
    DEVICE_716B = 0x716B,
    DEVICE_716C = 0x716C,
    DEVICE_716D = 0x716D,
    DEVICE_716F = 0x716F,
    DEVICE_7170 = 0x7170,
    DEVICE_7171 = 0x7171,
    DEVICE_7174 = 0x7174,
    DEVICE_7177 = 0x7177,
    DEVICE_717D = 0x717D,
    DEVICE_717F = 0x717F,
    DEVICE_7187 = 0x7187,
    DEVICE_718B = 0x718B,
    DEVICE_718C = 0x718C,
    DEVICE_7191 = 0x7191,
    DEVICE_7193 = 0x7193,
    DEVICE_7194 = 0x7194,
    DEVICE_7195 = 0x7195,
    DEVICE_7197 = 0x7197,
    DEVICE_7198 = 0x7198,
    DEVICE_719F = 0x719F,
    DEVICE_71A0 = 0x71A0,
    DEVICE_71A3 = 0x71A3,
    DEVICE_71A4 = 0x71A4,
    DEVICE_71A5 = 0x71A5,
    DEVICE_71A7 = 0x71A7,
    DEVICE_71A9 = 0x71A9,
    DEVICE_71AA = 0x71AA,
    DEVICE_71AB = 0x71AB,
    DEVICE_71AC = 0x71AC,
    DEVICE_71AD = 0x71AD,
    DEVICE_71AE = 0x71AE,
    DEVICE_71B7 = 0x71B7,
    DEVICE_71B8 = 0x71B8,
    DEVICE_71B9 = 0x71B9,
    DEVICE_71BB = 0x71BB,
    DEVICE_71BC = 0x71BC,
    DEVICE_71BF = 0x71BF,
    DEVICE_71C5 = 0x71C5,
    DEVICE_71C6 = 0x71C6,
    DEVICE_71C7 = 0x71C7,
    DEVICE_71DC = 0x71DC,
    DEVICE_71E0 = 0x71E0,
    DEVICE_71E1 = 0x71E1,
    DEVICE_71E2 = 0x71E2,
    DEVICE_71E3 = 0x71E3,
    DEVICE_71FC = 0x71FC,
    DEVICE_7209 = 0x7209,
    DEVICE_720A = 0x720A,
    DEVICE_720B = 0x720B,
    DEVICE_720C = 0x720C,
    DEVICE_7260 = 0x7260,
    DEVICE_7261 = 0x7261,
    DEVICE_726D = 0x726D,
    DEVICE_7273 = 0x7273,
    DEVICE_7274 = 0x7274,
    DEVICE_7279 = 0x7279,
    DEVICE_727A = 0x727A,
    DEVICE_727B = 0x727B,
    DEVICE_727C = 0x727C,
    DEVICE_727E = 0x727E,
    DEVICE_7281 = 0x7281,
    DEVICE_7282 = 0x7282,
    DEVICE_7283 = 0x7283,
    DEVICE_7288 = 0x7288,
    DEVICE_7293 = 0x7293,
    DEVICE_729D = 0x729D,
    DEVICE_72A4 = 0x72A4,
    DEVICE_72A7 = 0x72A7,
    DEVICE_72A8 = 0x72A8,
    DEVICE_72A9 = 0x72A9,
    DEVICE_72AA = 0x72AA,
    DEVICE_72AB = 0x72AB,
    DEVICE_72B8 = 0x72B8,
    DEVICE_72D0 = 0x72D0,
    DEVICE_72D1 = 0x72D1,
    DEVICE_72D2 = 0x72D2,
    DEVICE_72D3 = 0x72D3,
    DEVICE_72D4 = 0x72D4,
    DEVICE_72D5 = 0x72D5,
    DEVICE_72D6 = 0x72D6,
    DEVICE_72D7 = 0x72D7,
    DEVICE_72D8 = 0x72D8,
    DEVICE_72D9 = 0x72D9,
    DEVICE_72E8 = 0x72E8,
    DEVICE_72E9 = 0x72E9,
    DEVICE_72EF = 0x72EF,
    DEVICE_72F0 = 0x72F0,
    DEVICE_72FB = 0x72FB,
    DEVICE_730E = 0x730E,
    DEVICE_730F = 0x730F,
    DEVICE_7310 = 0x7310,
    DEVICE_731C = 0x731C,
    DEVICE_731D = 0x731D,
    DEVICE_7322 = 0x7322,
    DEVICE_7327 = 0x7327,
    DEVICE_732C = 0x732C,
    DEVICE_7331 = 0x7331,
    DEVICE_7332 = 0x7332,
    DEVICE_7333 = 0x7333,
    DEVICE_7335 = 0x7335,
    DEVICE_7336 = 0x7336,
    DEVICE_7342 = 0x7342,
    DEVICE_7349 = 0x7349,
    DEVICE_734A = 0x734A,
    DEVICE_7357 = 0x7357,
    DEVICE_7359 = 0x7359,
    DEVICE_7370 = 0x7370,
    DEVICE_7373 = 0x7373,
    DEVICE_7374 = 0x7374,
    DEVICE_7375 = 0x7375,
    DEVICE_7378 = 0x7378,
    DEVICE_737D = 0x737D,
    DEVICE_7384 = 0x7384,
    DEVICE_7385 = 0x7385,
    DEVICE_7386 = 0x7386,
    DEVICE_7387 = 0x7387,
    DEVICE_7390 = 0x7390,
    DEVICE_7391 = 0x7391,
    DEVICE_7392 = 0x7392,
    DEVICE_7393 = 0x7393,
    DEVICE_7394 = 0x7394,
    DEVICE_7397 = 0x7397,
    DEVICE_7398 = 0x7398,
    DEVICE_7399 = 0x7399,
    DEVICE_739A = 0x739A,
    DEVICE_739B = 0x739B,
    DEVICE_73A1 = 0x73A1,
    DEVICE_73A2 = 0x73A2,
    DEVICE_73A5 = 0x73A5,
    DEVICE_73A7 = 0x73A7,
    DEVICE_73A8 = 0x73A8,
    DEVICE_73A9 = 0x73A9,
    DEVICE_73AA = 0x73AA,
    DEVICE_73AB = 0x73AB,
    DEVICE_73AC = 0x73AC,
    DEVICE_73AD = 0x73AD,
    DEVICE_73AF = 0x73AF,
    DEVICE_73B1 = 0x73B1,
    DEVICE_73B2 = 0x73B2,
    DEVICE_73B3 = 0x73B3,
    DEVICE_73B4 = 0x73B4,
    DEVICE_73B5 = 0x73B5,
    DEVICE_73B6 = 0x73B6,
    DEVICE_73B7 = 0x73B7,
    DEVICE_73B8 = 0x73B8,
    DEVICE_73B9 = 0x73B9,
    DEVICE_73BA = 0x73BA,
    DEVICE_73BB = 0x73BB,
    DEVICE_73BD = 0x73BD,
    DEVICE_73BF = 0x73BF,
    DEVICE_73C0 = 0x73C0,
    DEVICE_73C1 = 0x73C1,
    DEVICE_73C2 = 0x73C2,
    DEVICE_73C3 = 0x73C3,
    DEVICE_73C5 = 0x73C5,
    DEVICE_73C6 = 0x73C6,
    DEVICE_73C8 = 0x73C8,
    DEVICE_73C9 = 0x73C9,
    DEVICE_73CA = 0x73CA,
    DEVICE_73CB = 0x73CB,
    DEVICE_73CC = 0x73CC,
    DEVICE_73D5 = 0x73D5,
    DEVICE_73D6 = 0x73D6,
    DEVICE_73D7 = 0x73D7,
    DEVICE_73E1 = 0x73E1,
    DEVICE_73EC = 0x73EC,
    DEVICE_73ED = 0x73ED,
    DEVICE_73F0 = 0x73F0,
    DEVICE_73F1 = 0x73F1,
    DEVICE_73F4 = 0x73F4,
    DEVICE_73F6 = 0x73F6,
    DEVICE_73F7 = 0x73F7,
    DEVICE_73F8 = 0x73F8,
    DEVICE_73F9 = 0x73F9,
    DEVICE_73FA = 0x73FA,
    DEVICE_73FB = 0x73FB,
    DEVICE_7404 = 0x7404,
    DEVICE_7405 = 0x7405,
    DEVICE_7406 = 0x7406,
    DEVICE_740E = 0x740E,
    DEVICE_740F = 0x740F,
    DEVICE_7410 = 0x7410,
    DEVICE_7411 = 0x7411,
    DEVICE_7414 = 0x7414,
    DEVICE_741C = 0x741C,
    DEVICE_741D = 0x741D,
    DEVICE_743C = 0x743C,
    DEVICE_7448 = 0x7448,
    DEVICE_7454 = 0x7454,
    DEVICE_7455 = 0x7455,
    DEVICE_7456 = 0x7456,
    DEVICE_7457 = 0x7457,
    DEVICE_745A = 0x745A,
    DEVICE_745E = 0x745E,
    DEVICE_745F = 0x745F,
    DEVICE_7460 = 0x7460,
    DEVICE_7461 = 0x7461,
    DEVICE_746D = 0x746D,
    DEVICE_746E = 0x746E,
    DEVICE_746F = 0x746F,
    DEVICE_7472 = 0x7472,
    DEVICE_7495 = 0x7495,
    DEVICE_7497 = 0x7497,
    DEVICE_74AE = 0x74AE,
    DEVICE_74B4 = 0x74B4,
    DEVICE_74B5 = 0x74B5,
    DEVICE_74C1 = 0x74C1,
    DEVICE_74C2 = 0x74C2,
    DEVICE_74C3 = 0x74C3,
    DEVICE_74C4 = 0x74C4,
    DEVICE_74D5 = 0x74D5,
    DEVICE_74D9 = 0x74D9,
    DEVICE_74DA = 0x74DA,
    DEVICE_74DB = 0x74DB,
    DEVICE_74DC = 0x74DC,
    DEVICE_74E8 = 0x74E8,
    DEVICE_7515 = 0x7515,
    DEVICE_7516 = 0x7516,
    DEVICE_7517 = 0x7517,
    DEVICE_7518 = 0x7518,
    DEVICE_751B = 0x751B,
    DEVICE_751C = 0x751C,
    DEVICE_7528 = 0x7528,
    DEVICE_7529 = 0x7529,
    DEVICE_752A = 0x752A,
    DEVICE_7539 = 0x7539,
    DEVICE_753A = 0x753A,
    DEVICE_7598 = 0x7598,
    DEVICE_75A4 = 0x75A4,
    DEVICE_75B1 = 0x75B1,
    DEVICE_75BA = 0x75BA,
    DEVICE_75BB = 0x75BB,
    DEVICE_75E5 = 0x75E5,
    DEVICE_75E6 = 0x75E6,
    DEVICE_75EF = 0x75EF,
    DEVICE_761C = 0x761C,
    DEVICE_761F = 0x761F,
    DEVICE_7620 = 0x7620,
    DEVICE_7621 = 0x7621,
    DEVICE_7622 = 0x7622,
    DEVICE_7626 = 0x7626,
    DEVICE_7627 = 0x7627,
    DEVICE_7638 = 0x7638,
    DEVICE_7639 = 0x7639,
    DEVICE_763A = 0x763A,
    DEVICE_763B = 0x763B,
    DEVICE_763C = 0x763C,
    DEVICE_764B = 0x764B,
    DEVICE_764C = 0x764C,
    DEVICE_764D = 0x764D,
    DEVICE_764E = 0x764E,
    DEVICE_764F = 0x764F,
    DEVICE_7654 = 0x7654,
    DEVICE_7655 = 0x7655,
    DEVICE_7656 = 0x7656,
    DEVICE_7657 = 0x7657,
    DEVICE_765D = 0x765D,
    DEVICE_765E = 0x765E,
    DEVICE_765F = 0x765F,
    DEVICE_7660 = 0x7660,
    DEVICE_766D = 0x766D,
    DEVICE_766E = 0x766E,
    DEVICE_766F = 0x766F,
    DEVICE_76A3 = 0x76A3,
    DEVICE_76A4 = 0x76A4,
    DEVICE_76A5 = 0x76A5,
    DEVICE_783E = 0x783E,
    DEVICE_9020 = 0x9020,
    DEVICE_9030 = 0x9030,
    DEVICE_9040 = 0x9040,
    DEVICE_9050 = 0x9050,
    DEVICE_9060 = 0x9060,
    DEVICE_9070 = 0x9070,
    DEVICE_9080 = 0x9080,
    DEVICE_9090 = 0x9090,
    DEVICE_90A0 = 0x90A0,
    DEVICE_A001 = 0xA001,
    DEVICE_B001 = 0xB001,
    DEVICE_B011 = 0xB011,
    DEVICE_B021 = 0xB021,
    DEVICE_B022 = 0xB022,
    DEVICE_B031 = 0xB031,
    DEVICE_B041 = 0xB041,
    DEVICE_B051 = 0xB051,
    DEVICE_B061 = 0xB061,
    DEVICE_B071 = 0xB071,
    DEVICE_B081 = 0xB081,
    DEVICE_B091 = 0xB091,
    DEVICE_B0B1 = 0xB0B1,
    DEVICE_B0C1 = 0xB0C1,
    DEVICE_B0E1 = 0xB0E1,
    DEVICE_C4C4 = 0xC4C4,
    DEVICE_C801 = 0xC801,
    DEVICE_C811 = 0xC811,
    DEVICE_C821 = 0xC821,
    DEVICE_C831 = 0xC831,
    DEVICE_C840 = 0xC840,
    DEVICE_D130 = 0xD130,
    DEVICE_D140 = 0xD140,
    DEVICE_D150 = 0xD150,
    DEVICE_D160 = 0xD160,
    DEVICE_D170 = 0xD170,
    DEVICE_D190 = 0xD190,
    DEVICE_D1A0 = 0xD1A0,
    DEVICE_D1B0 = 0xD1B0,
    DEVICE_D1C0 = 0xD1C0,
    DEVICE_D1D0 = 0xD1D0,
    DEVICE_D1E0 = 0xD1E0,
    DEVICE_D1F0 = 0xD1F0,
    DEVICE_D1F1 = 0xD1F1,
    DEVICE_D230 = 0xD230,
    DEVICE_D240 = 0xD240,
    DEVICE_D250 = 0xD250,
    DEVICE_D260 = 0xD260,
    DEVICE_D270 = 0xD270,
    DEVICE_D280 = 0xD280,
    DEVICE_D290 = 0xD290,
    DEVICE_D2A0 = 0xD2A0,
    DEVICE_D2B0 = 0xD2B0,
    DEVICE_E111 = 0xE111,
    DEVICE_E131 = 0xE131,
    DEVICE_E141 = 0xE141,
    DEVICE_E151 = 0xE151,
    DEVICE_E211 = 0xE211,
    DEVICE_E231 = 0xE231,
    DEVICE_E241 = 0xE241,
    DEVICE_E251 = 0xE251,
    DEVICE_E261 = 0xE261,
    DEVICE_E271 = 0xE271,
    DEVICE_F110 = 0xF110,
    DEVICE_F120 = 0xF120,
    DEVICE_FE00 = 0xFE00,
    DEVICE_FE41 = 0xFE41,
    DEVICE_FE51 = 0xFE51,
    DEVICE_FE61 = 0xFE61,
    DEVICE_FE70 = 0xFE70
};



inline const char8* enumToString(PciDevice1093 device1093) // TEST: NO
{
    // COMMON_LT((" | device1093 = %u", device1093)); // Commented to avoid bad looking logs



    switch (device1093)
    {
        case PciDevice1093::NONE:        return "NONE";
        case PciDevice1093::DEVICE_0160: return "DEVICE_0160";
        case PciDevice1093::DEVICE_0162: return "DEVICE_0162";
        case PciDevice1093::DEVICE_0FE1: return "DEVICE_0FE1";
        case PciDevice1093::DEVICE_1150: return "DEVICE_1150";
        case PciDevice1093::DEVICE_1170: return "DEVICE_1170";
        case PciDevice1093::DEVICE_1180: return "DEVICE_1180";
        case PciDevice1093::DEVICE_1190: return "DEVICE_1190";
        case PciDevice1093::DEVICE_11B0: return "DEVICE_11B0";
        case PciDevice1093::DEVICE_11C0: return "DEVICE_11C0";
        case PciDevice1093::DEVICE_11D0: return "DEVICE_11D0";
        case PciDevice1093::DEVICE_1270: return "DEVICE_1270";
        case PciDevice1093::DEVICE_1290: return "DEVICE_1290";
        case PciDevice1093::DEVICE_12B0: return "DEVICE_12B0";
        case PciDevice1093::DEVICE_1310: return "DEVICE_1310";
        case PciDevice1093::DEVICE_1320: return "DEVICE_1320";
        case PciDevice1093::DEVICE_1330: return "DEVICE_1330";
        case PciDevice1093::DEVICE_1340: return "DEVICE_1340";
        case PciDevice1093::DEVICE_1350: return "DEVICE_1350";
        case PciDevice1093::DEVICE_1360: return "DEVICE_1360";
        case PciDevice1093::DEVICE_13C0: return "DEVICE_13C0";
        case PciDevice1093::DEVICE_1490: return "DEVICE_1490";
        case PciDevice1093::DEVICE_14E0: return "DEVICE_14E0";
        case PciDevice1093::DEVICE_14F0: return "DEVICE_14F0";
        case PciDevice1093::DEVICE_1580: return "DEVICE_1580";
        case PciDevice1093::DEVICE_15B0: return "DEVICE_15B0";
        case PciDevice1093::DEVICE_1710: return "DEVICE_1710";
        case PciDevice1093::DEVICE_17C0: return "DEVICE_17C0";
        case PciDevice1093::DEVICE_17D0: return "DEVICE_17D0";
        case PciDevice1093::DEVICE_1870: return "DEVICE_1870";
        case PciDevice1093::DEVICE_1880: return "DEVICE_1880";
        case PciDevice1093::DEVICE_18B0: return "DEVICE_18B0";
        case PciDevice1093::DEVICE_18C0: return "DEVICE_18C0";
        case PciDevice1093::DEVICE_1920: return "DEVICE_1920";
        case PciDevice1093::DEVICE_1930: return "DEVICE_1930";
        case PciDevice1093::DEVICE_19C0: return "DEVICE_19C0";
        case PciDevice1093::DEVICE_1AA0: return "DEVICE_1AA0";
        case PciDevice1093::DEVICE_1AD0: return "DEVICE_1AD0";
        case PciDevice1093::DEVICE_1AE0: return "DEVICE_1AE0";
        case PciDevice1093::DEVICE_1E30: return "DEVICE_1E30";
        case PciDevice1093::DEVICE_1E40: return "DEVICE_1E40";
        case PciDevice1093::DEVICE_1E50: return "DEVICE_1E50";
        case PciDevice1093::DEVICE_2410: return "DEVICE_2410";
        case PciDevice1093::DEVICE_2420: return "DEVICE_2420";
        case PciDevice1093::DEVICE_2430: return "DEVICE_2430";
        case PciDevice1093::DEVICE_2470: return "DEVICE_2470";
        case PciDevice1093::DEVICE_24A0: return "DEVICE_24A0";
        case PciDevice1093::DEVICE_24B0: return "DEVICE_24B0";
        case PciDevice1093::DEVICE_24F0: return "DEVICE_24F0";
        case PciDevice1093::DEVICE_2510: return "DEVICE_2510";
        case PciDevice1093::DEVICE_2520: return "DEVICE_2520";
        case PciDevice1093::DEVICE_27A0: return "DEVICE_27A0";
        case PciDevice1093::DEVICE_27B0: return "DEVICE_27B0";
        case PciDevice1093::DEVICE_2880: return "DEVICE_2880";
        case PciDevice1093::DEVICE_2890: return "DEVICE_2890";
        case PciDevice1093::DEVICE_28A0: return "DEVICE_28A0";
        case PciDevice1093::DEVICE_28B0: return "DEVICE_28B0";
        case PciDevice1093::DEVICE_28C0: return "DEVICE_28C0";
        case PciDevice1093::DEVICE_28D0: return "DEVICE_28D0";
        case PciDevice1093::DEVICE_28E0: return "DEVICE_28E0";
        case PciDevice1093::DEVICE_29F0: return "DEVICE_29F0";
        case PciDevice1093::DEVICE_2A00: return "DEVICE_2A00";
        case PciDevice1093::DEVICE_2A60: return "DEVICE_2A60";
        case PciDevice1093::DEVICE_2A70: return "DEVICE_2A70";
        case PciDevice1093::DEVICE_2A80: return "DEVICE_2A80";
        case PciDevice1093::DEVICE_2AB0: return "DEVICE_2AB0";
        case PciDevice1093::DEVICE_2B10: return "DEVICE_2B10";
        case PciDevice1093::DEVICE_2B20: return "DEVICE_2B20";
        case PciDevice1093::DEVICE_2B80: return "DEVICE_2B80";
        case PciDevice1093::DEVICE_2B90: return "DEVICE_2B90";
        case PciDevice1093::DEVICE_2C60: return "DEVICE_2C60";
        case PciDevice1093::DEVICE_2C70: return "DEVICE_2C70";
        case PciDevice1093::DEVICE_2C80: return "DEVICE_2C80";
        case PciDevice1093::DEVICE_2C90: return "DEVICE_2C90";
        case PciDevice1093::DEVICE_2CA0: return "DEVICE_2CA0";
        case PciDevice1093::DEVICE_2CB0: return "DEVICE_2CB0";
        case PciDevice1093::DEVICE_2CC0: return "DEVICE_2CC0";
        case PciDevice1093::DEVICE_2D20: return "DEVICE_2D20";
        case PciDevice1093::DEVICE_2DB0: return "DEVICE_2DB0";
        case PciDevice1093::DEVICE_2DC0: return "DEVICE_2DC0";
        case PciDevice1093::DEVICE_2DD0: return "DEVICE_2DD0";
        case PciDevice1093::DEVICE_2EB0: return "DEVICE_2EB0";
        case PciDevice1093::DEVICE_2EC0: return "DEVICE_2EC0";
        case PciDevice1093::DEVICE_2ED0: return "DEVICE_2ED0";
        case PciDevice1093::DEVICE_2EE0: return "DEVICE_2EE0";
        case PciDevice1093::DEVICE_2EF0: return "DEVICE_2EF0";
        case PciDevice1093::DEVICE_2FD1: return "DEVICE_2FD1";
        case PciDevice1093::DEVICE_2FD2: return "DEVICE_2FD2";
        case PciDevice1093::DEVICE_2FD3: return "DEVICE_2FD3";
        case PciDevice1093::DEVICE_2FD5: return "DEVICE_2FD5";
        case PciDevice1093::DEVICE_2FD6: return "DEVICE_2FD6";
        case PciDevice1093::DEVICE_7003: return "DEVICE_7003";
        case PciDevice1093::DEVICE_7004: return "DEVICE_7004";
        case PciDevice1093::DEVICE_700B: return "DEVICE_700B";
        case PciDevice1093::DEVICE_700C: return "DEVICE_700C";
        case PciDevice1093::DEVICE_701A: return "DEVICE_701A";
        case PciDevice1093::DEVICE_701B: return "DEVICE_701B";
        case PciDevice1093::DEVICE_7023: return "DEVICE_7023";
        case PciDevice1093::DEVICE_7027: return "DEVICE_7027";
        case PciDevice1093::DEVICE_702C: return "DEVICE_702C";
        case PciDevice1093::DEVICE_702D: return "DEVICE_702D";
        case PciDevice1093::DEVICE_702E: return "DEVICE_702E";
        case PciDevice1093::DEVICE_702F: return "DEVICE_702F";
        case PciDevice1093::DEVICE_7030: return "DEVICE_7030";
        case PciDevice1093::DEVICE_7031: return "DEVICE_7031";
        case PciDevice1093::DEVICE_7032: return "DEVICE_7032";
        case PciDevice1093::DEVICE_7033: return "DEVICE_7033";
        case PciDevice1093::DEVICE_7034: return "DEVICE_7034";
        case PciDevice1093::DEVICE_7035: return "DEVICE_7035";
        case PciDevice1093::DEVICE_7036: return "DEVICE_7036";
        case PciDevice1093::DEVICE_7037: return "DEVICE_7037";
        case PciDevice1093::DEVICE_7038: return "DEVICE_7038";
        case PciDevice1093::DEVICE_7039: return "DEVICE_7039";
        case PciDevice1093::DEVICE_703F: return "DEVICE_703F";
        case PciDevice1093::DEVICE_7040: return "DEVICE_7040";
        case PciDevice1093::DEVICE_7044: return "DEVICE_7044";
        case PciDevice1093::DEVICE_7047: return "DEVICE_7047";
        case PciDevice1093::DEVICE_704C: return "DEVICE_704C";
        case PciDevice1093::DEVICE_704F: return "DEVICE_704F";
        case PciDevice1093::DEVICE_7050: return "DEVICE_7050";
        case PciDevice1093::DEVICE_7055: return "DEVICE_7055";
        case PciDevice1093::DEVICE_7056: return "DEVICE_7056";
        case PciDevice1093::DEVICE_705A: return "DEVICE_705A";
        case PciDevice1093::DEVICE_705B: return "DEVICE_705B";
        case PciDevice1093::DEVICE_705C: return "DEVICE_705C";
        case PciDevice1093::DEVICE_705D: return "DEVICE_705D";
        case PciDevice1093::DEVICE_705E: return "DEVICE_705E";
        case PciDevice1093::DEVICE_7060: return "DEVICE_7060";
        case PciDevice1093::DEVICE_7064: return "DEVICE_7064";
        case PciDevice1093::DEVICE_7065: return "DEVICE_7065";
        case PciDevice1093::DEVICE_7066: return "DEVICE_7066";
        case PciDevice1093::DEVICE_7067: return "DEVICE_7067";
        case PciDevice1093::DEVICE_7068: return "DEVICE_7068";
        case PciDevice1093::DEVICE_7069: return "DEVICE_7069";
        case PciDevice1093::DEVICE_706A: return "DEVICE_706A";
        case PciDevice1093::DEVICE_706B: return "DEVICE_706B";
        case PciDevice1093::DEVICE_7073: return "DEVICE_7073";
        case PciDevice1093::DEVICE_7074: return "DEVICE_7074";
        case PciDevice1093::DEVICE_7075: return "DEVICE_7075";
        case PciDevice1093::DEVICE_7076: return "DEVICE_7076";
        case PciDevice1093::DEVICE_707C: return "DEVICE_707C";
        case PciDevice1093::DEVICE_707E: return "DEVICE_707E";
        case PciDevice1093::DEVICE_7080: return "DEVICE_7080";
        case PciDevice1093::DEVICE_7081: return "DEVICE_7081";
        case PciDevice1093::DEVICE_7083: return "DEVICE_7083";
        case PciDevice1093::DEVICE_7085: return "DEVICE_7085";
        case PciDevice1093::DEVICE_7086: return "DEVICE_7086";
        case PciDevice1093::DEVICE_7087: return "DEVICE_7087";
        case PciDevice1093::DEVICE_7088: return "DEVICE_7088";
        case PciDevice1093::DEVICE_708C: return "DEVICE_708C";
        case PciDevice1093::DEVICE_708D: return "DEVICE_708D";
        case PciDevice1093::DEVICE_70A9: return "DEVICE_70A9";
        case PciDevice1093::DEVICE_70AA: return "DEVICE_70AA";
        case PciDevice1093::DEVICE_70AB: return "DEVICE_70AB";
        case PciDevice1093::DEVICE_70AC: return "DEVICE_70AC";
        case PciDevice1093::DEVICE_70AD: return "DEVICE_70AD";
        case PciDevice1093::DEVICE_70AE: return "DEVICE_70AE";
        case PciDevice1093::DEVICE_70AF: return "DEVICE_70AF";
        case PciDevice1093::DEVICE_70B0: return "DEVICE_70B0";
        case PciDevice1093::DEVICE_70B1: return "DEVICE_70B1";
        case PciDevice1093::DEVICE_70B2: return "DEVICE_70B2";
        case PciDevice1093::DEVICE_70B3: return "DEVICE_70B3";
        case PciDevice1093::DEVICE_70B4: return "DEVICE_70B4";
        case PciDevice1093::DEVICE_70B5: return "DEVICE_70B5";
        case PciDevice1093::DEVICE_70B6: return "DEVICE_70B6";
        case PciDevice1093::DEVICE_70B7: return "DEVICE_70B7";
        case PciDevice1093::DEVICE_70B8: return "DEVICE_70B8";
        case PciDevice1093::DEVICE_70B9: return "DEVICE_70B9";
        case PciDevice1093::DEVICE_70BA: return "DEVICE_70BA";
        case PciDevice1093::DEVICE_70BB: return "DEVICE_70BB";
        case PciDevice1093::DEVICE_70BC: return "DEVICE_70BC";
        case PciDevice1093::DEVICE_70BD: return "DEVICE_70BD";
        case PciDevice1093::DEVICE_70BE: return "DEVICE_70BE";
        case PciDevice1093::DEVICE_70BF: return "DEVICE_70BF";
        case PciDevice1093::DEVICE_70C0: return "DEVICE_70C0";
        case PciDevice1093::DEVICE_70C3: return "DEVICE_70C3";
        case PciDevice1093::DEVICE_70C4: return "DEVICE_70C4";
        case PciDevice1093::DEVICE_70C5: return "DEVICE_70C5";
        case PciDevice1093::DEVICE_70C6: return "DEVICE_70C6";
        case PciDevice1093::DEVICE_70C7: return "DEVICE_70C7";
        case PciDevice1093::DEVICE_70C8: return "DEVICE_70C8";
        case PciDevice1093::DEVICE_70C9: return "DEVICE_70C9";
        case PciDevice1093::DEVICE_70CA: return "DEVICE_70CA";
        case PciDevice1093::DEVICE_70CC: return "DEVICE_70CC";
        case PciDevice1093::DEVICE_70CD: return "DEVICE_70CD";
        case PciDevice1093::DEVICE_70CE: return "DEVICE_70CE";
        case PciDevice1093::DEVICE_70CF: return "DEVICE_70CF";
        case PciDevice1093::DEVICE_70D0: return "DEVICE_70D0";
        case PciDevice1093::DEVICE_70D1: return "DEVICE_70D1";
        case PciDevice1093::DEVICE_70D2: return "DEVICE_70D2";
        case PciDevice1093::DEVICE_70D3: return "DEVICE_70D3";
        case PciDevice1093::DEVICE_70D4: return "DEVICE_70D4";
        case PciDevice1093::DEVICE_70D6: return "DEVICE_70D6";
        case PciDevice1093::DEVICE_70D7: return "DEVICE_70D7";
        case PciDevice1093::DEVICE_70D8: return "DEVICE_70D8";
        case PciDevice1093::DEVICE_70D9: return "DEVICE_70D9";
        case PciDevice1093::DEVICE_70DA: return "DEVICE_70DA";
        case PciDevice1093::DEVICE_70DB: return "DEVICE_70DB";
        case PciDevice1093::DEVICE_70DC: return "DEVICE_70DC";
        case PciDevice1093::DEVICE_70DD: return "DEVICE_70DD";
        case PciDevice1093::DEVICE_70DE: return "DEVICE_70DE";
        case PciDevice1093::DEVICE_70DF: return "DEVICE_70DF";
        case PciDevice1093::DEVICE_70E0: return "DEVICE_70E0";
        case PciDevice1093::DEVICE_70E1: return "DEVICE_70E1";
        case PciDevice1093::DEVICE_70E2: return "DEVICE_70E2";
        case PciDevice1093::DEVICE_70E3: return "DEVICE_70E3";
        case PciDevice1093::DEVICE_70E4: return "DEVICE_70E4";
        case PciDevice1093::DEVICE_70E5: return "DEVICE_70E5";
        case PciDevice1093::DEVICE_70E6: return "DEVICE_70E6";
        case PciDevice1093::DEVICE_70E7: return "DEVICE_70E7";
        case PciDevice1093::DEVICE_70E8: return "DEVICE_70E8";
        case PciDevice1093::DEVICE_70E9: return "DEVICE_70E9";
        case PciDevice1093::DEVICE_70EA: return "DEVICE_70EA";
        case PciDevice1093::DEVICE_70EB: return "DEVICE_70EB";
        case PciDevice1093::DEVICE_70EC: return "DEVICE_70EC";
        case PciDevice1093::DEVICE_70ED: return "DEVICE_70ED";
        case PciDevice1093::DEVICE_70EE: return "DEVICE_70EE";
        case PciDevice1093::DEVICE_70EF: return "DEVICE_70EF";
        case PciDevice1093::DEVICE_70F0: return "DEVICE_70F0";
        case PciDevice1093::DEVICE_70F1: return "DEVICE_70F1";
        case PciDevice1093::DEVICE_70F2: return "DEVICE_70F2";
        case PciDevice1093::DEVICE_70F3: return "DEVICE_70F3";
        case PciDevice1093::DEVICE_70F6: return "DEVICE_70F6";
        case PciDevice1093::DEVICE_70F7: return "DEVICE_70F7";
        case PciDevice1093::DEVICE_70F8: return "DEVICE_70F8";
        case PciDevice1093::DEVICE_70FF: return "DEVICE_70FF";
        case PciDevice1093::DEVICE_7100: return "DEVICE_7100";
        case PciDevice1093::DEVICE_7104: return "DEVICE_7104";
        case PciDevice1093::DEVICE_7105: return "DEVICE_7105";
        case PciDevice1093::DEVICE_710A: return "DEVICE_710A";
        case PciDevice1093::DEVICE_710D: return "DEVICE_710D";
        case PciDevice1093::DEVICE_710E: return "DEVICE_710E";
        case PciDevice1093::DEVICE_710F: return "DEVICE_710F";
        case PciDevice1093::DEVICE_7110: return "DEVICE_7110";
        case PciDevice1093::DEVICE_7111: return "DEVICE_7111";
        case PciDevice1093::DEVICE_7119: return "DEVICE_7119";
        case PciDevice1093::DEVICE_711A: return "DEVICE_711A";
        case PciDevice1093::DEVICE_711B: return "DEVICE_711B";
        case PciDevice1093::DEVICE_711C: return "DEVICE_711C";
        case PciDevice1093::DEVICE_7120: return "DEVICE_7120";
        case PciDevice1093::DEVICE_7121: return "DEVICE_7121";
        case PciDevice1093::DEVICE_7122: return "DEVICE_7122";
        case PciDevice1093::DEVICE_7123: return "DEVICE_7123";
        case PciDevice1093::DEVICE_7124: return "DEVICE_7124";
        case PciDevice1093::DEVICE_7125: return "DEVICE_7125";
        case PciDevice1093::DEVICE_7126: return "DEVICE_7126";
        case PciDevice1093::DEVICE_7127: return "DEVICE_7127";
        case PciDevice1093::DEVICE_7128: return "DEVICE_7128";
        case PciDevice1093::DEVICE_7137: return "DEVICE_7137";
        case PciDevice1093::DEVICE_713C: return "DEVICE_713C";
        case PciDevice1093::DEVICE_713D: return "DEVICE_713D";
        case PciDevice1093::DEVICE_7142: return "DEVICE_7142";
        case PciDevice1093::DEVICE_7144: return "DEVICE_7144";
        case PciDevice1093::DEVICE_7145: return "DEVICE_7145";
        case PciDevice1093::DEVICE_7146: return "DEVICE_7146";
        case PciDevice1093::DEVICE_7147: return "DEVICE_7147";
        case PciDevice1093::DEVICE_7148: return "DEVICE_7148";
        case PciDevice1093::DEVICE_7149: return "DEVICE_7149";
        case PciDevice1093::DEVICE_714C: return "DEVICE_714C";
        case PciDevice1093::DEVICE_714D: return "DEVICE_714D";
        case PciDevice1093::DEVICE_7150: return "DEVICE_7150";
        case PciDevice1093::DEVICE_7152: return "DEVICE_7152";
        case PciDevice1093::DEVICE_7156: return "DEVICE_7156";
        case PciDevice1093::DEVICE_715D: return "DEVICE_715D";
        case PciDevice1093::DEVICE_7167: return "DEVICE_7167";
        case PciDevice1093::DEVICE_7168: return "DEVICE_7168";
        case PciDevice1093::DEVICE_716B: return "DEVICE_716B";
        case PciDevice1093::DEVICE_716C: return "DEVICE_716C";
        case PciDevice1093::DEVICE_716D: return "DEVICE_716D";
        case PciDevice1093::DEVICE_716F: return "DEVICE_716F";
        case PciDevice1093::DEVICE_7170: return "DEVICE_7170";
        case PciDevice1093::DEVICE_7171: return "DEVICE_7171";
        case PciDevice1093::DEVICE_7174: return "DEVICE_7174";
        case PciDevice1093::DEVICE_7177: return "DEVICE_7177";
        case PciDevice1093::DEVICE_717D: return "DEVICE_717D";
        case PciDevice1093::DEVICE_717F: return "DEVICE_717F";
        case PciDevice1093::DEVICE_7187: return "DEVICE_7187";
        case PciDevice1093::DEVICE_718B: return "DEVICE_718B";
        case PciDevice1093::DEVICE_718C: return "DEVICE_718C";
        case PciDevice1093::DEVICE_7191: return "DEVICE_7191";
        case PciDevice1093::DEVICE_7193: return "DEVICE_7193";
        case PciDevice1093::DEVICE_7194: return "DEVICE_7194";
        case PciDevice1093::DEVICE_7195: return "DEVICE_7195";
        case PciDevice1093::DEVICE_7197: return "DEVICE_7197";
        case PciDevice1093::DEVICE_7198: return "DEVICE_7198";
        case PciDevice1093::DEVICE_719F: return "DEVICE_719F";
        case PciDevice1093::DEVICE_71A0: return "DEVICE_71A0";
        case PciDevice1093::DEVICE_71A3: return "DEVICE_71A3";
        case PciDevice1093::DEVICE_71A4: return "DEVICE_71A4";
        case PciDevice1093::DEVICE_71A5: return "DEVICE_71A5";
        case PciDevice1093::DEVICE_71A7: return "DEVICE_71A7";
        case PciDevice1093::DEVICE_71A9: return "DEVICE_71A9";
        case PciDevice1093::DEVICE_71AA: return "DEVICE_71AA";
        case PciDevice1093::DEVICE_71AB: return "DEVICE_71AB";
        case PciDevice1093::DEVICE_71AC: return "DEVICE_71AC";
        case PciDevice1093::DEVICE_71AD: return "DEVICE_71AD";
        case PciDevice1093::DEVICE_71AE: return "DEVICE_71AE";
        case PciDevice1093::DEVICE_71B7: return "DEVICE_71B7";
        case PciDevice1093::DEVICE_71B8: return "DEVICE_71B8";
        case PciDevice1093::DEVICE_71B9: return "DEVICE_71B9";
        case PciDevice1093::DEVICE_71BB: return "DEVICE_71BB";
        case PciDevice1093::DEVICE_71BC: return "DEVICE_71BC";
        case PciDevice1093::DEVICE_71BF: return "DEVICE_71BF";
        case PciDevice1093::DEVICE_71C5: return "DEVICE_71C5";
        case PciDevice1093::DEVICE_71C6: return "DEVICE_71C6";
        case PciDevice1093::DEVICE_71C7: return "DEVICE_71C7";
        case PciDevice1093::DEVICE_71DC: return "DEVICE_71DC";
        case PciDevice1093::DEVICE_71E0: return "DEVICE_71E0";
        case PciDevice1093::DEVICE_71E1: return "DEVICE_71E1";
        case PciDevice1093::DEVICE_71E2: return "DEVICE_71E2";
        case PciDevice1093::DEVICE_71E3: return "DEVICE_71E3";
        case PciDevice1093::DEVICE_71FC: return "DEVICE_71FC";
        case PciDevice1093::DEVICE_7209: return "DEVICE_7209";
        case PciDevice1093::DEVICE_720A: return "DEVICE_720A";
        case PciDevice1093::DEVICE_720B: return "DEVICE_720B";
        case PciDevice1093::DEVICE_720C: return "DEVICE_720C";
        case PciDevice1093::DEVICE_7260: return "DEVICE_7260";
        case PciDevice1093::DEVICE_7261: return "DEVICE_7261";
        case PciDevice1093::DEVICE_726D: return "DEVICE_726D";
        case PciDevice1093::DEVICE_7273: return "DEVICE_7273";
        case PciDevice1093::DEVICE_7274: return "DEVICE_7274";
        case PciDevice1093::DEVICE_7279: return "DEVICE_7279";
        case PciDevice1093::DEVICE_727A: return "DEVICE_727A";
        case PciDevice1093::DEVICE_727B: return "DEVICE_727B";
        case PciDevice1093::DEVICE_727C: return "DEVICE_727C";
        case PciDevice1093::DEVICE_727E: return "DEVICE_727E";
        case PciDevice1093::DEVICE_7281: return "DEVICE_7281";
        case PciDevice1093::DEVICE_7282: return "DEVICE_7282";
        case PciDevice1093::DEVICE_7283: return "DEVICE_7283";
        case PciDevice1093::DEVICE_7288: return "DEVICE_7288";
        case PciDevice1093::DEVICE_7293: return "DEVICE_7293";
        case PciDevice1093::DEVICE_729D: return "DEVICE_729D";
        case PciDevice1093::DEVICE_72A4: return "DEVICE_72A4";
        case PciDevice1093::DEVICE_72A7: return "DEVICE_72A7";
        case PciDevice1093::DEVICE_72A8: return "DEVICE_72A8";
        case PciDevice1093::DEVICE_72A9: return "DEVICE_72A9";
        case PciDevice1093::DEVICE_72AA: return "DEVICE_72AA";
        case PciDevice1093::DEVICE_72AB: return "DEVICE_72AB";
        case PciDevice1093::DEVICE_72B8: return "DEVICE_72B8";
        case PciDevice1093::DEVICE_72D0: return "DEVICE_72D0";
        case PciDevice1093::DEVICE_72D1: return "DEVICE_72D1";
        case PciDevice1093::DEVICE_72D2: return "DEVICE_72D2";
        case PciDevice1093::DEVICE_72D3: return "DEVICE_72D3";
        case PciDevice1093::DEVICE_72D4: return "DEVICE_72D4";
        case PciDevice1093::DEVICE_72D5: return "DEVICE_72D5";
        case PciDevice1093::DEVICE_72D6: return "DEVICE_72D6";
        case PciDevice1093::DEVICE_72D7: return "DEVICE_72D7";
        case PciDevice1093::DEVICE_72D8: return "DEVICE_72D8";
        case PciDevice1093::DEVICE_72D9: return "DEVICE_72D9";
        case PciDevice1093::DEVICE_72E8: return "DEVICE_72E8";
        case PciDevice1093::DEVICE_72E9: return "DEVICE_72E9";
        case PciDevice1093::DEVICE_72EF: return "DEVICE_72EF";
        case PciDevice1093::DEVICE_72F0: return "DEVICE_72F0";
        case PciDevice1093::DEVICE_72FB: return "DEVICE_72FB";
        case PciDevice1093::DEVICE_730E: return "DEVICE_730E";
        case PciDevice1093::DEVICE_730F: return "DEVICE_730F";
        case PciDevice1093::DEVICE_7310: return "DEVICE_7310";
        case PciDevice1093::DEVICE_731C: return "DEVICE_731C";
        case PciDevice1093::DEVICE_731D: return "DEVICE_731D";
        case PciDevice1093::DEVICE_7322: return "DEVICE_7322";
        case PciDevice1093::DEVICE_7327: return "DEVICE_7327";
        case PciDevice1093::DEVICE_732C: return "DEVICE_732C";
        case PciDevice1093::DEVICE_7331: return "DEVICE_7331";
        case PciDevice1093::DEVICE_7332: return "DEVICE_7332";
        case PciDevice1093::DEVICE_7333: return "DEVICE_7333";
        case PciDevice1093::DEVICE_7335: return "DEVICE_7335";
        case PciDevice1093::DEVICE_7336: return "DEVICE_7336";
        case PciDevice1093::DEVICE_7342: return "DEVICE_7342";
        case PciDevice1093::DEVICE_7349: return "DEVICE_7349";
        case PciDevice1093::DEVICE_734A: return "DEVICE_734A";
        case PciDevice1093::DEVICE_7357: return "DEVICE_7357";
        case PciDevice1093::DEVICE_7359: return "DEVICE_7359";
        case PciDevice1093::DEVICE_7370: return "DEVICE_7370";
        case PciDevice1093::DEVICE_7373: return "DEVICE_7373";
        case PciDevice1093::DEVICE_7374: return "DEVICE_7374";
        case PciDevice1093::DEVICE_7375: return "DEVICE_7375";
        case PciDevice1093::DEVICE_7378: return "DEVICE_7378";
        case PciDevice1093::DEVICE_737D: return "DEVICE_737D";
        case PciDevice1093::DEVICE_7384: return "DEVICE_7384";
        case PciDevice1093::DEVICE_7385: return "DEVICE_7385";
        case PciDevice1093::DEVICE_7386: return "DEVICE_7386";
        case PciDevice1093::DEVICE_7387: return "DEVICE_7387";
        case PciDevice1093::DEVICE_7390: return "DEVICE_7390";
        case PciDevice1093::DEVICE_7391: return "DEVICE_7391";
        case PciDevice1093::DEVICE_7392: return "DEVICE_7392";
        case PciDevice1093::DEVICE_7393: return "DEVICE_7393";
        case PciDevice1093::DEVICE_7394: return "DEVICE_7394";
        case PciDevice1093::DEVICE_7397: return "DEVICE_7397";
        case PciDevice1093::DEVICE_7398: return "DEVICE_7398";
        case PciDevice1093::DEVICE_7399: return "DEVICE_7399";
        case PciDevice1093::DEVICE_739A: return "DEVICE_739A";
        case PciDevice1093::DEVICE_739B: return "DEVICE_739B";
        case PciDevice1093::DEVICE_73A1: return "DEVICE_73A1";
        case PciDevice1093::DEVICE_73A2: return "DEVICE_73A2";
        case PciDevice1093::DEVICE_73A5: return "DEVICE_73A5";
        case PciDevice1093::DEVICE_73A7: return "DEVICE_73A7";
        case PciDevice1093::DEVICE_73A8: return "DEVICE_73A8";
        case PciDevice1093::DEVICE_73A9: return "DEVICE_73A9";
        case PciDevice1093::DEVICE_73AA: return "DEVICE_73AA";
        case PciDevice1093::DEVICE_73AB: return "DEVICE_73AB";
        case PciDevice1093::DEVICE_73AC: return "DEVICE_73AC";
        case PciDevice1093::DEVICE_73AD: return "DEVICE_73AD";
        case PciDevice1093::DEVICE_73AF: return "DEVICE_73AF";
        case PciDevice1093::DEVICE_73B1: return "DEVICE_73B1";
        case PciDevice1093::DEVICE_73B2: return "DEVICE_73B2";
        case PciDevice1093::DEVICE_73B3: return "DEVICE_73B3";
        case PciDevice1093::DEVICE_73B4: return "DEVICE_73B4";
        case PciDevice1093::DEVICE_73B5: return "DEVICE_73B5";
        case PciDevice1093::DEVICE_73B6: return "DEVICE_73B6";
        case PciDevice1093::DEVICE_73B7: return "DEVICE_73B7";
        case PciDevice1093::DEVICE_73B8: return "DEVICE_73B8";
        case PciDevice1093::DEVICE_73B9: return "DEVICE_73B9";
        case PciDevice1093::DEVICE_73BA: return "DEVICE_73BA";
        case PciDevice1093::DEVICE_73BB: return "DEVICE_73BB";
        case PciDevice1093::DEVICE_73BD: return "DEVICE_73BD";
        case PciDevice1093::DEVICE_73BF: return "DEVICE_73BF";
        case PciDevice1093::DEVICE_73C0: return "DEVICE_73C0";
        case PciDevice1093::DEVICE_73C1: return "DEVICE_73C1";
        case PciDevice1093::DEVICE_73C2: return "DEVICE_73C2";
        case PciDevice1093::DEVICE_73C3: return "DEVICE_73C3";
        case PciDevice1093::DEVICE_73C5: return "DEVICE_73C5";
        case PciDevice1093::DEVICE_73C6: return "DEVICE_73C6";
        case PciDevice1093::DEVICE_73C8: return "DEVICE_73C8";
        case PciDevice1093::DEVICE_73C9: return "DEVICE_73C9";
        case PciDevice1093::DEVICE_73CA: return "DEVICE_73CA";
        case PciDevice1093::DEVICE_73CB: return "DEVICE_73CB";
        case PciDevice1093::DEVICE_73CC: return "DEVICE_73CC";
        case PciDevice1093::DEVICE_73D5: return "DEVICE_73D5";
        case PciDevice1093::DEVICE_73D6: return "DEVICE_73D6";
        case PciDevice1093::DEVICE_73D7: return "DEVICE_73D7";
        case PciDevice1093::DEVICE_73E1: return "DEVICE_73E1";
        case PciDevice1093::DEVICE_73EC: return "DEVICE_73EC";
        case PciDevice1093::DEVICE_73ED: return "DEVICE_73ED";
        case PciDevice1093::DEVICE_73F0: return "DEVICE_73F0";
        case PciDevice1093::DEVICE_73F1: return "DEVICE_73F1";
        case PciDevice1093::DEVICE_73F4: return "DEVICE_73F4";
        case PciDevice1093::DEVICE_73F6: return "DEVICE_73F6";
        case PciDevice1093::DEVICE_73F7: return "DEVICE_73F7";
        case PciDevice1093::DEVICE_73F8: return "DEVICE_73F8";
        case PciDevice1093::DEVICE_73F9: return "DEVICE_73F9";
        case PciDevice1093::DEVICE_73FA: return "DEVICE_73FA";
        case PciDevice1093::DEVICE_73FB: return "DEVICE_73FB";
        case PciDevice1093::DEVICE_7404: return "DEVICE_7404";
        case PciDevice1093::DEVICE_7405: return "DEVICE_7405";
        case PciDevice1093::DEVICE_7406: return "DEVICE_7406";
        case PciDevice1093::DEVICE_740E: return "DEVICE_740E";
        case PciDevice1093::DEVICE_740F: return "DEVICE_740F";
        case PciDevice1093::DEVICE_7410: return "DEVICE_7410";
        case PciDevice1093::DEVICE_7411: return "DEVICE_7411";
        case PciDevice1093::DEVICE_7414: return "DEVICE_7414";
        case PciDevice1093::DEVICE_741C: return "DEVICE_741C";
        case PciDevice1093::DEVICE_741D: return "DEVICE_741D";
        case PciDevice1093::DEVICE_743C: return "DEVICE_743C";
        case PciDevice1093::DEVICE_7448: return "DEVICE_7448";
        case PciDevice1093::DEVICE_7454: return "DEVICE_7454";
        case PciDevice1093::DEVICE_7455: return "DEVICE_7455";
        case PciDevice1093::DEVICE_7456: return "DEVICE_7456";
        case PciDevice1093::DEVICE_7457: return "DEVICE_7457";
        case PciDevice1093::DEVICE_745A: return "DEVICE_745A";
        case PciDevice1093::DEVICE_745E: return "DEVICE_745E";
        case PciDevice1093::DEVICE_745F: return "DEVICE_745F";
        case PciDevice1093::DEVICE_7460: return "DEVICE_7460";
        case PciDevice1093::DEVICE_7461: return "DEVICE_7461";
        case PciDevice1093::DEVICE_746D: return "DEVICE_746D";
        case PciDevice1093::DEVICE_746E: return "DEVICE_746E";
        case PciDevice1093::DEVICE_746F: return "DEVICE_746F";
        case PciDevice1093::DEVICE_7472: return "DEVICE_7472";
        case PciDevice1093::DEVICE_7495: return "DEVICE_7495";
        case PciDevice1093::DEVICE_7497: return "DEVICE_7497";
        case PciDevice1093::DEVICE_74AE: return "DEVICE_74AE";
        case PciDevice1093::DEVICE_74B4: return "DEVICE_74B4";
        case PciDevice1093::DEVICE_74B5: return "DEVICE_74B5";
        case PciDevice1093::DEVICE_74C1: return "DEVICE_74C1";
        case PciDevice1093::DEVICE_74C2: return "DEVICE_74C2";
        case PciDevice1093::DEVICE_74C3: return "DEVICE_74C3";
        case PciDevice1093::DEVICE_74C4: return "DEVICE_74C4";
        case PciDevice1093::DEVICE_74D5: return "DEVICE_74D5";
        case PciDevice1093::DEVICE_74D9: return "DEVICE_74D9";
        case PciDevice1093::DEVICE_74DA: return "DEVICE_74DA";
        case PciDevice1093::DEVICE_74DB: return "DEVICE_74DB";
        case PciDevice1093::DEVICE_74DC: return "DEVICE_74DC";
        case PciDevice1093::DEVICE_74E8: return "DEVICE_74E8";
        case PciDevice1093::DEVICE_7515: return "DEVICE_7515";
        case PciDevice1093::DEVICE_7516: return "DEVICE_7516";
        case PciDevice1093::DEVICE_7517: return "DEVICE_7517";
        case PciDevice1093::DEVICE_7518: return "DEVICE_7518";
        case PciDevice1093::DEVICE_751B: return "DEVICE_751B";
        case PciDevice1093::DEVICE_751C: return "DEVICE_751C";
        case PciDevice1093::DEVICE_7528: return "DEVICE_7528";
        case PciDevice1093::DEVICE_7529: return "DEVICE_7529";
        case PciDevice1093::DEVICE_752A: return "DEVICE_752A";
        case PciDevice1093::DEVICE_7539: return "DEVICE_7539";
        case PciDevice1093::DEVICE_753A: return "DEVICE_753A";
        case PciDevice1093::DEVICE_7598: return "DEVICE_7598";
        case PciDevice1093::DEVICE_75A4: return "DEVICE_75A4";
        case PciDevice1093::DEVICE_75B1: return "DEVICE_75B1";
        case PciDevice1093::DEVICE_75BA: return "DEVICE_75BA";
        case PciDevice1093::DEVICE_75BB: return "DEVICE_75BB";
        case PciDevice1093::DEVICE_75E5: return "DEVICE_75E5";
        case PciDevice1093::DEVICE_75E6: return "DEVICE_75E6";
        case PciDevice1093::DEVICE_75EF: return "DEVICE_75EF";
        case PciDevice1093::DEVICE_761C: return "DEVICE_761C";
        case PciDevice1093::DEVICE_761F: return "DEVICE_761F";
        case PciDevice1093::DEVICE_7620: return "DEVICE_7620";
        case PciDevice1093::DEVICE_7621: return "DEVICE_7621";
        case PciDevice1093::DEVICE_7622: return "DEVICE_7622";
        case PciDevice1093::DEVICE_7626: return "DEVICE_7626";
        case PciDevice1093::DEVICE_7627: return "DEVICE_7627";
        case PciDevice1093::DEVICE_7638: return "DEVICE_7638";
        case PciDevice1093::DEVICE_7639: return "DEVICE_7639";
        case PciDevice1093::DEVICE_763A: return "DEVICE_763A";
        case PciDevice1093::DEVICE_763B: return "DEVICE_763B";
        case PciDevice1093::DEVICE_763C: return "DEVICE_763C";
        case PciDevice1093::DEVICE_764B: return "DEVICE_764B";
        case PciDevice1093::DEVICE_764C: return "DEVICE_764C";
        case PciDevice1093::DEVICE_764D: return "DEVICE_764D";
        case PciDevice1093::DEVICE_764E: return "DEVICE_764E";
        case PciDevice1093::DEVICE_764F: return "DEVICE_764F";
        case PciDevice1093::DEVICE_7654: return "DEVICE_7654";
        case PciDevice1093::DEVICE_7655: return "DEVICE_7655";
        case PciDevice1093::DEVICE_7656: return "DEVICE_7656";
        case PciDevice1093::DEVICE_7657: return "DEVICE_7657";
        case PciDevice1093::DEVICE_765D: return "DEVICE_765D";
        case PciDevice1093::DEVICE_765E: return "DEVICE_765E";
        case PciDevice1093::DEVICE_765F: return "DEVICE_765F";
        case PciDevice1093::DEVICE_7660: return "DEVICE_7660";
        case PciDevice1093::DEVICE_766D: return "DEVICE_766D";
        case PciDevice1093::DEVICE_766E: return "DEVICE_766E";
        case PciDevice1093::DEVICE_766F: return "DEVICE_766F";
        case PciDevice1093::DEVICE_76A3: return "DEVICE_76A3";
        case PciDevice1093::DEVICE_76A4: return "DEVICE_76A4";
        case PciDevice1093::DEVICE_76A5: return "DEVICE_76A5";
        case PciDevice1093::DEVICE_783E: return "DEVICE_783E";
        case PciDevice1093::DEVICE_9020: return "DEVICE_9020";
        case PciDevice1093::DEVICE_9030: return "DEVICE_9030";
        case PciDevice1093::DEVICE_9040: return "DEVICE_9040";
        case PciDevice1093::DEVICE_9050: return "DEVICE_9050";
        case PciDevice1093::DEVICE_9060: return "DEVICE_9060";
        case PciDevice1093::DEVICE_9070: return "DEVICE_9070";
        case PciDevice1093::DEVICE_9080: return "DEVICE_9080";
        case PciDevice1093::DEVICE_9090: return "DEVICE_9090";
        case PciDevice1093::DEVICE_90A0: return "DEVICE_90A0";
        case PciDevice1093::DEVICE_A001: return "DEVICE_A001";
        case PciDevice1093::DEVICE_B001: return "DEVICE_B001";
        case PciDevice1093::DEVICE_B011: return "DEVICE_B011";
        case PciDevice1093::DEVICE_B021: return "DEVICE_B021";
        case PciDevice1093::DEVICE_B022: return "DEVICE_B022";
        case PciDevice1093::DEVICE_B031: return "DEVICE_B031";
        case PciDevice1093::DEVICE_B041: return "DEVICE_B041";
        case PciDevice1093::DEVICE_B051: return "DEVICE_B051";
        case PciDevice1093::DEVICE_B061: return "DEVICE_B061";
        case PciDevice1093::DEVICE_B071: return "DEVICE_B071";
        case PciDevice1093::DEVICE_B081: return "DEVICE_B081";
        case PciDevice1093::DEVICE_B091: return "DEVICE_B091";
        case PciDevice1093::DEVICE_B0B1: return "DEVICE_B0B1";
        case PciDevice1093::DEVICE_B0C1: return "DEVICE_B0C1";
        case PciDevice1093::DEVICE_B0E1: return "DEVICE_B0E1";
        case PciDevice1093::DEVICE_C4C4: return "DEVICE_C4C4";
        case PciDevice1093::DEVICE_C801: return "DEVICE_C801";
        case PciDevice1093::DEVICE_C811: return "DEVICE_C811";
        case PciDevice1093::DEVICE_C821: return "DEVICE_C821";
        case PciDevice1093::DEVICE_C831: return "DEVICE_C831";
        case PciDevice1093::DEVICE_C840: return "DEVICE_C840";
        case PciDevice1093::DEVICE_D130: return "DEVICE_D130";
        case PciDevice1093::DEVICE_D140: return "DEVICE_D140";
        case PciDevice1093::DEVICE_D150: return "DEVICE_D150";
        case PciDevice1093::DEVICE_D160: return "DEVICE_D160";
        case PciDevice1093::DEVICE_D170: return "DEVICE_D170";
        case PciDevice1093::DEVICE_D190: return "DEVICE_D190";
        case PciDevice1093::DEVICE_D1A0: return "DEVICE_D1A0";
        case PciDevice1093::DEVICE_D1B0: return "DEVICE_D1B0";
        case PciDevice1093::DEVICE_D1C0: return "DEVICE_D1C0";
        case PciDevice1093::DEVICE_D1D0: return "DEVICE_D1D0";
        case PciDevice1093::DEVICE_D1E0: return "DEVICE_D1E0";
        case PciDevice1093::DEVICE_D1F0: return "DEVICE_D1F0";
        case PciDevice1093::DEVICE_D1F1: return "DEVICE_D1F1";
        case PciDevice1093::DEVICE_D230: return "DEVICE_D230";
        case PciDevice1093::DEVICE_D240: return "DEVICE_D240";
        case PciDevice1093::DEVICE_D250: return "DEVICE_D250";
        case PciDevice1093::DEVICE_D260: return "DEVICE_D260";
        case PciDevice1093::DEVICE_D270: return "DEVICE_D270";
        case PciDevice1093::DEVICE_D280: return "DEVICE_D280";
        case PciDevice1093::DEVICE_D290: return "DEVICE_D290";
        case PciDevice1093::DEVICE_D2A0: return "DEVICE_D2A0";
        case PciDevice1093::DEVICE_D2B0: return "DEVICE_D2B0";
        case PciDevice1093::DEVICE_E111: return "DEVICE_E111";
        case PciDevice1093::DEVICE_E131: return "DEVICE_E131";
        case PciDevice1093::DEVICE_E141: return "DEVICE_E141";
        case PciDevice1093::DEVICE_E151: return "DEVICE_E151";
        case PciDevice1093::DEVICE_E211: return "DEVICE_E211";
        case PciDevice1093::DEVICE_E231: return "DEVICE_E231";
        case PciDevice1093::DEVICE_E241: return "DEVICE_E241";
        case PciDevice1093::DEVICE_E251: return "DEVICE_E251";
        case PciDevice1093::DEVICE_E261: return "DEVICE_E261";
        case PciDevice1093::DEVICE_E271: return "DEVICE_E271";
        case PciDevice1093::DEVICE_F110: return "DEVICE_F110";
        case PciDevice1093::DEVICE_F120: return "DEVICE_F120";
        case PciDevice1093::DEVICE_FE00: return "DEVICE_FE00";
        case PciDevice1093::DEVICE_FE41: return "DEVICE_FE41";
        case PciDevice1093::DEVICE_FE51: return "DEVICE_FE51";
        case PciDevice1093::DEVICE_FE61: return "DEVICE_FE61";
        case PciDevice1093::DEVICE_FE70: return "DEVICE_FE70";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1093 device1093) // TEST: NO
{
    // COMMON_LT((" | device1093 = %u", device1093)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1093, enumToString(device1093));

    return res;
}



inline const char8* enumToHumanString(PciDevice1093 device1093) // TEST: NO
{
    // COMMON_LT((" | device1093 = %u", device1093)); // Commented to avoid bad looking logs



    switch (device1093)
    {
        case PciDevice1093::DEVICE_0160: return "PCI-DIO-96";
        case PciDevice1093::DEVICE_0162: return "PCI-MIO-16XE-50";
        case PciDevice1093::DEVICE_0FE1: return "PXI-8320";
        case PciDevice1093::DEVICE_1150: return "PCI-6533 (PCI-DIO-32HS)";
        case PciDevice1093::DEVICE_1170: return "PCI-MIO-16XE-10";
        case PciDevice1093::DEVICE_1180: return "PCI-MIO-16E-1";
        case PciDevice1093::DEVICE_1190: return "PCI-MIO-16E-4";
        case PciDevice1093::DEVICE_11B0: return "PXI-6070E";
        case PciDevice1093::DEVICE_11C0: return "PXI-6040E";
        case PciDevice1093::DEVICE_11D0: return "PXI-6030E";
        case PciDevice1093::DEVICE_1270: return "PCI-6032E";
        case PciDevice1093::DEVICE_1290: return "PCI-6704";
        case PciDevice1093::DEVICE_12B0: return "PCI-6534";
        case PciDevice1093::DEVICE_1310: return "PCI-6602";
        case PciDevice1093::DEVICE_1320: return "PXI-6533";
        case PciDevice1093::DEVICE_1330: return "PCI-6031E";
        case PciDevice1093::DEVICE_1340: return "PCI-6033E";
        case PciDevice1093::DEVICE_1350: return "PCI-6071E";
        case PciDevice1093::DEVICE_1360: return "PXI-6602";
        case PciDevice1093::DEVICE_13C0: return "PXI-6508";
        case PciDevice1093::DEVICE_1490: return "PXI-6534";
        case PciDevice1093::DEVICE_14E0: return "PCI-6110";
        case PciDevice1093::DEVICE_14F0: return "PCI-6111";
        case PciDevice1093::DEVICE_1580: return "PXI-6031E";
        case PciDevice1093::DEVICE_15B0: return "PXI-6071E";
        case PciDevice1093::DEVICE_1710: return "PXI-6509";
        case PciDevice1093::DEVICE_17C0: return "PXI-5690";
        case PciDevice1093::DEVICE_17D0: return "PCI-6503";
        case PciDevice1093::DEVICE_1870: return "PCI-6713";
        case PciDevice1093::DEVICE_1880: return "PCI-6711";
        case PciDevice1093::DEVICE_18B0: return "PCI-6052E";
        case PciDevice1093::DEVICE_18C0: return "PXI-6052E";
        case PciDevice1093::DEVICE_1920: return "PXI-6704";
        case PciDevice1093::DEVICE_1930: return "PCI-6040E";
        case PciDevice1093::DEVICE_19C0: return "PCI-4472";
        case PciDevice1093::DEVICE_1AA0: return "PXI-4110";
        case PciDevice1093::DEVICE_1AD0: return "PCI-6133";
        case PciDevice1093::DEVICE_1AE0: return "PXI-6133";
        case PciDevice1093::DEVICE_1E30: return "PCI-6624";
        case PciDevice1093::DEVICE_1E40: return "PXI-6624";
        case PciDevice1093::DEVICE_1E50: return "PXI-5404";
        case PciDevice1093::DEVICE_2410: return "PCI-6733";
        case PciDevice1093::DEVICE_2420: return "PXI-6733";
        case PciDevice1093::DEVICE_2430: return "PCI-6731";
        case PciDevice1093::DEVICE_2470: return "PCI-4474";
        case PciDevice1093::DEVICE_24A0: return "PCI-4065";
        case PciDevice1093::DEVICE_24B0: return "PXI-4200";
        case PciDevice1093::DEVICE_24F0: return "PXI-4472";
        case PciDevice1093::DEVICE_2510: return "PCI-4472";
        case PciDevice1093::DEVICE_2520: return "PCI-4474";
        case PciDevice1093::DEVICE_27A0: return "PCI-6123";
        case PciDevice1093::DEVICE_27B0: return "PXI-6123";
        case PciDevice1093::DEVICE_2880: return "DAQCard-6601";
        case PciDevice1093::DEVICE_2890: return "PCI-6036E";
        case PciDevice1093::DEVICE_28A0: return "PXI-4461";
        case PciDevice1093::DEVICE_28B0: return "PCI-6013";
        case PciDevice1093::DEVICE_28C0: return "PCI-6014";
        case PciDevice1093::DEVICE_28D0: return "PCI-5122";
        case PciDevice1093::DEVICE_28E0: return "PXI-5122";
        case PciDevice1093::DEVICE_29F0: return "PXI-7334";
        case PciDevice1093::DEVICE_2A00: return "PXI-7344";
        case PciDevice1093::DEVICE_2A60: return "PCI-6023E";
        case PciDevice1093::DEVICE_2A70: return "PCI-6024E";
        case PciDevice1093::DEVICE_2A80: return "PCI-6025E";
        case PciDevice1093::DEVICE_2AB0: return "PXI-6025E";
        case PciDevice1093::DEVICE_2B10: return "PXI-6527";
        case PciDevice1093::DEVICE_2B20: return "PCI-6527";
        case PciDevice1093::DEVICE_2B80: return "PXI-6713";
        case PciDevice1093::DEVICE_2B90: return "PXI-6711";
        case PciDevice1093::DEVICE_2C60: return "PCI-6601";
        case PciDevice1093::DEVICE_2C70: return "PXI-6601";
        case PciDevice1093::DEVICE_2C80: return "PCI-6035E";
        case PciDevice1093::DEVICE_2C90: return "PCI-6703";
        case PciDevice1093::DEVICE_2CA0: return "PCI-6034E";
        case PciDevice1093::DEVICE_2CB0: return "PCI-7344";
        case PciDevice1093::DEVICE_2CC0: return "PXI-6608";
        case PciDevice1093::DEVICE_2D20: return "PXI-5600";
        case PciDevice1093::DEVICE_2DB0: return "PCI-6608";
        case PciDevice1093::DEVICE_2DC0: return "PCI-4070";
        case PciDevice1093::DEVICE_2DD0: return "PXI-4070";
        case PciDevice1093::DEVICE_2EB0: return "PXI-4472";
        case PciDevice1093::DEVICE_2EC0: return "PXI-6115";
        case PciDevice1093::DEVICE_2ED0: return "PCI-6115";
        case PciDevice1093::DEVICE_2EE0: return "PXI-6120";
        case PciDevice1093::DEVICE_2EF0: return "PCI-6120";
        case PciDevice1093::DEVICE_2FD1: return "PCI-7334";
        case PciDevice1093::DEVICE_2FD2: return "PCI-7350";
        case PciDevice1093::DEVICE_2FD3: return "PCI-7342";
        case PciDevice1093::DEVICE_2FD5: return "PXI-7350";
        case PciDevice1093::DEVICE_2FD6: return "PXI-7342";
        case PciDevice1093::DEVICE_7003: return "PCI-6551";
        case PciDevice1093::DEVICE_7004: return "PXI-6551";
        case PciDevice1093::DEVICE_700B: return "PXI-5421";
        case PciDevice1093::DEVICE_700C: return "PCI-5421";
        case PciDevice1093::DEVICE_701A: return "VXIpc-87xB";
        case PciDevice1093::DEVICE_701B: return "VXIpc-770";
        case PciDevice1093::DEVICE_7023: return "PXI-2593";
        case PciDevice1093::DEVICE_7027: return "PCI-MXI-2 Universal";
        case PciDevice1093::DEVICE_702C: return "PXI-7831R";
        case PciDevice1093::DEVICE_702D: return "PCI-7831R";
        case PciDevice1093::DEVICE_702E: return "PXI-7811R";
        case PciDevice1093::DEVICE_702F: return "PCI-7811R";
        case PciDevice1093::DEVICE_7030: return "PCI-CAN (Series 2)";
        case PciDevice1093::DEVICE_7031: return "PCI-CAN/2 (Series 2)";
        case PciDevice1093::DEVICE_7032: return "PCI-CAN/LS (Series 2)";
        case PciDevice1093::DEVICE_7033: return "PCI-CAN/LS2 (Series 2)";
        case PciDevice1093::DEVICE_7034: return "PCI-CAN/DS (Series 2)";
        case PciDevice1093::DEVICE_7035: return "PXI-8460 (Series 2, 1 port)";
        case PciDevice1093::DEVICE_7036: return "PXI-8460 (Series 2, 2 ports)";
        case PciDevice1093::DEVICE_7037: return "PXI-8461 (Series 2, 1 port)";
        case PciDevice1093::DEVICE_7038: return "PXI-8461 (Series 2, 2 ports)";
        case PciDevice1093::DEVICE_7039: return "PXI-8462 (Series 2)";
        case PciDevice1093::DEVICE_703F: return "PXI-2566";
        case PciDevice1093::DEVICE_7040: return "PXI-2567";
        case PciDevice1093::DEVICE_7044: return "MXI-4 Connection Monitor";
        case PciDevice1093::DEVICE_7047: return "PXI-6653";
        case PciDevice1093::DEVICE_704C: return "PXI-2530";
        case PciDevice1093::DEVICE_704F: return "PXI-4220";
        case PciDevice1093::DEVICE_7050: return "PXI-4204";
        case PciDevice1093::DEVICE_7055: return "PXI-7830R";
        case PciDevice1093::DEVICE_7056: return "PCI-7830R";
        case PciDevice1093::DEVICE_705A: return "PCI-CAN/XS (Series 2)";
        case PciDevice1093::DEVICE_705B: return "PCI-CAN/XS2 (Series 2)";
        case PciDevice1093::DEVICE_705C: return "PXI-8464 (Series 2, 1 port)";
        case PciDevice1093::DEVICE_705D: return "PXI-8464 (Series 2, 2 ports)";
        case PciDevice1093::DEVICE_705E: return "cRIO-9102";
        case PciDevice1093::DEVICE_7060: return "PXI-5610";
        case PciDevice1093::DEVICE_7064: return "PXI-1045 Trigger Routing Module";
        case PciDevice1093::DEVICE_7065: return "PXI-6652";
        case PciDevice1093::DEVICE_7066: return "PXI-6651";
        case PciDevice1093::DEVICE_7067: return "PXI-2529";
        case PciDevice1093::DEVICE_7068: return "PCI-CAN/SW (Series 2)";
        case PciDevice1093::DEVICE_7069: return "PCI-CAN/SW2 (Series 2)";
        case PciDevice1093::DEVICE_706A: return "PXI-8463 (Series 2, 1 port)";
        case PciDevice1093::DEVICE_706B: return "PXI-8463 (Series 2, 2 ports)";
        case PciDevice1093::DEVICE_7073: return "PCI-6723";
        case PciDevice1093::DEVICE_7074: return "PXI-7833R";
        case PciDevice1093::DEVICE_7075: return "PXI-6552";
        case PciDevice1093::DEVICE_7076: return "PCI-6552";
        case PciDevice1093::DEVICE_707C: return "PXI-1428";
        case PciDevice1093::DEVICE_707E: return "PXI-4462";
        case PciDevice1093::DEVICE_7080: return "PXI-8430/2 (RS-232) Interface";
        case PciDevice1093::DEVICE_7081: return "PXI-8431/2 (RS-485) Interface";
        case PciDevice1093::DEVICE_7083: return "PCI-7833R";
        case PciDevice1093::DEVICE_7085: return "PCI-6509";
        case PciDevice1093::DEVICE_7086: return "PXI-6528";
        case PciDevice1093::DEVICE_7087: return "PCI-6515";
        case PciDevice1093::DEVICE_7088: return "PCI-6514";
        case PciDevice1093::DEVICE_708C: return "PXI-2568";
        case PciDevice1093::DEVICE_708D: return "PXI-2569";
        case PciDevice1093::DEVICE_70A9: return "PCI-6528";
        case PciDevice1093::DEVICE_70AA: return "PCI-6229";
        case PciDevice1093::DEVICE_70AB: return "PCI-6259";
        case PciDevice1093::DEVICE_70AC: return "PCI-6289";
        case PciDevice1093::DEVICE_70AD: return "PXI-6251";
        case PciDevice1093::DEVICE_70AE: return "PXI-6220";
        case PciDevice1093::DEVICE_70AF: return "PCI-6221";
        case PciDevice1093::DEVICE_70B0: return "PCI-6220";
        case PciDevice1093::DEVICE_70B1: return "PXI-6229";
        case PciDevice1093::DEVICE_70B2: return "PXI-6259";
        case PciDevice1093::DEVICE_70B3: return "PXI-6289";
        case PciDevice1093::DEVICE_70B4: return "PCI-6250";
        case PciDevice1093::DEVICE_70B5: return "PXI-6221";
        case PciDevice1093::DEVICE_70B6: return "PCI-6280";
        case PciDevice1093::DEVICE_70B7: return "PCI-6254";
        case PciDevice1093::DEVICE_70B8: return "PCI-6251";
        case PciDevice1093::DEVICE_70B9: return "PXI-6250";
        case PciDevice1093::DEVICE_70BA: return "PXI-6254";
        case PciDevice1093::DEVICE_70BB: return "PXI-6280";
        case PciDevice1093::DEVICE_70BC: return "PCI-6284";
        case PciDevice1093::DEVICE_70BD: return "PCI-6281";
        case PciDevice1093::DEVICE_70BE: return "PXI-6284";
        case PciDevice1093::DEVICE_70BF: return "PXI-6281";
        case PciDevice1093::DEVICE_70C0: return "PCI-6143";
        case PciDevice1093::DEVICE_70C3: return "PCI-6511";
        case PciDevice1093::DEVICE_70C4: return "PXI-7330";
        case PciDevice1093::DEVICE_70C5: return "PXI-7340";
        case PciDevice1093::DEVICE_70C6: return "PCI-7330";
        case PciDevice1093::DEVICE_70C7: return "PCI-7340";
        case PciDevice1093::DEVICE_70C8: return "PCI-6513";
        case PciDevice1093::DEVICE_70C9: return "PXI-6515";
        case PciDevice1093::DEVICE_70CA: return "PCI-1405";
        case PciDevice1093::DEVICE_70CC: return "PCI-6512";
        case PciDevice1093::DEVICE_70CD: return "PXI-6514";
        case PciDevice1093::DEVICE_70CE: return "PXI-1405";
        case PciDevice1093::DEVICE_70CF: return "PCIe-GPIB";
        case PciDevice1093::DEVICE_70D0: return "PXI-2570";
        case PciDevice1093::DEVICE_70D1: return "PXI-6513";
        case PciDevice1093::DEVICE_70D2: return "PXI-6512";
        case PciDevice1093::DEVICE_70D3: return "PXI-6511";
        case PciDevice1093::DEVICE_70D4: return "PCI-6722";
        case PciDevice1093::DEVICE_70D6: return "PXI-4072";
        case PciDevice1093::DEVICE_70D7: return "PXI-6541";
        case PciDevice1093::DEVICE_70D8: return "PXI-6542";
        case PciDevice1093::DEVICE_70D9: return "PCI-6541";
        case PciDevice1093::DEVICE_70DA: return "PCI-6542";
        case PciDevice1093::DEVICE_70DB: return "PCI-8430/2 (RS-232) Interface";
        case PciDevice1093::DEVICE_70DC: return "PCI-8431/2 (RS-485) Interface";
        case PciDevice1093::DEVICE_70DD: return "PXI-8430/4 (RS-232) Interface";
        case PciDevice1093::DEVICE_70DE: return "PXI-8431/4 (RS-485) Interface";
        case PciDevice1093::DEVICE_70DF: return "PCI-8430/4 (RS-232) Interface";
        case PciDevice1093::DEVICE_70E0: return "PCI-8431/4 (RS-485) Interface";
        case PciDevice1093::DEVICE_70E1: return "PXI-2532";
        case PciDevice1093::DEVICE_70E2: return "PXI-8430/8 (RS-232) Interface";
        case PciDevice1093::DEVICE_70E3: return "PXI-8431/8 (RS-485) Interface";
        case PciDevice1093::DEVICE_70E4: return "PCI-8430/8 (RS-232) Interface";
        case PciDevice1093::DEVICE_70E5: return "PCI-8431/8 (RS-485) Interface";
        case PciDevice1093::DEVICE_70E6: return "PXI-8430/16 (RS-232) Interface";
        case PciDevice1093::DEVICE_70E7: return "PCI-8430/16 (RS-232) Interface";
        case PciDevice1093::DEVICE_70E8: return "PXI-8432/2 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_70E9: return "PXI-8433/2 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_70EA: return "PCI-8432/2 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_70EB: return "PCI-8433/2 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_70EC: return "PXI-8432/4 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_70ED: return "PXI-8433/4 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_70EE: return "PCI-8432/4 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_70EF: return "PCI-8433/4 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_70F0: return "PXI-5922";
        case PciDevice1093::DEVICE_70F1: return "PCI-5922";
        case PciDevice1093::DEVICE_70F2: return "PCI-6224";
        case PciDevice1093::DEVICE_70F3: return "PXI-6224";
        case PciDevice1093::DEVICE_70F6: return "cRIO-9101";
        case PciDevice1093::DEVICE_70F7: return "cRIO-9103";
        case PciDevice1093::DEVICE_70F8: return "cRIO-9104";
        case PciDevice1093::DEVICE_70FF: return "PXI-6723";
        case PciDevice1093::DEVICE_7100: return "PXI-6722";
        case PciDevice1093::DEVICE_7104: return "PCIx-1429";
        case PciDevice1093::DEVICE_7105: return "PCIe-1429";
        case PciDevice1093::DEVICE_710A: return "PXI-4071";
        case PciDevice1093::DEVICE_710D: return "PXI-6143";
        case PciDevice1093::DEVICE_710E: return "PCIe-GPIB";
        case PciDevice1093::DEVICE_710F: return "PXI-5422";
        case PciDevice1093::DEVICE_7110: return "PCI-5422";
        case PciDevice1093::DEVICE_7111: return "PXI-5441";
        case PciDevice1093::DEVICE_7119: return "PXI-6561";
        case PciDevice1093::DEVICE_711A: return "PXI-6562";
        case PciDevice1093::DEVICE_711B: return "PCI-6561";
        case PciDevice1093::DEVICE_711C: return "PCI-6562";
        case PciDevice1093::DEVICE_7120: return "PCI-7390";
        case PciDevice1093::DEVICE_7121: return "PXI-5122EX";
        case PciDevice1093::DEVICE_7122: return "PCI-5122EX";
        case PciDevice1093::DEVICE_7123: return "PXIe-5653";
        case PciDevice1093::DEVICE_7124: return "PCI-6510";
        case PciDevice1093::DEVICE_7125: return "PCI-6516";
        case PciDevice1093::DEVICE_7126: return "PCI-6517";
        case PciDevice1093::DEVICE_7127: return "PCI-6518";
        case PciDevice1093::DEVICE_7128: return "PCI-6519";
        case PciDevice1093::DEVICE_7137: return "PXI-2575";
        case PciDevice1093::DEVICE_713C: return "PXI-2585";
        case PciDevice1093::DEVICE_713D: return "PXI-2586";
        case PciDevice1093::DEVICE_7142: return "PXI-4224";
        case PciDevice1093::DEVICE_7144: return "PXI-5124";
        case PciDevice1093::DEVICE_7145: return "PCI-5124";
        case PciDevice1093::DEVICE_7146: return "PCI-6132";
        case PciDevice1093::DEVICE_7147: return "PXI-6132";
        case PciDevice1093::DEVICE_7148: return "PCI-6122";
        case PciDevice1093::DEVICE_7149: return "PXI-6122";
        case PciDevice1093::DEVICE_714C: return "PXI-5114";
        case PciDevice1093::DEVICE_714D: return "PCI-5114";
        case PciDevice1093::DEVICE_7150: return "PXI-2564";
        case PciDevice1093::DEVICE_7152: return "PCI-5640R";
        case PciDevice1093::DEVICE_7156: return "PXI-1044 Trigger Routing Module";
        case PciDevice1093::DEVICE_715D: return "PCI-1426";
        case PciDevice1093::DEVICE_7167: return "PXI-5412";
        case PciDevice1093::DEVICE_7168: return "PCI-5412";
        case PciDevice1093::DEVICE_716B: return "PCI-6230";
        case PciDevice1093::DEVICE_716C: return "PCI-6225";
        case PciDevice1093::DEVICE_716D: return "PXI-6225";
        case PciDevice1093::DEVICE_716F: return "PCI-4461";
        case PciDevice1093::DEVICE_7170: return "PCI-4462";
        case PciDevice1093::DEVICE_7171: return "PCI-6010";
        case PciDevice1093::DEVICE_7174: return "PXI-8360";
        case PciDevice1093::DEVICE_7177: return "PXI-6230";
        case PciDevice1093::DEVICE_717D: return "PCIe-6251";
        case PciDevice1093::DEVICE_717F: return "PCIe-6259";
        case PciDevice1093::DEVICE_7187: return "PCI-1410";
        case PciDevice1093::DEVICE_718B: return "PCI-6521";
        case PciDevice1093::DEVICE_718C: return "PXI-6521";
        case PciDevice1093::DEVICE_7191: return "PCI-6154";
        case PciDevice1093::DEVICE_7193: return "PXI-7813R";
        case PciDevice1093::DEVICE_7194: return "PCI-7813R";
        case PciDevice1093::DEVICE_7195: return "PCI-8254R";
        case PciDevice1093::DEVICE_7197: return "PXI-5402";
        case PciDevice1093::DEVICE_7198: return "PCI-5402";
        case PciDevice1093::DEVICE_719F: return "PCIe-6535";
        case PciDevice1093::DEVICE_71A0: return "PCIe-6536";
        case PciDevice1093::DEVICE_71A3: return "PXI-5650";
        case PciDevice1093::DEVICE_71A4: return "PXI-5652";
        case PciDevice1093::DEVICE_71A5: return "PXI-2594";
        case PciDevice1093::DEVICE_71A7: return "PXI-2595";
        case PciDevice1093::DEVICE_71A9: return "PXI-2596";
        case PciDevice1093::DEVICE_71AA: return "PXI-2597";
        case PciDevice1093::DEVICE_71AB: return "PXI-2598";
        case PciDevice1093::DEVICE_71AC: return "PXI-2599";
        case PciDevice1093::DEVICE_71AD: return "PCI-GPIB+";
        case PciDevice1093::DEVICE_71AE: return "PCIe-1430";
        case PciDevice1093::DEVICE_71B7: return "PXI-1056 Trigger Routing Module";
        case PciDevice1093::DEVICE_71B8: return "PXI-1045 Trigger Routing Module";
        case PciDevice1093::DEVICE_71B9: return "PXI-1044 Trigger Routing Module";
        case PciDevice1093::DEVICE_71BB: return "PXI-2584";
        case PciDevice1093::DEVICE_71BC: return "PCI-6221 (37-pin)";
        case PciDevice1093::DEVICE_71BF: return "PCIe-1427";
        case PciDevice1093::DEVICE_71C5: return "PCI-6520";
        case PciDevice1093::DEVICE_71C6: return "PXI-2576";
        case PciDevice1093::DEVICE_71C7: return "cRIO-9072";
        case PciDevice1093::DEVICE_71DC: return "PCI-1588";
        case PciDevice1093::DEVICE_71E0: return "PCI-6255";
        case PciDevice1093::DEVICE_71E1: return "PXI-6255";
        case PciDevice1093::DEVICE_71E2: return "PXI-5406";
        case PciDevice1093::DEVICE_71E3: return "PCI-5406";
        case PciDevice1093::DEVICE_71FC: return "PXI-4022";
        case PciDevice1093::DEVICE_7209: return "PCI-6233";
        case PciDevice1093::DEVICE_720A: return "PXI-6233";
        case PciDevice1093::DEVICE_720B: return "PCI-6238";
        case PciDevice1093::DEVICE_720C: return "PXI-6238";
        case PciDevice1093::DEVICE_7260: return "PXI-5142";
        case PciDevice1093::DEVICE_7261: return "PCI-5142";
        case PciDevice1093::DEVICE_726D: return "PXI-5651";
        case PciDevice1093::DEVICE_7273: return "PXI-4461";
        case PciDevice1093::DEVICE_7274: return "PXI-4462";
        case PciDevice1093::DEVICE_7279: return "PCI-6232";
        case PciDevice1093::DEVICE_727A: return "PXI-6232";
        case PciDevice1093::DEVICE_727B: return "PCI-6239";
        case PciDevice1093::DEVICE_727C: return "PXI-6239";
        case PciDevice1093::DEVICE_727E: return "SMBus Controller";
        case PciDevice1093::DEVICE_7281: return "PCI-6236";
        case PciDevice1093::DEVICE_7282: return "PXI-6236";
        case PciDevice1093::DEVICE_7283: return "PXI-2554";
        case PciDevice1093::DEVICE_7288: return "PXIe-5611";
        case PciDevice1093::DEVICE_7293: return "PCIe-8255R";
        case PciDevice1093::DEVICE_729D: return "cRIO-9074";
        case PciDevice1093::DEVICE_72A4: return "PCIe-4065";
        case PciDevice1093::DEVICE_72A7: return "PCIe-6537";
        case PciDevice1093::DEVICE_72A8: return "PXI-5152";
        case PciDevice1093::DEVICE_72A9: return "PCI-5152";
        case PciDevice1093::DEVICE_72AA: return "PXI-5105";
        case PciDevice1093::DEVICE_72AB: return "PCI-5105";
        case PciDevice1093::DEVICE_72B8: return "PXI-6682";
        case PciDevice1093::DEVICE_72D0: return "PXI-2545";
        case PciDevice1093::DEVICE_72D1: return "PXI-2546";
        case PciDevice1093::DEVICE_72D2: return "PXI-2547";
        case PciDevice1093::DEVICE_72D3: return "PXI-2548";
        case PciDevice1093::DEVICE_72D4: return "PXI-2549";
        case PciDevice1093::DEVICE_72D5: return "PXI-2555";
        case PciDevice1093::DEVICE_72D6: return "PXI-2556";
        case PciDevice1093::DEVICE_72D7: return "PXI-2557";
        case PciDevice1093::DEVICE_72D8: return "PXI-2558";
        case PciDevice1093::DEVICE_72D9: return "PXI-2559";
        case PciDevice1093::DEVICE_72E8: return "PXIe-6251";
        case PciDevice1093::DEVICE_72E9: return "PXIe-6259";
        case PciDevice1093::DEVICE_72EF: return "PXI-4498";
        case PciDevice1093::DEVICE_72F0: return "PXI-4496";
        case PciDevice1093::DEVICE_72FB: return "PXIe-6672";
        case PciDevice1093::DEVICE_730E: return "PXI-4130";
        case PciDevice1093::DEVICE_730F: return "PXI-5922EX";
        case PciDevice1093::DEVICE_7310: return "PCI-5922EX";
        case PciDevice1093::DEVICE_731C: return "PXI-2535";
        case PciDevice1093::DEVICE_731D: return "PXI-2536";
        case PciDevice1093::DEVICE_7322: return "PXIe-6124";
        case PciDevice1093::DEVICE_7327: return "PXI-6529";
        case PciDevice1093::DEVICE_732C: return "VXI-8360T";
        case PciDevice1093::DEVICE_7331: return "PXIe-5602";
        case PciDevice1093::DEVICE_7332: return "PXIe-5601";
        case PciDevice1093::DEVICE_7333: return "PXI-5900";
        case PciDevice1093::DEVICE_7335: return "PXI-2533";
        case PciDevice1093::DEVICE_7336: return "PXI-2534";
        case PciDevice1093::DEVICE_7342: return "PXI-4461";
        case PciDevice1093::DEVICE_7349: return "PXI-5154";
        case PciDevice1093::DEVICE_734A: return "PCI-5154";
        case PciDevice1093::DEVICE_7357: return "PXI-4065";
        case PciDevice1093::DEVICE_7359: return "PXI-4495";
        case PciDevice1093::DEVICE_7370: return "PXI-4461";
        case PciDevice1093::DEVICE_7373: return "sbRIO-9601";
        case PciDevice1093::DEVICE_7374: return "IOtech-9601";
        case PciDevice1093::DEVICE_7375: return "sbRIO-9602";
        case PciDevice1093::DEVICE_7378: return "sbRIO-9641";
        case PciDevice1093::DEVICE_737D: return "PXI-5124EX";
        case PciDevice1093::DEVICE_7384: return "PXI-7851R";
        case PciDevice1093::DEVICE_7385: return "PXI-7852R";
        case PciDevice1093::DEVICE_7386: return "PCIe-7851R";
        case PciDevice1093::DEVICE_7387: return "PCIe-7852R";
        case PciDevice1093::DEVICE_7390: return "PXI-7841R";
        case PciDevice1093::DEVICE_7391: return "PXI-7842R";
        case PciDevice1093::DEVICE_7392: return "PXI-7853R";
        case PciDevice1093::DEVICE_7393: return "PCIe-7841R";
        case PciDevice1093::DEVICE_7394: return "PCIe-7842R";
        case PciDevice1093::DEVICE_7397: return "sbRIO-9611";
        case PciDevice1093::DEVICE_7398: return "sbRIO-9612";
        case PciDevice1093::DEVICE_7399: return "sbRIO-9631";
        case PciDevice1093::DEVICE_739A: return "sbRIO-9632";
        case PciDevice1093::DEVICE_739B: return "sbRIO-9642";
        case PciDevice1093::DEVICE_73A1: return "PXIe-4498";
        case PciDevice1093::DEVICE_73A2: return "PXIe-4496";
        case PciDevice1093::DEVICE_73A5: return "PXIe-5641R";
        case PciDevice1093::DEVICE_73A7: return "PXI-8250 Chassis Monitor Module";
        case PciDevice1093::DEVICE_73A8: return "PXI-8511 CAN/LS";
        case PciDevice1093::DEVICE_73A9: return "PXI-8511 CAN/LS";
        case PciDevice1093::DEVICE_73AA: return "PXI-8512 CAN/HS";
        case PciDevice1093::DEVICE_73AB: return "PXI-8512 CAN/HS";
        case PciDevice1093::DEVICE_73AC: return "PXI-8513 CAN/XS";
        case PciDevice1093::DEVICE_73AD: return "PXI-8513 CAN/XS";
        case PciDevice1093::DEVICE_73AF: return "PXI-8516 LIN";
        case PciDevice1093::DEVICE_73B1: return "PXI-8517 FlexRay";
        case PciDevice1093::DEVICE_73B2: return "PXI-8531 CANopen";
        case PciDevice1093::DEVICE_73B3: return "PXI-8531 CANopen";
        case PciDevice1093::DEVICE_73B4: return "PXI-8532 DeviceNet";
        case PciDevice1093::DEVICE_73B5: return "PXI-8532 DeviceNet";
        case PciDevice1093::DEVICE_73B6: return "PCI-8511 CAN/LS";
        case PciDevice1093::DEVICE_73B7: return "PCI-8511 CAN/LS";
        case PciDevice1093::DEVICE_73B8: return "PCI-8512 CAN/HS";
        case PciDevice1093::DEVICE_73B9: return "PCI-8512 CAN/HS";
        case PciDevice1093::DEVICE_73BA: return "PCI-8513 CAN/XS";
        case PciDevice1093::DEVICE_73BB: return "PCI-8513 CAN/XS";
        case PciDevice1093::DEVICE_73BD: return "PCI-8516 LIN";
        case PciDevice1093::DEVICE_73BF: return "PCI-8517 FlexRay";
        case PciDevice1093::DEVICE_73C0: return "PCI-8531 CANopen";
        case PciDevice1093::DEVICE_73C1: return "PCI-8531 CANopen";
        case PciDevice1093::DEVICE_73C2: return "PCI-8532 DeviceNet";
        case PciDevice1093::DEVICE_73C3: return "PCI-8532 DeviceNet";
        case PciDevice1093::DEVICE_73C5: return "PXIe-2527";
        case PciDevice1093::DEVICE_73C6: return "PXIe-2529";
        case PciDevice1093::DEVICE_73C8: return "PXIe-2530";
        case PciDevice1093::DEVICE_73C9: return "PXIe-2532";
        case PciDevice1093::DEVICE_73CA: return "PXIe-2569";
        case PciDevice1093::DEVICE_73CB: return "PXIe-2575";
        case PciDevice1093::DEVICE_73CC: return "PXIe-2593";
        case PciDevice1093::DEVICE_73D5: return "PXI-7951R";
        case PciDevice1093::DEVICE_73D6: return "PXI-7952R";
        case PciDevice1093::DEVICE_73D7: return "PXI-7953R";
        case PciDevice1093::DEVICE_73E1: return "PXI-7854R";
        case PciDevice1093::DEVICE_73EC: return "PXI-7954R";
        case PciDevice1093::DEVICE_73ED: return "cRIO-9073";
        case PciDevice1093::DEVICE_73F0: return "PXI-5153";
        case PciDevice1093::DEVICE_73F1: return "PCI-5153";
        case PciDevice1093::DEVICE_73F4: return "PXI-2515";
        case PciDevice1093::DEVICE_73F6: return "cRIO-9111";
        case PciDevice1093::DEVICE_73F7: return "cRIO-9112";
        case PciDevice1093::DEVICE_73F8: return "cRIO-9113";
        case PciDevice1093::DEVICE_73F9: return "cRIO-9114";
        case PciDevice1093::DEVICE_73FA: return "cRIO-9116";
        case PciDevice1093::DEVICE_73FB: return "cRIO-9118";
        case PciDevice1093::DEVICE_7404: return "PXI-4132";
        case PciDevice1093::DEVICE_7405: return "PXIe-6674T";
        case PciDevice1093::DEVICE_7406: return "PXIe-6674";
        case PciDevice1093::DEVICE_740E: return "PCIe-8430/16 (RS-232) Interface";
        case PciDevice1093::DEVICE_740F: return "PCIe-8430/8 (RS-232) Interface";
        case PciDevice1093::DEVICE_7410: return "PCIe-8431/16 (RS-485) Interface";
        case PciDevice1093::DEVICE_7411: return "PCIe-8431/8 (RS-485) Interface";
        case PciDevice1093::DEVICE_7414: return "PCIe-GPIB+";
        case PciDevice1093::DEVICE_741C: return "PXI-5691";
        case PciDevice1093::DEVICE_741D: return "PXI-5695";
        case PciDevice1093::DEVICE_743C: return "CSC-3059";
        case PciDevice1093::DEVICE_7448: return "PXI-2510";
        case PciDevice1093::DEVICE_7454: return "PXI-2512";
        case PciDevice1093::DEVICE_7455: return "PXI-2514";
        case PciDevice1093::DEVICE_7456: return "PXIe-2512";
        case PciDevice1093::DEVICE_7457: return "PXIe-2514";
        case PciDevice1093::DEVICE_745A: return "PXI-6682H";
        case PciDevice1093::DEVICE_745E: return "PXI-5153EX";
        case PciDevice1093::DEVICE_745F: return "PCI-5153EX";
        case PciDevice1093::DEVICE_7460: return "PXI-5154EX";
        case PciDevice1093::DEVICE_7461: return "PCI-5154EX";
        case PciDevice1093::DEVICE_746D: return "PXIe-5650";
        case PciDevice1093::DEVICE_746E: return "PXIe-5651";
        case PciDevice1093::DEVICE_746F: return "PXIe-5652";
        case PciDevice1093::DEVICE_7472: return "PXI-2800";
        case PciDevice1093::DEVICE_7495: return "PXIe-5603";
        case PciDevice1093::DEVICE_7497: return "PXIe-5605";
        case PciDevice1093::DEVICE_74AE: return "PXIe-2515";
        case PciDevice1093::DEVICE_74B4: return "PXI-2531";
        case PciDevice1093::DEVICE_74B5: return "PXIe-2531";
        case PciDevice1093::DEVICE_74C1: return "PXIe-8430/16 (RS-232) Interface";
        case PciDevice1093::DEVICE_74C2: return "PXIe-8430/8 (RS-232) Interface";
        case PciDevice1093::DEVICE_74C3: return "PXIe-8431/16 (RS-485) Interface";
        case PciDevice1093::DEVICE_74C4: return "PXIe-8431/8 (RS-485) Interface";
        case PciDevice1093::DEVICE_74D5: return "PXIe-5630";
        case PciDevice1093::DEVICE_74D9: return "PCIe-8432/2 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_74DA: return "PCIe-8433/2 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_74DB: return "PCIe-8432/4 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_74DC: return "PCIe-8433/4 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_74E8: return "NI 9148";
        case PciDevice1093::DEVICE_7515: return "PCIe-8430/2 (RS-232) Interface";
        case PciDevice1093::DEVICE_7516: return "PCIe-8430/4 (RS-232) Interface";
        case PciDevice1093::DEVICE_7517: return "PCIe-8431/2 (RS-485) Interface";
        case PciDevice1093::DEVICE_7518: return "PCIe-8431/4 (RS-485) Interface";
        case PciDevice1093::DEVICE_751B: return "cRIO-9081";
        case PciDevice1093::DEVICE_751C: return "cRIO-9082";
        case PciDevice1093::DEVICE_7528: return "PXIe-4497";
        case PciDevice1093::DEVICE_7529: return "PXIe-4499";
        case PciDevice1093::DEVICE_752A: return "PXIe-4492";
        case PciDevice1093::DEVICE_7539: return "NI 9157";
        case PciDevice1093::DEVICE_753A: return "NI 9159";
        case PciDevice1093::DEVICE_7598: return "PXI-2571";
        case PciDevice1093::DEVICE_75A4: return "PXI-4131A";
        case PciDevice1093::DEVICE_75B1: return "PCIe-7854R";
        case PciDevice1093::DEVICE_75BA: return "PXI-2543";
        case PciDevice1093::DEVICE_75BB: return "PXIe-2543";
        case PciDevice1093::DEVICE_75E5: return "PXI-6683";
        case PciDevice1093::DEVICE_75E6: return "PXI-6683H";
        case PciDevice1093::DEVICE_75EF: return "PXIe-5632";
        case PciDevice1093::DEVICE_761C: return "VXI-8360LT";
        case PciDevice1093::DEVICE_761F: return "PXI-2540";
        case PciDevice1093::DEVICE_7620: return "PXIe-2540";
        case PciDevice1093::DEVICE_7621: return "PXI-2541";
        case PciDevice1093::DEVICE_7622: return "PXIe-2541";
        case PciDevice1093::DEVICE_7626: return "NI 9154";
        case PciDevice1093::DEVICE_7627: return "NI 9155";
        case PciDevice1093::DEVICE_7638: return "PXI-2720";
        case PciDevice1093::DEVICE_7639: return "PXI-2722";
        case PciDevice1093::DEVICE_763A: return "PXIe-2725";
        case PciDevice1093::DEVICE_763B: return "PXIe-2727";
        case PciDevice1093::DEVICE_763C: return "PXI-4465";
        case PciDevice1093::DEVICE_764B: return "PXIe-2790";
        case PciDevice1093::DEVICE_764C: return "PXI-2520";
        case PciDevice1093::DEVICE_764D: return "PXI-2521";
        case PciDevice1093::DEVICE_764E: return "PXI-2522";
        case PciDevice1093::DEVICE_764F: return "PXI-2523";
        case PciDevice1093::DEVICE_7654: return "PXI-2796";
        case PciDevice1093::DEVICE_7655: return "PXI-2797";
        case PciDevice1093::DEVICE_7656: return "PXI-2798";
        case PciDevice1093::DEVICE_7657: return "PXI-2799";
        case PciDevice1093::DEVICE_765D: return "PXI-2542";
        case PciDevice1093::DEVICE_765E: return "PXIe-2542";
        case PciDevice1093::DEVICE_765F: return "PXI-2544";
        case PciDevice1093::DEVICE_7660: return "PXIe-2544";
        case PciDevice1093::DEVICE_766D: return "PCIe-6535B";
        case PciDevice1093::DEVICE_766E: return "PCIe-6536B";
        case PciDevice1093::DEVICE_766F: return "PCIe-6537B";
        case PciDevice1093::DEVICE_76A3: return "PXIe-6535B";
        case PciDevice1093::DEVICE_76A4: return "PXIe-6536B";
        case PciDevice1093::DEVICE_76A5: return "PXIe-6537B";
        case PciDevice1093::DEVICE_783E: return "PXI-8368";
        case PciDevice1093::DEVICE_9020: return "PXI-2501";
        case PciDevice1093::DEVICE_9030: return "PXI-2503";
        case PciDevice1093::DEVICE_9040: return "PXI-2527";
        case PciDevice1093::DEVICE_9050: return "PXI-2565";
        case PciDevice1093::DEVICE_9060: return "PXI-2590";
        case PciDevice1093::DEVICE_9070: return "PXI-2591";
        case PciDevice1093::DEVICE_9080: return "PXI-2580";
        case PciDevice1093::DEVICE_9090: return "PCI-4021";
        case PciDevice1093::DEVICE_90A0: return "PXI-4021";
        case PciDevice1093::DEVICE_A001: return "PCI-MXI-2";
        case PciDevice1093::DEVICE_B001: return "PCI-1408";
        case PciDevice1093::DEVICE_B011: return "PXI-1408";
        case PciDevice1093::DEVICE_B021: return "PCI-1424";
        case PciDevice1093::DEVICE_B022: return "PXI-1424";
        case PciDevice1093::DEVICE_B031: return "PCI-1413";
        case PciDevice1093::DEVICE_B041: return "PCI-1407";
        case PciDevice1093::DEVICE_B051: return "PXI-1407";
        case PciDevice1093::DEVICE_B061: return "PCI-1411";
        case PciDevice1093::DEVICE_B071: return "PCI-1422";
        case PciDevice1093::DEVICE_B081: return "PXI-1422";
        case PciDevice1093::DEVICE_B091: return "PXI-1411";
        case PciDevice1093::DEVICE_B0B1: return "PCI-1409";
        case PciDevice1093::DEVICE_B0C1: return "PXI-1409";
        case PciDevice1093::DEVICE_B0E1: return "PCI-1428";
        case PciDevice1093::DEVICE_C4C4: return "PXIe/PCIe Device";
        case PciDevice1093::DEVICE_C801: return "PCI-GPIB";
        case PciDevice1093::DEVICE_C811: return "PCI-GPIB+";
        case PciDevice1093::DEVICE_C821: return "PXI-GPIB";
        case PciDevice1093::DEVICE_C831: return "PMC-GPIB";
        case PciDevice1093::DEVICE_C840: return "PCI-GPIB";
        case PciDevice1093::DEVICE_D130: return "PCI-232/2 Interface";
        case PciDevice1093::DEVICE_D140: return "PCI-232/4 Interface";
        case PciDevice1093::DEVICE_D150: return "PCI-232/8 Interface";
        case PciDevice1093::DEVICE_D160: return "PCI-485/2 Interface";
        case PciDevice1093::DEVICE_D170: return "PCI-485/4 Interface";
        case PciDevice1093::DEVICE_D190: return "PXI-8422/2 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_D1A0: return "PXI-8422/4 (Isolated RS-232) Interface";
        case PciDevice1093::DEVICE_D1B0: return "PXI-8423/2 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_D1C0: return "PXI-8423/4 (Isolated RS-485) Interface";
        case PciDevice1093::DEVICE_D1D0: return "PXI-8420/2 (RS-232) Interface";
        case PciDevice1093::DEVICE_D1E0: return "PXI-8420/4 (RS-232) Interface";
        case PciDevice1093::DEVICE_D1F0: return "PXI-8420/8 (RS-232) Interface";
        case PciDevice1093::DEVICE_D1F1: return "PXI-8420/16 (RS-232) Interface";
        case PciDevice1093::DEVICE_D230: return "PXI-8421/2 (RS-485) Interface";
        case PciDevice1093::DEVICE_D240: return "PXI-8421/4 (RS-485) Interface";
        case PciDevice1093::DEVICE_D250: return "PCI-232/2 (Isolated) Interface";
        case PciDevice1093::DEVICE_D260: return "PCI-485/2 (Isolated) Interface";
        case PciDevice1093::DEVICE_D270: return "PCI-232/4 (Isolated) Interface";
        case PciDevice1093::DEVICE_D280: return "PCI-485/4 (Isolated) Interface";
        case PciDevice1093::DEVICE_D290: return "PCI-485/8 Interface";
        case PciDevice1093::DEVICE_D2A0: return "PXI-8421/8 (RS-485) Interface";
        case PciDevice1093::DEVICE_D2B0: return "PCI-232/16 Interface";
        case PciDevice1093::DEVICE_E111: return "PCI-CAN";
        case PciDevice1093::DEVICE_E131: return "PXI-8461 (1 port)";
        case PciDevice1093::DEVICE_E141: return "PCI-CAN/LS";
        case PciDevice1093::DEVICE_E151: return "PXI-8460 (1 port)";
        case PciDevice1093::DEVICE_E211: return "PCI-CAN/2";
        case PciDevice1093::DEVICE_E231: return "PXI-8461 (2 ports)";
        case PciDevice1093::DEVICE_E241: return "PCI-CAN/LS2";
        case PciDevice1093::DEVICE_E251: return "PXI-8460 (2 ports)";
        case PciDevice1093::DEVICE_E261: return "PCI-CAN/DS";
        case PciDevice1093::DEVICE_E271: return "PXI-8462";
        case PciDevice1093::DEVICE_F110: return "VMEpc-650";
        case PciDevice1093::DEVICE_F120: return "VXIpc-650";
        case PciDevice1093::DEVICE_FE00: return "VXIpc-87x";
        case PciDevice1093::DEVICE_FE41: return "VXIpc-860";
        case PciDevice1093::DEVICE_FE51: return "VXIpc-74x";
        case PciDevice1093::DEVICE_FE61: return "VXIpc-850";
        case PciDevice1093::DEVICE_FE70: return "VXIpc-880";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1093_PCIDEVICE1093_H
