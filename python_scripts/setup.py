from setuptools import setup

setup( name='deltadebugnode',
       version='0.1',
       description='A wrapper for launching and interacting with a Delta Debug Node',
       url='http://github.com/deltait/delta',
       author='Deltait, Inc.',
       author_email='vandeberg@deltait.com',
       license='See LICENSE.md',
       packages=['deltadebugnode'],
       #install_requires=['deltaapi'],
       zip_safe=False )