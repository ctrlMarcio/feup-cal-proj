# Algorithm Analysis and Design project

[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/luist18/feup-cal-proj/C++%20CI%20Build?label=build%20%F0%9F%94%A8&logo=github)](https://github.com/luist18/feup-cal-proj/actions?query=workflow%3A%22C%2B%2B+CI+Build%22)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/luist18/feup-cal-proj/C++%20CI%20Documentation?label=documentation%20%F0%9F%93%84&logo=github)](https://github.com/luist18/feup-cal-proj/actions?query=workflow%3A%22C%2B%2B+CI+Documentation%22)
[![Travis (.com)](https://img.shields.io/travis/com/luist18/feup-cal-proj?logo=travis)](https://travis-ci.com/github/luist18/feup-cal-proj)
[![Codecov](https://img.shields.io/codecov/c/github/luist18/feup-cal-proj?logo=codecov)](https://codecov.io/gh/luist18/feup-cal-proj)
[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/luist18/feup-cal-proj?logo=codefactor)](https://www.codefactor.io/repository/github/luist18/feup-cal-proj)
[![GitHub license](https://img.shields.io/github/license/luist18/feup-cal-proj?color=blue)](https://github.com/luist18/feup-cal-proj/blob/master/LICENSE)

This repository comprises the second part of the [Algorithm Analysis and Design](https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=436441) course unit project. The goal was to create a solution for a specific problem applying the object-oriented paradigm in C++ and algorithm design.

## Project description

The theme approached in the problem is a particularization of the Travelling Salesman Problem, the Vehicle Routing Problem with Pick-up and Delivery. This repository contains the algorithm solution for that problem as well as an application related to the problem.

### Project article

A more theoretical study of the problem can accessed [here](https://drive.google.com/file/d/1YlVI9hJ1NtfuTwiSq19lsFMAXwLnCYQZ/view?usp=sharing). The study contains all the information related to the algorithm development process as well as the conceptual business model.

## Documentation

The code documentation is generated with [doxygen](http://www.doxygen.nl). Doxygen is a third-party documentation tool, thus, it is necessary a previous installation in order to be able to get the documentation.
A standard project doxygen configuration file is located in the 'docs' directory under the name _doxyfile_. Currently, the documentation is only exported in HTML. After exporting the files are stored in the **docs** directory.

Here is an example of how to export the documentation with the standard project doxygen configuration file:

```bash
cd doc
doxygen Doxyfile
```

## Testing

The unit tests are perfomed by [Google Test](https://github.com/google/googletest), the Google's C++ test framework. Currently, the version used is the latest.

The code coverage can be consulted by clicking the coverage badge in the header.

### Disclaimer

This repository contains the **C++** solution for the problem. Note that it might contain errors and should not be used as a solution.

### License

[MIT](https://opensource.org/licenses/MIT)
