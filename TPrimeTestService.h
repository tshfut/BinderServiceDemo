#ifndef TPRIME_TEST_SERVICE_H
#define TPRIME_TEST_SERVICE_H

#include <stdint.h>
#include <sys/types.h>
#include "ITest.h"
namespace tprime
{

class TPrimeTestService : public BnTestService
{
  public:
    explicit TPrimeTestService();

    virtual void testFun_01();
    virtual void testFun_02();

    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags);
};

}; // namespace tprime

#endif // TPRIME_TEST_SERVICE_H
