#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_ARRAYLIST_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_ARRAYLIST_H



#include <buildconfig.h>
#include <common/src/bits64/containers/arraylist.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_containers_arraylist);
{
    TEST_CASE("ArrayList()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("append()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       1);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);



        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       2);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);



        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       3);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);
        TEST_ASSERT_EQUALS(temp.mValues[2], 9);



        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       4);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);
        TEST_ASSERT_EQUALS(temp.mValues[2], 9);
        TEST_ASSERT_EQUALS(temp.mValues[3], 5);



        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);
        TEST_ASSERT_EQUALS(temp.mValues[2], 9);
        TEST_ASSERT_EQUALS(temp.mValues[3], 5);
        TEST_ASSERT_EQUALS(temp.mValues[4], 3);
    }
    TEST_CASE_END();



    TEST_CASE("prepend()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);



        TEST_ASSERT_EQUALS(temp.prepend(1), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       1);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);



        TEST_ASSERT_EQUALS(temp.prepend(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       2);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 7);
        TEST_ASSERT_EQUALS(temp.mValues[1], 1);



        TEST_ASSERT_EQUALS(temp.prepend(9), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       3);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);
        TEST_ASSERT_EQUALS(temp.mValues[2], 1);



        TEST_ASSERT_EQUALS(temp.prepend(5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       4);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 7);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);



        TEST_ASSERT_EQUALS(temp.prepend(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 3);
        TEST_ASSERT_EQUALS(temp.mValues[1], 5);
        TEST_ASSERT_EQUALS(temp.mValues[2], 9);
        TEST_ASSERT_EQUALS(temp.mValues[3], 7);
        TEST_ASSERT_EQUALS(temp.mValues[4], 1);
    }
    TEST_CASE_END();



    TEST_CASE("insert()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);



        TEST_ASSERT_EQUALS(temp.insert(0, 1), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       1);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);



        TEST_ASSERT_EQUALS(temp.insert(1, 7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       2);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);



        TEST_ASSERT_EQUALS(temp.insert(0, 9), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       3);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 1);
        TEST_ASSERT_EQUALS(temp.mValues[2], 7);



        TEST_ASSERT_EQUALS(temp.insert(1, 5), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   4);
        TEST_ASSERT_EQUALS(temp.mSize,       4);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 5);
        TEST_ASSERT_EQUALS(temp.mValues[2], 1);
        TEST_ASSERT_EQUALS(temp.mValues[3], 7);



        TEST_ASSERT_EQUALS(temp.insert(3, 3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 5);
        TEST_ASSERT_EQUALS(temp.mValues[2], 1);
        TEST_ASSERT_EQUALS(temp.mValues[3], 3);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);
    }
    TEST_CASE_END();



    TEST_CASE("removeAt()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);



        TEST_ASSERT_EQUALS(temp.removeAt(5), NgosStatus::NO_EFFECT);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);



        // TODO: Need to do when changed to i64
        /*
        TEST_ASSERT_EQUALS(temp.removeAt(-1), NgosStatus::NO_EFFECT);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);
        */



        TEST_ASSERT_EQUALS(temp.removeAt(3), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       4);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 7);



        TEST_ASSERT_EQUALS(temp.removeAt(0), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       3);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 3);
        TEST_ASSERT_EQUALS(temp.mValues[2], 7);



        TEST_ASSERT_EQUALS(temp.removeAt(2), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       2);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 3);



        TEST_ASSERT_EQUALS(temp.removeAt(0), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       1);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);

        TEST_ASSERT_EQUALS(temp.mValues[0], 3);



        TEST_ASSERT_EQUALS(temp.removeAt(0), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("clear()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity,   8);
        TEST_ASSERT_EQUALS(temp.mSize,       5);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);



        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("sort()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);



        TEST_ASSERT_EQUALS(temp.sort(), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 3);
        TEST_ASSERT_EQUALS(temp.mValues[2], 5);
        TEST_ASSERT_EQUALS(temp.mValues[3], 7);
        TEST_ASSERT_EQUALS(temp.mValues[4], 9);



        TEST_ASSERT_EQUALS(temp.sort([](const u8 &first, const u8 &second)
        {
            UEFI_LT((" | first = %u, second = %u", first, second));



            return first > second;
        }), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 7);
        TEST_ASSERT_EQUALS(temp.mValues[2], 5);
        TEST_ASSERT_EQUALS(temp.mValues[3], 3);
        TEST_ASSERT_EQUALS(temp.mValues[4], 1);
    }
    TEST_CASE_END();



    TEST_CASE("first()");
    {
        ArrayList<u8> temp;



        TEST_ASSERT_EQUALS(temp.prepend(5), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.first(), 5);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);



        TEST_ASSERT_EQUALS(temp.prepend(9), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.first(), 9);

        TEST_ASSERT_EQUALS(temp.mValues[0], 9);
        TEST_ASSERT_EQUALS(temp.mValues[1], 5);



        TEST_ASSERT_EQUALS(temp.prepend(3), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.first(), 3);

        TEST_ASSERT_EQUALS(temp.mValues[0], 3);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 5);



        TEST_ASSERT_EQUALS(temp.prepend(1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.first(), 1);

        TEST_ASSERT_EQUALS(temp.mValues[0], 1);
        TEST_ASSERT_EQUALS(temp.mValues[1], 3);
        TEST_ASSERT_EQUALS(temp.mValues[2], 9);
        TEST_ASSERT_EQUALS(temp.mValues[3], 5);



        TEST_ASSERT_EQUALS(temp.prepend(7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.first(), 7);

        TEST_ASSERT_EQUALS(temp.mValues[0], 7);
        TEST_ASSERT_EQUALS(temp.mValues[1], 1);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 9);
        TEST_ASSERT_EQUALS(temp.mValues[4], 5);
    }
    TEST_CASE_END();



    TEST_CASE("last()");
    {
        ArrayList<u8> temp;



        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.last(), 5);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);



        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.last(), 9);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);



        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.last(), 3);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);



        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.last(), 1);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);



        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.last(), 7);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);
    }
    TEST_CASE_END();



    TEST_CASE("at()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);

        TEST_ASSERT_EQUALS(temp.at(0), 5);
        TEST_ASSERT_EQUALS(temp.at(1), 9);
        TEST_ASSERT_EQUALS(temp.at(2), 3);
        TEST_ASSERT_EQUALS(temp.at(3), 1);
        TEST_ASSERT_EQUALS(temp.at(4), 7);
    }
    TEST_CASE_END();



    TEST_CASE("operator[]()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 3);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);

        TEST_ASSERT_EQUALS(temp[0], 5);
        TEST_ASSERT_EQUALS(temp[1], 9);
        TEST_ASSERT_EQUALS(temp[2], 3);
        TEST_ASSERT_EQUALS(temp[3], 1);
        TEST_ASSERT_EQUALS(temp[4], 7);

        temp[2] = 2;

        TEST_ASSERT_EQUALS(temp.mValues[0], 5);
        TEST_ASSERT_EQUALS(temp.mValues[1], 9);
        TEST_ASSERT_EQUALS(temp.mValues[2], 2);
        TEST_ASSERT_EQUALS(temp.mValues[3], 1);
        TEST_ASSERT_EQUALS(temp.mValues[4], 7);

        TEST_ASSERT_EQUALS(temp[0], 5);
        TEST_ASSERT_EQUALS(temp[1], 9);
        TEST_ASSERT_EQUALS(temp[2], 2);
        TEST_ASSERT_EQUALS(temp[3], 1);
        TEST_ASSERT_EQUALS(temp[4], 7);
    }
    TEST_CASE_END();



    TEST_CASE("getSize()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.getSize(), 0);

        TEST_ASSERT_EQUALS(temp.append(5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getSize(), 1);

        TEST_ASSERT_EQUALS(temp.append(9), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getSize(), 2);

        TEST_ASSERT_EQUALS(temp.append(3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getSize(), 3);

        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getSize(), 4);

        TEST_ASSERT_EQUALS(temp.append(7), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getSize(), 5);
    }
    TEST_CASE_END();



    TEST_CASE("isEmpty()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.isEmpty(), true);

        TEST_ASSERT_EQUALS(temp.append(1), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.isEmpty(), false);

        TEST_ASSERT_EQUALS(temp.clear(), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.isEmpty(), true);
    }
    TEST_CASE_END();



    TEST_CASE("setCapacity()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);



        TEST_ASSERT_EQUALS(temp.setCapacity(5), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity,   5);
        TEST_ASSERT_EQUALS(temp.mSize,       0);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);



        TEST_ASSERT_EQUALS(temp.setCapacity(10), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity,   10);
        TEST_ASSERT_EQUALS(temp.mSize,       0);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);



        temp.mSize    = 4;
        u8 *oldBuffer = temp.mValues;



        TEST_ASSERT_EQUALS(temp.setCapacity(6), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity,   6);
        TEST_ASSERT_EQUALS(temp.mSize,       4);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);
        TEST_ASSERT_EQUALS(temp.mValues,     oldBuffer);



        TEST_ASSERT_EQUALS(temp.setCapacity(3), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity,   3);
        TEST_ASSERT_EQUALS(temp.mSize,       3);
        TEST_ASSERT_NOT_EQUALS(temp.mValues, nullptr);
        TEST_ASSERT_EQUALS(temp.mValues,     oldBuffer);



        TEST_ASSERT_EQUALS(temp.setCapacity(0), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);
        TEST_ASSERT_EQUALS(temp.mSize,     0);
        TEST_ASSERT_EQUALS(temp.mValues,   nullptr);
    }
    TEST_CASE_END();



    TEST_CASE("getCapacity()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.getCapacity(), 0);

        TEST_ASSERT_EQUALS(temp.append(5),     NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getCapacity(), 4);

        TEST_ASSERT_EQUALS(temp.append(9),     NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getCapacity(), 4);

        TEST_ASSERT_EQUALS(temp.append(3),     NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getCapacity(), 4);

        TEST_ASSERT_EQUALS(temp.append(1),     NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getCapacity(), 4);

        TEST_ASSERT_EQUALS(temp.append(7),     NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.getCapacity(), 8);
    }
    TEST_CASE_END();



    TEST_CASE("extendCapacity()");
    {
        ArrayList<u8> temp;

        TEST_ASSERT_EQUALS(temp.mCapacity, 0);

        TEST_ASSERT_EQUALS(temp.extendCapacity(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.mCapacity,        4);

        temp.mSize = 4;

        TEST_ASSERT_EQUALS(temp.extendCapacity(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.mCapacity,        8);

        TEST_ASSERT_EQUALS(temp.extendCapacity(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.mCapacity,        8);

        temp.mSize = 8;

        TEST_ASSERT_EQUALS(temp.extendCapacity(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(temp.mCapacity,        16);
    }
    TEST_CASE_END();



    TEST_CASE("quickSort()");
    {
        ArrayList<u8> temp;

        for (i64 i = 0; i < 32; ++i)
        {
            TEST_ASSERT_EQUALS(temp.append(i * 169), NgosStatus::OK);
        }

        TEST_ASSERT_EQUALS(temp.mValues[0],  0);
        TEST_ASSERT_EQUALS(temp.mValues[1],  169);
        TEST_ASSERT_EQUALS(temp.mValues[2],  82);
        TEST_ASSERT_EQUALS(temp.mValues[3],  251);
        TEST_ASSERT_EQUALS(temp.mValues[4],  164);
        TEST_ASSERT_EQUALS(temp.mValues[5],  77);
        TEST_ASSERT_EQUALS(temp.mValues[6],  246);
        TEST_ASSERT_EQUALS(temp.mValues[7],  159);
        TEST_ASSERT_EQUALS(temp.mValues[8],  72);
        TEST_ASSERT_EQUALS(temp.mValues[9],  241);
        TEST_ASSERT_EQUALS(temp.mValues[10], 154);
        TEST_ASSERT_EQUALS(temp.mValues[11], 67);
        TEST_ASSERT_EQUALS(temp.mValues[12], 236);
        TEST_ASSERT_EQUALS(temp.mValues[13], 149);
        TEST_ASSERT_EQUALS(temp.mValues[14], 62);
        TEST_ASSERT_EQUALS(temp.mValues[15], 231);
        TEST_ASSERT_EQUALS(temp.mValues[16], 144);
        TEST_ASSERT_EQUALS(temp.mValues[17], 57);
        TEST_ASSERT_EQUALS(temp.mValues[18], 226);
        TEST_ASSERT_EQUALS(temp.mValues[19], 139);
        TEST_ASSERT_EQUALS(temp.mValues[20], 52);
        TEST_ASSERT_EQUALS(temp.mValues[21], 221);
        TEST_ASSERT_EQUALS(temp.mValues[22], 134);
        TEST_ASSERT_EQUALS(temp.mValues[23], 47);
        TEST_ASSERT_EQUALS(temp.mValues[24], 216);
        TEST_ASSERT_EQUALS(temp.mValues[25], 129);
        TEST_ASSERT_EQUALS(temp.mValues[26], 42);
        TEST_ASSERT_EQUALS(temp.mValues[27], 211);
        TEST_ASSERT_EQUALS(temp.mValues[28], 124);
        TEST_ASSERT_EQUALS(temp.mValues[29], 37);
        TEST_ASSERT_EQUALS(temp.mValues[30], 206);
        TEST_ASSERT_EQUALS(temp.mValues[31], 119);



        TEST_ASSERT_EQUALS(temp.quickSort(7, 25), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mValues[0],  0);
        TEST_ASSERT_EQUALS(temp.mValues[1],  169);
        TEST_ASSERT_EQUALS(temp.mValues[2],  82);
        TEST_ASSERT_EQUALS(temp.mValues[3],  251);
        TEST_ASSERT_EQUALS(temp.mValues[4],  164);
        TEST_ASSERT_EQUALS(temp.mValues[5],  77);
        TEST_ASSERT_EQUALS(temp.mValues[6],  246);
        TEST_ASSERT_EQUALS(temp.mValues[7],  47);
        TEST_ASSERT_EQUALS(temp.mValues[8],  52);
        TEST_ASSERT_EQUALS(temp.mValues[9],  57);
        TEST_ASSERT_EQUALS(temp.mValues[10], 62);
        TEST_ASSERT_EQUALS(temp.mValues[11], 67);
        TEST_ASSERT_EQUALS(temp.mValues[12], 72);
        TEST_ASSERT_EQUALS(temp.mValues[13], 129);
        TEST_ASSERT_EQUALS(temp.mValues[14], 134);
        TEST_ASSERT_EQUALS(temp.mValues[15], 139);
        TEST_ASSERT_EQUALS(temp.mValues[16], 144);
        TEST_ASSERT_EQUALS(temp.mValues[17], 149);
        TEST_ASSERT_EQUALS(temp.mValues[18], 154);
        TEST_ASSERT_EQUALS(temp.mValues[19], 159);
        TEST_ASSERT_EQUALS(temp.mValues[20], 216);
        TEST_ASSERT_EQUALS(temp.mValues[21], 221);
        TEST_ASSERT_EQUALS(temp.mValues[22], 226);
        TEST_ASSERT_EQUALS(temp.mValues[23], 231);
        TEST_ASSERT_EQUALS(temp.mValues[24], 236);
        TEST_ASSERT_EQUALS(temp.mValues[25], 241);
        TEST_ASSERT_EQUALS(temp.mValues[26], 42);
        TEST_ASSERT_EQUALS(temp.mValues[27], 211);
        TEST_ASSERT_EQUALS(temp.mValues[28], 124);
        TEST_ASSERT_EQUALS(temp.mValues[29], 37);
        TEST_ASSERT_EQUALS(temp.mValues[30], 206);
        TEST_ASSERT_EQUALS(temp.mValues[31], 119);



        TEST_ASSERT_EQUALS(temp.quickSort(7, 25, [](const u8 &first, const u8 &second)
        {
            UEFI_LT((" | first = %u, second = %u", first, second));



            return first > second;
        }), NgosStatus::OK);



        TEST_ASSERT_EQUALS(temp.mValues[0],  0);
        TEST_ASSERT_EQUALS(temp.mValues[1],  169);
        TEST_ASSERT_EQUALS(temp.mValues[2],  82);
        TEST_ASSERT_EQUALS(temp.mValues[3],  251);
        TEST_ASSERT_EQUALS(temp.mValues[4],  164);
        TEST_ASSERT_EQUALS(temp.mValues[5],  77);
        TEST_ASSERT_EQUALS(temp.mValues[6],  246);
        TEST_ASSERT_EQUALS(temp.mValues[7],  241);
        TEST_ASSERT_EQUALS(temp.mValues[8],  236);
        TEST_ASSERT_EQUALS(temp.mValues[9],  231);
        TEST_ASSERT_EQUALS(temp.mValues[10], 226);
        TEST_ASSERT_EQUALS(temp.mValues[11], 221);
        TEST_ASSERT_EQUALS(temp.mValues[12], 216);
        TEST_ASSERT_EQUALS(temp.mValues[13], 159);
        TEST_ASSERT_EQUALS(temp.mValues[14], 154);
        TEST_ASSERT_EQUALS(temp.mValues[15], 149);
        TEST_ASSERT_EQUALS(temp.mValues[16], 144);
        TEST_ASSERT_EQUALS(temp.mValues[17], 139);
        TEST_ASSERT_EQUALS(temp.mValues[18], 134);
        TEST_ASSERT_EQUALS(temp.mValues[19], 129);
        TEST_ASSERT_EQUALS(temp.mValues[20], 72);
        TEST_ASSERT_EQUALS(temp.mValues[21], 67);
        TEST_ASSERT_EQUALS(temp.mValues[22], 62);
        TEST_ASSERT_EQUALS(temp.mValues[23], 57);
        TEST_ASSERT_EQUALS(temp.mValues[24], 52);
        TEST_ASSERT_EQUALS(temp.mValues[25], 47);
        TEST_ASSERT_EQUALS(temp.mValues[26], 42);
        TEST_ASSERT_EQUALS(temp.mValues[27], 211);
        TEST_ASSERT_EQUALS(temp.mValues[28], 124);
        TEST_ASSERT_EQUALS(temp.mValues[29], 37);
        TEST_ASSERT_EQUALS(temp.mValues[30], 206);
        TEST_ASSERT_EQUALS(temp.mValues[31], 119);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_ARRAYLIST_H
