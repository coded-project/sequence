CodedProject::Sequence
======================

A C++, STL-compilant container which can be used to store numeric data, or any other data, for which arithmetic operators/expressions are valid.

Building the source
-------------------

Luckilly for you, the CodedProject::Sequence container is made up entirely of template classes meaning that there is nothing to be built!

All you need to do is add the include directory within this repository to your the include path for your project and include the "sequence/sequence.hpp" file wherever you use the container.

This, however may not be ideal, since you will end up adding a random directory to your include path for all of your project which use this container.
Instead, there are a few different options which you could consider:

1. (Recommended) Add the folder include/sequence/ to your project, prefereably under your own include directory if you have one, or somewhere else where it may be easily included by all of the targets within your project.
2. Copy the folder include/sequence/ to /usr/include/ if you are on a Unix based system and have administrator privileges (or maybe ~/include/ if you do not haveadmin rights?), or anywhere else on your system where you tend to keep include files for commonly used libraries (maybe C:\include on Windows?).
