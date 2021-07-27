#include <iostream>
#include "InputHandler.h"
#include "Analyzer.h"

int main(int argc, char* argv[]) {
    InputHandler input(argc, argv);
    
    Analyzer analyzer(input.getSources(), input.getAdditionalIncludes());
    analyzer.exec();

    system("pause");
}
