# Proposed Project Structure

The following structure ensures that the data analysis tool is clean, modular and scalable. The proposed structure is based on principles of **modularity**, **single responsibility**, and **separation of concerns**, which align with best practices in software engineering.

```bash
DataAnalyzer/
├── CMakeLists.txt         # build + test wiring
├── include/
│   ├── Analyzer.h         # public API, pragma once, namespace da
│   └── utils.h
├── src/
│   ├── Analyzer.cpp       # implementation; include only needed headers
│   └── utils.cpp
├── main.cpp               # CLI parsing + orchestration
├── data/
│   └── sample.csv
├── tests/
│   ├── test_analyzer.cpp  # unit tests
│   └── test_utils.cpp
└── README.md
```
