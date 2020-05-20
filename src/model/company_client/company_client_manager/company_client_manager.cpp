#include <algorithm>
#include "company_client_manager.h"

CompanyClientManager::CompanyClientManager() = default;

bool CompanyClientManager::isValid(const CompanyClient &companyClient) const {
    return companyClient.getUUID() != 0 && !companyClient.getName().empty();
}

bool CompanyClientManager::add(CompanyClient companyClient) {
    if (!isValid(companyClient)) return false;
    if (has(companyClient)) return false;
    companies.push_back(companyClient);
    return true;
}

bool CompanyClientManager::remove(CompanyClient companyClient) {
    if (!has(companyClient)) return false;
    companies.erase(std::find(companies.begin(), companies.end(), companyClient));
    return true;
}

bool CompanyClientManager::has(CompanyClient &companyClient) const {
    return std::find(companies.begin(), companies.end(), companyClient) != companies.end();
}

bool CompanyClientManager::has(const long uuid) const {
    return std::find_if(companies.begin(), companies.end(), [&uuid](const CompanyClient &companyClient) {
        return companyClient.getUUID() == uuid;
    }) != companies.end();
}

std::vector<CompanyClient> CompanyClientManager::getCompanies() const {
    return companies;
}

long CompanyClientManager::getUsedVehiclesNumber() const {
    long total = 0;

    for (const CompanyClient &companyClient : this->companies)
        total += companyClient.getVehicleNumber();

    return total;
}

CompanyClient *CompanyClientManager::getCompany(long uuid) {
    auto it = companies.begin();

    while (it != companies.end()) {
        if ((*it).getUUID() == uuid) {
            return &(*it);
        }
        it++;
    }

    return nullptr;
}

CompanyClient *CompanyClientManager::getCompany(const std::string &email) {
    auto it = companies.begin();

    while (it != companies.end()) {
        if ((*it).getRepresentative().getEmail() == email) {
            return &(*it);
        }
        it++;
    }

    return nullptr;
}

