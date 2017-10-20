TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += framelesswindow \
    exampleforwindows \
    examplesimplest

exampleforwindows.depends = framelesswindow
examplesimplest.depends = framelesswindow
