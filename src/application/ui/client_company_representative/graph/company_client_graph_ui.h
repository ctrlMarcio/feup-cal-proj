#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_GRAPH_UI_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_GRAPH_UI_H

#include "../../../../../lib/graphviewer.h"
#include "../../../../model/company_client/company_client.h"
#include "../../ui/ui_manager.h"

class CompanyClientGraphUI : public UI {
public:
    explicit CompanyClientGraphUI(const UIManager &uiManager, bool returning);

    void run() override;

private:
    UIManager uiManager;

    bool returning;

    void buildGraph();
};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_GRAPH_UI_H
