#ifndef FEUP_CAL_PROJ_UI_UTIL_H
#define FEUP_CAL_PROJ_UI_UTIL_H

#include <vector>
#include <string>

#define TAB '\t'

namespace ui_util {

    std::string getCurrentDate();

    class Option {
    public:
        static const short OPTION;

        static const short NEWLINE;

        static const short LINE;

        Option();

        explicit Option(std::string desc);

        Option(int option, std::string desc);

        int getOption() const;

        const std::string &getDescription() const;

        std::string getLine() const;

    private:
        short type;

        int option;

        std::string desc;
    };

    Option make_empty_line();

    Option make_line(std::string desc);

    Option make_option(int option, std::string desc);

    int getOption(const std::vector<Option> &options);

};

#endif //FEUP_CAL_PROJ_UI_UTIL_H
