# DependencyAnalyzer

DependencyAnalyzer is console app for finding code dependency of each file in given directory.

### usage:
DependencyAnalyzer.exe <sources path> [options]

options:

-I - path for source files search
    
example:

DependencyAnalyzer.exe d:\mysources\ -I d:\mysources\includes -I d:\mylibrary
    


### modules:

#### Analyzer
Is the main module, who store dependency roots, build trees of dependency and count frequency of file includes. Cyclic dependencies ignored

#### DependencyNode
Structure for information of one node of dependency tree

#### IncludeSeeker
Modudule for seek includes in code-files. Get dependencies of one file

#### InputHandler
Parse console input (see usage)

#### OutputWriter
Print result into console. If file included, but not found mark (!)
