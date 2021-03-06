/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016-2018 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <forward_list>
#include <iterator>
#include <catch.hpp>
#include <cpp-sort/probes/runs.h>

TEST_CASE( "presortedness measure: runs", "[probe][runs]" )
{
    SECTION( "simple tests" )
    {
        std::forward_list<int> li = { 40, 49, 58, 99, 60, 70, 12, 87, 9, 8, 82, 91, 99, 67, 82, 92 };
        CHECK( cppsort::probe::runs(li) == 5 );
        CHECK( cppsort::probe::runs(std::begin(li), std::end(li)) == 5 );

        // From Right invariant metrics and measures of
        // presortedness by Estivill-Castro, Mannila and Wood
        std::forward_list<int> li2 = { 4, 2, 6, 5, 3, 1, 9, 7, 10, 8 };
        CHECK( cppsort::probe::runs(li2) == 6 );
        CHECK( cppsort::probe::runs(std::begin(li2), std::end(li2)) == 6 );
    }

    SECTION( "lower bound" )
    {
        std::forward_list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        CHECK( cppsort::probe::runs(li) == 0 );
        CHECK( cppsort::probe::runs(std::begin(li), std::end(li)) == 0 );

        std::forward_list<int> li1 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        CHECK( cppsort::probe::runs(li1) == 0 );
    }

    SECTION( "upper bound" )
    {
        // The upper bound should correspond to the size of
        // the input sequence minus one

        std::forward_list<int> li = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        CHECK( cppsort::probe::runs(li) == 10 );
        CHECK( cppsort::probe::runs(std::begin(li), std::end(li)) == 10 );
    }
}
