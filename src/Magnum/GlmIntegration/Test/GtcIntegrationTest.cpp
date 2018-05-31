/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018
              Vladimír Vondruš <mosra@centrum.cz>
    Copyright © 2017 sigman78 <sigman78@gmail.com>

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
#include "Magnum/GlmIntegration/GtcIntegration.h"

namespace Magnum { namespace GlmIntegration { namespace Test {

struct GtcIntegrationTest: TestSuite::Tester {
    explicit GtcIntegrationTest();

    void quat();
    void dquat();
};

GtcIntegrationTest::GtcIntegrationTest() {
    addTests({&GtcIntegrationTest::quat,
              &GtcIntegrationTest::dquat});
}

void GtcIntegrationTest::quat() {
    Quaternion a{{1.0f, 2.0f, 3.0f}, 4.0f};
    glm::quat b{4.0f, 1.0f, 2.0f, 3.0f};

    CORRADE_COMPARE(Quaternion{b}, a);
    CORRADE_VERIFY(glm::quat{a} == b);
}

void GtcIntegrationTest::dquat() {
    Quaterniond a{{1.0, 2.0, 3.0}, 4.0};
    glm::dquat b{4.0, 1.0, 2.0, 3.0};

    CORRADE_COMPARE(Quaterniond{b}, a);
    CORRADE_VERIFY(glm::dquat{a} == b);
}

}}}

CORRADE_TEST_MAIN(Magnum::GlmIntegration::Test::GtcIntegrationTest)