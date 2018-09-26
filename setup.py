from distutils.core import setup, Extension

# define the extension module
rdtscp_module = Extension('rdtscp_module', sources=['rdtscp_module.c'])

# run the setup
setup(ext_modules=[rdtscp_module])
