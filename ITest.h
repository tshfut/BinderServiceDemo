//Test.h
#ifndef __TEST_H
#define __TEST_H

#include <iostream>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace tprime
{

// service common interface
class ITestService : public IInterface
{
  public:
    DECLARE_META_INTERFACE(TestService) // detail: frameworks/native/libs/binder/include/binder/IInterface.h
    virtual void testFun_01() = 0;
    virtual void testFun_02() = 0;
};

class BnTestService : public BnInterface<ITestService>
{
  public:
    enum
    {
        TEST_01 = IBinder::FIRST_CALL_TRANSACTION,
        TEST_02,
    };

    virtual void testFun_01()
    {
        std::cout << "BnTestService::testFun_01" << std::endl;
    }
    virtual void testFun_02()
    {
        std::cout << "BnTestService::testFun_02" << std::endl;
    }

    virtual status_t onTransact(uint32_t code, const Parcel &data,
                                Parcel *reply, uint32_t flags = 0);
}; //BnTestService

}; // namespace tprime

#endif // __TEST_H
