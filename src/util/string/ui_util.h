#ifndef FEUP_CAL_PROJ_UI_UTIL_H
#define FEUP_CAL_PROJ_UI_UTIL_H

#include <vector>
#include <string>

#define TAB '\t'

/**
 * @brief Contains useful functions and utilities to deal with UI operations.
 */
namespace ui_util {

    /**
     * @brief Gets the current date as a string.
     *
     * @return  the current date
     */
    std::string getCurrentDate();

    /**
     * @brief Represents an option of a UI menu.
     */
    class Option {
    public:
        /**
         * @brief Identifier of an option.
         */
        static const short OPTION;

        /**
         * @brief Identifier of a new line.
         */
        static const short NEWLINE;

        /**
         * @brief Identifier of an empty line.
         */
        static const short LINE;

        /**
         * @brief Instantiates a new empty line.
         */
        Option();

        /**
         * @brief Instantiates a new line.
         *
         * @param desc   the description of the line.
         */
        explicit Option(std::string desc);

        /**
         * @brief Instantiates an option.
         *
         * @param option    the option number
         * @param desc      the description of the option
         */
        Option(int option, std::string desc);

        /**
         * @brief Gets the option number.
         *
         * @return the option number
         */
        int getOption() const;

        /**
         * @brief Gets the description.
         *
         * @return the description
         */
        const std::string &getDescription() const;

        /**
         * @brief Gets the line.
         *
         * @return the line
         */
        std::string getLine() const;

    private:
        /**
         * @brief The type of the option.
         */
        short type;

        /**
         * @brief The option number.
         */
        int option;

        /**
         * @brief The option description.
         */
        std::string desc;
    };

    /**
     * @brief Makes an empty line.
     *
     * @return  an empty line
     */
    Option make_empty_line();

    /**
     * @brief Makes a new line.
     *
     * @return  a new line
     */
    Option make_line(std::string desc);

    /**
     * @brief Makes an option.
     *
     * @return  an option
     */
    Option make_option(int option, std::string desc);

    /**
     * @brief Gets an option given a vector of options.
     *
     * @param options   the vector of options
     * @return  the selected option
     */
    int getOption(const std::vector<Option> &options);

    /**
     * @brief Gets a not empty string from the standard input.
     *
     * @param description   the message to show
     * @return  the string
     */
    std::string getString(const std::string &description);

    /**
     * @brief Gets an integer from the standard input.
     *
     * @param description	the message to show
     * @return	the integer
     */
    int getInteger(const std::string &description);

    /**
     * @brief Gets a long from the standard input.
     *
     * @param description	the message to show
     * @return	the long
     */
    long getLong(const std::string &description);

    /**
     * @brief Gets an unsigned number from the standard input.
     *
     * @param description   the message to show
     * @return  the unsigned number
     */
    unsigned long getUnsigned(const std::string &description);
};

#endif //FEUP_CAL_PROJ_UI_UTIL_H
