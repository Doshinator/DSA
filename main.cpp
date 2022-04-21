#include "array.h"
#include "test.h"




int main(){

    ARRAY *a;

    Test(true, a->containsDuplicate({5, 4, 4, 3}));
    Test(false, a->containsDuplicate({5, 1, 4, 3, 2}));

    Test::printResult();
    return 0;
    
}

