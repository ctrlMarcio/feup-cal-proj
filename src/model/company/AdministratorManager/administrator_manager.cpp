#include "administrator_manager.h"

AdministratorManager::AdministratorManager() {}

bool AdministratorManager::isValid(Administrator administrator)
{
    for (auto i : administratorSet)
    {
        if (i.getEmail()==administrator.getEmail())
        {
            return false;
        }
    }
    return true;
}

bool AdministratorManager::add(Administrator administrator)
{
    if (isValid(administrator))
    {
        administratorSet.push_back(administrator);
        return true;
    }
    return false;
}

bool AdministratorManager::remove(Administrator administrator)
{
    std::vector<Administrator>::iterator it;
    it = administratorSet.begin();
    for (auto i: administratorSet)
    {
        if (i.getEmail()==administrator.getEmail())
        {
            administratorSet.erase(it);
            return true;
        }
        it++;
    }
    return false;
}