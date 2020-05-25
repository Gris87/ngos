#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_MAP_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_MAP_H



#include <buildconfig.h>
#include <common/src/bits64/containers/map.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_containers_map);
{
    TEST_CASE("Map()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.isEmpty(), true);
    }
    TEST_CASE_END();



    TEST_CASE("insert()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        1);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 1000);



        TEST_ASSERT_EQUALS(temp.insert(3, 123), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        2);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);



        TEST_ASSERT_EQUALS(temp.insert(9, 789), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(7, 888), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(4, 456), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(7, 123456789), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 123456789);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(4, 987654321), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 987654321);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 123456789);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(3, 98765), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 98765);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 987654321);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 123456789);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.insert(9, 12345), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 98765);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 987654321);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 123456789);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 12345);



        TEST_ASSERT_EQUALS(temp.insert(5, 45678), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 98765);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 987654321);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 45678);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 123456789);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 12345);
    }
    TEST_CASE_END();



    TEST_CASE("remove()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(3, 123),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(9, 789),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(7, 888),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(4, 456),  NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(1), NgosStatus::NOT_FOUND);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(10), NgosStatus::NOT_FOUND);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(4), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(7), NgosStatus::NOT_FOUND);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.remove(9), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        2);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 1000);



        TEST_ASSERT_EQUALS(temp.remove(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        1);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 1000);



        TEST_ASSERT_EQUALS(temp.remove(5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.remove(5), NgosStatus::NOT_FOUND);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);
    }
    TEST_CASE_END();



    TEST_CASE("clear()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(3, 123),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(9, 789),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(7, 888),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(4, 456),  NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);
    }
    TEST_CASE_END();



    TEST_CASE("contains()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(3, 123),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(9, 789),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(7, 888),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(4, 456),  NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.contains(1),  false);
        TEST_ASSERT_EQUALS(temp.contains(10), false);
        TEST_ASSERT_EQUALS(temp.contains(8),  false);
        TEST_ASSERT_EQUALS(temp.contains(4),  true);
        TEST_ASSERT_EQUALS(temp.contains(3),  true);
        TEST_ASSERT_EQUALS(temp.contains(9),  true);
    }
    TEST_CASE_END();



    TEST_CASE("value()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.mPairs.getSize(), 0);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(3, 123),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(9, 789),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(7, 888),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(4, 456),  NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.value(1,  0), 0);
        TEST_ASSERT_EQUALS(temp.value(10, 0), 0);
        TEST_ASSERT_EQUALS(temp.value(8,  0), 0);
        TEST_ASSERT_EQUALS(temp.value(4,  0), 456);
        TEST_ASSERT_EQUALS(temp.value(3,  0), 123);
        TEST_ASSERT_EQUALS(temp.value(9,  0), 789);
    }
    TEST_CASE_END();



    TEST_CASE("isEmpty()");
    {
        Map<u8, u32> temp;

        TEST_ASSERT_EQUALS(temp.isEmpty(), true);



        TEST_ASSERT_EQUALS(temp.insert(5, 1000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(3, 123),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(9, 789),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(7, 888),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.insert(4, 456),  NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mPairs.getSize(),        5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getKey(),   3);
        TEST_ASSERT_EQUALS(temp.mPairs.at(0).getValue(), 123);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getKey(),   4);
        TEST_ASSERT_EQUALS(temp.mPairs.at(1).getValue(), 456);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getKey(),   5);
        TEST_ASSERT_EQUALS(temp.mPairs.at(2).getValue(), 1000);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getKey(),   7);
        TEST_ASSERT_EQUALS(temp.mPairs.at(3).getValue(), 888);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getKey(),   9);
        TEST_ASSERT_EQUALS(temp.mPairs.at(4).getValue(), 789);



        TEST_ASSERT_EQUALS(temp.isEmpty(), false);



        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.isEmpty(), true);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_MAP_H
