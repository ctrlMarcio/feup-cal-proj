#ifndef FEUP_CAL_PROJ_VIEW_PATHS_UI_H
#define FEUP_CAL_PROJ_VIEW_PATHS_UI_H

#include "../../ui/ui_manager.h"

class ViewPathsUI : public UI {
public:
    explicit ViewPathsUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;

    void showGoogleMaps(CompanyClient &client, bool approximate);

    void showGraphView(CompanyClient &client, bool approximate);
};

#endif //FEUP_CAL_PROJ_VIEW_PATHS_UI_H
