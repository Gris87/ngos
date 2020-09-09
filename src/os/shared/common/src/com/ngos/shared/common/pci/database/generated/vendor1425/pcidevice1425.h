// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCIDEVICE1425_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCIDEVICE1425_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1425/pcisubdevice14250030.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1425/pcisubdevice14255001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1425: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_0022 = 0x0022,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031,
    DEVICE_0032 = 0x0032,
    DEVICE_0033 = 0x0033,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0036 = 0x0036,
    DEVICE_0037 = 0x0037,
    DEVICE_4001 = 0x4001,
    DEVICE_4002 = 0x4002,
    DEVICE_4003 = 0x4003,
    DEVICE_4004 = 0x4004,
    DEVICE_4005 = 0x4005,
    DEVICE_4006 = 0x4006,
    DEVICE_4007 = 0x4007,
    DEVICE_4008 = 0x4008,
    DEVICE_4009 = 0x4009,
    DEVICE_400A = 0x400A,
    DEVICE_400B = 0x400B,
    DEVICE_400C = 0x400C,
    DEVICE_400D = 0x400D,
    DEVICE_400E = 0x400E,
    DEVICE_400F = 0x400F,
    DEVICE_4080 = 0x4080,
    DEVICE_4081 = 0x4081,
    DEVICE_4082 = 0x4082,
    DEVICE_4083 = 0x4083,
    DEVICE_4084 = 0x4084,
    DEVICE_4085 = 0x4085,
    DEVICE_4086 = 0x4086,
    DEVICE_4087 = 0x4087,
    DEVICE_4088 = 0x4088,
    DEVICE_4401 = 0x4401,
    DEVICE_4402 = 0x4402,
    DEVICE_4403 = 0x4403,
    DEVICE_4404 = 0x4404,
    DEVICE_4405 = 0x4405,
    DEVICE_4406 = 0x4406,
    DEVICE_4407 = 0x4407,
    DEVICE_4408 = 0x4408,
    DEVICE_4409 = 0x4409,
    DEVICE_440A = 0x440A,
    DEVICE_440B = 0x440B,
    DEVICE_440C = 0x440C,
    DEVICE_440D = 0x440D,
    DEVICE_440E = 0x440E,
    DEVICE_440F = 0x440F,
    DEVICE_4480 = 0x4480,
    DEVICE_4481 = 0x4481,
    DEVICE_4482 = 0x4482,
    DEVICE_4483 = 0x4483,
    DEVICE_4484 = 0x4484,
    DEVICE_4485 = 0x4485,
    DEVICE_4486 = 0x4486,
    DEVICE_4487 = 0x4487,
    DEVICE_4488 = 0x4488,
    DEVICE_4501 = 0x4501,
    DEVICE_4502 = 0x4502,
    DEVICE_4503 = 0x4503,
    DEVICE_4504 = 0x4504,
    DEVICE_4505 = 0x4505,
    DEVICE_4506 = 0x4506,
    DEVICE_4507 = 0x4507,
    DEVICE_4508 = 0x4508,
    DEVICE_4509 = 0x4509,
    DEVICE_450A = 0x450A,
    DEVICE_450B = 0x450B,
    DEVICE_450C = 0x450C,
    DEVICE_450D = 0x450D,
    DEVICE_450E = 0x450E,
    DEVICE_450F = 0x450F,
    DEVICE_4580 = 0x4580,
    DEVICE_4581 = 0x4581,
    DEVICE_4582 = 0x4582,
    DEVICE_4583 = 0x4583,
    DEVICE_4584 = 0x4584,
    DEVICE_4585 = 0x4585,
    DEVICE_4586 = 0x4586,
    DEVICE_4587 = 0x4587,
    DEVICE_4588 = 0x4588,
    DEVICE_4601 = 0x4601,
    DEVICE_4602 = 0x4602,
    DEVICE_4603 = 0x4603,
    DEVICE_4604 = 0x4604,
    DEVICE_4605 = 0x4605,
    DEVICE_4606 = 0x4606,
    DEVICE_4607 = 0x4607,
    DEVICE_4608 = 0x4608,
    DEVICE_4609 = 0x4609,
    DEVICE_460A = 0x460A,
    DEVICE_460B = 0x460B,
    DEVICE_460C = 0x460C,
    DEVICE_460D = 0x460D,
    DEVICE_460E = 0x460E,
    DEVICE_460F = 0x460F,
    DEVICE_4680 = 0x4680,
    DEVICE_4681 = 0x4681,
    DEVICE_4682 = 0x4682,
    DEVICE_4683 = 0x4683,
    DEVICE_4684 = 0x4684,
    DEVICE_4685 = 0x4685,
    DEVICE_4686 = 0x4686,
    DEVICE_4687 = 0x4687,
    DEVICE_4688 = 0x4688,
    DEVICE_4701 = 0x4701,
    DEVICE_4702 = 0x4702,
    DEVICE_4703 = 0x4703,
    DEVICE_4704 = 0x4704,
    DEVICE_4705 = 0x4705,
    DEVICE_4706 = 0x4706,
    DEVICE_4707 = 0x4707,
    DEVICE_4708 = 0x4708,
    DEVICE_4709 = 0x4709,
    DEVICE_470A = 0x470A,
    DEVICE_470B = 0x470B,
    DEVICE_470C = 0x470C,
    DEVICE_470D = 0x470D,
    DEVICE_470E = 0x470E,
    DEVICE_470F = 0x470F,
    DEVICE_4780 = 0x4780,
    DEVICE_4781 = 0x4781,
    DEVICE_4782 = 0x4782,
    DEVICE_4783 = 0x4783,
    DEVICE_4784 = 0x4784,
    DEVICE_4785 = 0x4785,
    DEVICE_4786 = 0x4786,
    DEVICE_4787 = 0x4787,
    DEVICE_4788 = 0x4788,
    DEVICE_4801 = 0x4801,
    DEVICE_4802 = 0x4802,
    DEVICE_4803 = 0x4803,
    DEVICE_4804 = 0x4804,
    DEVICE_4805 = 0x4805,
    DEVICE_4806 = 0x4806,
    DEVICE_4807 = 0x4807,
    DEVICE_4808 = 0x4808,
    DEVICE_4809 = 0x4809,
    DEVICE_480A = 0x480A,
    DEVICE_480B = 0x480B,
    DEVICE_480C = 0x480C,
    DEVICE_480D = 0x480D,
    DEVICE_480E = 0x480E,
    DEVICE_480F = 0x480F,
    DEVICE_4880 = 0x4880,
    DEVICE_4881 = 0x4881,
    DEVICE_4882 = 0x4882,
    DEVICE_4883 = 0x4883,
    DEVICE_4884 = 0x4884,
    DEVICE_4885 = 0x4885,
    DEVICE_4886 = 0x4886,
    DEVICE_4887 = 0x4887,
    DEVICE_4888 = 0x4888,
    DEVICE_5001 = 0x5001,
    DEVICE_5002 = 0x5002,
    DEVICE_5003 = 0x5003,
    DEVICE_5004 = 0x5004,
    DEVICE_5005 = 0x5005,
    DEVICE_5006 = 0x5006,
    DEVICE_5007 = 0x5007,
    DEVICE_5008 = 0x5008,
    DEVICE_5009 = 0x5009,
    DEVICE_500A = 0x500A,
    DEVICE_500B = 0x500B,
    DEVICE_500C = 0x500C,
    DEVICE_500D = 0x500D,
    DEVICE_500E = 0x500E,
    DEVICE_500F = 0x500F,
    DEVICE_5010 = 0x5010,
    DEVICE_5011 = 0x5011,
    DEVICE_5012 = 0x5012,
    DEVICE_5013 = 0x5013,
    DEVICE_5014 = 0x5014,
    DEVICE_5015 = 0x5015,
    DEVICE_5016 = 0x5016,
    DEVICE_5017 = 0x5017,
    DEVICE_5018 = 0x5018,
    DEVICE_5019 = 0x5019,
    DEVICE_501A = 0x501A,
    DEVICE_501B = 0x501B,
    DEVICE_5080 = 0x5080,
    DEVICE_5081 = 0x5081,
    DEVICE_5082 = 0x5082,
    DEVICE_5083 = 0x5083,
    DEVICE_5084 = 0x5084,
    DEVICE_5085 = 0x5085,
    DEVICE_5086 = 0x5086,
    DEVICE_5087 = 0x5087,
    DEVICE_5088 = 0x5088,
    DEVICE_5089 = 0x5089,
    DEVICE_5090 = 0x5090,
    DEVICE_5091 = 0x5091,
    DEVICE_5092 = 0x5092,
    DEVICE_5093 = 0x5093,
    DEVICE_5094 = 0x5094,
    DEVICE_5095 = 0x5095,
    DEVICE_5096 = 0x5096,
    DEVICE_5097 = 0x5097,
    DEVICE_5098 = 0x5098,
    DEVICE_5099 = 0x5099,
    DEVICE_509A = 0x509A,
    DEVICE_509B = 0x509B,
    DEVICE_509C = 0x509C,
    DEVICE_509D = 0x509D,
    DEVICE_509E = 0x509E,
    DEVICE_509F = 0x509F,
    DEVICE_50A0 = 0x50A0,
    DEVICE_50A1 = 0x50A1,
    DEVICE_50A2 = 0x50A2,
    DEVICE_50A3 = 0x50A3,
    DEVICE_50A4 = 0x50A4,
    DEVICE_50A5 = 0x50A5,
    DEVICE_50A6 = 0x50A6,
    DEVICE_50A7 = 0x50A7,
    DEVICE_50A8 = 0x50A8,
    DEVICE_50A9 = 0x50A9,
    DEVICE_50AA = 0x50AA,
    DEVICE_50AB = 0x50AB,
    DEVICE_50AC = 0x50AC,
    DEVICE_50AD = 0x50AD,
    DEVICE_50AE = 0x50AE,
    DEVICE_50AF = 0x50AF,
    DEVICE_50B0 = 0x50B0,
    DEVICE_5401 = 0x5401,
    DEVICE_5402 = 0x5402,
    DEVICE_5403 = 0x5403,
    DEVICE_5404 = 0x5404,
    DEVICE_5405 = 0x5405,
    DEVICE_5406 = 0x5406,
    DEVICE_5407 = 0x5407,
    DEVICE_5408 = 0x5408,
    DEVICE_5409 = 0x5409,
    DEVICE_540A = 0x540A,
    DEVICE_540B = 0x540B,
    DEVICE_540C = 0x540C,
    DEVICE_540D = 0x540D,
    DEVICE_540E = 0x540E,
    DEVICE_540F = 0x540F,
    DEVICE_5410 = 0x5410,
    DEVICE_5411 = 0x5411,
    DEVICE_5412 = 0x5412,
    DEVICE_5413 = 0x5413,
    DEVICE_5414 = 0x5414,
    DEVICE_5415 = 0x5415,
    DEVICE_5416 = 0x5416,
    DEVICE_5417 = 0x5417,
    DEVICE_5418 = 0x5418,
    DEVICE_5419 = 0x5419,
    DEVICE_541A = 0x541A,
    DEVICE_541B = 0x541B,
    DEVICE_5480 = 0x5480,
    DEVICE_5481 = 0x5481,
    DEVICE_5482 = 0x5482,
    DEVICE_5483 = 0x5483,
    DEVICE_5484 = 0x5484,
    DEVICE_5485 = 0x5485,
    DEVICE_5486 = 0x5486,
    DEVICE_5487 = 0x5487,
    DEVICE_5488 = 0x5488,
    DEVICE_5489 = 0x5489,
    DEVICE_5490 = 0x5490,
    DEVICE_5491 = 0x5491,
    DEVICE_5492 = 0x5492,
    DEVICE_5493 = 0x5493,
    DEVICE_5494 = 0x5494,
    DEVICE_5495 = 0x5495,
    DEVICE_5496 = 0x5496,
    DEVICE_5497 = 0x5497,
    DEVICE_5498 = 0x5498,
    DEVICE_5499 = 0x5499,
    DEVICE_549A = 0x549A,
    DEVICE_549B = 0x549B,
    DEVICE_549C = 0x549C,
    DEVICE_549D = 0x549D,
    DEVICE_549E = 0x549E,
    DEVICE_549F = 0x549F,
    DEVICE_54A0 = 0x54A0,
    DEVICE_54A1 = 0x54A1,
    DEVICE_54A2 = 0x54A2,
    DEVICE_54A3 = 0x54A3,
    DEVICE_54A4 = 0x54A4,
    DEVICE_54A5 = 0x54A5,
    DEVICE_54A6 = 0x54A6,
    DEVICE_54A7 = 0x54A7,
    DEVICE_54A8 = 0x54A8,
    DEVICE_54A9 = 0x54A9,
    DEVICE_54AA = 0x54AA,
    DEVICE_54AB = 0x54AB,
    DEVICE_54AC = 0x54AC,
    DEVICE_54AD = 0x54AD,
    DEVICE_54AE = 0x54AE,
    DEVICE_54AF = 0x54AF,
    DEVICE_54B0 = 0x54B0,
    DEVICE_5501 = 0x5501,
    DEVICE_5502 = 0x5502,
    DEVICE_5503 = 0x5503,
    DEVICE_5504 = 0x5504,
    DEVICE_5505 = 0x5505,
    DEVICE_5506 = 0x5506,
    DEVICE_5507 = 0x5507,
    DEVICE_5508 = 0x5508,
    DEVICE_5509 = 0x5509,
    DEVICE_550A = 0x550A,
    DEVICE_550B = 0x550B,
    DEVICE_550C = 0x550C,
    DEVICE_550D = 0x550D,
    DEVICE_550E = 0x550E,
    DEVICE_550F = 0x550F,
    DEVICE_5510 = 0x5510,
    DEVICE_5511 = 0x5511,
    DEVICE_5512 = 0x5512,
    DEVICE_5513 = 0x5513,
    DEVICE_5514 = 0x5514,
    DEVICE_5515 = 0x5515,
    DEVICE_5516 = 0x5516,
    DEVICE_5517 = 0x5517,
    DEVICE_5518 = 0x5518,
    DEVICE_5519 = 0x5519,
    DEVICE_551A = 0x551A,
    DEVICE_551B = 0x551B,
    DEVICE_5580 = 0x5580,
    DEVICE_5581 = 0x5581,
    DEVICE_5582 = 0x5582,
    DEVICE_5583 = 0x5583,
    DEVICE_5584 = 0x5584,
    DEVICE_5585 = 0x5585,
    DEVICE_5586 = 0x5586,
    DEVICE_5587 = 0x5587,
    DEVICE_5588 = 0x5588,
    DEVICE_5589 = 0x5589,
    DEVICE_5590 = 0x5590,
    DEVICE_5591 = 0x5591,
    DEVICE_5592 = 0x5592,
    DEVICE_5593 = 0x5593,
    DEVICE_5594 = 0x5594,
    DEVICE_5595 = 0x5595,
    DEVICE_5596 = 0x5596,
    DEVICE_5597 = 0x5597,
    DEVICE_5598 = 0x5598,
    DEVICE_5599 = 0x5599,
    DEVICE_559A = 0x559A,
    DEVICE_559B = 0x559B,
    DEVICE_559C = 0x559C,
    DEVICE_559D = 0x559D,
    DEVICE_559E = 0x559E,
    DEVICE_559F = 0x559F,
    DEVICE_55A0 = 0x55A0,
    DEVICE_55A1 = 0x55A1,
    DEVICE_55A2 = 0x55A2,
    DEVICE_55A3 = 0x55A3,
    DEVICE_55A4 = 0x55A4,
    DEVICE_55A5 = 0x55A5,
    DEVICE_55A6 = 0x55A6,
    DEVICE_55A7 = 0x55A7,
    DEVICE_55A8 = 0x55A8,
    DEVICE_55A9 = 0x55A9,
    DEVICE_55AA = 0x55AA,
    DEVICE_55AB = 0x55AB,
    DEVICE_55AC = 0x55AC,
    DEVICE_55AD = 0x55AD,
    DEVICE_55AE = 0x55AE,
    DEVICE_55AF = 0x55AF,
    DEVICE_55B0 = 0x55B0,
    DEVICE_5601 = 0x5601,
    DEVICE_5602 = 0x5602,
    DEVICE_5603 = 0x5603,
    DEVICE_5604 = 0x5604,
    DEVICE_5605 = 0x5605,
    DEVICE_5606 = 0x5606,
    DEVICE_5607 = 0x5607,
    DEVICE_5608 = 0x5608,
    DEVICE_5609 = 0x5609,
    DEVICE_560A = 0x560A,
    DEVICE_560B = 0x560B,
    DEVICE_560C = 0x560C,
    DEVICE_560D = 0x560D,
    DEVICE_560E = 0x560E,
    DEVICE_560F = 0x560F,
    DEVICE_5610 = 0x5610,
    DEVICE_5611 = 0x5611,
    DEVICE_5612 = 0x5612,
    DEVICE_5613 = 0x5613,
    DEVICE_5614 = 0x5614,
    DEVICE_5615 = 0x5615,
    DEVICE_5616 = 0x5616,
    DEVICE_5617 = 0x5617,
    DEVICE_5618 = 0x5618,
    DEVICE_5619 = 0x5619,
    DEVICE_561A = 0x561A,
    DEVICE_561B = 0x561B,
    DEVICE_5680 = 0x5680,
    DEVICE_5681 = 0x5681,
    DEVICE_5682 = 0x5682,
    DEVICE_5683 = 0x5683,
    DEVICE_5684 = 0x5684,
    DEVICE_5685 = 0x5685,
    DEVICE_5686 = 0x5686,
    DEVICE_5687 = 0x5687,
    DEVICE_5688 = 0x5688,
    DEVICE_5689 = 0x5689,
    DEVICE_5690 = 0x5690,
    DEVICE_5691 = 0x5691,
    DEVICE_5692 = 0x5692,
    DEVICE_5693 = 0x5693,
    DEVICE_5694 = 0x5694,
    DEVICE_5695 = 0x5695,
    DEVICE_5696 = 0x5696,
    DEVICE_5697 = 0x5697,
    DEVICE_5698 = 0x5698,
    DEVICE_5699 = 0x5699,
    DEVICE_569A = 0x569A,
    DEVICE_569B = 0x569B,
    DEVICE_569C = 0x569C,
    DEVICE_569D = 0x569D,
    DEVICE_569E = 0x569E,
    DEVICE_569F = 0x569F,
    DEVICE_56A0 = 0x56A0,
    DEVICE_56A1 = 0x56A1,
    DEVICE_56A2 = 0x56A2,
    DEVICE_56A3 = 0x56A3,
    DEVICE_56A4 = 0x56A4,
    DEVICE_56A5 = 0x56A5,
    DEVICE_56A6 = 0x56A6,
    DEVICE_56A7 = 0x56A7,
    DEVICE_56A8 = 0x56A8,
    DEVICE_56A9 = 0x56A9,
    DEVICE_56AA = 0x56AA,
    DEVICE_56AB = 0x56AB,
    DEVICE_56AC = 0x56AC,
    DEVICE_56AD = 0x56AD,
    DEVICE_56AE = 0x56AE,
    DEVICE_56AF = 0x56AF,
    DEVICE_56B0 = 0x56B0,
    DEVICE_5701 = 0x5701,
    DEVICE_5702 = 0x5702,
    DEVICE_5703 = 0x5703,
    DEVICE_5704 = 0x5704,
    DEVICE_5705 = 0x5705,
    DEVICE_5706 = 0x5706,
    DEVICE_5707 = 0x5707,
    DEVICE_5708 = 0x5708,
    DEVICE_5709 = 0x5709,
    DEVICE_570A = 0x570A,
    DEVICE_570B = 0x570B,
    DEVICE_570C = 0x570C,
    DEVICE_570D = 0x570D,
    DEVICE_570E = 0x570E,
    DEVICE_570F = 0x570F,
    DEVICE_5710 = 0x5710,
    DEVICE_5711 = 0x5711,
    DEVICE_5712 = 0x5712,
    DEVICE_5713 = 0x5713,
    DEVICE_5714 = 0x5714,
    DEVICE_5715 = 0x5715,
    DEVICE_5780 = 0x5780,
    DEVICE_5781 = 0x5781,
    DEVICE_5782 = 0x5782,
    DEVICE_5783 = 0x5783,
    DEVICE_5784 = 0x5784,
    DEVICE_5785 = 0x5785,
    DEVICE_5786 = 0x5786,
    DEVICE_5787 = 0x5787,
    DEVICE_5788 = 0x5788,
    DEVICE_5789 = 0x5789,
    DEVICE_5790 = 0x5790,
    DEVICE_5791 = 0x5791,
    DEVICE_5792 = 0x5792,
    DEVICE_5793 = 0x5793,
    DEVICE_5794 = 0x5794,
    DEVICE_5795 = 0x5795,
    DEVICE_5796 = 0x5796,
    DEVICE_5797 = 0x5797,
    DEVICE_5801 = 0x5801,
    DEVICE_5802 = 0x5802,
    DEVICE_5803 = 0x5803,
    DEVICE_5804 = 0x5804,
    DEVICE_5805 = 0x5805,
    DEVICE_5806 = 0x5806,
    DEVICE_5807 = 0x5807,
    DEVICE_5808 = 0x5808,
    DEVICE_5809 = 0x5809,
    DEVICE_580A = 0x580A,
    DEVICE_580B = 0x580B,
    DEVICE_580C = 0x580C,
    DEVICE_580D = 0x580D,
    DEVICE_580E = 0x580E,
    DEVICE_580F = 0x580F,
    DEVICE_5810 = 0x5810,
    DEVICE_5811 = 0x5811,
    DEVICE_5812 = 0x5812,
    DEVICE_5813 = 0x5813,
    DEVICE_5814 = 0x5814,
    DEVICE_5815 = 0x5815,
    DEVICE_5816 = 0x5816,
    DEVICE_5817 = 0x5817,
    DEVICE_5818 = 0x5818,
    DEVICE_5819 = 0x5819,
    DEVICE_581A = 0x581A,
    DEVICE_581B = 0x581B,
    DEVICE_5880 = 0x5880,
    DEVICE_5881 = 0x5881,
    DEVICE_5882 = 0x5882,
    DEVICE_5883 = 0x5883,
    DEVICE_5884 = 0x5884,
    DEVICE_5885 = 0x5885,
    DEVICE_5886 = 0x5886,
    DEVICE_5887 = 0x5887,
    DEVICE_5888 = 0x5888,
    DEVICE_5889 = 0x5889,
    DEVICE_5890 = 0x5890,
    DEVICE_5891 = 0x5891,
    DEVICE_5892 = 0x5892,
    DEVICE_5893 = 0x5893,
    DEVICE_5894 = 0x5894,
    DEVICE_5895 = 0x5895,
    DEVICE_5896 = 0x5896,
    DEVICE_5897 = 0x5897,
    DEVICE_5898 = 0x5898,
    DEVICE_5899 = 0x5899,
    DEVICE_589A = 0x589A,
    DEVICE_589B = 0x589B,
    DEVICE_589C = 0x589C,
    DEVICE_589D = 0x589D,
    DEVICE_589E = 0x589E,
    DEVICE_589F = 0x589F,
    DEVICE_58A0 = 0x58A0,
    DEVICE_58A1 = 0x58A1,
    DEVICE_58A2 = 0x58A2,
    DEVICE_58A3 = 0x58A3,
    DEVICE_58A4 = 0x58A4,
    DEVICE_58A5 = 0x58A5,
    DEVICE_58A6 = 0x58A6,
    DEVICE_58A7 = 0x58A7,
    DEVICE_58A8 = 0x58A8,
    DEVICE_58A9 = 0x58A9,
    DEVICE_58AA = 0x58AA,
    DEVICE_58AB = 0x58AB,
    DEVICE_58AC = 0x58AC,
    DEVICE_58AD = 0x58AD,
    DEVICE_58AE = 0x58AE,
    DEVICE_58AF = 0x58AF,
    DEVICE_58B0 = 0x58B0,
    DEVICE_6001 = 0x6001,
    DEVICE_6002 = 0x6002,
    DEVICE_6003 = 0x6003,
    DEVICE_6004 = 0x6004,
    DEVICE_6005 = 0x6005,
    DEVICE_6006 = 0x6006,
    DEVICE_6007 = 0x6007,
    DEVICE_6008 = 0x6008,
    DEVICE_6009 = 0x6009,
    DEVICE_600D = 0x600D,
    DEVICE_6011 = 0x6011,
    DEVICE_6014 = 0x6014,
    DEVICE_6015 = 0x6015,
    DEVICE_6080 = 0x6080,
    DEVICE_6081 = 0x6081,
    DEVICE_6082 = 0x6082,
    DEVICE_6083 = 0x6083,
    DEVICE_6084 = 0x6084,
    DEVICE_6085 = 0x6085,
    DEVICE_6086 = 0x6086,
    DEVICE_6087 = 0x6087,
    DEVICE_6088 = 0x6088,
    DEVICE_6089 = 0x6089,
    DEVICE_608A = 0x608A,
    DEVICE_6401 = 0x6401,
    DEVICE_6402 = 0x6402,
    DEVICE_6403 = 0x6403,
    DEVICE_6404 = 0x6404,
    DEVICE_6405 = 0x6405,
    DEVICE_6406 = 0x6406,
    DEVICE_6407 = 0x6407,
    DEVICE_6408 = 0x6408,
    DEVICE_6409 = 0x6409,
    DEVICE_640D = 0x640D,
    DEVICE_6411 = 0x6411,
    DEVICE_6414 = 0x6414,
    DEVICE_6415 = 0x6415,
    DEVICE_6480 = 0x6480,
    DEVICE_6481 = 0x6481,
    DEVICE_6482 = 0x6482,
    DEVICE_6483 = 0x6483,
    DEVICE_6484 = 0x6484,
    DEVICE_6485 = 0x6485,
    DEVICE_6486 = 0x6486,
    DEVICE_6487 = 0x6487,
    DEVICE_6488 = 0x6488,
    DEVICE_6489 = 0x6489,
    DEVICE_648A = 0x648A,
    DEVICE_6501 = 0x6501,
    DEVICE_6502 = 0x6502,
    DEVICE_6503 = 0x6503,
    DEVICE_6504 = 0x6504,
    DEVICE_6505 = 0x6505,
    DEVICE_6506 = 0x6506,
    DEVICE_6507 = 0x6507,
    DEVICE_6508 = 0x6508,
    DEVICE_6509 = 0x6509,
    DEVICE_650D = 0x650D,
    DEVICE_6511 = 0x6511,
    DEVICE_6514 = 0x6514,
    DEVICE_6515 = 0x6515,
    DEVICE_6580 = 0x6580,
    DEVICE_6581 = 0x6581,
    DEVICE_6582 = 0x6582,
    DEVICE_6583 = 0x6583,
    DEVICE_6584 = 0x6584,
    DEVICE_6585 = 0x6585,
    DEVICE_6586 = 0x6586,
    DEVICE_6587 = 0x6587,
    DEVICE_6588 = 0x6588,
    DEVICE_6589 = 0x6589,
    DEVICE_658A = 0x658A,
    DEVICE_6601 = 0x6601,
    DEVICE_6602 = 0x6602,
    DEVICE_6603 = 0x6603,
    DEVICE_6604 = 0x6604,
    DEVICE_6605 = 0x6605,
    DEVICE_6606 = 0x6606,
    DEVICE_6607 = 0x6607,
    DEVICE_6608 = 0x6608,
    DEVICE_6609 = 0x6609,
    DEVICE_660D = 0x660D,
    DEVICE_6611 = 0x6611,
    DEVICE_6614 = 0x6614,
    DEVICE_6615 = 0x6615,
    DEVICE_6680 = 0x6680,
    DEVICE_6681 = 0x6681,
    DEVICE_6682 = 0x6682,
    DEVICE_6683 = 0x6683,
    DEVICE_6684 = 0x6684,
    DEVICE_6685 = 0x6685,
    DEVICE_6686 = 0x6686,
    DEVICE_6687 = 0x6687,
    DEVICE_6688 = 0x6688,
    DEVICE_6689 = 0x6689,
    DEVICE_668A = 0x668A,
    DEVICE_6801 = 0x6801,
    DEVICE_6802 = 0x6802,
    DEVICE_6803 = 0x6803,
    DEVICE_6804 = 0x6804,
    DEVICE_6805 = 0x6805,
    DEVICE_6806 = 0x6806,
    DEVICE_6807 = 0x6807,
    DEVICE_6808 = 0x6808,
    DEVICE_6809 = 0x6809,
    DEVICE_680D = 0x680D,
    DEVICE_6811 = 0x6811,
    DEVICE_6814 = 0x6814,
    DEVICE_6815 = 0x6815,
    DEVICE_6880 = 0x6880,
    DEVICE_6881 = 0x6881,
    DEVICE_6882 = 0x6882,
    DEVICE_6883 = 0x6883,
    DEVICE_6884 = 0x6884,
    DEVICE_6885 = 0x6885,
    DEVICE_6886 = 0x6886,
    DEVICE_6887 = 0x6887,
    DEVICE_6888 = 0x6888,
    DEVICE_6889 = 0x6889,
    DEVICE_688A = 0x688A,
    DEVICE_A000 = 0xA000
};



inline const char8* enumToString(PciDevice1425 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1425::NONE:        return "NONE";
        case PciDevice1425::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1425::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1425::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1425::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1425::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1425::DEVICE_0032: return "DEVICE_0032";
        case PciDevice1425::DEVICE_0033: return "DEVICE_0033";
        case PciDevice1425::DEVICE_0034: return "DEVICE_0034";
        case PciDevice1425::DEVICE_0035: return "DEVICE_0035";
        case PciDevice1425::DEVICE_0036: return "DEVICE_0036";
        case PciDevice1425::DEVICE_0037: return "DEVICE_0037";
        case PciDevice1425::DEVICE_4001: return "DEVICE_4001";
        case PciDevice1425::DEVICE_4002: return "DEVICE_4002";
        case PciDevice1425::DEVICE_4003: return "DEVICE_4003";
        case PciDevice1425::DEVICE_4004: return "DEVICE_4004";
        case PciDevice1425::DEVICE_4005: return "DEVICE_4005";
        case PciDevice1425::DEVICE_4006: return "DEVICE_4006";
        case PciDevice1425::DEVICE_4007: return "DEVICE_4007";
        case PciDevice1425::DEVICE_4008: return "DEVICE_4008";
        case PciDevice1425::DEVICE_4009: return "DEVICE_4009";
        case PciDevice1425::DEVICE_400A: return "DEVICE_400A";
        case PciDevice1425::DEVICE_400B: return "DEVICE_400B";
        case PciDevice1425::DEVICE_400C: return "DEVICE_400C";
        case PciDevice1425::DEVICE_400D: return "DEVICE_400D";
        case PciDevice1425::DEVICE_400E: return "DEVICE_400E";
        case PciDevice1425::DEVICE_400F: return "DEVICE_400F";
        case PciDevice1425::DEVICE_4080: return "DEVICE_4080";
        case PciDevice1425::DEVICE_4081: return "DEVICE_4081";
        case PciDevice1425::DEVICE_4082: return "DEVICE_4082";
        case PciDevice1425::DEVICE_4083: return "DEVICE_4083";
        case PciDevice1425::DEVICE_4084: return "DEVICE_4084";
        case PciDevice1425::DEVICE_4085: return "DEVICE_4085";
        case PciDevice1425::DEVICE_4086: return "DEVICE_4086";
        case PciDevice1425::DEVICE_4087: return "DEVICE_4087";
        case PciDevice1425::DEVICE_4088: return "DEVICE_4088";
        case PciDevice1425::DEVICE_4401: return "DEVICE_4401";
        case PciDevice1425::DEVICE_4402: return "DEVICE_4402";
        case PciDevice1425::DEVICE_4403: return "DEVICE_4403";
        case PciDevice1425::DEVICE_4404: return "DEVICE_4404";
        case PciDevice1425::DEVICE_4405: return "DEVICE_4405";
        case PciDevice1425::DEVICE_4406: return "DEVICE_4406";
        case PciDevice1425::DEVICE_4407: return "DEVICE_4407";
        case PciDevice1425::DEVICE_4408: return "DEVICE_4408";
        case PciDevice1425::DEVICE_4409: return "DEVICE_4409";
        case PciDevice1425::DEVICE_440A: return "DEVICE_440A";
        case PciDevice1425::DEVICE_440B: return "DEVICE_440B";
        case PciDevice1425::DEVICE_440C: return "DEVICE_440C";
        case PciDevice1425::DEVICE_440D: return "DEVICE_440D";
        case PciDevice1425::DEVICE_440E: return "DEVICE_440E";
        case PciDevice1425::DEVICE_440F: return "DEVICE_440F";
        case PciDevice1425::DEVICE_4480: return "DEVICE_4480";
        case PciDevice1425::DEVICE_4481: return "DEVICE_4481";
        case PciDevice1425::DEVICE_4482: return "DEVICE_4482";
        case PciDevice1425::DEVICE_4483: return "DEVICE_4483";
        case PciDevice1425::DEVICE_4484: return "DEVICE_4484";
        case PciDevice1425::DEVICE_4485: return "DEVICE_4485";
        case PciDevice1425::DEVICE_4486: return "DEVICE_4486";
        case PciDevice1425::DEVICE_4487: return "DEVICE_4487";
        case PciDevice1425::DEVICE_4488: return "DEVICE_4488";
        case PciDevice1425::DEVICE_4501: return "DEVICE_4501";
        case PciDevice1425::DEVICE_4502: return "DEVICE_4502";
        case PciDevice1425::DEVICE_4503: return "DEVICE_4503";
        case PciDevice1425::DEVICE_4504: return "DEVICE_4504";
        case PciDevice1425::DEVICE_4505: return "DEVICE_4505";
        case PciDevice1425::DEVICE_4506: return "DEVICE_4506";
        case PciDevice1425::DEVICE_4507: return "DEVICE_4507";
        case PciDevice1425::DEVICE_4508: return "DEVICE_4508";
        case PciDevice1425::DEVICE_4509: return "DEVICE_4509";
        case PciDevice1425::DEVICE_450A: return "DEVICE_450A";
        case PciDevice1425::DEVICE_450B: return "DEVICE_450B";
        case PciDevice1425::DEVICE_450C: return "DEVICE_450C";
        case PciDevice1425::DEVICE_450D: return "DEVICE_450D";
        case PciDevice1425::DEVICE_450E: return "DEVICE_450E";
        case PciDevice1425::DEVICE_450F: return "DEVICE_450F";
        case PciDevice1425::DEVICE_4580: return "DEVICE_4580";
        case PciDevice1425::DEVICE_4581: return "DEVICE_4581";
        case PciDevice1425::DEVICE_4582: return "DEVICE_4582";
        case PciDevice1425::DEVICE_4583: return "DEVICE_4583";
        case PciDevice1425::DEVICE_4584: return "DEVICE_4584";
        case PciDevice1425::DEVICE_4585: return "DEVICE_4585";
        case PciDevice1425::DEVICE_4586: return "DEVICE_4586";
        case PciDevice1425::DEVICE_4587: return "DEVICE_4587";
        case PciDevice1425::DEVICE_4588: return "DEVICE_4588";
        case PciDevice1425::DEVICE_4601: return "DEVICE_4601";
        case PciDevice1425::DEVICE_4602: return "DEVICE_4602";
        case PciDevice1425::DEVICE_4603: return "DEVICE_4603";
        case PciDevice1425::DEVICE_4604: return "DEVICE_4604";
        case PciDevice1425::DEVICE_4605: return "DEVICE_4605";
        case PciDevice1425::DEVICE_4606: return "DEVICE_4606";
        case PciDevice1425::DEVICE_4607: return "DEVICE_4607";
        case PciDevice1425::DEVICE_4608: return "DEVICE_4608";
        case PciDevice1425::DEVICE_4609: return "DEVICE_4609";
        case PciDevice1425::DEVICE_460A: return "DEVICE_460A";
        case PciDevice1425::DEVICE_460B: return "DEVICE_460B";
        case PciDevice1425::DEVICE_460C: return "DEVICE_460C";
        case PciDevice1425::DEVICE_460D: return "DEVICE_460D";
        case PciDevice1425::DEVICE_460E: return "DEVICE_460E";
        case PciDevice1425::DEVICE_460F: return "DEVICE_460F";
        case PciDevice1425::DEVICE_4680: return "DEVICE_4680";
        case PciDevice1425::DEVICE_4681: return "DEVICE_4681";
        case PciDevice1425::DEVICE_4682: return "DEVICE_4682";
        case PciDevice1425::DEVICE_4683: return "DEVICE_4683";
        case PciDevice1425::DEVICE_4684: return "DEVICE_4684";
        case PciDevice1425::DEVICE_4685: return "DEVICE_4685";
        case PciDevice1425::DEVICE_4686: return "DEVICE_4686";
        case PciDevice1425::DEVICE_4687: return "DEVICE_4687";
        case PciDevice1425::DEVICE_4688: return "DEVICE_4688";
        case PciDevice1425::DEVICE_4701: return "DEVICE_4701";
        case PciDevice1425::DEVICE_4702: return "DEVICE_4702";
        case PciDevice1425::DEVICE_4703: return "DEVICE_4703";
        case PciDevice1425::DEVICE_4704: return "DEVICE_4704";
        case PciDevice1425::DEVICE_4705: return "DEVICE_4705";
        case PciDevice1425::DEVICE_4706: return "DEVICE_4706";
        case PciDevice1425::DEVICE_4707: return "DEVICE_4707";
        case PciDevice1425::DEVICE_4708: return "DEVICE_4708";
        case PciDevice1425::DEVICE_4709: return "DEVICE_4709";
        case PciDevice1425::DEVICE_470A: return "DEVICE_470A";
        case PciDevice1425::DEVICE_470B: return "DEVICE_470B";
        case PciDevice1425::DEVICE_470C: return "DEVICE_470C";
        case PciDevice1425::DEVICE_470D: return "DEVICE_470D";
        case PciDevice1425::DEVICE_470E: return "DEVICE_470E";
        case PciDevice1425::DEVICE_470F: return "DEVICE_470F";
        case PciDevice1425::DEVICE_4780: return "DEVICE_4780";
        case PciDevice1425::DEVICE_4781: return "DEVICE_4781";
        case PciDevice1425::DEVICE_4782: return "DEVICE_4782";
        case PciDevice1425::DEVICE_4783: return "DEVICE_4783";
        case PciDevice1425::DEVICE_4784: return "DEVICE_4784";
        case PciDevice1425::DEVICE_4785: return "DEVICE_4785";
        case PciDevice1425::DEVICE_4786: return "DEVICE_4786";
        case PciDevice1425::DEVICE_4787: return "DEVICE_4787";
        case PciDevice1425::DEVICE_4788: return "DEVICE_4788";
        case PciDevice1425::DEVICE_4801: return "DEVICE_4801";
        case PciDevice1425::DEVICE_4802: return "DEVICE_4802";
        case PciDevice1425::DEVICE_4803: return "DEVICE_4803";
        case PciDevice1425::DEVICE_4804: return "DEVICE_4804";
        case PciDevice1425::DEVICE_4805: return "DEVICE_4805";
        case PciDevice1425::DEVICE_4806: return "DEVICE_4806";
        case PciDevice1425::DEVICE_4807: return "DEVICE_4807";
        case PciDevice1425::DEVICE_4808: return "DEVICE_4808";
        case PciDevice1425::DEVICE_4809: return "DEVICE_4809";
        case PciDevice1425::DEVICE_480A: return "DEVICE_480A";
        case PciDevice1425::DEVICE_480B: return "DEVICE_480B";
        case PciDevice1425::DEVICE_480C: return "DEVICE_480C";
        case PciDevice1425::DEVICE_480D: return "DEVICE_480D";
        case PciDevice1425::DEVICE_480E: return "DEVICE_480E";
        case PciDevice1425::DEVICE_480F: return "DEVICE_480F";
        case PciDevice1425::DEVICE_4880: return "DEVICE_4880";
        case PciDevice1425::DEVICE_4881: return "DEVICE_4881";
        case PciDevice1425::DEVICE_4882: return "DEVICE_4882";
        case PciDevice1425::DEVICE_4883: return "DEVICE_4883";
        case PciDevice1425::DEVICE_4884: return "DEVICE_4884";
        case PciDevice1425::DEVICE_4885: return "DEVICE_4885";
        case PciDevice1425::DEVICE_4886: return "DEVICE_4886";
        case PciDevice1425::DEVICE_4887: return "DEVICE_4887";
        case PciDevice1425::DEVICE_4888: return "DEVICE_4888";
        case PciDevice1425::DEVICE_5001: return "DEVICE_5001";
        case PciDevice1425::DEVICE_5002: return "DEVICE_5002";
        case PciDevice1425::DEVICE_5003: return "DEVICE_5003";
        case PciDevice1425::DEVICE_5004: return "DEVICE_5004";
        case PciDevice1425::DEVICE_5005: return "DEVICE_5005";
        case PciDevice1425::DEVICE_5006: return "DEVICE_5006";
        case PciDevice1425::DEVICE_5007: return "DEVICE_5007";
        case PciDevice1425::DEVICE_5008: return "DEVICE_5008";
        case PciDevice1425::DEVICE_5009: return "DEVICE_5009";
        case PciDevice1425::DEVICE_500A: return "DEVICE_500A";
        case PciDevice1425::DEVICE_500B: return "DEVICE_500B";
        case PciDevice1425::DEVICE_500C: return "DEVICE_500C";
        case PciDevice1425::DEVICE_500D: return "DEVICE_500D";
        case PciDevice1425::DEVICE_500E: return "DEVICE_500E";
        case PciDevice1425::DEVICE_500F: return "DEVICE_500F";
        case PciDevice1425::DEVICE_5010: return "DEVICE_5010";
        case PciDevice1425::DEVICE_5011: return "DEVICE_5011";
        case PciDevice1425::DEVICE_5012: return "DEVICE_5012";
        case PciDevice1425::DEVICE_5013: return "DEVICE_5013";
        case PciDevice1425::DEVICE_5014: return "DEVICE_5014";
        case PciDevice1425::DEVICE_5015: return "DEVICE_5015";
        case PciDevice1425::DEVICE_5016: return "DEVICE_5016";
        case PciDevice1425::DEVICE_5017: return "DEVICE_5017";
        case PciDevice1425::DEVICE_5018: return "DEVICE_5018";
        case PciDevice1425::DEVICE_5019: return "DEVICE_5019";
        case PciDevice1425::DEVICE_501A: return "DEVICE_501A";
        case PciDevice1425::DEVICE_501B: return "DEVICE_501B";
        case PciDevice1425::DEVICE_5080: return "DEVICE_5080";
        case PciDevice1425::DEVICE_5081: return "DEVICE_5081";
        case PciDevice1425::DEVICE_5082: return "DEVICE_5082";
        case PciDevice1425::DEVICE_5083: return "DEVICE_5083";
        case PciDevice1425::DEVICE_5084: return "DEVICE_5084";
        case PciDevice1425::DEVICE_5085: return "DEVICE_5085";
        case PciDevice1425::DEVICE_5086: return "DEVICE_5086";
        case PciDevice1425::DEVICE_5087: return "DEVICE_5087";
        case PciDevice1425::DEVICE_5088: return "DEVICE_5088";
        case PciDevice1425::DEVICE_5089: return "DEVICE_5089";
        case PciDevice1425::DEVICE_5090: return "DEVICE_5090";
        case PciDevice1425::DEVICE_5091: return "DEVICE_5091";
        case PciDevice1425::DEVICE_5092: return "DEVICE_5092";
        case PciDevice1425::DEVICE_5093: return "DEVICE_5093";
        case PciDevice1425::DEVICE_5094: return "DEVICE_5094";
        case PciDevice1425::DEVICE_5095: return "DEVICE_5095";
        case PciDevice1425::DEVICE_5096: return "DEVICE_5096";
        case PciDevice1425::DEVICE_5097: return "DEVICE_5097";
        case PciDevice1425::DEVICE_5098: return "DEVICE_5098";
        case PciDevice1425::DEVICE_5099: return "DEVICE_5099";
        case PciDevice1425::DEVICE_509A: return "DEVICE_509A";
        case PciDevice1425::DEVICE_509B: return "DEVICE_509B";
        case PciDevice1425::DEVICE_509C: return "DEVICE_509C";
        case PciDevice1425::DEVICE_509D: return "DEVICE_509D";
        case PciDevice1425::DEVICE_509E: return "DEVICE_509E";
        case PciDevice1425::DEVICE_509F: return "DEVICE_509F";
        case PciDevice1425::DEVICE_50A0: return "DEVICE_50A0";
        case PciDevice1425::DEVICE_50A1: return "DEVICE_50A1";
        case PciDevice1425::DEVICE_50A2: return "DEVICE_50A2";
        case PciDevice1425::DEVICE_50A3: return "DEVICE_50A3";
        case PciDevice1425::DEVICE_50A4: return "DEVICE_50A4";
        case PciDevice1425::DEVICE_50A5: return "DEVICE_50A5";
        case PciDevice1425::DEVICE_50A6: return "DEVICE_50A6";
        case PciDevice1425::DEVICE_50A7: return "DEVICE_50A7";
        case PciDevice1425::DEVICE_50A8: return "DEVICE_50A8";
        case PciDevice1425::DEVICE_50A9: return "DEVICE_50A9";
        case PciDevice1425::DEVICE_50AA: return "DEVICE_50AA";
        case PciDevice1425::DEVICE_50AB: return "DEVICE_50AB";
        case PciDevice1425::DEVICE_50AC: return "DEVICE_50AC";
        case PciDevice1425::DEVICE_50AD: return "DEVICE_50AD";
        case PciDevice1425::DEVICE_50AE: return "DEVICE_50AE";
        case PciDevice1425::DEVICE_50AF: return "DEVICE_50AF";
        case PciDevice1425::DEVICE_50B0: return "DEVICE_50B0";
        case PciDevice1425::DEVICE_5401: return "DEVICE_5401";
        case PciDevice1425::DEVICE_5402: return "DEVICE_5402";
        case PciDevice1425::DEVICE_5403: return "DEVICE_5403";
        case PciDevice1425::DEVICE_5404: return "DEVICE_5404";
        case PciDevice1425::DEVICE_5405: return "DEVICE_5405";
        case PciDevice1425::DEVICE_5406: return "DEVICE_5406";
        case PciDevice1425::DEVICE_5407: return "DEVICE_5407";
        case PciDevice1425::DEVICE_5408: return "DEVICE_5408";
        case PciDevice1425::DEVICE_5409: return "DEVICE_5409";
        case PciDevice1425::DEVICE_540A: return "DEVICE_540A";
        case PciDevice1425::DEVICE_540B: return "DEVICE_540B";
        case PciDevice1425::DEVICE_540C: return "DEVICE_540C";
        case PciDevice1425::DEVICE_540D: return "DEVICE_540D";
        case PciDevice1425::DEVICE_540E: return "DEVICE_540E";
        case PciDevice1425::DEVICE_540F: return "DEVICE_540F";
        case PciDevice1425::DEVICE_5410: return "DEVICE_5410";
        case PciDevice1425::DEVICE_5411: return "DEVICE_5411";
        case PciDevice1425::DEVICE_5412: return "DEVICE_5412";
        case PciDevice1425::DEVICE_5413: return "DEVICE_5413";
        case PciDevice1425::DEVICE_5414: return "DEVICE_5414";
        case PciDevice1425::DEVICE_5415: return "DEVICE_5415";
        case PciDevice1425::DEVICE_5416: return "DEVICE_5416";
        case PciDevice1425::DEVICE_5417: return "DEVICE_5417";
        case PciDevice1425::DEVICE_5418: return "DEVICE_5418";
        case PciDevice1425::DEVICE_5419: return "DEVICE_5419";
        case PciDevice1425::DEVICE_541A: return "DEVICE_541A";
        case PciDevice1425::DEVICE_541B: return "DEVICE_541B";
        case PciDevice1425::DEVICE_5480: return "DEVICE_5480";
        case PciDevice1425::DEVICE_5481: return "DEVICE_5481";
        case PciDevice1425::DEVICE_5482: return "DEVICE_5482";
        case PciDevice1425::DEVICE_5483: return "DEVICE_5483";
        case PciDevice1425::DEVICE_5484: return "DEVICE_5484";
        case PciDevice1425::DEVICE_5485: return "DEVICE_5485";
        case PciDevice1425::DEVICE_5486: return "DEVICE_5486";
        case PciDevice1425::DEVICE_5487: return "DEVICE_5487";
        case PciDevice1425::DEVICE_5488: return "DEVICE_5488";
        case PciDevice1425::DEVICE_5489: return "DEVICE_5489";
        case PciDevice1425::DEVICE_5490: return "DEVICE_5490";
        case PciDevice1425::DEVICE_5491: return "DEVICE_5491";
        case PciDevice1425::DEVICE_5492: return "DEVICE_5492";
        case PciDevice1425::DEVICE_5493: return "DEVICE_5493";
        case PciDevice1425::DEVICE_5494: return "DEVICE_5494";
        case PciDevice1425::DEVICE_5495: return "DEVICE_5495";
        case PciDevice1425::DEVICE_5496: return "DEVICE_5496";
        case PciDevice1425::DEVICE_5497: return "DEVICE_5497";
        case PciDevice1425::DEVICE_5498: return "DEVICE_5498";
        case PciDevice1425::DEVICE_5499: return "DEVICE_5499";
        case PciDevice1425::DEVICE_549A: return "DEVICE_549A";
        case PciDevice1425::DEVICE_549B: return "DEVICE_549B";
        case PciDevice1425::DEVICE_549C: return "DEVICE_549C";
        case PciDevice1425::DEVICE_549D: return "DEVICE_549D";
        case PciDevice1425::DEVICE_549E: return "DEVICE_549E";
        case PciDevice1425::DEVICE_549F: return "DEVICE_549F";
        case PciDevice1425::DEVICE_54A0: return "DEVICE_54A0";
        case PciDevice1425::DEVICE_54A1: return "DEVICE_54A1";
        case PciDevice1425::DEVICE_54A2: return "DEVICE_54A2";
        case PciDevice1425::DEVICE_54A3: return "DEVICE_54A3";
        case PciDevice1425::DEVICE_54A4: return "DEVICE_54A4";
        case PciDevice1425::DEVICE_54A5: return "DEVICE_54A5";
        case PciDevice1425::DEVICE_54A6: return "DEVICE_54A6";
        case PciDevice1425::DEVICE_54A7: return "DEVICE_54A7";
        case PciDevice1425::DEVICE_54A8: return "DEVICE_54A8";
        case PciDevice1425::DEVICE_54A9: return "DEVICE_54A9";
        case PciDevice1425::DEVICE_54AA: return "DEVICE_54AA";
        case PciDevice1425::DEVICE_54AB: return "DEVICE_54AB";
        case PciDevice1425::DEVICE_54AC: return "DEVICE_54AC";
        case PciDevice1425::DEVICE_54AD: return "DEVICE_54AD";
        case PciDevice1425::DEVICE_54AE: return "DEVICE_54AE";
        case PciDevice1425::DEVICE_54AF: return "DEVICE_54AF";
        case PciDevice1425::DEVICE_54B0: return "DEVICE_54B0";
        case PciDevice1425::DEVICE_5501: return "DEVICE_5501";
        case PciDevice1425::DEVICE_5502: return "DEVICE_5502";
        case PciDevice1425::DEVICE_5503: return "DEVICE_5503";
        case PciDevice1425::DEVICE_5504: return "DEVICE_5504";
        case PciDevice1425::DEVICE_5505: return "DEVICE_5505";
        case PciDevice1425::DEVICE_5506: return "DEVICE_5506";
        case PciDevice1425::DEVICE_5507: return "DEVICE_5507";
        case PciDevice1425::DEVICE_5508: return "DEVICE_5508";
        case PciDevice1425::DEVICE_5509: return "DEVICE_5509";
        case PciDevice1425::DEVICE_550A: return "DEVICE_550A";
        case PciDevice1425::DEVICE_550B: return "DEVICE_550B";
        case PciDevice1425::DEVICE_550C: return "DEVICE_550C";
        case PciDevice1425::DEVICE_550D: return "DEVICE_550D";
        case PciDevice1425::DEVICE_550E: return "DEVICE_550E";
        case PciDevice1425::DEVICE_550F: return "DEVICE_550F";
        case PciDevice1425::DEVICE_5510: return "DEVICE_5510";
        case PciDevice1425::DEVICE_5511: return "DEVICE_5511";
        case PciDevice1425::DEVICE_5512: return "DEVICE_5512";
        case PciDevice1425::DEVICE_5513: return "DEVICE_5513";
        case PciDevice1425::DEVICE_5514: return "DEVICE_5514";
        case PciDevice1425::DEVICE_5515: return "DEVICE_5515";
        case PciDevice1425::DEVICE_5516: return "DEVICE_5516";
        case PciDevice1425::DEVICE_5517: return "DEVICE_5517";
        case PciDevice1425::DEVICE_5518: return "DEVICE_5518";
        case PciDevice1425::DEVICE_5519: return "DEVICE_5519";
        case PciDevice1425::DEVICE_551A: return "DEVICE_551A";
        case PciDevice1425::DEVICE_551B: return "DEVICE_551B";
        case PciDevice1425::DEVICE_5580: return "DEVICE_5580";
        case PciDevice1425::DEVICE_5581: return "DEVICE_5581";
        case PciDevice1425::DEVICE_5582: return "DEVICE_5582";
        case PciDevice1425::DEVICE_5583: return "DEVICE_5583";
        case PciDevice1425::DEVICE_5584: return "DEVICE_5584";
        case PciDevice1425::DEVICE_5585: return "DEVICE_5585";
        case PciDevice1425::DEVICE_5586: return "DEVICE_5586";
        case PciDevice1425::DEVICE_5587: return "DEVICE_5587";
        case PciDevice1425::DEVICE_5588: return "DEVICE_5588";
        case PciDevice1425::DEVICE_5589: return "DEVICE_5589";
        case PciDevice1425::DEVICE_5590: return "DEVICE_5590";
        case PciDevice1425::DEVICE_5591: return "DEVICE_5591";
        case PciDevice1425::DEVICE_5592: return "DEVICE_5592";
        case PciDevice1425::DEVICE_5593: return "DEVICE_5593";
        case PciDevice1425::DEVICE_5594: return "DEVICE_5594";
        case PciDevice1425::DEVICE_5595: return "DEVICE_5595";
        case PciDevice1425::DEVICE_5596: return "DEVICE_5596";
        case PciDevice1425::DEVICE_5597: return "DEVICE_5597";
        case PciDevice1425::DEVICE_5598: return "DEVICE_5598";
        case PciDevice1425::DEVICE_5599: return "DEVICE_5599";
        case PciDevice1425::DEVICE_559A: return "DEVICE_559A";
        case PciDevice1425::DEVICE_559B: return "DEVICE_559B";
        case PciDevice1425::DEVICE_559C: return "DEVICE_559C";
        case PciDevice1425::DEVICE_559D: return "DEVICE_559D";
        case PciDevice1425::DEVICE_559E: return "DEVICE_559E";
        case PciDevice1425::DEVICE_559F: return "DEVICE_559F";
        case PciDevice1425::DEVICE_55A0: return "DEVICE_55A0";
        case PciDevice1425::DEVICE_55A1: return "DEVICE_55A1";
        case PciDevice1425::DEVICE_55A2: return "DEVICE_55A2";
        case PciDevice1425::DEVICE_55A3: return "DEVICE_55A3";
        case PciDevice1425::DEVICE_55A4: return "DEVICE_55A4";
        case PciDevice1425::DEVICE_55A5: return "DEVICE_55A5";
        case PciDevice1425::DEVICE_55A6: return "DEVICE_55A6";
        case PciDevice1425::DEVICE_55A7: return "DEVICE_55A7";
        case PciDevice1425::DEVICE_55A8: return "DEVICE_55A8";
        case PciDevice1425::DEVICE_55A9: return "DEVICE_55A9";
        case PciDevice1425::DEVICE_55AA: return "DEVICE_55AA";
        case PciDevice1425::DEVICE_55AB: return "DEVICE_55AB";
        case PciDevice1425::DEVICE_55AC: return "DEVICE_55AC";
        case PciDevice1425::DEVICE_55AD: return "DEVICE_55AD";
        case PciDevice1425::DEVICE_55AE: return "DEVICE_55AE";
        case PciDevice1425::DEVICE_55AF: return "DEVICE_55AF";
        case PciDevice1425::DEVICE_55B0: return "DEVICE_55B0";
        case PciDevice1425::DEVICE_5601: return "DEVICE_5601";
        case PciDevice1425::DEVICE_5602: return "DEVICE_5602";
        case PciDevice1425::DEVICE_5603: return "DEVICE_5603";
        case PciDevice1425::DEVICE_5604: return "DEVICE_5604";
        case PciDevice1425::DEVICE_5605: return "DEVICE_5605";
        case PciDevice1425::DEVICE_5606: return "DEVICE_5606";
        case PciDevice1425::DEVICE_5607: return "DEVICE_5607";
        case PciDevice1425::DEVICE_5608: return "DEVICE_5608";
        case PciDevice1425::DEVICE_5609: return "DEVICE_5609";
        case PciDevice1425::DEVICE_560A: return "DEVICE_560A";
        case PciDevice1425::DEVICE_560B: return "DEVICE_560B";
        case PciDevice1425::DEVICE_560C: return "DEVICE_560C";
        case PciDevice1425::DEVICE_560D: return "DEVICE_560D";
        case PciDevice1425::DEVICE_560E: return "DEVICE_560E";
        case PciDevice1425::DEVICE_560F: return "DEVICE_560F";
        case PciDevice1425::DEVICE_5610: return "DEVICE_5610";
        case PciDevice1425::DEVICE_5611: return "DEVICE_5611";
        case PciDevice1425::DEVICE_5612: return "DEVICE_5612";
        case PciDevice1425::DEVICE_5613: return "DEVICE_5613";
        case PciDevice1425::DEVICE_5614: return "DEVICE_5614";
        case PciDevice1425::DEVICE_5615: return "DEVICE_5615";
        case PciDevice1425::DEVICE_5616: return "DEVICE_5616";
        case PciDevice1425::DEVICE_5617: return "DEVICE_5617";
        case PciDevice1425::DEVICE_5618: return "DEVICE_5618";
        case PciDevice1425::DEVICE_5619: return "DEVICE_5619";
        case PciDevice1425::DEVICE_561A: return "DEVICE_561A";
        case PciDevice1425::DEVICE_561B: return "DEVICE_561B";
        case PciDevice1425::DEVICE_5680: return "DEVICE_5680";
        case PciDevice1425::DEVICE_5681: return "DEVICE_5681";
        case PciDevice1425::DEVICE_5682: return "DEVICE_5682";
        case PciDevice1425::DEVICE_5683: return "DEVICE_5683";
        case PciDevice1425::DEVICE_5684: return "DEVICE_5684";
        case PciDevice1425::DEVICE_5685: return "DEVICE_5685";
        case PciDevice1425::DEVICE_5686: return "DEVICE_5686";
        case PciDevice1425::DEVICE_5687: return "DEVICE_5687";
        case PciDevice1425::DEVICE_5688: return "DEVICE_5688";
        case PciDevice1425::DEVICE_5689: return "DEVICE_5689";
        case PciDevice1425::DEVICE_5690: return "DEVICE_5690";
        case PciDevice1425::DEVICE_5691: return "DEVICE_5691";
        case PciDevice1425::DEVICE_5692: return "DEVICE_5692";
        case PciDevice1425::DEVICE_5693: return "DEVICE_5693";
        case PciDevice1425::DEVICE_5694: return "DEVICE_5694";
        case PciDevice1425::DEVICE_5695: return "DEVICE_5695";
        case PciDevice1425::DEVICE_5696: return "DEVICE_5696";
        case PciDevice1425::DEVICE_5697: return "DEVICE_5697";
        case PciDevice1425::DEVICE_5698: return "DEVICE_5698";
        case PciDevice1425::DEVICE_5699: return "DEVICE_5699";
        case PciDevice1425::DEVICE_569A: return "DEVICE_569A";
        case PciDevice1425::DEVICE_569B: return "DEVICE_569B";
        case PciDevice1425::DEVICE_569C: return "DEVICE_569C";
        case PciDevice1425::DEVICE_569D: return "DEVICE_569D";
        case PciDevice1425::DEVICE_569E: return "DEVICE_569E";
        case PciDevice1425::DEVICE_569F: return "DEVICE_569F";
        case PciDevice1425::DEVICE_56A0: return "DEVICE_56A0";
        case PciDevice1425::DEVICE_56A1: return "DEVICE_56A1";
        case PciDevice1425::DEVICE_56A2: return "DEVICE_56A2";
        case PciDevice1425::DEVICE_56A3: return "DEVICE_56A3";
        case PciDevice1425::DEVICE_56A4: return "DEVICE_56A4";
        case PciDevice1425::DEVICE_56A5: return "DEVICE_56A5";
        case PciDevice1425::DEVICE_56A6: return "DEVICE_56A6";
        case PciDevice1425::DEVICE_56A7: return "DEVICE_56A7";
        case PciDevice1425::DEVICE_56A8: return "DEVICE_56A8";
        case PciDevice1425::DEVICE_56A9: return "DEVICE_56A9";
        case PciDevice1425::DEVICE_56AA: return "DEVICE_56AA";
        case PciDevice1425::DEVICE_56AB: return "DEVICE_56AB";
        case PciDevice1425::DEVICE_56AC: return "DEVICE_56AC";
        case PciDevice1425::DEVICE_56AD: return "DEVICE_56AD";
        case PciDevice1425::DEVICE_56AE: return "DEVICE_56AE";
        case PciDevice1425::DEVICE_56AF: return "DEVICE_56AF";
        case PciDevice1425::DEVICE_56B0: return "DEVICE_56B0";
        case PciDevice1425::DEVICE_5701: return "DEVICE_5701";
        case PciDevice1425::DEVICE_5702: return "DEVICE_5702";
        case PciDevice1425::DEVICE_5703: return "DEVICE_5703";
        case PciDevice1425::DEVICE_5704: return "DEVICE_5704";
        case PciDevice1425::DEVICE_5705: return "DEVICE_5705";
        case PciDevice1425::DEVICE_5706: return "DEVICE_5706";
        case PciDevice1425::DEVICE_5707: return "DEVICE_5707";
        case PciDevice1425::DEVICE_5708: return "DEVICE_5708";
        case PciDevice1425::DEVICE_5709: return "DEVICE_5709";
        case PciDevice1425::DEVICE_570A: return "DEVICE_570A";
        case PciDevice1425::DEVICE_570B: return "DEVICE_570B";
        case PciDevice1425::DEVICE_570C: return "DEVICE_570C";
        case PciDevice1425::DEVICE_570D: return "DEVICE_570D";
        case PciDevice1425::DEVICE_570E: return "DEVICE_570E";
        case PciDevice1425::DEVICE_570F: return "DEVICE_570F";
        case PciDevice1425::DEVICE_5710: return "DEVICE_5710";
        case PciDevice1425::DEVICE_5711: return "DEVICE_5711";
        case PciDevice1425::DEVICE_5712: return "DEVICE_5712";
        case PciDevice1425::DEVICE_5713: return "DEVICE_5713";
        case PciDevice1425::DEVICE_5714: return "DEVICE_5714";
        case PciDevice1425::DEVICE_5715: return "DEVICE_5715";
        case PciDevice1425::DEVICE_5780: return "DEVICE_5780";
        case PciDevice1425::DEVICE_5781: return "DEVICE_5781";
        case PciDevice1425::DEVICE_5782: return "DEVICE_5782";
        case PciDevice1425::DEVICE_5783: return "DEVICE_5783";
        case PciDevice1425::DEVICE_5784: return "DEVICE_5784";
        case PciDevice1425::DEVICE_5785: return "DEVICE_5785";
        case PciDevice1425::DEVICE_5786: return "DEVICE_5786";
        case PciDevice1425::DEVICE_5787: return "DEVICE_5787";
        case PciDevice1425::DEVICE_5788: return "DEVICE_5788";
        case PciDevice1425::DEVICE_5789: return "DEVICE_5789";
        case PciDevice1425::DEVICE_5790: return "DEVICE_5790";
        case PciDevice1425::DEVICE_5791: return "DEVICE_5791";
        case PciDevice1425::DEVICE_5792: return "DEVICE_5792";
        case PciDevice1425::DEVICE_5793: return "DEVICE_5793";
        case PciDevice1425::DEVICE_5794: return "DEVICE_5794";
        case PciDevice1425::DEVICE_5795: return "DEVICE_5795";
        case PciDevice1425::DEVICE_5796: return "DEVICE_5796";
        case PciDevice1425::DEVICE_5797: return "DEVICE_5797";
        case PciDevice1425::DEVICE_5801: return "DEVICE_5801";
        case PciDevice1425::DEVICE_5802: return "DEVICE_5802";
        case PciDevice1425::DEVICE_5803: return "DEVICE_5803";
        case PciDevice1425::DEVICE_5804: return "DEVICE_5804";
        case PciDevice1425::DEVICE_5805: return "DEVICE_5805";
        case PciDevice1425::DEVICE_5806: return "DEVICE_5806";
        case PciDevice1425::DEVICE_5807: return "DEVICE_5807";
        case PciDevice1425::DEVICE_5808: return "DEVICE_5808";
        case PciDevice1425::DEVICE_5809: return "DEVICE_5809";
        case PciDevice1425::DEVICE_580A: return "DEVICE_580A";
        case PciDevice1425::DEVICE_580B: return "DEVICE_580B";
        case PciDevice1425::DEVICE_580C: return "DEVICE_580C";
        case PciDevice1425::DEVICE_580D: return "DEVICE_580D";
        case PciDevice1425::DEVICE_580E: return "DEVICE_580E";
        case PciDevice1425::DEVICE_580F: return "DEVICE_580F";
        case PciDevice1425::DEVICE_5810: return "DEVICE_5810";
        case PciDevice1425::DEVICE_5811: return "DEVICE_5811";
        case PciDevice1425::DEVICE_5812: return "DEVICE_5812";
        case PciDevice1425::DEVICE_5813: return "DEVICE_5813";
        case PciDevice1425::DEVICE_5814: return "DEVICE_5814";
        case PciDevice1425::DEVICE_5815: return "DEVICE_5815";
        case PciDevice1425::DEVICE_5816: return "DEVICE_5816";
        case PciDevice1425::DEVICE_5817: return "DEVICE_5817";
        case PciDevice1425::DEVICE_5818: return "DEVICE_5818";
        case PciDevice1425::DEVICE_5819: return "DEVICE_5819";
        case PciDevice1425::DEVICE_581A: return "DEVICE_581A";
        case PciDevice1425::DEVICE_581B: return "DEVICE_581B";
        case PciDevice1425::DEVICE_5880: return "DEVICE_5880";
        case PciDevice1425::DEVICE_5881: return "DEVICE_5881";
        case PciDevice1425::DEVICE_5882: return "DEVICE_5882";
        case PciDevice1425::DEVICE_5883: return "DEVICE_5883";
        case PciDevice1425::DEVICE_5884: return "DEVICE_5884";
        case PciDevice1425::DEVICE_5885: return "DEVICE_5885";
        case PciDevice1425::DEVICE_5886: return "DEVICE_5886";
        case PciDevice1425::DEVICE_5887: return "DEVICE_5887";
        case PciDevice1425::DEVICE_5888: return "DEVICE_5888";
        case PciDevice1425::DEVICE_5889: return "DEVICE_5889";
        case PciDevice1425::DEVICE_5890: return "DEVICE_5890";
        case PciDevice1425::DEVICE_5891: return "DEVICE_5891";
        case PciDevice1425::DEVICE_5892: return "DEVICE_5892";
        case PciDevice1425::DEVICE_5893: return "DEVICE_5893";
        case PciDevice1425::DEVICE_5894: return "DEVICE_5894";
        case PciDevice1425::DEVICE_5895: return "DEVICE_5895";
        case PciDevice1425::DEVICE_5896: return "DEVICE_5896";
        case PciDevice1425::DEVICE_5897: return "DEVICE_5897";
        case PciDevice1425::DEVICE_5898: return "DEVICE_5898";
        case PciDevice1425::DEVICE_5899: return "DEVICE_5899";
        case PciDevice1425::DEVICE_589A: return "DEVICE_589A";
        case PciDevice1425::DEVICE_589B: return "DEVICE_589B";
        case PciDevice1425::DEVICE_589C: return "DEVICE_589C";
        case PciDevice1425::DEVICE_589D: return "DEVICE_589D";
        case PciDevice1425::DEVICE_589E: return "DEVICE_589E";
        case PciDevice1425::DEVICE_589F: return "DEVICE_589F";
        case PciDevice1425::DEVICE_58A0: return "DEVICE_58A0";
        case PciDevice1425::DEVICE_58A1: return "DEVICE_58A1";
        case PciDevice1425::DEVICE_58A2: return "DEVICE_58A2";
        case PciDevice1425::DEVICE_58A3: return "DEVICE_58A3";
        case PciDevice1425::DEVICE_58A4: return "DEVICE_58A4";
        case PciDevice1425::DEVICE_58A5: return "DEVICE_58A5";
        case PciDevice1425::DEVICE_58A6: return "DEVICE_58A6";
        case PciDevice1425::DEVICE_58A7: return "DEVICE_58A7";
        case PciDevice1425::DEVICE_58A8: return "DEVICE_58A8";
        case PciDevice1425::DEVICE_58A9: return "DEVICE_58A9";
        case PciDevice1425::DEVICE_58AA: return "DEVICE_58AA";
        case PciDevice1425::DEVICE_58AB: return "DEVICE_58AB";
        case PciDevice1425::DEVICE_58AC: return "DEVICE_58AC";
        case PciDevice1425::DEVICE_58AD: return "DEVICE_58AD";
        case PciDevice1425::DEVICE_58AE: return "DEVICE_58AE";
        case PciDevice1425::DEVICE_58AF: return "DEVICE_58AF";
        case PciDevice1425::DEVICE_58B0: return "DEVICE_58B0";
        case PciDevice1425::DEVICE_6001: return "DEVICE_6001";
        case PciDevice1425::DEVICE_6002: return "DEVICE_6002";
        case PciDevice1425::DEVICE_6003: return "DEVICE_6003";
        case PciDevice1425::DEVICE_6004: return "DEVICE_6004";
        case PciDevice1425::DEVICE_6005: return "DEVICE_6005";
        case PciDevice1425::DEVICE_6006: return "DEVICE_6006";
        case PciDevice1425::DEVICE_6007: return "DEVICE_6007";
        case PciDevice1425::DEVICE_6008: return "DEVICE_6008";
        case PciDevice1425::DEVICE_6009: return "DEVICE_6009";
        case PciDevice1425::DEVICE_600D: return "DEVICE_600D";
        case PciDevice1425::DEVICE_6011: return "DEVICE_6011";
        case PciDevice1425::DEVICE_6014: return "DEVICE_6014";
        case PciDevice1425::DEVICE_6015: return "DEVICE_6015";
        case PciDevice1425::DEVICE_6080: return "DEVICE_6080";
        case PciDevice1425::DEVICE_6081: return "DEVICE_6081";
        case PciDevice1425::DEVICE_6082: return "DEVICE_6082";
        case PciDevice1425::DEVICE_6083: return "DEVICE_6083";
        case PciDevice1425::DEVICE_6084: return "DEVICE_6084";
        case PciDevice1425::DEVICE_6085: return "DEVICE_6085";
        case PciDevice1425::DEVICE_6086: return "DEVICE_6086";
        case PciDevice1425::DEVICE_6087: return "DEVICE_6087";
        case PciDevice1425::DEVICE_6088: return "DEVICE_6088";
        case PciDevice1425::DEVICE_6089: return "DEVICE_6089";
        case PciDevice1425::DEVICE_608A: return "DEVICE_608A";
        case PciDevice1425::DEVICE_6401: return "DEVICE_6401";
        case PciDevice1425::DEVICE_6402: return "DEVICE_6402";
        case PciDevice1425::DEVICE_6403: return "DEVICE_6403";
        case PciDevice1425::DEVICE_6404: return "DEVICE_6404";
        case PciDevice1425::DEVICE_6405: return "DEVICE_6405";
        case PciDevice1425::DEVICE_6406: return "DEVICE_6406";
        case PciDevice1425::DEVICE_6407: return "DEVICE_6407";
        case PciDevice1425::DEVICE_6408: return "DEVICE_6408";
        case PciDevice1425::DEVICE_6409: return "DEVICE_6409";
        case PciDevice1425::DEVICE_640D: return "DEVICE_640D";
        case PciDevice1425::DEVICE_6411: return "DEVICE_6411";
        case PciDevice1425::DEVICE_6414: return "DEVICE_6414";
        case PciDevice1425::DEVICE_6415: return "DEVICE_6415";
        case PciDevice1425::DEVICE_6480: return "DEVICE_6480";
        case PciDevice1425::DEVICE_6481: return "DEVICE_6481";
        case PciDevice1425::DEVICE_6482: return "DEVICE_6482";
        case PciDevice1425::DEVICE_6483: return "DEVICE_6483";
        case PciDevice1425::DEVICE_6484: return "DEVICE_6484";
        case PciDevice1425::DEVICE_6485: return "DEVICE_6485";
        case PciDevice1425::DEVICE_6486: return "DEVICE_6486";
        case PciDevice1425::DEVICE_6487: return "DEVICE_6487";
        case PciDevice1425::DEVICE_6488: return "DEVICE_6488";
        case PciDevice1425::DEVICE_6489: return "DEVICE_6489";
        case PciDevice1425::DEVICE_648A: return "DEVICE_648A";
        case PciDevice1425::DEVICE_6501: return "DEVICE_6501";
        case PciDevice1425::DEVICE_6502: return "DEVICE_6502";
        case PciDevice1425::DEVICE_6503: return "DEVICE_6503";
        case PciDevice1425::DEVICE_6504: return "DEVICE_6504";
        case PciDevice1425::DEVICE_6505: return "DEVICE_6505";
        case PciDevice1425::DEVICE_6506: return "DEVICE_6506";
        case PciDevice1425::DEVICE_6507: return "DEVICE_6507";
        case PciDevice1425::DEVICE_6508: return "DEVICE_6508";
        case PciDevice1425::DEVICE_6509: return "DEVICE_6509";
        case PciDevice1425::DEVICE_650D: return "DEVICE_650D";
        case PciDevice1425::DEVICE_6511: return "DEVICE_6511";
        case PciDevice1425::DEVICE_6514: return "DEVICE_6514";
        case PciDevice1425::DEVICE_6515: return "DEVICE_6515";
        case PciDevice1425::DEVICE_6580: return "DEVICE_6580";
        case PciDevice1425::DEVICE_6581: return "DEVICE_6581";
        case PciDevice1425::DEVICE_6582: return "DEVICE_6582";
        case PciDevice1425::DEVICE_6583: return "DEVICE_6583";
        case PciDevice1425::DEVICE_6584: return "DEVICE_6584";
        case PciDevice1425::DEVICE_6585: return "DEVICE_6585";
        case PciDevice1425::DEVICE_6586: return "DEVICE_6586";
        case PciDevice1425::DEVICE_6587: return "DEVICE_6587";
        case PciDevice1425::DEVICE_6588: return "DEVICE_6588";
        case PciDevice1425::DEVICE_6589: return "DEVICE_6589";
        case PciDevice1425::DEVICE_658A: return "DEVICE_658A";
        case PciDevice1425::DEVICE_6601: return "DEVICE_6601";
        case PciDevice1425::DEVICE_6602: return "DEVICE_6602";
        case PciDevice1425::DEVICE_6603: return "DEVICE_6603";
        case PciDevice1425::DEVICE_6604: return "DEVICE_6604";
        case PciDevice1425::DEVICE_6605: return "DEVICE_6605";
        case PciDevice1425::DEVICE_6606: return "DEVICE_6606";
        case PciDevice1425::DEVICE_6607: return "DEVICE_6607";
        case PciDevice1425::DEVICE_6608: return "DEVICE_6608";
        case PciDevice1425::DEVICE_6609: return "DEVICE_6609";
        case PciDevice1425::DEVICE_660D: return "DEVICE_660D";
        case PciDevice1425::DEVICE_6611: return "DEVICE_6611";
        case PciDevice1425::DEVICE_6614: return "DEVICE_6614";
        case PciDevice1425::DEVICE_6615: return "DEVICE_6615";
        case PciDevice1425::DEVICE_6680: return "DEVICE_6680";
        case PciDevice1425::DEVICE_6681: return "DEVICE_6681";
        case PciDevice1425::DEVICE_6682: return "DEVICE_6682";
        case PciDevice1425::DEVICE_6683: return "DEVICE_6683";
        case PciDevice1425::DEVICE_6684: return "DEVICE_6684";
        case PciDevice1425::DEVICE_6685: return "DEVICE_6685";
        case PciDevice1425::DEVICE_6686: return "DEVICE_6686";
        case PciDevice1425::DEVICE_6687: return "DEVICE_6687";
        case PciDevice1425::DEVICE_6688: return "DEVICE_6688";
        case PciDevice1425::DEVICE_6689: return "DEVICE_6689";
        case PciDevice1425::DEVICE_668A: return "DEVICE_668A";
        case PciDevice1425::DEVICE_6801: return "DEVICE_6801";
        case PciDevice1425::DEVICE_6802: return "DEVICE_6802";
        case PciDevice1425::DEVICE_6803: return "DEVICE_6803";
        case PciDevice1425::DEVICE_6804: return "DEVICE_6804";
        case PciDevice1425::DEVICE_6805: return "DEVICE_6805";
        case PciDevice1425::DEVICE_6806: return "DEVICE_6806";
        case PciDevice1425::DEVICE_6807: return "DEVICE_6807";
        case PciDevice1425::DEVICE_6808: return "DEVICE_6808";
        case PciDevice1425::DEVICE_6809: return "DEVICE_6809";
        case PciDevice1425::DEVICE_680D: return "DEVICE_680D";
        case PciDevice1425::DEVICE_6811: return "DEVICE_6811";
        case PciDevice1425::DEVICE_6814: return "DEVICE_6814";
        case PciDevice1425::DEVICE_6815: return "DEVICE_6815";
        case PciDevice1425::DEVICE_6880: return "DEVICE_6880";
        case PciDevice1425::DEVICE_6881: return "DEVICE_6881";
        case PciDevice1425::DEVICE_6882: return "DEVICE_6882";
        case PciDevice1425::DEVICE_6883: return "DEVICE_6883";
        case PciDevice1425::DEVICE_6884: return "DEVICE_6884";
        case PciDevice1425::DEVICE_6885: return "DEVICE_6885";
        case PciDevice1425::DEVICE_6886: return "DEVICE_6886";
        case PciDevice1425::DEVICE_6887: return "DEVICE_6887";
        case PciDevice1425::DEVICE_6888: return "DEVICE_6888";
        case PciDevice1425::DEVICE_6889: return "DEVICE_6889";
        case PciDevice1425::DEVICE_688A: return "DEVICE_688A";
        case PciDevice1425::DEVICE_A000: return "DEVICE_A000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1425 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1425 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1425::DEVICE_000B: return "T210 Protocol Engine";
        case PciDevice1425::DEVICE_000C: return "T204 Protocol Engine";
        case PciDevice1425::DEVICE_0022: return "10GbE Ethernet Adapter";
        case PciDevice1425::DEVICE_0030: return "T310 10GbE Single Port Adapter";
        case PciDevice1425::DEVICE_0031: return "T320 10GbE Dual Port Adapter";
        case PciDevice1425::DEVICE_0032: return "T302 1GbE Dual Port Adapter";
        case PciDevice1425::DEVICE_0033: return "T304 1GbE Quad Port Adapter";
        case PciDevice1425::DEVICE_0034: return "B320 10GbE Dual Port Adapter";
        case PciDevice1425::DEVICE_0035: return "S310-CR 10GbE Single Port Adapter";
        case PciDevice1425::DEVICE_0036: return "S320-LP-CR 10GbE Dual Port Adapter";
        case PciDevice1425::DEVICE_0037: return "N320-G2-CR 10GbE Dual Port Adapter";
        case PciDevice1425::DEVICE_4001: return "T420-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4002: return "T422-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4003: return "T440-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4004: return "T420-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4005: return "T440-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4006: return "T440-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4007: return "T420-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4008: return "T420-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4009: return "T420-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400A: return "T404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400B: return "B420-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400C: return "B404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400D: return "T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400E: return "T440-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_400F: return "T440 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4080: return "T480-4080 T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4081: return "T440F-4081 T440-FCoE Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4082: return "T420-4082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4083: return "T420X-4083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4084: return "T440-4084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4085: return "T420-4085 SFP+ Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4086: return "T440-4086 10Gbase-T Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4087: return "T440T-4087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4088: return "T440-4088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4401: return "T420-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4402: return "T422-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4403: return "T440-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4404: return "T420-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4405: return "T440-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4406: return "T440-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4407: return "T420-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4408: return "T420-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4409: return "T420-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440A: return "T404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440B: return "B420-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440C: return "B404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440D: return "T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440E: return "T440-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_440F: return "T440 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4480: return "T480-4080 T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4481: return "T440F-4081 T440-FCoE Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4482: return "T420-4082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4483: return "T420X-4083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4484: return "T440-4084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4485: return "T420-4085 SFP+ Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4486: return "T440-4086 10Gbase-T Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4487: return "T440T-4087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4488: return "T440-4088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4501: return "T420-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4502: return "T422-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4503: return "T440-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4504: return "T420-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4505: return "T440-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4506: return "T440-CH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4507: return "T420-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4508: return "T420-CX Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4509: return "T420-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450A: return "T404-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450B: return "B420-SR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450C: return "B404-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450D: return "T480 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450E: return "T440-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_450F: return "T440 [Amsterdam] Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4580: return "T480-4080 T480 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4581: return "T440F-4081 T440-FCoE Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4582: return "T420-4082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4583: return "T420X-4083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4584: return "T440-4084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4585: return "T420-4085 SFP+ Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4586: return "T440-4086 10Gbase-T Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4587: return "T440T-4087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4588: return "T440-4088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4601: return "T420-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4602: return "T422-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4603: return "T440-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4604: return "T420-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4605: return "T440-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4606: return "T440-CH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4607: return "T420-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4608: return "T420-CX Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4609: return "T420-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460A: return "T404-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460B: return "B420-SR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460C: return "B404-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460D: return "T480 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460E: return "T440-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_460F: return "T440 [Amsterdam] Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4680: return "T480-4080 T480 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4681: return "T440F-4081 T440-FCoE Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4682: return "T420-4082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4683: return "T420X-4083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4684: return "T440-4084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4685: return "T420-4085 SFP+ Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4686: return "T440-4086 10Gbase-T Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4687: return "T440T-4087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4688: return "T440-4088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_4701: return "T420-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4702: return "T422-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4703: return "T440-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4704: return "T420-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4705: return "T440-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4706: return "T440-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4707: return "T420-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4708: return "T420-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4709: return "T420-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470A: return "T404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470B: return "B420-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470C: return "B404-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470D: return "T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470E: return "T440-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_470F: return "T440 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4780: return "T480-4080 T480 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4781: return "T440F-4081 T440-FCoE Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4782: return "T420-4082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4783: return "T420X-4083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4784: return "T440-4084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4785: return "T420-4085 SFP+ Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4786: return "T440-4086 10Gbase-T Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4787: return "T440T-4087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4788: return "T440-4088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_4801: return "T420-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4802: return "T422-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4803: return "T440-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4804: return "T420-BCH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4805: return "T440-BCH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4806: return "T440-CH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4807: return "T420-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4808: return "T420-CX Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4809: return "T420-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480A: return "T404-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480B: return "B420-SR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480C: return "B404-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480D: return "T480 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480E: return "T440-LP-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_480F: return "T440 [Amsterdam] Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4880: return "T480-4080 T480 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4881: return "T440F-4081 T440-FCoE Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4882: return "T420-4082 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4883: return "T420X-4083 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4884: return "T440-4084 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4885: return "T420-4085 SFP+ Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4886: return "T440-4086 10Gbase-T Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4887: return "T440T-4087 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_4888: return "T440-4088 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5001: return "T520-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5002: return "T522-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5003: return "T540-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5004: return "T520-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5005: return "T540-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5006: return "T540-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5007: return "T520-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5008: return "T520-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5009: return "T520-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500A: return "T504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500B: return "B520-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500C: return "B504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500D: return "T580-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500E: return "T540-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_500F: return "T540 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5010: return "T580-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5011: return "T520-LL-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5012: return "T560-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5013: return "T580-CHR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5014: return "T580-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5015: return "T502-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5016: return "T580-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5017: return "T520-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5018: return "T540-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5019: return "T540-LP-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_501A: return "T540-SO-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_501B: return "T540-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5080: return "T540-5080 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5081: return "T540-5081 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5082: return "T504-5082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5083: return "T540-5083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5084: return "T540-5084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5085: return "T580-5085 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5086: return "T580-5086 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5087: return "T580-5087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5088: return "T570-5088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5089: return "T520-5089 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5090: return "T540-5090 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5091: return "T522-5091 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5092: return "T520-5092 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5093: return "T580-5093 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5094: return "T540-5094 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5095: return "T540-5095 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5096: return "T580-5096 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5097: return "T520-5097 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5098: return "T580-5098 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5099: return "T580-5099 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509A: return "T520-509A Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509B: return "T540-509B Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509C: return "T520-509C Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509D: return "T540-509D Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509E: return "T520-509E Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_509F: return "T540-509F Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A0: return "T540-50A0 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A1: return "T540-50A1 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A2: return "T580-50A2 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A3: return "T580-50A3 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A4: return "T540-50A4 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A5: return "T522-50A5 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A6: return "T522-50A6 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A7: return "T580-50A7 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A8: return "T580-50A8 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50A9: return "T580-50A9 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AA: return "T580-50AA Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AB: return "T520-50AB Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AC: return "T540-50AC Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AD: return "T520-50AD Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AE: return "T540-50AE Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50AF: return "T580-50AF Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_50B0: return "T520-50B0 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5401: return "T520-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5402: return "T522-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5403: return "T540-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5404: return "T520-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5405: return "T540-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5406: return "T540-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5407: return "T520-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5408: return "T520-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5409: return "T520-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540A: return "T504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540B: return "B520-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540C: return "B504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540D: return "T580-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540E: return "T540-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_540F: return "T540 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5410: return "T580-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5411: return "T520-LL-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5412: return "T560-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5413: return "T580-CHR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5414: return "T580-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5415: return "T502-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5416: return "T580-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5417: return "T520-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5418: return "T540-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5419: return "T540-LP-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_541A: return "T540-SO-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_541B: return "T540-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5480: return "T540-5080 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5481: return "T540-5081 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5482: return "T504-5082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5483: return "T540-5083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5484: return "T540-5084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5485: return "T580-5085 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5486: return "T580-5086 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5487: return "T580-5087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5488: return "T570-5088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5489: return "T520-5089 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5490: return "T540-5090 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5491: return "T522-5091 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5492: return "T520-5092 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5493: return "T580-5093 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5494: return "T540-5094 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5495: return "T540-5095 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5496: return "T580-5096 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5497: return "T520-5097 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5498: return "T580-5098 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5499: return "T580-5099 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549A: return "T520-509A Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549B: return "T540-509B Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549C: return "T520-509C Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549D: return "T540-509D Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549E: return "T520-509E Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_549F: return "T540-509F Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A0: return "T540-50A0 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A1: return "T540-50A1 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A2: return "T580-50A2 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A3: return "T580-50A3 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A4: return "T540-50A4 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A5: return "T522-50A5 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A6: return "T522-50A6 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A7: return "T580-50A7 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A8: return "T580-50A8 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54A9: return "T580-50A9 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AA: return "T580-50AA Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AB: return "T520-50AB Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AC: return "T540-50AC Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AD: return "T520-50AD Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AE: return "T540-50AE Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54AF: return "T580-50AF Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_54B0: return "T520-50B0 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5501: return "T520-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5502: return "T522-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5503: return "T540-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5504: return "T520-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5505: return "T540-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5506: return "T540-CH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5507: return "T520-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5508: return "T520-CX Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5509: return "T520-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550A: return "T504-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550B: return "B520-SR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550C: return "B504-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550D: return "T580-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550E: return "T540-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_550F: return "T540 [Amsterdam] Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5510: return "T580-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5511: return "T520-LL-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5512: return "T560-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5513: return "T580-CHR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5514: return "T580-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5515: return "T502-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5516: return "T580-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5517: return "T520-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5518: return "T540-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5519: return "T540-LP-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_551A: return "T540-SO-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_551B: return "T540-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5580: return "T540-5080 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5581: return "T540-5081 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5582: return "T504-5082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5583: return "T540-5083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5584: return "T540-5084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5585: return "T580-5085 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5586: return "T580-5086 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5587: return "T580-5087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5588: return "T570-5088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5589: return "T520-5089 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5590: return "T540-5090 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5591: return "T522-5091 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5592: return "T520-5092 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5593: return "T580-5093 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5594: return "T540-5094 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5595: return "T540-5095 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5596: return "T580-5096 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5597: return "T520-5097 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5598: return "T580-5098 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5599: return "T580-5099 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559A: return "T520-509A Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559B: return "T540-509B Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559C: return "T520-509C Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559D: return "T540-509D Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559E: return "T520-509E Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_559F: return "T540-509F Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A0: return "T540-50A0 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A1: return "T540-50A1 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A2: return "T580-50A2 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A3: return "T580-50A3 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A4: return "T540-50A4 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A5: return "T522-50A5 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A6: return "T522-50A6 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A7: return "T580-50A7 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A8: return "T580-50A8 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55A9: return "T580-50A9 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AA: return "T580-50AA Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AB: return "T520-50AB Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AC: return "T540-50AC Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AD: return "T520-50AD Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AE: return "T540-50AE Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55AF: return "T580-50AF Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_55B0: return "T520-50B0 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5601: return "T520-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5602: return "T522-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5603: return "T540-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5604: return "T520-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5605: return "T540-BCH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5606: return "T540-CH Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5607: return "T520-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5608: return "T520-CX Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5609: return "T520-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560A: return "T504-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560B: return "B520-SR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560C: return "B504-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560D: return "T580-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560E: return "T540-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_560F: return "T540 [Amsterdam] Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5610: return "T580-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5611: return "T520-LL-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5612: return "T560-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5613: return "T580-CHR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5614: return "T580-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5615: return "T502-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5616: return "T580-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5617: return "T520-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5618: return "T540-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5619: return "T540-LP-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_561A: return "T540-SO-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_561B: return "T540-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5680: return "T540-5080 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5681: return "T540-5081 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5682: return "T504-5082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5683: return "T540-5083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5684: return "T540-5084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5685: return "T580-5085 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5686: return "T580-5086 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5687: return "T580-5087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5688: return "T570-5088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5689: return "T520-5089 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5690: return "T540-5090 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5691: return "T522-5091 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5692: return "T520-5092 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5693: return "T580-5093 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5694: return "T540-5094 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5695: return "T540-5095 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5696: return "T580-5096 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5697: return "T520-5097 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5698: return "T580-5098 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5699: return "T580-5099 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569A: return "T520-509A Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569B: return "T540-509B Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569C: return "T520-509C Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569D: return "T540-509D Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569E: return "T520-509E Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_569F: return "T540-509F Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A0: return "T540-50A0 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A1: return "T540-50A1 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A2: return "T580-50A2 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A3: return "T580-50A3 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A4: return "T540-50A4 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A5: return "T522-50A5 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A6: return "T522-50A6 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A7: return "T580-50A7 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A8: return "T580-50A8 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56A9: return "T580-50A9 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AA: return "T580-50AA Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AB: return "T520-50AB Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AC: return "T540-50AC Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AD: return "T520-50AD Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AE: return "T540-50AE Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56AF: return "T580-50AF Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_56B0: return "T520-50B0 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_5701: return "T520-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5702: return "T522-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5703: return "T540-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5704: return "T520-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5705: return "T540-BCH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5706: return "T540-CH Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5707: return "T520-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5708: return "T520-CX Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5709: return "T520-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570A: return "T504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570B: return "B520-SR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570C: return "B504-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570D: return "T580-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570E: return "T540-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_570F: return "T540 [Amsterdam] Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5710: return "T580-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5711: return "T520-LL-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5712: return "T560-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5713: return "T580-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5714: return "T580-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5715: return "T502-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5780: return "T540-5080 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5781: return "T540-5081 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5782: return "T504-5082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5783: return "T540-5083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5784: return "T580-5084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5785: return "T580-5085 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5786: return "T580-5086 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5787: return "T580-5087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5788: return "T570-5088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5789: return "T520-5089 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5790: return "T540-5090 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5791: return "T522-5091 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5792: return "T520-5092 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5793: return "T580-5093 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5794: return "T540-5094 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5795: return "T540-5095 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5796: return "T580-5096 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5797: return "T520-5097 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_5801: return "T520-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5802: return "T522-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5803: return "T540-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5804: return "T520-BCH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5805: return "T540-BCH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5806: return "T540-CH Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5807: return "T520-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5808: return "T520-CX Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5809: return "T520-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580A: return "T504-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580B: return "B520-SR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580C: return "B504-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580D: return "T580-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580E: return "T540-LP-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_580F: return "T540 [Amsterdam] Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5810: return "T580-LP-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5811: return "T520-LL-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5812: return "T560-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5813: return "T580-CHR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5814: return "T580-SO-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5815: return "T502-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5816: return "T580-OCP-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5817: return "T520-OCP-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5818: return "T540-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5819: return "T540-LP-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_581A: return "T540-SO-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_581B: return "T540-SO-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5880: return "T540-5080 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5881: return "T540-5081 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5882: return "T504-5082 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5883: return "T540-5083 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5884: return "T540-5084 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5885: return "T580-5085 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5886: return "T580-5086 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5887: return "T580-5087 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5888: return "T570-5088 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5889: return "T520-5089 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5890: return "T540-5090 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5891: return "T522-5091 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5892: return "T520-5092 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5893: return "T580-5093 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5894: return "T540-5094 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5895: return "T540-5095 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5896: return "T580-5096 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5897: return "T520-5097 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5898: return "T580-5098 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_5899: return "T580-5099 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589A: return "T520-509A Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589B: return "T540-509B Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589C: return "T520-509C Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589D: return "T540-509D Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589E: return "T520-509E Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_589F: return "T540-509F Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A0: return "T540-50A0 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A1: return "T540-50A1 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A2: return "T580-50A2 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A3: return "T580-50A3 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A4: return "T540-50A4 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A5: return "T522-50A5 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A6: return "T522-50A6 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A7: return "T580-50A7 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A8: return "T580-50A8 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58A9: return "T580-50A9 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AA: return "T580-50AA Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AB: return "T520-50AB Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AC: return "T540-50AC Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AD: return "T520-50AD Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AE: return "T540-50AE Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58AF: return "T580-50AF Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_58B0: return "T520-50B0 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6001: return "T6225-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6002: return "T6225-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6003: return "T6425-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6004: return "T6425-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6005: return "T6225-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6006: return "T62100-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6007: return "T62100-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6008: return "T62100-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6009: return "T6210-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_600D: return "T62100-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6011: return "T6225-LL-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6014: return "T61100-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6015: return "T6201-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6080: return "T6225-6080 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6081: return "T62100-6081 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6082: return "T6225-6082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6083: return "T62100-6083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6084: return "T64100-6084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6085: return "T6240-6085 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6086: return "T6225-6086 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6087: return "T6225-6087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6088: return "T62100-6088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6089: return "T62100-6089 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_608A: return "T62100-608a Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6401: return "T6225-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6402: return "T6225-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6403: return "T6425-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6404: return "T6425-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6405: return "T6225-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6406: return "T62100-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6407: return "T62100-LP-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6408: return "T62100-SO-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6409: return "T6210-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_640D: return "T62100-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6411: return "T6225-LL-CR Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6414: return "T61100-OCP-SO Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6415: return "T6201-BT Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6480: return "T6225-6080 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6481: return "T62100-6081 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6482: return "T6225-6082 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6483: return "T62100-6083 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6484: return "T64100-6084 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6485: return "T6240-6085 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6486: return "T6225-6086 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6487: return "T6225-6087 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6488: return "T62100-6088 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6489: return "T62100-6089 Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_648A: return "T62100-608a Unified Wire Ethernet Controller";
        case PciDevice1425::DEVICE_6501: return "T6225-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6502: return "T6225-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6503: return "T6425-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6504: return "T6425-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6505: return "T6225-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6506: return "T62100-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6507: return "T62100-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6508: return "T62100-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6509: return "T6210-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_650D: return "T62100-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6511: return "T6225-LL-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6514: return "T61100-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6515: return "T6201-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6580: return "T6225-6080 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6581: return "T62100-6081 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6582: return "T6225-6082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6583: return "T62100-6083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6584: return "T64100-6084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6585: return "T6240-6085 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6586: return "T6225-6086 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6587: return "T6225-6087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6588: return "T62100-6088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6589: return "T62100-6089 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_658A: return "T62100-608a Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6601: return "T6225-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6602: return "T6225-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6603: return "T6425-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6604: return "T6425-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6605: return "T6225-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6606: return "T62100-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6607: return "T62100-LP-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6608: return "T62100-SO-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6609: return "T6210-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_660D: return "T62100-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6611: return "T6225-LL-CR Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6614: return "T61100-OCP-SO Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6615: return "T6201-BT Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6680: return "T6225-6080 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6681: return "T62100-6081 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6682: return "T6225-6082 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6683: return "T62100-6083 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6684: return "T64100-6084 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6685: return "T6240-6085 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6686: return "T6225-6086 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6687: return "T6225-6087 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6688: return "T62100-6088 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6689: return "T62100-6089 Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_668A: return "T62100-608a Unified Wire Storage Controller";
        case PciDevice1425::DEVICE_6801: return "T6225-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6802: return "T6225-SO-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6803: return "T6425-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6804: return "T6425-SO-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6805: return "T6225-OCP-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6806: return "T62100-OCP-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6807: return "T62100-LP-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6808: return "T62100-SO-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6809: return "T6210-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_680D: return "T62100-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6811: return "T6225-LL-CR Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6814: return "T61100-OCP-SO Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6815: return "T6201-BT Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6880: return "T6225-6080 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6881: return "T62100-6081 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6882: return "T6225-6082 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6883: return "T62100-6083 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6884: return "T64100-6084 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6885: return "T6240-6085 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6886: return "T6225-6086 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6887: return "T6225-6087 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6888: return "T62100-6088 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_6889: return "T62100-6089 Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_688A: return "T62100-608a Unified Wire Ethernet Controller [VF]";
        case PciDevice1425::DEVICE_A000: return "PE10K Unified Wire Ethernet Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1425 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1425::DEVICE_000B: return "Unknown device";
        case PciDevice1425::DEVICE_000C: return "Unknown device";
        case PciDevice1425::DEVICE_0022: return "Unknown device";
        case PciDevice1425::DEVICE_0030: return enumToHumanString((PciSubDevice14250030)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1425::DEVICE_0031: return "Unknown device";
        case PciDevice1425::DEVICE_0032: return "Unknown device";
        case PciDevice1425::DEVICE_0033: return "Unknown device";
        case PciDevice1425::DEVICE_0034: return "Unknown device";
        case PciDevice1425::DEVICE_0035: return "Unknown device";
        case PciDevice1425::DEVICE_0036: return "Unknown device";
        case PciDevice1425::DEVICE_0037: return "Unknown device";
        case PciDevice1425::DEVICE_4001: return "Unknown device";
        case PciDevice1425::DEVICE_4002: return "Unknown device";
        case PciDevice1425::DEVICE_4003: return "Unknown device";
        case PciDevice1425::DEVICE_4004: return "Unknown device";
        case PciDevice1425::DEVICE_4005: return "Unknown device";
        case PciDevice1425::DEVICE_4006: return "Unknown device";
        case PciDevice1425::DEVICE_4007: return "Unknown device";
        case PciDevice1425::DEVICE_4008: return "Unknown device";
        case PciDevice1425::DEVICE_4009: return "Unknown device";
        case PciDevice1425::DEVICE_400A: return "Unknown device";
        case PciDevice1425::DEVICE_400B: return "Unknown device";
        case PciDevice1425::DEVICE_400C: return "Unknown device";
        case PciDevice1425::DEVICE_400D: return "Unknown device";
        case PciDevice1425::DEVICE_400E: return "Unknown device";
        case PciDevice1425::DEVICE_400F: return "Unknown device";
        case PciDevice1425::DEVICE_4080: return "Unknown device";
        case PciDevice1425::DEVICE_4081: return "Unknown device";
        case PciDevice1425::DEVICE_4082: return "Unknown device";
        case PciDevice1425::DEVICE_4083: return "Unknown device";
        case PciDevice1425::DEVICE_4084: return "Unknown device";
        case PciDevice1425::DEVICE_4085: return "Unknown device";
        case PciDevice1425::DEVICE_4086: return "Unknown device";
        case PciDevice1425::DEVICE_4087: return "Unknown device";
        case PciDevice1425::DEVICE_4088: return "Unknown device";
        case PciDevice1425::DEVICE_4401: return "Unknown device";
        case PciDevice1425::DEVICE_4402: return "Unknown device";
        case PciDevice1425::DEVICE_4403: return "Unknown device";
        case PciDevice1425::DEVICE_4404: return "Unknown device";
        case PciDevice1425::DEVICE_4405: return "Unknown device";
        case PciDevice1425::DEVICE_4406: return "Unknown device";
        case PciDevice1425::DEVICE_4407: return "Unknown device";
        case PciDevice1425::DEVICE_4408: return "Unknown device";
        case PciDevice1425::DEVICE_4409: return "Unknown device";
        case PciDevice1425::DEVICE_440A: return "Unknown device";
        case PciDevice1425::DEVICE_440B: return "Unknown device";
        case PciDevice1425::DEVICE_440C: return "Unknown device";
        case PciDevice1425::DEVICE_440D: return "Unknown device";
        case PciDevice1425::DEVICE_440E: return "Unknown device";
        case PciDevice1425::DEVICE_440F: return "Unknown device";
        case PciDevice1425::DEVICE_4480: return "Unknown device";
        case PciDevice1425::DEVICE_4481: return "Unknown device";
        case PciDevice1425::DEVICE_4482: return "Unknown device";
        case PciDevice1425::DEVICE_4483: return "Unknown device";
        case PciDevice1425::DEVICE_4484: return "Unknown device";
        case PciDevice1425::DEVICE_4485: return "Unknown device";
        case PciDevice1425::DEVICE_4486: return "Unknown device";
        case PciDevice1425::DEVICE_4487: return "Unknown device";
        case PciDevice1425::DEVICE_4488: return "Unknown device";
        case PciDevice1425::DEVICE_4501: return "Unknown device";
        case PciDevice1425::DEVICE_4502: return "Unknown device";
        case PciDevice1425::DEVICE_4503: return "Unknown device";
        case PciDevice1425::DEVICE_4504: return "Unknown device";
        case PciDevice1425::DEVICE_4505: return "Unknown device";
        case PciDevice1425::DEVICE_4506: return "Unknown device";
        case PciDevice1425::DEVICE_4507: return "Unknown device";
        case PciDevice1425::DEVICE_4508: return "Unknown device";
        case PciDevice1425::DEVICE_4509: return "Unknown device";
        case PciDevice1425::DEVICE_450A: return "Unknown device";
        case PciDevice1425::DEVICE_450B: return "Unknown device";
        case PciDevice1425::DEVICE_450C: return "Unknown device";
        case PciDevice1425::DEVICE_450D: return "Unknown device";
        case PciDevice1425::DEVICE_450E: return "Unknown device";
        case PciDevice1425::DEVICE_450F: return "Unknown device";
        case PciDevice1425::DEVICE_4580: return "Unknown device";
        case PciDevice1425::DEVICE_4581: return "Unknown device";
        case PciDevice1425::DEVICE_4582: return "Unknown device";
        case PciDevice1425::DEVICE_4583: return "Unknown device";
        case PciDevice1425::DEVICE_4584: return "Unknown device";
        case PciDevice1425::DEVICE_4585: return "Unknown device";
        case PciDevice1425::DEVICE_4586: return "Unknown device";
        case PciDevice1425::DEVICE_4587: return "Unknown device";
        case PciDevice1425::DEVICE_4588: return "Unknown device";
        case PciDevice1425::DEVICE_4601: return "Unknown device";
        case PciDevice1425::DEVICE_4602: return "Unknown device";
        case PciDevice1425::DEVICE_4603: return "Unknown device";
        case PciDevice1425::DEVICE_4604: return "Unknown device";
        case PciDevice1425::DEVICE_4605: return "Unknown device";
        case PciDevice1425::DEVICE_4606: return "Unknown device";
        case PciDevice1425::DEVICE_4607: return "Unknown device";
        case PciDevice1425::DEVICE_4608: return "Unknown device";
        case PciDevice1425::DEVICE_4609: return "Unknown device";
        case PciDevice1425::DEVICE_460A: return "Unknown device";
        case PciDevice1425::DEVICE_460B: return "Unknown device";
        case PciDevice1425::DEVICE_460C: return "Unknown device";
        case PciDevice1425::DEVICE_460D: return "Unknown device";
        case PciDevice1425::DEVICE_460E: return "Unknown device";
        case PciDevice1425::DEVICE_460F: return "Unknown device";
        case PciDevice1425::DEVICE_4680: return "Unknown device";
        case PciDevice1425::DEVICE_4681: return "Unknown device";
        case PciDevice1425::DEVICE_4682: return "Unknown device";
        case PciDevice1425::DEVICE_4683: return "Unknown device";
        case PciDevice1425::DEVICE_4684: return "Unknown device";
        case PciDevice1425::DEVICE_4685: return "Unknown device";
        case PciDevice1425::DEVICE_4686: return "Unknown device";
        case PciDevice1425::DEVICE_4687: return "Unknown device";
        case PciDevice1425::DEVICE_4688: return "Unknown device";
        case PciDevice1425::DEVICE_4701: return "Unknown device";
        case PciDevice1425::DEVICE_4702: return "Unknown device";
        case PciDevice1425::DEVICE_4703: return "Unknown device";
        case PciDevice1425::DEVICE_4704: return "Unknown device";
        case PciDevice1425::DEVICE_4705: return "Unknown device";
        case PciDevice1425::DEVICE_4706: return "Unknown device";
        case PciDevice1425::DEVICE_4707: return "Unknown device";
        case PciDevice1425::DEVICE_4708: return "Unknown device";
        case PciDevice1425::DEVICE_4709: return "Unknown device";
        case PciDevice1425::DEVICE_470A: return "Unknown device";
        case PciDevice1425::DEVICE_470B: return "Unknown device";
        case PciDevice1425::DEVICE_470C: return "Unknown device";
        case PciDevice1425::DEVICE_470D: return "Unknown device";
        case PciDevice1425::DEVICE_470E: return "Unknown device";
        case PciDevice1425::DEVICE_470F: return "Unknown device";
        case PciDevice1425::DEVICE_4780: return "Unknown device";
        case PciDevice1425::DEVICE_4781: return "Unknown device";
        case PciDevice1425::DEVICE_4782: return "Unknown device";
        case PciDevice1425::DEVICE_4783: return "Unknown device";
        case PciDevice1425::DEVICE_4784: return "Unknown device";
        case PciDevice1425::DEVICE_4785: return "Unknown device";
        case PciDevice1425::DEVICE_4786: return "Unknown device";
        case PciDevice1425::DEVICE_4787: return "Unknown device";
        case PciDevice1425::DEVICE_4788: return "Unknown device";
        case PciDevice1425::DEVICE_4801: return "Unknown device";
        case PciDevice1425::DEVICE_4802: return "Unknown device";
        case PciDevice1425::DEVICE_4803: return "Unknown device";
        case PciDevice1425::DEVICE_4804: return "Unknown device";
        case PciDevice1425::DEVICE_4805: return "Unknown device";
        case PciDevice1425::DEVICE_4806: return "Unknown device";
        case PciDevice1425::DEVICE_4807: return "Unknown device";
        case PciDevice1425::DEVICE_4808: return "Unknown device";
        case PciDevice1425::DEVICE_4809: return "Unknown device";
        case PciDevice1425::DEVICE_480A: return "Unknown device";
        case PciDevice1425::DEVICE_480B: return "Unknown device";
        case PciDevice1425::DEVICE_480C: return "Unknown device";
        case PciDevice1425::DEVICE_480D: return "Unknown device";
        case PciDevice1425::DEVICE_480E: return "Unknown device";
        case PciDevice1425::DEVICE_480F: return "Unknown device";
        case PciDevice1425::DEVICE_4880: return "Unknown device";
        case PciDevice1425::DEVICE_4881: return "Unknown device";
        case PciDevice1425::DEVICE_4882: return "Unknown device";
        case PciDevice1425::DEVICE_4883: return "Unknown device";
        case PciDevice1425::DEVICE_4884: return "Unknown device";
        case PciDevice1425::DEVICE_4885: return "Unknown device";
        case PciDevice1425::DEVICE_4886: return "Unknown device";
        case PciDevice1425::DEVICE_4887: return "Unknown device";
        case PciDevice1425::DEVICE_4888: return "Unknown device";
        case PciDevice1425::DEVICE_5001: return enumToHumanString((PciSubDevice14255001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1425::DEVICE_5002: return "Unknown device";
        case PciDevice1425::DEVICE_5003: return "Unknown device";
        case PciDevice1425::DEVICE_5004: return "Unknown device";
        case PciDevice1425::DEVICE_5005: return "Unknown device";
        case PciDevice1425::DEVICE_5006: return "Unknown device";
        case PciDevice1425::DEVICE_5007: return "Unknown device";
        case PciDevice1425::DEVICE_5008: return "Unknown device";
        case PciDevice1425::DEVICE_5009: return "Unknown device";
        case PciDevice1425::DEVICE_500A: return "Unknown device";
        case PciDevice1425::DEVICE_500B: return "Unknown device";
        case PciDevice1425::DEVICE_500C: return "Unknown device";
        case PciDevice1425::DEVICE_500D: return "Unknown device";
        case PciDevice1425::DEVICE_500E: return "Unknown device";
        case PciDevice1425::DEVICE_500F: return "Unknown device";
        case PciDevice1425::DEVICE_5010: return "Unknown device";
        case PciDevice1425::DEVICE_5011: return "Unknown device";
        case PciDevice1425::DEVICE_5012: return "Unknown device";
        case PciDevice1425::DEVICE_5013: return "Unknown device";
        case PciDevice1425::DEVICE_5014: return "Unknown device";
        case PciDevice1425::DEVICE_5015: return "Unknown device";
        case PciDevice1425::DEVICE_5016: return "Unknown device";
        case PciDevice1425::DEVICE_5017: return "Unknown device";
        case PciDevice1425::DEVICE_5018: return "Unknown device";
        case PciDevice1425::DEVICE_5019: return "Unknown device";
        case PciDevice1425::DEVICE_501A: return "Unknown device";
        case PciDevice1425::DEVICE_501B: return "Unknown device";
        case PciDevice1425::DEVICE_5080: return "Unknown device";
        case PciDevice1425::DEVICE_5081: return "Unknown device";
        case PciDevice1425::DEVICE_5082: return "Unknown device";
        case PciDevice1425::DEVICE_5083: return "Unknown device";
        case PciDevice1425::DEVICE_5084: return "Unknown device";
        case PciDevice1425::DEVICE_5085: return "Unknown device";
        case PciDevice1425::DEVICE_5086: return "Unknown device";
        case PciDevice1425::DEVICE_5087: return "Unknown device";
        case PciDevice1425::DEVICE_5088: return "Unknown device";
        case PciDevice1425::DEVICE_5089: return "Unknown device";
        case PciDevice1425::DEVICE_5090: return "Unknown device";
        case PciDevice1425::DEVICE_5091: return "Unknown device";
        case PciDevice1425::DEVICE_5092: return "Unknown device";
        case PciDevice1425::DEVICE_5093: return "Unknown device";
        case PciDevice1425::DEVICE_5094: return "Unknown device";
        case PciDevice1425::DEVICE_5095: return "Unknown device";
        case PciDevice1425::DEVICE_5096: return "Unknown device";
        case PciDevice1425::DEVICE_5097: return "Unknown device";
        case PciDevice1425::DEVICE_5098: return "Unknown device";
        case PciDevice1425::DEVICE_5099: return "Unknown device";
        case PciDevice1425::DEVICE_509A: return "Unknown device";
        case PciDevice1425::DEVICE_509B: return "Unknown device";
        case PciDevice1425::DEVICE_509C: return "Unknown device";
        case PciDevice1425::DEVICE_509D: return "Unknown device";
        case PciDevice1425::DEVICE_509E: return "Unknown device";
        case PciDevice1425::DEVICE_509F: return "Unknown device";
        case PciDevice1425::DEVICE_50A0: return "Unknown device";
        case PciDevice1425::DEVICE_50A1: return "Unknown device";
        case PciDevice1425::DEVICE_50A2: return "Unknown device";
        case PciDevice1425::DEVICE_50A3: return "Unknown device";
        case PciDevice1425::DEVICE_50A4: return "Unknown device";
        case PciDevice1425::DEVICE_50A5: return "Unknown device";
        case PciDevice1425::DEVICE_50A6: return "Unknown device";
        case PciDevice1425::DEVICE_50A7: return "Unknown device";
        case PciDevice1425::DEVICE_50A8: return "Unknown device";
        case PciDevice1425::DEVICE_50A9: return "Unknown device";
        case PciDevice1425::DEVICE_50AA: return "Unknown device";
        case PciDevice1425::DEVICE_50AB: return "Unknown device";
        case PciDevice1425::DEVICE_50AC: return "Unknown device";
        case PciDevice1425::DEVICE_50AD: return "Unknown device";
        case PciDevice1425::DEVICE_50AE: return "Unknown device";
        case PciDevice1425::DEVICE_50AF: return "Unknown device";
        case PciDevice1425::DEVICE_50B0: return "Unknown device";
        case PciDevice1425::DEVICE_5401: return "Unknown device";
        case PciDevice1425::DEVICE_5402: return "Unknown device";
        case PciDevice1425::DEVICE_5403: return "Unknown device";
        case PciDevice1425::DEVICE_5404: return "Unknown device";
        case PciDevice1425::DEVICE_5405: return "Unknown device";
        case PciDevice1425::DEVICE_5406: return "Unknown device";
        case PciDevice1425::DEVICE_5407: return "Unknown device";
        case PciDevice1425::DEVICE_5408: return "Unknown device";
        case PciDevice1425::DEVICE_5409: return "Unknown device";
        case PciDevice1425::DEVICE_540A: return "Unknown device";
        case PciDevice1425::DEVICE_540B: return "Unknown device";
        case PciDevice1425::DEVICE_540C: return "Unknown device";
        case PciDevice1425::DEVICE_540D: return "Unknown device";
        case PciDevice1425::DEVICE_540E: return "Unknown device";
        case PciDevice1425::DEVICE_540F: return "Unknown device";
        case PciDevice1425::DEVICE_5410: return "Unknown device";
        case PciDevice1425::DEVICE_5411: return "Unknown device";
        case PciDevice1425::DEVICE_5412: return "Unknown device";
        case PciDevice1425::DEVICE_5413: return "Unknown device";
        case PciDevice1425::DEVICE_5414: return "Unknown device";
        case PciDevice1425::DEVICE_5415: return "Unknown device";
        case PciDevice1425::DEVICE_5416: return "Unknown device";
        case PciDevice1425::DEVICE_5417: return "Unknown device";
        case PciDevice1425::DEVICE_5418: return "Unknown device";
        case PciDevice1425::DEVICE_5419: return "Unknown device";
        case PciDevice1425::DEVICE_541A: return "Unknown device";
        case PciDevice1425::DEVICE_541B: return "Unknown device";
        case PciDevice1425::DEVICE_5480: return "Unknown device";
        case PciDevice1425::DEVICE_5481: return "Unknown device";
        case PciDevice1425::DEVICE_5482: return "Unknown device";
        case PciDevice1425::DEVICE_5483: return "Unknown device";
        case PciDevice1425::DEVICE_5484: return "Unknown device";
        case PciDevice1425::DEVICE_5485: return "Unknown device";
        case PciDevice1425::DEVICE_5486: return "Unknown device";
        case PciDevice1425::DEVICE_5487: return "Unknown device";
        case PciDevice1425::DEVICE_5488: return "Unknown device";
        case PciDevice1425::DEVICE_5489: return "Unknown device";
        case PciDevice1425::DEVICE_5490: return "Unknown device";
        case PciDevice1425::DEVICE_5491: return "Unknown device";
        case PciDevice1425::DEVICE_5492: return "Unknown device";
        case PciDevice1425::DEVICE_5493: return "Unknown device";
        case PciDevice1425::DEVICE_5494: return "Unknown device";
        case PciDevice1425::DEVICE_5495: return "Unknown device";
        case PciDevice1425::DEVICE_5496: return "Unknown device";
        case PciDevice1425::DEVICE_5497: return "Unknown device";
        case PciDevice1425::DEVICE_5498: return "Unknown device";
        case PciDevice1425::DEVICE_5499: return "Unknown device";
        case PciDevice1425::DEVICE_549A: return "Unknown device";
        case PciDevice1425::DEVICE_549B: return "Unknown device";
        case PciDevice1425::DEVICE_549C: return "Unknown device";
        case PciDevice1425::DEVICE_549D: return "Unknown device";
        case PciDevice1425::DEVICE_549E: return "Unknown device";
        case PciDevice1425::DEVICE_549F: return "Unknown device";
        case PciDevice1425::DEVICE_54A0: return "Unknown device";
        case PciDevice1425::DEVICE_54A1: return "Unknown device";
        case PciDevice1425::DEVICE_54A2: return "Unknown device";
        case PciDevice1425::DEVICE_54A3: return "Unknown device";
        case PciDevice1425::DEVICE_54A4: return "Unknown device";
        case PciDevice1425::DEVICE_54A5: return "Unknown device";
        case PciDevice1425::DEVICE_54A6: return "Unknown device";
        case PciDevice1425::DEVICE_54A7: return "Unknown device";
        case PciDevice1425::DEVICE_54A8: return "Unknown device";
        case PciDevice1425::DEVICE_54A9: return "Unknown device";
        case PciDevice1425::DEVICE_54AA: return "Unknown device";
        case PciDevice1425::DEVICE_54AB: return "Unknown device";
        case PciDevice1425::DEVICE_54AC: return "Unknown device";
        case PciDevice1425::DEVICE_54AD: return "Unknown device";
        case PciDevice1425::DEVICE_54AE: return "Unknown device";
        case PciDevice1425::DEVICE_54AF: return "Unknown device";
        case PciDevice1425::DEVICE_54B0: return "Unknown device";
        case PciDevice1425::DEVICE_5501: return "Unknown device";
        case PciDevice1425::DEVICE_5502: return "Unknown device";
        case PciDevice1425::DEVICE_5503: return "Unknown device";
        case PciDevice1425::DEVICE_5504: return "Unknown device";
        case PciDevice1425::DEVICE_5505: return "Unknown device";
        case PciDevice1425::DEVICE_5506: return "Unknown device";
        case PciDevice1425::DEVICE_5507: return "Unknown device";
        case PciDevice1425::DEVICE_5508: return "Unknown device";
        case PciDevice1425::DEVICE_5509: return "Unknown device";
        case PciDevice1425::DEVICE_550A: return "Unknown device";
        case PciDevice1425::DEVICE_550B: return "Unknown device";
        case PciDevice1425::DEVICE_550C: return "Unknown device";
        case PciDevice1425::DEVICE_550D: return "Unknown device";
        case PciDevice1425::DEVICE_550E: return "Unknown device";
        case PciDevice1425::DEVICE_550F: return "Unknown device";
        case PciDevice1425::DEVICE_5510: return "Unknown device";
        case PciDevice1425::DEVICE_5511: return "Unknown device";
        case PciDevice1425::DEVICE_5512: return "Unknown device";
        case PciDevice1425::DEVICE_5513: return "Unknown device";
        case PciDevice1425::DEVICE_5514: return "Unknown device";
        case PciDevice1425::DEVICE_5515: return "Unknown device";
        case PciDevice1425::DEVICE_5516: return "Unknown device";
        case PciDevice1425::DEVICE_5517: return "Unknown device";
        case PciDevice1425::DEVICE_5518: return "Unknown device";
        case PciDevice1425::DEVICE_5519: return "Unknown device";
        case PciDevice1425::DEVICE_551A: return "Unknown device";
        case PciDevice1425::DEVICE_551B: return "Unknown device";
        case PciDevice1425::DEVICE_5580: return "Unknown device";
        case PciDevice1425::DEVICE_5581: return "Unknown device";
        case PciDevice1425::DEVICE_5582: return "Unknown device";
        case PciDevice1425::DEVICE_5583: return "Unknown device";
        case PciDevice1425::DEVICE_5584: return "Unknown device";
        case PciDevice1425::DEVICE_5585: return "Unknown device";
        case PciDevice1425::DEVICE_5586: return "Unknown device";
        case PciDevice1425::DEVICE_5587: return "Unknown device";
        case PciDevice1425::DEVICE_5588: return "Unknown device";
        case PciDevice1425::DEVICE_5589: return "Unknown device";
        case PciDevice1425::DEVICE_5590: return "Unknown device";
        case PciDevice1425::DEVICE_5591: return "Unknown device";
        case PciDevice1425::DEVICE_5592: return "Unknown device";
        case PciDevice1425::DEVICE_5593: return "Unknown device";
        case PciDevice1425::DEVICE_5594: return "Unknown device";
        case PciDevice1425::DEVICE_5595: return "Unknown device";
        case PciDevice1425::DEVICE_5596: return "Unknown device";
        case PciDevice1425::DEVICE_5597: return "Unknown device";
        case PciDevice1425::DEVICE_5598: return "Unknown device";
        case PciDevice1425::DEVICE_5599: return "Unknown device";
        case PciDevice1425::DEVICE_559A: return "Unknown device";
        case PciDevice1425::DEVICE_559B: return "Unknown device";
        case PciDevice1425::DEVICE_559C: return "Unknown device";
        case PciDevice1425::DEVICE_559D: return "Unknown device";
        case PciDevice1425::DEVICE_559E: return "Unknown device";
        case PciDevice1425::DEVICE_559F: return "Unknown device";
        case PciDevice1425::DEVICE_55A0: return "Unknown device";
        case PciDevice1425::DEVICE_55A1: return "Unknown device";
        case PciDevice1425::DEVICE_55A2: return "Unknown device";
        case PciDevice1425::DEVICE_55A3: return "Unknown device";
        case PciDevice1425::DEVICE_55A4: return "Unknown device";
        case PciDevice1425::DEVICE_55A5: return "Unknown device";
        case PciDevice1425::DEVICE_55A6: return "Unknown device";
        case PciDevice1425::DEVICE_55A7: return "Unknown device";
        case PciDevice1425::DEVICE_55A8: return "Unknown device";
        case PciDevice1425::DEVICE_55A9: return "Unknown device";
        case PciDevice1425::DEVICE_55AA: return "Unknown device";
        case PciDevice1425::DEVICE_55AB: return "Unknown device";
        case PciDevice1425::DEVICE_55AC: return "Unknown device";
        case PciDevice1425::DEVICE_55AD: return "Unknown device";
        case PciDevice1425::DEVICE_55AE: return "Unknown device";
        case PciDevice1425::DEVICE_55AF: return "Unknown device";
        case PciDevice1425::DEVICE_55B0: return "Unknown device";
        case PciDevice1425::DEVICE_5601: return "Unknown device";
        case PciDevice1425::DEVICE_5602: return "Unknown device";
        case PciDevice1425::DEVICE_5603: return "Unknown device";
        case PciDevice1425::DEVICE_5604: return "Unknown device";
        case PciDevice1425::DEVICE_5605: return "Unknown device";
        case PciDevice1425::DEVICE_5606: return "Unknown device";
        case PciDevice1425::DEVICE_5607: return "Unknown device";
        case PciDevice1425::DEVICE_5608: return "Unknown device";
        case PciDevice1425::DEVICE_5609: return "Unknown device";
        case PciDevice1425::DEVICE_560A: return "Unknown device";
        case PciDevice1425::DEVICE_560B: return "Unknown device";
        case PciDevice1425::DEVICE_560C: return "Unknown device";
        case PciDevice1425::DEVICE_560D: return "Unknown device";
        case PciDevice1425::DEVICE_560E: return "Unknown device";
        case PciDevice1425::DEVICE_560F: return "Unknown device";
        case PciDevice1425::DEVICE_5610: return "Unknown device";
        case PciDevice1425::DEVICE_5611: return "Unknown device";
        case PciDevice1425::DEVICE_5612: return "Unknown device";
        case PciDevice1425::DEVICE_5613: return "Unknown device";
        case PciDevice1425::DEVICE_5614: return "Unknown device";
        case PciDevice1425::DEVICE_5615: return "Unknown device";
        case PciDevice1425::DEVICE_5616: return "Unknown device";
        case PciDevice1425::DEVICE_5617: return "Unknown device";
        case PciDevice1425::DEVICE_5618: return "Unknown device";
        case PciDevice1425::DEVICE_5619: return "Unknown device";
        case PciDevice1425::DEVICE_561A: return "Unknown device";
        case PciDevice1425::DEVICE_561B: return "Unknown device";
        case PciDevice1425::DEVICE_5680: return "Unknown device";
        case PciDevice1425::DEVICE_5681: return "Unknown device";
        case PciDevice1425::DEVICE_5682: return "Unknown device";
        case PciDevice1425::DEVICE_5683: return "Unknown device";
        case PciDevice1425::DEVICE_5684: return "Unknown device";
        case PciDevice1425::DEVICE_5685: return "Unknown device";
        case PciDevice1425::DEVICE_5686: return "Unknown device";
        case PciDevice1425::DEVICE_5687: return "Unknown device";
        case PciDevice1425::DEVICE_5688: return "Unknown device";
        case PciDevice1425::DEVICE_5689: return "Unknown device";
        case PciDevice1425::DEVICE_5690: return "Unknown device";
        case PciDevice1425::DEVICE_5691: return "Unknown device";
        case PciDevice1425::DEVICE_5692: return "Unknown device";
        case PciDevice1425::DEVICE_5693: return "Unknown device";
        case PciDevice1425::DEVICE_5694: return "Unknown device";
        case PciDevice1425::DEVICE_5695: return "Unknown device";
        case PciDevice1425::DEVICE_5696: return "Unknown device";
        case PciDevice1425::DEVICE_5697: return "Unknown device";
        case PciDevice1425::DEVICE_5698: return "Unknown device";
        case PciDevice1425::DEVICE_5699: return "Unknown device";
        case PciDevice1425::DEVICE_569A: return "Unknown device";
        case PciDevice1425::DEVICE_569B: return "Unknown device";
        case PciDevice1425::DEVICE_569C: return "Unknown device";
        case PciDevice1425::DEVICE_569D: return "Unknown device";
        case PciDevice1425::DEVICE_569E: return "Unknown device";
        case PciDevice1425::DEVICE_569F: return "Unknown device";
        case PciDevice1425::DEVICE_56A0: return "Unknown device";
        case PciDevice1425::DEVICE_56A1: return "Unknown device";
        case PciDevice1425::DEVICE_56A2: return "Unknown device";
        case PciDevice1425::DEVICE_56A3: return "Unknown device";
        case PciDevice1425::DEVICE_56A4: return "Unknown device";
        case PciDevice1425::DEVICE_56A5: return "Unknown device";
        case PciDevice1425::DEVICE_56A6: return "Unknown device";
        case PciDevice1425::DEVICE_56A7: return "Unknown device";
        case PciDevice1425::DEVICE_56A8: return "Unknown device";
        case PciDevice1425::DEVICE_56A9: return "Unknown device";
        case PciDevice1425::DEVICE_56AA: return "Unknown device";
        case PciDevice1425::DEVICE_56AB: return "Unknown device";
        case PciDevice1425::DEVICE_56AC: return "Unknown device";
        case PciDevice1425::DEVICE_56AD: return "Unknown device";
        case PciDevice1425::DEVICE_56AE: return "Unknown device";
        case PciDevice1425::DEVICE_56AF: return "Unknown device";
        case PciDevice1425::DEVICE_56B0: return "Unknown device";
        case PciDevice1425::DEVICE_5701: return "Unknown device";
        case PciDevice1425::DEVICE_5702: return "Unknown device";
        case PciDevice1425::DEVICE_5703: return "Unknown device";
        case PciDevice1425::DEVICE_5704: return "Unknown device";
        case PciDevice1425::DEVICE_5705: return "Unknown device";
        case PciDevice1425::DEVICE_5706: return "Unknown device";
        case PciDevice1425::DEVICE_5707: return "Unknown device";
        case PciDevice1425::DEVICE_5708: return "Unknown device";
        case PciDevice1425::DEVICE_5709: return "Unknown device";
        case PciDevice1425::DEVICE_570A: return "Unknown device";
        case PciDevice1425::DEVICE_570B: return "Unknown device";
        case PciDevice1425::DEVICE_570C: return "Unknown device";
        case PciDevice1425::DEVICE_570D: return "Unknown device";
        case PciDevice1425::DEVICE_570E: return "Unknown device";
        case PciDevice1425::DEVICE_570F: return "Unknown device";
        case PciDevice1425::DEVICE_5710: return "Unknown device";
        case PciDevice1425::DEVICE_5711: return "Unknown device";
        case PciDevice1425::DEVICE_5712: return "Unknown device";
        case PciDevice1425::DEVICE_5713: return "Unknown device";
        case PciDevice1425::DEVICE_5714: return "Unknown device";
        case PciDevice1425::DEVICE_5715: return "Unknown device";
        case PciDevice1425::DEVICE_5780: return "Unknown device";
        case PciDevice1425::DEVICE_5781: return "Unknown device";
        case PciDevice1425::DEVICE_5782: return "Unknown device";
        case PciDevice1425::DEVICE_5783: return "Unknown device";
        case PciDevice1425::DEVICE_5784: return "Unknown device";
        case PciDevice1425::DEVICE_5785: return "Unknown device";
        case PciDevice1425::DEVICE_5786: return "Unknown device";
        case PciDevice1425::DEVICE_5787: return "Unknown device";
        case PciDevice1425::DEVICE_5788: return "Unknown device";
        case PciDevice1425::DEVICE_5789: return "Unknown device";
        case PciDevice1425::DEVICE_5790: return "Unknown device";
        case PciDevice1425::DEVICE_5791: return "Unknown device";
        case PciDevice1425::DEVICE_5792: return "Unknown device";
        case PciDevice1425::DEVICE_5793: return "Unknown device";
        case PciDevice1425::DEVICE_5794: return "Unknown device";
        case PciDevice1425::DEVICE_5795: return "Unknown device";
        case PciDevice1425::DEVICE_5796: return "Unknown device";
        case PciDevice1425::DEVICE_5797: return "Unknown device";
        case PciDevice1425::DEVICE_5801: return "Unknown device";
        case PciDevice1425::DEVICE_5802: return "Unknown device";
        case PciDevice1425::DEVICE_5803: return "Unknown device";
        case PciDevice1425::DEVICE_5804: return "Unknown device";
        case PciDevice1425::DEVICE_5805: return "Unknown device";
        case PciDevice1425::DEVICE_5806: return "Unknown device";
        case PciDevice1425::DEVICE_5807: return "Unknown device";
        case PciDevice1425::DEVICE_5808: return "Unknown device";
        case PciDevice1425::DEVICE_5809: return "Unknown device";
        case PciDevice1425::DEVICE_580A: return "Unknown device";
        case PciDevice1425::DEVICE_580B: return "Unknown device";
        case PciDevice1425::DEVICE_580C: return "Unknown device";
        case PciDevice1425::DEVICE_580D: return "Unknown device";
        case PciDevice1425::DEVICE_580E: return "Unknown device";
        case PciDevice1425::DEVICE_580F: return "Unknown device";
        case PciDevice1425::DEVICE_5810: return "Unknown device";
        case PciDevice1425::DEVICE_5811: return "Unknown device";
        case PciDevice1425::DEVICE_5812: return "Unknown device";
        case PciDevice1425::DEVICE_5813: return "Unknown device";
        case PciDevice1425::DEVICE_5814: return "Unknown device";
        case PciDevice1425::DEVICE_5815: return "Unknown device";
        case PciDevice1425::DEVICE_5816: return "Unknown device";
        case PciDevice1425::DEVICE_5817: return "Unknown device";
        case PciDevice1425::DEVICE_5818: return "Unknown device";
        case PciDevice1425::DEVICE_5819: return "Unknown device";
        case PciDevice1425::DEVICE_581A: return "Unknown device";
        case PciDevice1425::DEVICE_581B: return "Unknown device";
        case PciDevice1425::DEVICE_5880: return "Unknown device";
        case PciDevice1425::DEVICE_5881: return "Unknown device";
        case PciDevice1425::DEVICE_5882: return "Unknown device";
        case PciDevice1425::DEVICE_5883: return "Unknown device";
        case PciDevice1425::DEVICE_5884: return "Unknown device";
        case PciDevice1425::DEVICE_5885: return "Unknown device";
        case PciDevice1425::DEVICE_5886: return "Unknown device";
        case PciDevice1425::DEVICE_5887: return "Unknown device";
        case PciDevice1425::DEVICE_5888: return "Unknown device";
        case PciDevice1425::DEVICE_5889: return "Unknown device";
        case PciDevice1425::DEVICE_5890: return "Unknown device";
        case PciDevice1425::DEVICE_5891: return "Unknown device";
        case PciDevice1425::DEVICE_5892: return "Unknown device";
        case PciDevice1425::DEVICE_5893: return "Unknown device";
        case PciDevice1425::DEVICE_5894: return "Unknown device";
        case PciDevice1425::DEVICE_5895: return "Unknown device";
        case PciDevice1425::DEVICE_5896: return "Unknown device";
        case PciDevice1425::DEVICE_5897: return "Unknown device";
        case PciDevice1425::DEVICE_5898: return "Unknown device";
        case PciDevice1425::DEVICE_5899: return "Unknown device";
        case PciDevice1425::DEVICE_589A: return "Unknown device";
        case PciDevice1425::DEVICE_589B: return "Unknown device";
        case PciDevice1425::DEVICE_589C: return "Unknown device";
        case PciDevice1425::DEVICE_589D: return "Unknown device";
        case PciDevice1425::DEVICE_589E: return "Unknown device";
        case PciDevice1425::DEVICE_589F: return "Unknown device";
        case PciDevice1425::DEVICE_58A0: return "Unknown device";
        case PciDevice1425::DEVICE_58A1: return "Unknown device";
        case PciDevice1425::DEVICE_58A2: return "Unknown device";
        case PciDevice1425::DEVICE_58A3: return "Unknown device";
        case PciDevice1425::DEVICE_58A4: return "Unknown device";
        case PciDevice1425::DEVICE_58A5: return "Unknown device";
        case PciDevice1425::DEVICE_58A6: return "Unknown device";
        case PciDevice1425::DEVICE_58A7: return "Unknown device";
        case PciDevice1425::DEVICE_58A8: return "Unknown device";
        case PciDevice1425::DEVICE_58A9: return "Unknown device";
        case PciDevice1425::DEVICE_58AA: return "Unknown device";
        case PciDevice1425::DEVICE_58AB: return "Unknown device";
        case PciDevice1425::DEVICE_58AC: return "Unknown device";
        case PciDevice1425::DEVICE_58AD: return "Unknown device";
        case PciDevice1425::DEVICE_58AE: return "Unknown device";
        case PciDevice1425::DEVICE_58AF: return "Unknown device";
        case PciDevice1425::DEVICE_58B0: return "Unknown device";
        case PciDevice1425::DEVICE_6001: return "Unknown device";
        case PciDevice1425::DEVICE_6002: return "Unknown device";
        case PciDevice1425::DEVICE_6003: return "Unknown device";
        case PciDevice1425::DEVICE_6004: return "Unknown device";
        case PciDevice1425::DEVICE_6005: return "Unknown device";
        case PciDevice1425::DEVICE_6006: return "Unknown device";
        case PciDevice1425::DEVICE_6007: return "Unknown device";
        case PciDevice1425::DEVICE_6008: return "Unknown device";
        case PciDevice1425::DEVICE_6009: return "Unknown device";
        case PciDevice1425::DEVICE_600D: return "Unknown device";
        case PciDevice1425::DEVICE_6011: return "Unknown device";
        case PciDevice1425::DEVICE_6014: return "Unknown device";
        case PciDevice1425::DEVICE_6015: return "Unknown device";
        case PciDevice1425::DEVICE_6080: return "Unknown device";
        case PciDevice1425::DEVICE_6081: return "Unknown device";
        case PciDevice1425::DEVICE_6082: return "Unknown device";
        case PciDevice1425::DEVICE_6083: return "Unknown device";
        case PciDevice1425::DEVICE_6084: return "Unknown device";
        case PciDevice1425::DEVICE_6085: return "Unknown device";
        case PciDevice1425::DEVICE_6086: return "Unknown device";
        case PciDevice1425::DEVICE_6087: return "Unknown device";
        case PciDevice1425::DEVICE_6088: return "Unknown device";
        case PciDevice1425::DEVICE_6089: return "Unknown device";
        case PciDevice1425::DEVICE_608A: return "Unknown device";
        case PciDevice1425::DEVICE_6401: return "Unknown device";
        case PciDevice1425::DEVICE_6402: return "Unknown device";
        case PciDevice1425::DEVICE_6403: return "Unknown device";
        case PciDevice1425::DEVICE_6404: return "Unknown device";
        case PciDevice1425::DEVICE_6405: return "Unknown device";
        case PciDevice1425::DEVICE_6406: return "Unknown device";
        case PciDevice1425::DEVICE_6407: return "Unknown device";
        case PciDevice1425::DEVICE_6408: return "Unknown device";
        case PciDevice1425::DEVICE_6409: return "Unknown device";
        case PciDevice1425::DEVICE_640D: return "Unknown device";
        case PciDevice1425::DEVICE_6411: return "Unknown device";
        case PciDevice1425::DEVICE_6414: return "Unknown device";
        case PciDevice1425::DEVICE_6415: return "Unknown device";
        case PciDevice1425::DEVICE_6480: return "Unknown device";
        case PciDevice1425::DEVICE_6481: return "Unknown device";
        case PciDevice1425::DEVICE_6482: return "Unknown device";
        case PciDevice1425::DEVICE_6483: return "Unknown device";
        case PciDevice1425::DEVICE_6484: return "Unknown device";
        case PciDevice1425::DEVICE_6485: return "Unknown device";
        case PciDevice1425::DEVICE_6486: return "Unknown device";
        case PciDevice1425::DEVICE_6487: return "Unknown device";
        case PciDevice1425::DEVICE_6488: return "Unknown device";
        case PciDevice1425::DEVICE_6489: return "Unknown device";
        case PciDevice1425::DEVICE_648A: return "Unknown device";
        case PciDevice1425::DEVICE_6501: return "Unknown device";
        case PciDevice1425::DEVICE_6502: return "Unknown device";
        case PciDevice1425::DEVICE_6503: return "Unknown device";
        case PciDevice1425::DEVICE_6504: return "Unknown device";
        case PciDevice1425::DEVICE_6505: return "Unknown device";
        case PciDevice1425::DEVICE_6506: return "Unknown device";
        case PciDevice1425::DEVICE_6507: return "Unknown device";
        case PciDevice1425::DEVICE_6508: return "Unknown device";
        case PciDevice1425::DEVICE_6509: return "Unknown device";
        case PciDevice1425::DEVICE_650D: return "Unknown device";
        case PciDevice1425::DEVICE_6511: return "Unknown device";
        case PciDevice1425::DEVICE_6514: return "Unknown device";
        case PciDevice1425::DEVICE_6515: return "Unknown device";
        case PciDevice1425::DEVICE_6580: return "Unknown device";
        case PciDevice1425::DEVICE_6581: return "Unknown device";
        case PciDevice1425::DEVICE_6582: return "Unknown device";
        case PciDevice1425::DEVICE_6583: return "Unknown device";
        case PciDevice1425::DEVICE_6584: return "Unknown device";
        case PciDevice1425::DEVICE_6585: return "Unknown device";
        case PciDevice1425::DEVICE_6586: return "Unknown device";
        case PciDevice1425::DEVICE_6587: return "Unknown device";
        case PciDevice1425::DEVICE_6588: return "Unknown device";
        case PciDevice1425::DEVICE_6589: return "Unknown device";
        case PciDevice1425::DEVICE_658A: return "Unknown device";
        case PciDevice1425::DEVICE_6601: return "Unknown device";
        case PciDevice1425::DEVICE_6602: return "Unknown device";
        case PciDevice1425::DEVICE_6603: return "Unknown device";
        case PciDevice1425::DEVICE_6604: return "Unknown device";
        case PciDevice1425::DEVICE_6605: return "Unknown device";
        case PciDevice1425::DEVICE_6606: return "Unknown device";
        case PciDevice1425::DEVICE_6607: return "Unknown device";
        case PciDevice1425::DEVICE_6608: return "Unknown device";
        case PciDevice1425::DEVICE_6609: return "Unknown device";
        case PciDevice1425::DEVICE_660D: return "Unknown device";
        case PciDevice1425::DEVICE_6611: return "Unknown device";
        case PciDevice1425::DEVICE_6614: return "Unknown device";
        case PciDevice1425::DEVICE_6615: return "Unknown device";
        case PciDevice1425::DEVICE_6680: return "Unknown device";
        case PciDevice1425::DEVICE_6681: return "Unknown device";
        case PciDevice1425::DEVICE_6682: return "Unknown device";
        case PciDevice1425::DEVICE_6683: return "Unknown device";
        case PciDevice1425::DEVICE_6684: return "Unknown device";
        case PciDevice1425::DEVICE_6685: return "Unknown device";
        case PciDevice1425::DEVICE_6686: return "Unknown device";
        case PciDevice1425::DEVICE_6687: return "Unknown device";
        case PciDevice1425::DEVICE_6688: return "Unknown device";
        case PciDevice1425::DEVICE_6689: return "Unknown device";
        case PciDevice1425::DEVICE_668A: return "Unknown device";
        case PciDevice1425::DEVICE_6801: return "Unknown device";
        case PciDevice1425::DEVICE_6802: return "Unknown device";
        case PciDevice1425::DEVICE_6803: return "Unknown device";
        case PciDevice1425::DEVICE_6804: return "Unknown device";
        case PciDevice1425::DEVICE_6805: return "Unknown device";
        case PciDevice1425::DEVICE_6806: return "Unknown device";
        case PciDevice1425::DEVICE_6807: return "Unknown device";
        case PciDevice1425::DEVICE_6808: return "Unknown device";
        case PciDevice1425::DEVICE_6809: return "Unknown device";
        case PciDevice1425::DEVICE_680D: return "Unknown device";
        case PciDevice1425::DEVICE_6811: return "Unknown device";
        case PciDevice1425::DEVICE_6814: return "Unknown device";
        case PciDevice1425::DEVICE_6815: return "Unknown device";
        case PciDevice1425::DEVICE_6880: return "Unknown device";
        case PciDevice1425::DEVICE_6881: return "Unknown device";
        case PciDevice1425::DEVICE_6882: return "Unknown device";
        case PciDevice1425::DEVICE_6883: return "Unknown device";
        case PciDevice1425::DEVICE_6884: return "Unknown device";
        case PciDevice1425::DEVICE_6885: return "Unknown device";
        case PciDevice1425::DEVICE_6886: return "Unknown device";
        case PciDevice1425::DEVICE_6887: return "Unknown device";
        case PciDevice1425::DEVICE_6888: return "Unknown device";
        case PciDevice1425::DEVICE_6889: return "Unknown device";
        case PciDevice1425::DEVICE_688A: return "Unknown device";
        case PciDevice1425::DEVICE_A000: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCIDEVICE1425_H
