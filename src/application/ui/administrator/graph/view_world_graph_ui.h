#ifndef FEUP_CAL_PROJ_VIEW_WORLD_GRAPH_UI_H
#define FEUP_CAL_PROJ_VIEW_WORLD_GRAPH_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class ViewWorldGraphUI : public UI {
public:
    explicit ViewWorldGraphUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    void buildGraph() const;
};


#endif //FEUP_CAL_PROJ_VIEW_WORLD_GRAPH_UI_H
