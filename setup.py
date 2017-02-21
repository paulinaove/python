from distutils.core import setup
from distutils.core import Extension
MOD = "factorial"
module = Extension(MOD, sources = ["factorial.c"])
setup(name = MOD, ext_modules = [module])
