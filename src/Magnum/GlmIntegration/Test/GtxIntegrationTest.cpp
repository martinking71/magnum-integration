/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include <Corrade/TestSuite/Tester.h>

#include "Magnum/Magnum.h"

#define GLM_ENABLE_EXPERIMENTAL /* WTF, GLM! */
#include "Magnum/GlmIntegration/GtxIntegration.h"

namespace Magnum { namespace GlmIntegration { namespace Test {

struct GtxIntegrationTest: TestSuite::Tester {
    explicit GtxIntegrationTest();

    void dualquat();
    void ddualquat();
};

GtxIntegrationTest::GtxIntegrationTest() {
    addTests({&GtxIntegrationTest::dualquat,
              &GtxIntegrationTest::ddualquat});
}

void GtxIntegrationTest::dualquat() {
    DualQuaternion a{{{1.0f, 2.0f, 3.0f}, 4.0f},
                     {{5.0f, 6.0f, 7.0f}, 8.0f}};
    glm::dualquat b{{4.0f, 1.0f, 2.0f, 3.0f},
                    {8.0f, 5.0f, 6.0f, 7.0f}};

    CORRADE_COMPARE(DualQuaternion{b}, a);
    CORRADE_VERIFY(glm::dualquat{a} == b);
}

void GtxIntegrationTest::ddualquat() {
    DualQuaterniond a{{{1.0, 2.0, 3.0}, 4.0},
                      {{5.0, 6.0, 7.0}, 8.0}};
    glm::ddualquat b{{4.0, 1.0, 2.0, 3.0},
                     {8.0, 5.0, 6.0, 7.0}};

    CORRADE_COMPARE(DualQuaterniond{b}, a);
    CORRADE_VERIFY(glm::ddualquat{a} == b);
}
}}}

CORRADE_TEST_MAIN(Magnum::GlmIntegration::Test::GtxIntegrationTest)