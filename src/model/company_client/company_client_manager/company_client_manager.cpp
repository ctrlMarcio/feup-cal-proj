#include <algorithm>
#include "company_client_manager.h"

CompanyClientManager::CompanyClientManager() {}

bool CompanyClientManager::isValid(const CompanyClient &companyClient) const {
    return companyClient.getUUID() != 0 && !companyClient.getName().empty();
}

bool CompanyClientManager::add(CompanyClient companyClient) {
    if (!isValid(companyClient)) return false;
    if (has(companyClient)) return false;
    return companiesClient.insert(companyClient).second;
}

bool CompanyClientManager::remove(CompanyClient companyClient) {
    if (!has(companyClient)) return false;
    return companiesClient.erase(companyClient) > 0;
}

bool CompanyClientManager::has(CompanyClient &companyClient) const {
    return std::find(companiesClient.begin(), companiesClient.end(), companyClient) != companiesClient.end();
}

bool CompanyClientManager::has(const long uuid) const {
    return std::find_if(companiesClient.begin(), companiesClient.end(), [&uuid](const CompanyClient &companyClient) {
        return companyClient.getUUID() == uuid;
    }) != companiesClient.end();
}

std::unordered_set<CompanyClient, companies_client_hash> CompanyClientManager::getCompaniesClient() const {
    return companiesClient;
}

long CompanyClientManager::getUsedVehiclesNumber() const {
	long total = 0;

	for (const CompanyClient &companyClient : this->companiesClient)
		total += companyClient.getVehicleNumber();

	return total;
}

