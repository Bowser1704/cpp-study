#include <iostream>

int main(){
    //看清楚注释的情况 
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */" << std::endl;
    std::cout << /* "*/" /* "/*" */;
    return 0;
}
