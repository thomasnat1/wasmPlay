// em++ increment3.cpp -o increment3.js -s INVOKE_RUN=0 -s EXPORTED_FUNCTIONS="['_increment']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']" <script type="text/javascript">
#include <iostream>
extern "C"
int increment(int num){
    num++;
    std::cout << num << std::endl;
    return 0;
}