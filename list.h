//
// Created by avmd on 28.02.23.
//

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#endif //UNTITLED1_LIST_H


#ifndef TEMPLATES_LIST_2021_02_11
#define TEMPLATES_LIST_2021_02_11

namespace lab618 {

    struct MyStruct {
        int a;
        double b;

        explicit operator bool() const {
            if (a != 0 || b != 0)
                return true;
            return false;
        }
    };

};
#endif //#ifndef TEMPLATES_LIST_2021_02_11