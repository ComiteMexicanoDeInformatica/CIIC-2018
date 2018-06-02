#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import re

from ctest import *

class Test(CTest):
    def test(self):
        inregex = re.compile(r'^(\d+) (\d+)\n((?:\d+(?: \d+)*\n)*)$')
        match = re.match(inregex, self.input)

        self.assertTrue(match != None)
        
        results = match.groups()
        self.assertEqual(len(results), 3)

        T = int(results[0])
        C = int(results[1])

        self.assertTrue(1 <= T <= 500000)
        self.assertTrue(1 <= C <= 1000000)

        inlist = results[2].split('\n')
        inlist.pop()

        self.assertEqual(len(inlist), C+1)

        V = [[int(x) for x in y.split()] for y in inlist[:C]]

        self.assertTrue(all(
            1 <= g1 <= T and 1 <= g2 <= T and 0 <= c <= 10**9
            for g1, g2, c in V
        ))

        # no repeats
        self.assertEqual(
            len(V),
            len(frozenset(frozenset([g1, g2]) for g1, g2, _ in V))
        )

        I = [int(x) for x in inlist[-1].split()]

        self.assertEqual(len(I), T)

        self.assertTrue(all(
            abs(x) <= 10**10
            for x in I
        ))

        outregex = re.compile(r'^\d+\n$')
        self.assertTrue(re.match(outregex, self.output) != None)

Test().run()
