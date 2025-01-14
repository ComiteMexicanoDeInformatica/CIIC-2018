import sys
import os
import traceback

from collections import deque

class TestFailure(Exception):
    pass

class CTest:
    def __init__(self):
        self.input = sys.stdin.read()
        self.caseName = sys.argv[1]

        with open('data.out', 'r') as out:
            self.output = out.read()

    def run(self):
        try:
            self.test()
        except:
            sys.stderr.write(traceback.format_exc())
            print(0)
        else:
            print(1)

    def assertTrue(self, p):
        if not p:
            raise TestFailure()

    def assertFalse(self, p):
        if p:
            raise TestFailure()

    def assertEqual(self, p, q):
        if p != q:
            raise TestFailure(
                'Equality failure!\nExpected: {}\nGot: {}'.format(q,p)
            )

    def assertNotEqual(self, p, q):
        if p == q:
            raise TestFailure(
                'Inequality failure!\nGot: {}'.format(p)
            )
