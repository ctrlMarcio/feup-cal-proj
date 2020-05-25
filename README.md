# Algorithm Analysis and Design project

[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/luist18/feup-cal-proj/C++%20CI%20Build?label=build%20%F0%9F%94%A8&logo=github)](https://github.com/luist18/feup-cal-proj/actions?query=workflow%3A%22C%2B%2B+CI+Build%22)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/luist18/feup-cal-proj/C++%20CI%20Documentation?label=docs%20%F0%9F%93%84&logo=github)](https://luist18.github.io/feup-cal-proj/)
[![Travis (.com)](https://img.shields.io/travis/com/luist18/feup-cal-proj?logo=travis)](https://travis-ci.com/github/luist18/feup-cal-proj)
[![Codecov](https://img.shields.io/codecov/c/github/luist18/feup-cal-proj?logo=codecov)](https://codecov.io/gh/luist18/feup-cal-proj)
[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/luist18/feup-cal-proj?logo=codefactor)](https://www.codefactor.io/repository/github/luist18/feup-cal-proj)
[![GitHub license](https://img.shields.io/github/license/luist18/feup-cal-proj?color=blue)](https://github.com/luist18/feup-cal-proj/blob/master/LICENSE)

This repository comprises the second part of the [Algorithm Analysis and Design](https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=436441) course unit project. The goal was to create a solution for a specific problem applying the object-oriented paradigm in C++ and algorithm design.

## Project description

The theme approached in the problem is a particularization of the Travelling Salesman Problem, the Vehicle Routing Problem with Pick-up and Delivery. This repository contains the algorithm solution for that problem as well as an application related to the problem.

### Project article

A more theoretical study of the problem can accessed [here](https://drive.google.com/file/d/1YlVI9hJ1NtfuTwiSq19lsFMAXwLnCYQZ/view?usp=sharing). The study contains all the information related to the algorithm development process as well as the conceptual business model.

## Compiling

### Dependencies

#### GraphViewer

[GraphViewer](https://github.com/STEMS-group/GraphViewer) is a tool for graph visualization based on the JUNG framework, in the context of the Algorithm Design and Analysis course, at FEUP. It has been developed and mantained over the years by the course's Teaching Assistant students.

#### Google Test

[Google](https://github.com/google/googletest) Test is a unit testing library for the C++ programming language, based on the xUnit architecture.

### Requirements

* **CMake 3.10.2** or higher
* **Java 8** or higher (used in GraphViewer)

### Linux

To compile a linux executable file run the ```build.sh``` script in the root directory. The output files are going to be stored in the **build** directory.

### Windows

To compile a linux executable file run the ```winbuild.sh``` script in the root directory. The output files are going to be stored in the **winbuild** directory.

## Running

### Resources and libraries

The maps must be placed in the **resources** directory. The GraphViewer jar file must be placed in the **lib** directory. Both directories have to be in the same directory as the executable file.

### Program arguments

#### Map name

The name of the map to run the application. There are currently two maps in the resources. A small map around FEUP, **resources/Porto**. And a highly connected graph with the city of Porto, **resources/Porto_strong**.

**Values:** Porto and Porto_strong.

#### Company garage id

The location ID of the company's garage. The location ID of a node is defined in the nodes.txt file of a map.

**Values:** any ID in the nodes.txt file of a map.

#### Demonstration mode

When defined true the application bootstraps a default company client with a set of predefined pick-up points. **This argument is optional.**

**Values:** true of false.

### Running in Linux

```bash
./application <map name> <company garage id> [<demonstration mode>]
```

### Running in Windows

```powershell
.\application.exe <map name> <company garage id> [<demonstration mode>]
```

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

## Examples

### 1. Company with 4 available vehicles and 7 pick-up points

![Company with 4 available vehicles and 7 pick-up points](https://i.imgur.com/4oy8kE0.gif)

### 2. Company with 3 available vehicles and 6 pick-up points

![Company with 3 available vehicles and 6 pick-up points](https://i.imgur.com/QAmIdw6.gif)

### Disclaimer

This repository contains the **C++** solution for the problem. Note that it might contain errors and should not be used as a solution for anyone besides the authors.

### License

[MIT](https://opensource.org/licenses/MIT)
