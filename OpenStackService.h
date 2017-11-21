/*
Copyright 2012 Cloudbase Solutions Srl
All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may obtain
a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
License for the specific language governing permissions and limitations
under the License.
*/

#pragma once

#include "ServiceBase.h"

#define MAX_SVC_PATH (MAX_PATH * 10)

class CWrapperService : public CServiceBase
{
public:

    CWrapperService(PWSTR pszServiceName,
        TCHAR* szCmdLine,
        BOOL fCanStop = TRUE,
        BOOL fCanShutdown = TRUE,
        BOOL fCanPauseContinue = FALSE);
    virtual ~CWrapperService(void);

protected:

    virtual void OnStart(DWORD dwArgc, PWSTR *pszArgv);
    virtual void OnStop();

private:

    static DWORD WINAPI WaitForProcessThread(LPVOID lpParam);
    static void WINAPI KillProcessTree(DWORD dwProcId);

    TCHAR m_szCmdLine[MAX_SVC_PATH];
    DWORD m_dwProcessId;
    HANDLE m_hProcess;
    HANDLE m_WaitForProcessThread;
    volatile BOOL m_IsStopping;
};
