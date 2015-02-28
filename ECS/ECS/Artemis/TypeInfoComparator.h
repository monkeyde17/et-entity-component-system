/****************************************************************************
 * TypeInfoComparator.h
 * Gasboy
 *
 * Created by Stefan Nguyen on 9/12/12.
 *
 * Copyright Vinova Pte. Ltd. All rights reserved.
 ****************************************************************************/

#ifndef Gasboy_TypeInfoComparator_h
#define Gasboy_TypeInfoComparator_h

#include <typeinfo>

/* 用于map的比较函数 */
struct type_info_comparator
{
    bool operator ()(const std::type_info* a, const std::type_info* b) const
    {
        /* 判断类型a是否是在类b之前定义*/
        return a->before(*b);
    }
};


#endif
