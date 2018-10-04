#include <iostream>
#include "TPrimeTestService.h"

namespace tprime
{

TPrimeTestService::TPrimeTestService()
{
}

void TPrimeTestService::testFun_01()
{
    std::cout << "TrpimeTestService::testFun_01" << std::endl;
}

void TPrimeTestService::testFun_02()
{
    std::cout << "TrpimeTestService::testFun_02" << std::endl;
}

status_t TPrimeTestService::onTransact(
    uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags)
{
    status_t err = BnTestService::onTransact(code, data, reply, flags);
    if (err == UNKNOWN_TRANSACTION || err == PERMISSION_DENIED)
    {
        CHECK_INTERFACE(ITestService, data, reply);
        std::cout << "TPrimeTestService::onTransact" << std::endl;
    }
    return err;
}

}; // namespace tprime
