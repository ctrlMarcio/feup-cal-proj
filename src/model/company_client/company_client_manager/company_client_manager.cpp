#include "company_client_manager.h"

CompanyClientManager::CompanyClientManager() {}

bool CompanyClientManager::isValid(CompanyClient companyClient)
{
    for (auto i : companyClientSet)
    {
        if (i.getUUID() == companyClient.getUUID())
        {
            return false;
        }
    }
    return true;
}

bool CompanyClientManager::add(CompanyClient companyClient)
{
    if (isValid(companyClient))
    {
        companyClientSet.push_back(companyClient);
        return true;
    }
    return false;
}

bool CompanyClientManager::remove(CompanyClient companyClient)
{
    std::vector<CompanyClient>::iterator it;
    it = companyClientSet.begin();
    for (auto i: companyClientSet)
    {
        if (i.getUUID() == companyClient.getUUID())
        {
            companyClientSet.erase(it);
            return true;
        }
        it++;
    }
    return false;
}