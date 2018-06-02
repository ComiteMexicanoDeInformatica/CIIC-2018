#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        inregex = re.compile(r'^(\d+)\n(-?\d+(?: -?\d+)*)\n$')
        results = re.match(inregex, self.input).groups()
        self.assertEqual(len(results), 2)

        N = int(results[0])
        self.assertTrue(1 <= N <= 100000)

        nums = [int(x) for x in results[1].strip().split()]
        self.assertTrue(abs(sum(nums)) < 2**31)

        outregex = re.compile(r'^-?\d+\n$')
        self.assertTrue(re.match(outregex, self.output) != None)

Test().run()
