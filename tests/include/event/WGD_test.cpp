//
// Created by pavel on 10/26/15.
//

#include "gtest/gtest.h"
#include "defined.hpp"
#include "event/WGD.hpp"
#include "structures/mcolor.hpp"

using namespace std;
using namespace event;
using namespace structure;

TEST(WgdTest, BasicConstructor1) {
    using wgd_t = WGD<Mcolor>;
    Mcolor parent(1);
    Mcolor children(1);
    size_t mult = 2;
    wgd_t wgd(parent, children, mult);
    EXPECT_EQ(mult, wgd.get_multiplicity());
    EXPECT_EQ(parent, wgd.get_parent());
    EXPECT_EQ(children, wgd.get_children());
}