#define LOG_TAG "TestService"

#include <iostream>
#include "ITest.h"

namespace tprime
{

class BpTestService : public BpInterface<ITestService>
{
  public:
    explicit BpTestService(const sp<IBinder> &impl)
        : BpInterface<ITestService>(impl)
    {
    }

    virtual ~BpTestService();
    virtual void testFun_01()
    {
        std::cout << "BpTestService::testFun_01" << std::endl;
        Parcel data, reply;
        data.writeInterfaceToken(ITestService::getInterfaceDescriptor());
        remote()->transact(BnTestService::TEST_01, data, &reply);
        // return interface_cast<ITestService>(reply.readStrongBinder());
    }

    virtual void testFun_02()
    {
        std::cout << "BpTestService::testFun_02" << std::endl;
        Parcel data, reply;
        data.writeInterfaceToken(ITestService::getInterfaceDescriptor());
        remote()->transact(BnTestService::TEST_02, data, &reply);
        // return
    }
};

// Out-of-line virtual method definition to trigger vtable emission in this
// translation unit (see clang warning -Wweak-vtables)
BpTestService::~BpTestService() {}
IMPLEMENT_META_INTERFACE(TestService, "tprime.test.ITestComposer");

status_t BnTestService::onTransact(uint32_t code, const Parcel &data,
                                   Parcel *reply, uint32_t flags)
{
    switch (code)
    {
    case TEST_01:
        CHECK_INTERFACE(ITestService, data, reply);
        testFun_01();
        return NO_ERROR;
    case TEST_02:
        CHECK_INTERFACE(ITestService, data, reply);
        testFun_02();
        return NO_ERROR;
    default:
    {
        return BBinder::onTransact(code, data, reply, flags);
    }
    }
}

}; // namespace tprime
