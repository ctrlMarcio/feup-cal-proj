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

    void calculatePaths(CompanyClient &company);

    void showGoogleMaps(CompanyClient &client);

    void showGraphView(CompanyClient &client);
};

#endif //FEUP_CAL_PROJ_VIEW_PATHS_UI_H
