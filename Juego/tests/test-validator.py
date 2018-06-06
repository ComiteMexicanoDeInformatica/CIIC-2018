#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        inregex = re.compile(r'^(\d+)\n(-?\d+(?: -?\d+)*)\n$')
        match = re.match(inregex, self.input)

        self.assertTrue(match != None)

        results = match.groups()
        self.assertEqual(len(results), 2)

        N = int(results[0])
        self.assertTrue(1 <= N <= 100000)

        nums = [int(x) for x in results[1].strip().split()]

        self.assertEqual(len(nums), 2*N)
        self.assertTrue(sum(abs(x) for x in nums) < 2**31)

        if 'easy' in self.caseName:
            self.assertTrue(
                all(x >= 0 for x in nums) or
                all(x <= 0 for x in nums)
            )
        elif 'medium' in self.caseName:
            self.assertTrue(N <= 20)
        else:
            self.assertTrue(N >= 30)

        outregex = re.compile(r'^-?\d+\n$')
        self.assertTrue(re.match(outregex, self.output) != None)

Test().run()
