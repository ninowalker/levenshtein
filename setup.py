from distutils.core import setup, Extension

module1 = Extension('levenshtein', sources = ['python.c','levenshtein.c'])

setup (name = 'levenshtein',
       version = '1.0',
       description = 'The levenshtein module implements fast Damerau-Levenshtein edit distance computation in O(n) memory and O(n^2) time, using a C wrapper',
       ext_modules = [module1])
