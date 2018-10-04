
#include <iostream>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "ITest.h"

int main()
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("tprime.TestService"));
    sp<tprime::ITestService> ts = interface_cast<tprime::ITestService>(binder);
    ts->testFun_01();
    ts->testFun_02();

    return 0;
}